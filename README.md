# Socket_Programming_Assignment


---


Group Members

* Jason Zhu (Student ID: 702734977)


---


List of Relevant Files

* server.c: Source code for the TCP server. Sets up the listening socket, reads the requested file,
output file information.

* client.c: Source code for the TCP client. Prompts the user for a filename, establishes a TCP connection,
writes output to out.txt file, and tracks final statistics.

* Makefile: Script for compiling program.

* README.md: Documentation File


---


Compilation Instructions

To compile the programs on Linux system or macOS terminal,

1) run make

2) run ./server

3) create a test file

4) open a new terminal and run ./client

5) input test file when prompted by client

6) make clean to remove server, client, and out.txt
