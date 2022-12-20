import threading
import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# We assign a name to the socket with a specific adress and port,
# allowing it to receive incoming connections or send data to a specific adress
# as the intermediate server between person a and b.

addr = "127.0.0.1"
port = 8080

server.bind((addr, port))
server.listen()

clients = []
aliases = [] # Nicknames

# With the broadcast function, we simply iterate through all the list of clients
# and for each client we send the message. As simple as bananas.
def broadcast(message):
    for client in clients:
        client.send(message)

def handle_client(client):
    while True:
        try:
            message = client.recv(1024) # 1024 is the maximum number of bytes the server can receive
            broadcast(message)
        except:
            # If the handling fails, we need to get rid of the client.
            index = clients.index(client)
            clients.remove(client)
            client.close()
            alias = aliases[index]
            broadcast("{} has left the chat room.".format(alias).encode("utf-8")) # We need to send as bytes
            aliases.remove(alias)
            break

def receive():
    while True:
        print("Server is running...")

        client, address = server.accept()

        print("Connected to {}".format(str(address)))

        client.send("alias?".encode("utf-8"))
        alias = client.recv(1024)

        aliases.append(alias)
        clients.append(client)

        print("The alias of this client is {}".format(alias).encode("utf-8"))

        broadcast("{} has joined the chat room.".format(alias).encode("utf-8"))

        client.send("You are now connected".encode("utf-8"))

        # Now we need to create the thread to separate the tasks in
        # order to get asynchronism in our functions.
        thread = threading.Thread(target = handle_client, args = (client,))
        thread.start()

if __name__ == "__main__":
    receive()
