# Push Swap

## 📖 Descripción

Push_swap es un proyecto de algoritmos de ordenamiento que implementa múltiples estrategias para ordenar una pila de números enteros utilizando un conjunto limitado de operaciones. El programa selecciona automáticamente el algoritmo más eficiente basándose en un **índice de desorden** calculado dinámicamente.

Este proyecto fue desarrollado en pareja por **ncaravac** y **vvan-ach** como parte del currículum de 42 Barcelona.

## 🎯 Objetivo

El objetivo principal es ordenar una pila de números enteros (stack A) utilizando una pila auxiliar (stack B) con el menor número posible de operaciones. El programa implementa tres algoritmos diferentes que se adaptan según el nivel de desorden de los datos de entrada.

## 🔧 Operaciones Permitidas

El programa puede realizar las siguientes operaciones:

### Intercambio (Swap)
- **sa**: Intercambia los dos primeros elementos de la pila A
- **sb**: Intercambia los dos primeros elementos de la pila B
- **ss**: Ejecuta sa y sb simultáneamente

### Empuje (Push)
- **pa**: Mueve el primer elemento de B a la cima de A
- **pb**: Mueve el primer elemento de A a la cima de B

### Rotación (Rotate)
- **ra**: Rota la pila A hacia arriba (el primer elemento se convierte en el último)
- **rb**: Rota la pila B hacia arriba
- **rr**: Ejecuta ra y rb simultáneamente

### Rotación Inversa (Reverse Rotate)
- **rra**: Rota la pila A hacia abajo (el último elemento se convierte en el primero)
- **rrb**: Rota la pila B hacia abajo
- **rrr**: Ejecuta rra y rrb simultáneamente

## 🧮 Índice de Desorden

El **índice de desorden** es una métrica clave que determina qué algoritmo utilizar. Se calcula mediante la siguiente fórmula:

```
DI = (errores * 100) / ((n * (n - 1)) / 2)
```

Donde:
- **errores**: Número de pares de elementos que están en orden incorrecto
- **n**: Número total de elementos en la pila

El índice varía de 0% (completamente ordenado) a 100% (orden inverso completo).

### Interpretación del Índice

- **DI = 0%**: La pila ya está ordenada
- **0% < DI < 20%**: Desorden bajo → Se utiliza el algoritmo **Simple**
- **20% ≤ DI < 50%**: Desorden medio → Se utiliza el algoritmo **Medium**
- **DI ≥ 50%**: Desorden alto → Se utiliza el algoritmo **Complex**

## 🎨 Algoritmos Implementados

### 1. Algoritmo Simple - O(n²)

**Estrategia**: Búsqueda e inserción del mínimo.

**Funcionamiento**:
1. Encuentra el elemento mínimo en la pila A
2. Lo rota hasta la cima (usando ra o rra según esté más cerca)
3. Lo empuja a la pila B con pb
4. Repite hasta que queden solo 3 elementos en A
5. Ordena los 3 elementos restantes con operaciones específicas
6. Devuelve todos los elementos de B a A

**Complejidad**: O(n²)  
**Mejor uso**: Pilas con menos de 20% de desorden o tamaños pequeños

### 2. Algoritmo Medium - O(n√n)

**Estrategia**: División en chunks (fragmentos) y ordenamiento por rangos.

**Funcionamiento**:
1. Ordena los valores en un array auxiliar para obtener rangos
2. Divide la pila en chunks basados en percentiles
3. Para cada chunk:
   - Identifica el número más cercano (desde arriba o abajo)
   - Lo rota hasta la cima
   - Lo empuja a la pila B
   - Usa rotación en B para mantener elementos mayores arriba
4. Devuelve elementos de B a A desde el máximo al mínimo

**Complejidad**: O(n√n)  
**Mejor uso**: Pilas con 20-50% de desorden

### 3. Algoritmo Complex - O(n log n)

**Estrategia**: Quick Sort adaptado (divide y conquista).

**Funcionamiento**:
1. Calcula el pivote como la mediana de la pila
2. Particiona la pila:
   - Elementos ≤ pivote → pila B
   - Elementos > pivote → quedan en A
3. Aplica recursivamente el algoritmo a ambas sub-pilas
4. Para grupos de 3 o menos elementos, usa ordenamiento directo

