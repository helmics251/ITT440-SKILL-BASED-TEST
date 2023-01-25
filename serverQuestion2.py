import socket

def convert_to_celsius(fahrenheit):
    celsius = (fahrenheit - 32) * 5 / 9
    return celsius

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('', 1234))
    server_socket.listen(1)

    print("Server is listening for incoming connections...")

    while True:
        conn, addr = server_socket.accept()
        print(f"Connected by {addr}")
        while True:
            data = conn.recv(1024)
            if not data:
                break
            fahrenheit = float(data.decode())
            celsius = convert_to_celsius(fahrenheit)
            conn.send(str(celsius).encode())
        conn.close()

if __name__ == '__main__':
    main()
