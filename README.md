# TCP-Communication
This repository contains a simple example of client-server communication using the TCP protocol in C.

Contents
Introduction
Usage
Compilation
Contributing
License
Introduction
This code demonstrates a basic implementation of a TCP server and client that can send and receive messages over a network connection. The server listens for incoming connections and echoes back any messages it receives from clients.

Usage
Compile the Code:

You need to compile the server and client before running them. Open a terminal or command prompt, navigate to the directory containing the code, and compile as follows:

bash
Copy code
# Compile the server
gcc server.c -o server

# Compile the client
gcc client.c -o client
Run the Server:

In one terminal window, navigate to the directory where you compiled the server and run it with:

bash
Copy code
./server
The server will start and listen for incoming connections.

Run the Client:

In another terminal window, navigate to the directory where you compiled the client and run it with:

bash
Copy code
./client
The client will connect to the server, and you can interact with it. Follow the prompts to send and receive messages. Type "exit" in the client to quit the client and press Ctrl+C in the server's terminal window to quit the server.

Compilation
The code can be compiled using the GNU C Compiler (GCC). Make sure you have GCC installed on your system.

To compile the server:

bash
Copy code
gcc server.c -o server
To compile the client:

bash
Copy code
gcc client.c -o client
Contributing
If you want to contribute to this project, feel free to fork the repository and open a pull request with your changes.

License
This project is open-source and is distributed under the MIT License. See the LICENSE file for details.

You can include additional information or details as needed, but this README provides a basic structure for anyone who wants to understand, compile, and use your client-server code.