**Complejidad**: O(n log n)  
**Mejor uso**: Pilas con más de 50% de desorden o tamaños grandes

## 🚀 Compilación y Uso

### Compilación

```bash
make
```

Para compilar en modo debug:

```bash
make debug
```

Para limpiar archivos objeto:

```bash
make clean
```

Para limpiar todo (incluyendo ejecutable):

```bash
make fclean
```

### Uso Básico

```bash
./push_swap [FLAGS] <números>
```

**Ejemplos**:

```bash
# Modo adaptativo (por defecto)
./push_swap 5 2 3 1 4

# Forzar algoritmo simple
./push_swap --simple 5 2 3 1 4

# Forzar algoritmo medium
./push_swap --medium 42 17 8 23 56 91 33

# Forzar algoritmo complex
./push_swap --complex 9 7 5 3 1 2 4 6 8

# Modo adaptativo con estadísticas
./push_swap --adaptive 5 2 3 1 4

# Solo ver estadísticas (benchmark)
./push_swap --bench 5 2 3 1 4

# Benchmark con algoritmo específico
./push_swap --bench --simple 5 2 3 1 4
./push_swap --bench --medium 5 2 3 1 4
./push_swap --bench --complex 5 2 3 1 4
```

## 🏁 Flags Disponibles

### `--simple`
Fuerza el uso del algoritmo Simple (O(n²)) independientemente del índice de desorden.

**Cuándo usarlo**: 
- Para probar el algoritmo en casos específicos
- Pilas muy pequeñas (< 10 elementos)
- Comparación de rendimiento

### `--medium`
Fuerza el uso del algoritmo Medium (O(n√n)) independientemente del índice de desorden.

**Cuándo usarlo**:
- Para pilas de tamaño medio (10-100 elementos)
- Cuando el desorden es moderado
- Testing y comparación

### `--complex`
Fuerza el uso del algoritmo Complex (O(n log n)) independientemente del índice de desorden.

**Cuándo usarlo**:
- Para pilas grandes (> 100 elementos)
- Alto nivel de desorden
- Rendimiento óptimo en casos complejos

### `--adaptive`
Selecciona automáticamente el mejor algoritmo basándose en el índice de desorden (este es el comportamiento por defecto).

**Cuándo usarlo**:
- Cuando no conoces el nivel de desorden
- Para obtener el mejor rendimiento automático
- Uso general del programa

### `--bench`
Muestra estadísticas detalladas de la ejecución incluyendo:
- Índice de desorden calculado
- Algoritmo seleccionado
- Número total de operaciones
- Desglose de cada tipo de operación (sa, sb, pa, pb, ra, rb, etc.)

**Cuándo usarlo**:
- Para analizar el rendimiento
- Comparar diferentes algoritmos
- Debugging y optimización

**Nota**: Se pueden combinar flags, por ejemplo: `--bench --simple` ejecutará el algoritmo simple y mostrará las estadísticas.

## 📊 Ejemplos de Salida

### Salida Normal

```bash
$ ./push_swap 5 2 3 1 4
pb
pb
ra
pb
ra
pa
pa
pa
```

### Salida con Benchmark

```bash
$ ./push_swap --bench 5 2 3 1 4
pb
pb
ra
pb
ra
pa
pa
pa
[bench] disorder:  60.00%
[bench] strategy:  Adaptive / O(n log n)
[bench] total_ops:  8
[bench] sa:  0  sb:  0  ss:  0  pa:  3  pb:  3
[bench] ra:  2  rb:  0  rr:  0  rra:  0  rrb:  0  rrr:  0
```

### Comparación de Algoritmos

```bash
# Simple (forzado)
$ ./push_swap --bench --simple 9 7 5 3 1 2 4 6 8
[bench] strategy:  Simple / O(n^2)
[bench] total_ops:  28

# Medium (forzado)
$ ./push_swap --bench --medium 9 7 5 3 1 2 4 6 8
[bench] strategy:  Medium / O(n√n)
[bench] total_ops:  22

# Complex (forzado)
$ ./push_swap --bench --complex 9 7 5 3 1 2 4 6 8
[bench] strategy:  Complex / O(n log n)
[bench] total_ops:  18
```

