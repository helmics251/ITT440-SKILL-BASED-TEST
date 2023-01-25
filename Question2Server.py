import socket

def convert_to_celsius(fahren):
    cels = (fahren - 32) * 5 / 9
    return cels

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('', 8080))
    server_socket.listen(1)

    print("Server is listening for incoming connections...")

    while True:
        conn, addr = server_socket.accept()
        print(f"Connected by {addr}")
        while True:
            data = conn.recv(1024)
            if not data:
                break
            fahren = float(data.decode())
            cels = convert_to_celsius(fahren)
            conn.send(str(cels).encode())
        conn.close()

if __name__ == '__main__':
    main()
