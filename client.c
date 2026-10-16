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
	int client_socket;
	struct sockaddr_in address;
	char filename[MAX_DATA_SIZE];
	
	// Prompting user for filename
	printf("Enter filename: ");
	if(scanf("%79s", filename) != 1){
		fprintf(stderr, "Invalid input: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	size_t filename_len = strlen(filename);

	

	return 0;
}