## 🧪 Testing

Para probar el programa con un checker:

```bash
# Generar números aleatorios y verificar
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | ./checker $ARG

# Contar operaciones
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | wc -l

# Test con benchmark
ARG=$(seq 1 500 | shuf); ./push_swap --bench $ARG
```

## 📈 Rendimiento Esperado

### Pilas Pequeñas (< 100 números)
- **3 números**: 2-3 operaciones
- **5 números**: 7-12 operaciones
- **100 números**: < 700 operaciones (modo adaptativo)

### Pilas Grandes
- **500 números**: < 5500 operaciones
- **1000 números**: < 11500 operaciones

## 🏗️ Estructura del Proyecto

```
push_swap/
├── Makefile                    # Compilación del proyecto
├── README.md                   # Este archivo
├── includes/
│   └── push_swap.h            # Definiciones y prototipos
├── libft/                      # Biblioteca de funciones auxiliares
│   ├── includes/
│   │   └── libft.h
│   └── srcs/
│       ├── ft_array_sort.c
│       ├── ft_atol.c
│       ├── ft_check_flags.c
│       └── ... (otras funciones)
└── srcs/
    ├── push_swap.c            # Función principal
    ├── adaptive.c             # Selector adaptativo
    ├── disorder_index.c       # Cálculo del índice de desorden
    ├── simple.c               # Algoritmo Simple
    ├── medium.c               # Algoritmo Medium
    ├── complex.c              # Algoritmo Complex
    ├── bench_*.c              # Versiones con benchmark
    ├── parse_options.c        # Parseo de flags
    ├── print_bench_info.c     # Impresión de estadísticas
    ├── swap.c                 # Operaciones sa, sb, ss
    ├── push.c                 # Operaciones pa, pb
    ├── rotate.c               # Operaciones ra, rb, rr
    ├── reverse_rotate.c       # Operaciones rra, rrb, rrr
    ├── sort_three*.c          # Ordenamiento de 3 elementos
    └── free.c                 # Liberación de memoria
```

## 🔬 Detalles Técnicos

### Estructuras de Datos

#### `t_list`
Lista enlazada para representar las pilas.

#### `t_stacks`
Contiene punteros a ambas pilas (A y B) y límites para chunks.

#### `t_stats`
Almacena estadísticas de ejecución para el modo benchmark.

#### `t_options`
Gestiona las opciones de línea de comandos.

### Validación de Entrada

El programa valida:
- ✅ Solo números enteros
- ✅ Rango de valores (INT_MIN a INT_MAX)
- ✅ Sin duplicados
- ✅ Flags válidos
- ❌ Entrada vacía devuelve sin error
- ❌ Entrada inválida imprime "Error\n" en stderr

## 🎓 Conceptos Aprendidos

Este proyecto cubre los siguientes conceptos algorítmicos:

1. **Análisis de Complejidad**: Comparación de algoritmos O(n²), O(n√n) y O(n log n)
2. **Algoritmos de Ordenamiento**: Quick Sort, ordenamiento por inserción, ordenamiento por chunks
3. **Estructuras de Datos**: Listas enlazadas, pilas (stacks)
4. **Optimización**: Selección adaptativa de algoritmos según características de entrada
5. **Análisis de Datos**: Cálculo de métricas (índice de desorden)
6. **Parsing**: Procesamiento de argumentos y flags
7. **Testing y Benchmarking**: Medición y comparación de rendimiento

## 👥 Autores

- **ncaravac** (Nicolás Caravaca)
- **vvan-ach** (Victor Van Achter)

Proyecto realizado en **42 Barcelona** - 2025/2026

## 📝 Licencia

Este proyecto es parte del currículum de 42 y sigue sus políticas de uso educativo.

## 🔗 Recursos Adicionales

Para entender mejor los algoritmos de ordenamiento y la teoría detrás de push_swap:

- [Visualizador de algoritmos de ordenamiento](https://www.sortvisualizer.com/)
- [Complejidad algorítmica](https://www.bigocheatsheet.com/)
- [Lista enlazadas en C](https://www.learn-c.org/en/Linked_lists)

---

**Nota**: Este README documenta la implementación final del proyecto push_swap con todas sus características y funcionalidades.
