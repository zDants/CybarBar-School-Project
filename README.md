# CybarBar-School-Project
CyberBar es un sistema automatizado diseñado para la preparación de cócteles y shots utilizando Arduino Uno, motores paso a paso y conectividad Bluetooth. El sistema permite seleccionar recetas desde una aplicación móvil y ejecuta movimientos precisos de desplazamiento y elevación para servir los ingredientes.


 🍸 CyberBar - Bartender Automático 
Proyecto de 5to Electrónica - Control de Mezclas vía Bluetooth

CyberBar es un sistema automatizado diseñado para la preparación de cócteles y shots utilizando **Arduino Uno**, motores paso a paso y conectividad Bluetooth. El sistema permite seleccionar recetas desde una aplicación móvil y ejecuta movimientos precisos de desplazamiento y elevación para servir los ingredientes.

 🚀 Características Técnicas
Microcontrolador:** Arduino Uno R3.
Comunicación:** Módulo Bluetooth HC-05 (Configurado a 38400 baudios).
 Motores: 
     Motor Nema 17 / Paso a paso para desplazamiento horizontal.
     2 Motores paso a paso en paralelo para el sistema de elevación (servido)[.
Drivers: L298N alimentados con fuente externa de 12V.
Estructura de Control: Lógica de "Ida y Vuelta" para asegurar precisión en cada shot.

 📍 Mapa de Posiciones (Pasos)
El sistema utiliza el Jarabe como punto de origen (Home):
Jarabe: 0 pasos.
Jugo de Limón: 533 pasos.
Jugo de Naranja: 1066 pasos.
Jugo de Piña: 1600 pasos.

 📜 Menú de Recetas
El sistema interpreta caracteres enviados vía Serial (Bluetooth) para ejecutar las siguientes recetas:

| Comando | Receta | Composición |
| :--- | :--- | :--- |
| A | Caribean Sun | 1 Piña, 1 Naranja, 1 Limón, 1 Jarabe |
| B | Pineapple Paradise | 2 Piña, 2 Limón |
| C | Refreshing Citrus | 2 Naranja, 1 Limón, 1 Jarabe |
| D | Fizz Tropical | 2 Limón, 2 Jarabe |

 🛠️ Instalación y Uso
1. Sube el código `.ino` al Arduino (Recuerda desconectar el pin RX antes de subir).
2. Conecta la fuente de 12V y asegúrate de compartir el GND con el Arduino.
3. Vincula tu smartphone al módulo.
4. Utiliza una App de Terminal Serial o una App personalizada para enviar las letras A, B, C o D.
