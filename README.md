
# Client-Server Chat Application

## Overview
In today's fast-paced digital world, instant communication is a fundamental aspect of our daily lives. This project introduces a client-server chat system developed in C, enabling multiple users to connect to a central server and engage in text-based conversations. The system prioritizes message security using a basic Caesar cipher encryption technique.

## Components
- **Server**: Listens on a designated port and manages multiple client connections using a multithreaded approach. Each client connection is handled by a unique thread, allowing for concurrent interactions.
- **Client**: Connects to the server, allows users to create a personalized username, send and receive messages, engage in private conversations, request chat history, and measure Round-Trip Time (RTT) for network performance.

## Architecture
![Architecture Diagram](https://d3i71xaburhd42.cloudfront.net/e610e082f875a5d76dd72adc1e6a47a58fd5ceeb/500px/3-Figure4-1.png)

## Features
- **Real-time Chat**: Multiple clients can interact with each other in real-time.
- **Basic Encryption**: Messages are encrypted and decrypted using the Caesar cipher for added security.
- **Private Messaging**: Users can send messages to specific individuals.
- **Chat History**: Users can request and view the chat history.
- **RTT Measurement**: Measures the Round-Trip Time for messages to gauge network performance.

## Installation
1. **Clone the Repository**:
```bash
git clone https://github.com/adi-305/CN_Project.git
```

2. **Compile the Code:**:
```bash
gcc server.c -o server -lpthread
gcc client.c -o client -lpthread
```

## Usage

1. **Start the Server**:
```bash
./server
```

2. **Start the Client**:
```bash
./client
```

