import serial
import serial.tools.list_ports
import time

def list_serial_ports():
    ports = serial.tools.list_ports.comports()
    available_ports = []
    for port in ports:
        available_ports.append(port.device)
    return available_ports


def main():
    print("=== UART String Sender ===")
    
    # List available COM Ports
    ports = list_serial_ports()
    if not ports:
        print("No COM ports found! Please check your connection.")
        return
    
    print("Available COM Ports:")
    for i, port in enumerate(ports):
        print(f"{i + 1}: {port}")

    # Select COM Port
    port_index = int(input("Select COM Port (Enter number): ")) - 1
    com_port = ports[port_index]

    # UART Settings (Match with STM32 settings)
    baud_rate = 2400   # Set to 2400 as per requirement
    data_bits = serial.EIGHTBITS
    parity = serial.PARITY_NONE
    stop_bits = serial.STOPBITS_ONE

    # Open Serial Port
    try:
        ser = serial.Serial(
            port=com_port,
            baudrate=baud_rate,
            bytesize=data_bits,
            parity=parity,
            stopbits=stop_bits,
            timeout=1
        )
        print(f"Connected to {com_port} at {baud_rate} baud.\n")
    except serial.SerialException:
        print("Failed to connect to the serial port.")
        return

    # Sending Loop
    try:
         # Get User Input
         # Read from text file 
         with open('input.txt', 'r') as file:
             user_input = file.read()
            
         # Send String
         data_to_send = user_input + '\r' # Append carriage return
         #send_data_in_chunks(data_to_send)  # Send data in chunks
         ser.write(data_to_send.encode())
         print("Sent:", repr(data_to_send))  # to show the delimiter

         print("\n\n Waiting for data from STM32...\n ")

         # Receive data from STM32
         # Collect data in chunks
         received_data = b""
         while True:
             chunk = ser.read(100)  # Read in 100-byte chunks
             if not chunk:
                 break
             received_data += chunk

         # Display the complete received data
         print("Received Data:", received_data.decode())
    except KeyboardInterrupt:
        print("\nInterrupted! Exiting...")
    finally:
        ser.close()
        print("\n \n Serial port closed.")

if __name__ == "__main__":
    main()
