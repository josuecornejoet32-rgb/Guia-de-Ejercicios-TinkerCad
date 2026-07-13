# Proyecto Informático
Nombre: Josue Cornejo
Profesor: Gonzalo Consorti
Curso: 4-2
Correo: josue.cornejoet32@gmail.com

Consigna:
Implementar un sistema para controlar un ventilador y una lámpara en una habitación, usando:
Un sensor de temperatura para medir la temperatura ambiente.
Un sensor de movimiento (PIR) para detectar si hay alguien en la habitación.
Controlar un ventilador (simulado con un Motor DC gris) de 12V con velocidad variable (dimmer) dependiendo de la temperatura, 
y una lámpara 12V que se encienda solo cuando hay personas.
  Temperatura mayor a 50°C  
Ventilador a máxima velocidad si importar si hay o no gente dentro
 Temperatura menor a 50°C  
el ventilador esta apagado

Si hay movimiento (persona detectada) y temperatura menor a 50°C  
Ventilador se enciende con velocidad proporcional a temperatura en rangos:
Lámpara encendida mientras tengamos persona dentro
≤15°C → velocidad mínima PWM = 50
= 30°C → PWM = 150
>= 50°C → PWM = 255 (máximo)
Si no hay persona (sin movimiento) 
lámpara apagada
