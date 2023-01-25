import socket

def main():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('192.168.191.128', 8888))

    quote = client_socket.recv(1024).decode()
    print(f"QOTD: {quote}")

    client_socket.close()

if __name__ == '__main__':
    main()
