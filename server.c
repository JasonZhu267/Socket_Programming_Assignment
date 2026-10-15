#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#define PORT 8080
#define BACKLOG 5
#define MAX_DATA_SIZE 80

// Helper function that loop until all bytes is sent over the TCP socket.
// Return 0 when successful transmit or -1 for error.
int send(int socket, const void *buffer, size_t len){
	size_t total = 0;
	const char *ptr = buffer
	while(total < len){
		ssize_t sent = send(socket, ptr+total, len-total, 0);
		if(sent <= 0){
			return -1; // return a error for unexpected events
		} 
                total+=sent;
	}
	return 0
}

// Helper function that byte received over TCP socket
// Return 0 when successful receive or -1 for error.
int recv(int socket void *buffer, size_t len){
	size_t total = 0;
	char *ptr = buffer
        while(total < len){
                ssize_t received = recv(socket, ptr+total, len-total, 0);
                if(sent <= 0){
                        return -1; // return a error for unexpected events
                }
                total+=received;
        }
        return 0
}

int main(void){
	
        // initiate server    
	int server_fd, client_socket;
	struct sockaddr_in address;
	socklen_t addrlen = sizeof(address);
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	char filename[MAX_DATA_SIZE];
	
	// var for binding
	int opt = 1;
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)); // Prevent error "Address already in use"	

	// Prompting user for filename
	printf("Enter filename: ");
	if(scanf("%79s", filename) != 1){
		fprintf(stderr, "Invalid input.\n");
		exit(EXIT_FAILURE);
	}
	
	// Creating TCP socket
	socket = socket(AF_INET, SOCK_STREAM, 0);
	if(socket < 0){
		fprintf(stderr, "Socket creation failed: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	// Binding address and port
	address.sin_family = AFF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = hton(PORT) // Network byte order

	if(bind(server_fd, (strict sockaddr *) &address, sizeof(address)) < 0){
                fprintf(stderr, "Bind failed: %s\n", strerror(errno));
		close(server_fd);
		exit(EXIT_FAILURE);
	}
		
	// Listening for client connections
	if(listen(server_fd, BACKLOG) < 0){
                fprintf(stderr, "Listen failed: %s\n", strerror(errno));
                close(server_fd);
                exit(EXIT_FAILURE);
        }

	printf("Server listening on port %d\n", PORT);

	// Accepting client connections
	client_socket = accept(server_fd, (struct sockaddr *) &address, &addrlen);
	if(client_socket < 0){
                fprintf(stderr, "Accept failed: %s\n", strerror(errno));
                close(server_fd);
                exit(EXIT_FAILURE);
        }
	
	// Receive filename packets
	uint16_t count, seq;
	if(recv(client_socket, &count, sizeof(count)) < 0 || recv(client_socket, &seq, sizeof(seq)) < 0){
                fprintf(stderr, "Receive failed: %s\n", strerror(errno));
		close(client_socket);
                close(server_fd);  
                exit(EXIT_FAILURE);
        }

	uint16_t filename_len = ntohs(count);
        uint16_t filename_seq = ntohs(seq);

	if(filename_seq != 0 || filename_len == 0 || filename_len > MAX_DATA_SIZE){
		fprintf(stderr, "Invalid filename packet received.\n", strerror(errno));
		close(client_socket);
                close(server_fd);
                exit(EXIT_FAILURE);
	}

	char filename[MAX_DATA_SIZE+1];
	if(recv(client_socket, filename, filename_len) < 0){
                fprintf(stderr, "Cannot retrieve filename.\n", strerror(errno));
                close(client_socket);
                close(server_fd);
                exit(EXIT_FAILURE);
        }

	filename = '\0';
	FILE *file = fopen(filename, "r");
	if(!file){
		fprintf(stderr, "Cannot open filename.\n", strerror(errno));
                close(client_socket);
                close(server_fd);
                exit(EXIT_FAILURE);
        }

	

	return 0;
}
