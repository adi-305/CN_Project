#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/time.h>

#define PORT 10200

typedef struct Message {
    char username[100];
    char text[1024];
} Message;

// Thread function to receive messages from the server
void *receive_messages(void *arg) {
    int client_socket = *((int *)arg);
    Message msg;

    while (1) {
        int n = recv(client_socket, &msg, sizeof(Message), 0);
        if (n <= 0) {
            printf("Server disconnected. Exiting...\n");
            exit(0);
        }
        printf("%s: %s", msg.username, msg.text);
    }
}

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    pthread_t tid;

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Create a thread to receive messages
    pthread_create(&tid, NULL, receive_messages, &client_socket);

    // Get the username from the user
    char username[100];
    printf("Enter Username: ");
    // fgets(username, sizeof(username), stdin); // Uncomment this line if you want to use fgets
    scanf("%s", username);
    username[strlen(username)] = '\0';

    // Input and send messages to the server
    char message[1024];
    while (1) {
        struct timeval start, end;
        Message newmsg;
        
        // Record start time
        gettimeofday(&start, NULL);

        // Get message from user
        fgets(message, sizeof(message), stdin);

        // Prepare message to send
        strcpy(newmsg.username, username);
        strcpy(newmsg.text, message);

        // Send message to server
        send(client_socket, &newmsg, sizeof(Message), 0);

        // Record end time and calculate RTT
        gettimeofday(&end, NULL);
        long seconds = end.tv_sec - start.tv_sec;
        long microseconds = end.tv_usec - start.tv_usec;
        double elapsed = seconds + microseconds / 1e6;
        printf("RTT for message: %f seconds\n", elapsed);
    }

    return 0;
}
