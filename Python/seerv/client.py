import threading 
import socket

alias = input("Choose your nickname: ")
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Instead of binding to a host, we're going to connect our client.
client.connect(('0.0.0.0', 8080))

def client_receive():
    while True:
        try:
            message = client.recv(1024).decode("utf-8") # Now we decode because we're receiving
            if message == "alias?":
                client.send(alias.encode("utf-8"))
            else:
                print(message)
        except:
            print("ERROR: Unexpected behavior")
            client.close()
            break
      
def client_send():
    while True:
        message = '{}: {}'.format(alias, input(""))
        client.send(message.encode("utf-8"))

receive_thread = threading.Thread(target = client_receive)
receive_thread.start()

send_thread = threading.Thread(target = client_send)
send_thread.start()

