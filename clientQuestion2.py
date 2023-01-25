import socket

def main():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('192.168.191.128', 1234))

    fahrenheit = float(input("Enter temperature in Fahrenheit: "))
    client_socket.send(str(fahrenheit).encode())

    celsius = client_socket.recv(1024).decode()
    print(f"Temperature in Celsius: {celsius}")

    client_socket.close()

if __name__ == '__main__':
    main()
