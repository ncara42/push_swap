/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:32:15 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/07 00:09:51 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_n_chunks(int n)
{
		if (n <= 5) // Si hay 5 numeros, quiero 1 chunk
			return (1); 
		else if (n <= 50)
			return (2);
		else if (n <= 100)
			return (3);
		else if (n <= 500) // Si hay 500 numeros, quiero 20 chunks
			return (9);
	return (11); // Si hay más de 500 (cosa que no se evalua), puse 25 porque me daba un poco la gana, gay
				// Vuelve a la linea 111
}

int		get_top_pos(t_list *stack_a, long *arr, int start, int end)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->content >= arr[start] && stack_a->content <= arr[end])
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (-1);
}

int		get_bottom_pos(t_list *stack_a, long *arr, int start, int end)
{
	int	i;
	int	bottom;
	
	i = 0;
	bottom = -1;
	while (stack_a)
	{
		if (stack_a->content >= arr[start] && stack_a->content <= arr[end])
			bottom = i; // Aqui en lugar de devolver la primera posicion como en get_top, devuelvo la ultima, por eso guardo el valor, en lugar de devolverlo
		stack_a = stack_a->next;
		i++;
	}
	return (bottom);
}

void	nearest_num(t_list **stack_a, t_list **stack_b, long *arr,
			int start, int end)
{
	int	top;
	int	bottom;
	int	size;
	int pivot;

	top = get_top_pos(*stack_a, arr, start, end); // #6 Función (linea 40) -> El primer numero del stack está mas cerca de la cima
	bottom = get_bottom_pos(*stack_a, arr, start, end); // #7 Funcion (linea 55) -> Lo mismo, pero el más cercano empezando desde el último
	size = ft_lstsize(*stack_a);
	if (top <= size - bottom)
	{
		while (top-- > 0)
			ra(stack_a, 0);
	}
	else
	{
		bottom = size - bottom;
		while (bottom-- > 0)
			rra(stack_a, 0);
	}
	pb(stack_a, stack_b, 0);
    pivot = start + (end - start) / 2; // Esto es lo que me hizo la IA
    if (ft_lstsize(*stack_b) > 1 && (*stack_b)->content < arr[pivot]) // y esto
        rb(stack_b, 0);
		// Baja a la linea 191, el codigo sigue ahí
}

int		in_range(t_list *stack_a, long *arr, int start, int end)
{
	while (stack_a)
	{
		if (stack_a->content >= arr[start] && stack_a->content <= arr[end]) // Está dentro del rango?
			return (1); // SÍ: OK
		stack_a = stack_a->next; // NO: pasa al siguiente numero
	}
	return (0);
}

void	get_chunks(t_list **stack_a, t_list **stack_b, long *arr, int n)
{
	int	chunks;
	int	size;
	int	start;
	int	end;
	int	i;

	chunks = get_n_chunks(n); // #3 Funcion (linea 26) -> Quiero N chunks en funcion del tamaño del stack A
	size = n / chunks;
	i = 0;
	while (i < chunks)
	{
		start = i * size; // El chunk empieza en 0 (0 * size = 0)
		if (i == chunks - 1)
			end = n - 1; // Le resto uno porque empezamos a contar desde 0 (0-49 son 50)
		else
			end = start + size - 1;
		while (in_range(*stack_a, arr, start, end)) // #4 Funcion (linea 100) -> Checkeo si el primer numero del stack está en el range
			nearest_num(stack_a, stack_b, arr, start, end); // #5 Función (lina 72) Si está en el range, entonces calculo cual es el mas cercano, tanto de la cima como del final
		i++;
	}
}

int		get_max_pos(t_list *stack_b)
{
	int	pos;
	int	max_pos;
	int	max_val;
	
	pos = 0;
	max_pos = 0;
	max_val = stack_b->content;
	while (stack_b)
	{
		if (stack_b->content > max_val)
		{
			max_val = stack_b->content;
			max_pos = pos;
		}
		stack_b = stack_b->next;
		pos++;
	}
	return (max_pos);
}

void	pushing_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max_pos; // Necesito ordenar en A pasando los mayores de B primero para que queden al fondo
	int	size;

	while (*stack_b)
	{
		max_pos = get_max_pos(*stack_b); // #9 Funcion (linea 136) Obtengo el numero mayor del stack B
		size = ft_lstsize(*stack_b);
		if (max_pos <= size / 2) // Si estás por debajo de la mitad (o sea en la primera mitad), lo subo hacia arriba
		{
			while (max_pos-- > 0)
				rb(stack_b, 0);
		}
		else // Si está por debajo, lo subo rotando desde abajo
		{
			max_pos = size - max_pos;
			while (max_pos--)
				rrb(stack_b, 0);
		}
		pa(stack_a, stack_b, 0); // Una vez arriba, hago pa y LISTO!!!
	}
}

void	medium(t_list **stack_a, t_list **stack_b) // #1 Función main
{
	long	*arr;
	int		size;
	size = ft_lstsize(*stack_a);
	arr = array_sort(*stack_a, size);
	if (!arr)
		return ;
	get_chunks(stack_a, stack_b, arr, size); // #2 Función (linea 111) -> Voy a dividir chunks
	pushing_to_a(stack_a, stack_b); // #8 Función (linea 158) -> Ya hice push a B, ahora toca hacer B->A
	free(arr);
}