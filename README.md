# so_long

<p align="center">
  <img src="https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42&logoColor=white" alt="42 School"/>
  <img src="https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c" alt="Language C"/>
  <img src="https://img.shields.io/badge/Graphics-MiniLibX-green?style=flat-square" alt="MiniLibX"/>
</p>

## 📋 Descripción

**so_long** es un proyecto que consiste en crear un pequeño juego 2D donde el jugador debe recolectar todos los objetos del mapa y encontrar la salida, evitando obstáculos. El proyecto introduce conceptos fundamentales de programación gráfica, gestión de eventos y texturas.

El objetivo principal es aprender a trabajar con la librería gráfica MiniLibX, manejar eventos del teclado y ventanas, y gestionar la memoria de manera eficiente.

<p align="center">
  <img src="dem.gif" alt="so_long gameplay" width="600"/>
</p>

## 🎮 Características

- **Renderizado 2D**: Uso de sprites y texturas en formato `.xpm`
- **Movimiento del jugador**: Control mediante teclas WASD o flechas
- **Sistema de coleccionables**: El jugador debe recoger todos los items antes de poder salir
- **Contador de movimientos**: Muestra el número de pasos realizados
- **Validación de mapas**: Verifica que el mapa sea válido antes de iniciar el juego
- **Gestión de memoria**: Implementación sin memory leaks

## 🛠️ Requisitos

- **Sistema operativo**: Linux o macOS
- **Compilador**: cc, gcc o clang
- **MiniLibX**: Librería gráfica (incluida en el proyecto o instalada en el sistema)
- **Make**: Para compilar el proyecto

### Instalación de dependencias (Linux)

```bash
sudo apt update
sudo apt install gcc make xorg libxext-dev libbsd-dev
```

## 📦 Instalación

1. Clona el repositorio:
```bash
git clone https://github.com/dajose-p/so_long.git
cd so_long
```

2. Compila el proyecto:
```bash
make
```

3. Ejecuta el juego:
```bash
./so_long <mapa válido>
```

## 🎯 Uso

### Controles

- **W / ↑**: Mover arriba
- **A / ←**: Mover izquierda
- **S / ↓**: Mover abajo
- **D / →**: Mover derecha
- **ESC**: Salir del juego

### Formato del mapa

Los mapas deben tener extensión `.ber` y seguir estas reglas:

- **1**: Muro
- **0**: Espacio vacío
- **P**: Posición inicial del jugador (solo uno)
- **C**: Coleccionable (mínimo uno)
- **E**: Salida (solo una)

#### Ejemplo de mapa válido:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

### Reglas del mapa

- El mapa debe estar rodeado por muros (1)
- Debe contener exactamente un jugador (P) y una salida (E)
- Debe tener al menos un coleccionable (C)
- Debe existir un camino válido entre el jugador, los coleccionables y la salida
- Todas las líneas deben tener la misma longitud

## 🔧 Comandos del Makefile

- `make`: Compila el proyecto
- `make clean`: Elimina archivos objeto
- `make fclean`: Elimina archivos objeto y ejecutable
- `make re`: Recompila todo el proyecto
- `make play`: Jugar a diferentes mapas como si fuesen niveles

## 🎨 Texturas

Las texturas utilizadas son archivos `.xpm` que representan:

- **Muros**: Bloques que delimitan el mapa
- **Suelo**: Espacio por donde puede caminar el jugador
- **Jugador**: Sprite del personaje
- **Coleccionables**: Items que el jugador debe recoger
- **Salida**: Puerta o portal de salida

## ✅ Validaciones implementadas

- [x] Verificación de extensión `.ber`
- [x] Mapa rectangular
- [x] Mapa rodeado de muros
- [x] Camino válido (flood fill algorithm)
- [x] Número correcto de jugadores, salidas y coleccionables
- [x] Caracteres válidos en el mapa
- [x] Gestión de memoria sin leaks

## 🐛 Manejo de errores

El programa maneja los siguientes errores:

- Archivo de mapa no encontrado
- Formato de mapa inválido
- Mapa no rectangular
- Mapa sin cerrar con muros
- Número incorrecto de elementos (P, E, C)
- No existe camino válido
- Errores de asignación de memoria

## 📝 Notas de implementación

- El proyecto utiliza funciones custom de libft como `ft_calloc`, `ft_strdup`, `get_next_line`
- La gestión de memoria es crítica: todas las asignaciones deben ser liberadas correctamente
- Es importante cerrar la ventana correctamente para evitar leaks de la MiniLibX
- El algoritmo de flood fill valida que todos los coleccionables y la salida sean alcanzables

## 👤 Autor

Tu nombre - [@dajose-p](https://github.com/dajose-p)
