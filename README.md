# AVR-Calculator
By: Ahmad Tohamy
Email: tuhami.10.8@gmail.com

Basic 1-operation calculator using Atmega32 microcontroller
 Generic Drivers used:
  Hard-ware Abstraction Layer :
    -2*16 LCD driver
    -4*4 Keypad driver
  MicroController Abstraction Layer :
    -Digital Input Output driver 
    
Hardware simulated with protues simulation provided to following path:
AVR-Calculator/Proteus Simulation/AVR_calc.pdsprj

'''
Folder Structure :
/assign_calc
  /APP
      main.c
  /HAL
      /LCD
          LCD_config.h
          LCD_interface.h
          LCD_private.h
          LCD_program.c
      /KEYPAD
          KEYPAD_config.h
          KEYPAD_interface.h
          KEYPAD_private.h
          KEYPAD_program.c
  /LIB
      bitmath.h
      stdtypes.h
  /MCAL
      /DIO
          DIO_config.h
          DIO_interface.h
          DIO_private.h
          DIO_program.c
'''
