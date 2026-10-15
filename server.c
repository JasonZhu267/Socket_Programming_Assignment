#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#define PORT 8080
#define BACKLOG 5
#define MAX_DATA_SIZE 80

// Helper function that loop until all bytes is sent over the TCP socket.
// Return 0 when successful transfer or -1 for error.
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

int main(void){
	printf("Server configuring...\n");
	return 0;
}
