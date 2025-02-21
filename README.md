**UART Data Transfer with Flash Storage on STM32**
This project demonstrates UART-based data communication between a PC and an STM32 microcontroller. The application receives data from the PC via UART, stores it in the flash memory of the STM32, and then sends the data back to the PC. The system also displays the real-time data transmission speed in bits per second (bps) for both RX (Reception) and TX (Transmission).

**Features**
**UART Communication:** Reliable data transfer between PC and STM32.
**Flash Memory Storage:** Stores received data in STM32's internal flash.
**Data Echo:** Reads stored data from flash and sends it back to the PC.
**Real-Time Data Rate Monitoring:** Displays live transmission speeds (bps) for RX and TX.
**Non-Interrupt UART Reception:** Ensures continuous data flow.

**Project Structure**

├── Core
│   ├── Src
│   │   ├── main.c         # Main application code
│   │   └── stm32xxxx_it.c # Interrupt Service Routines
|   |   └── flash_store_data.c # Code for Erase and Sector identification
│   └── Inc
│       └── main.h         # Header file with definitions and prototypes
|       └──flash_store_data.h
├── PC_Side
│   └── UART_TX_Application.py # Python script for PC-side UART communication
└── README.md
**Hardware Requirements**
STM32 Microcontroller (Tested on STM32F7 series)
PC with Python 3.x installed
**Software Requirements**
STM32CubeIDE: For compiling and flashing the firmware.
Python 3.x: For running the UART transmission script on the PC.
pyserial: Python library for serial communication.

**Author**
- Solomon Selva
- Embedded Systems Engineer
- For job interview assignment
