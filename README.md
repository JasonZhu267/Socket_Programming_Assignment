# Socket_Programming_Assignment


---


Group Members

* Jason Zhu (Student ID: 702734977)


---


List of Relevant Files

* server.c: Source code for the TCP server. Sets up the listening socket, reads the requested file,formats application-layer packets using network byte order, and streams data/EOT packets to the client.

* client.c: Source code for the TCP client. Prompts the user for a filename, establishes a TCP connection, sends sequence 0 packet, receives data packets,writes output to out.txt file, and tracks final statistics.

* Makefile: Script for compiling program.

* README.md: Documentation File


---


Configuration Information

* The server port (8080) is defined using the macro PORT at the top of both server.c and client.c

* The server IP address (127.0.0.1) is defined using the macro SERVER_IP at the top of client.c


___


Compilation Instructions


To compile the programs on Linux system or macOS terminal, run make.


---


Running Instruction

1) create a test file

2) run ./server

3) open a new terminal and run ./client  

4) input test file when prompted by client

5) run make clean to remove server, client, and out.txt
