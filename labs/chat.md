---
layout: default
course_number: CS330
title: "Programming Assignment: Chat Application using C sockets"
---

### Background
  Chat applications have become an integral part of modern communication, enabling users to interact in real time over the internet. From simple text-based messaging to sophisticated multimedia sharing, chat applications serve various purposes, including personal communication, professional collaboration, and social networking.

### Objective
  The goal of this assignment is to implement a simple chat application using socket programming in C. You will create both a server that listens for incoming connections and a client that connects to the server to send and receive messages. This will help you understand socket programming, multi-threading, and basic client-server architecture.

### Server Implementation 
 - Socket Creation: Implement a TCP server that creates a socket and binds it to a specified port (e.g., 8080).
 - Listening for Connections: The server should listen for incoming client connections.
 - The server should handle multiple clients concurrently.
 - Message Handling:
    - Receive messages from clients.
    - Broadcast the received messages back to all clients.
    - Print received messages to the server console.
  - Robustness: Implement a way to gracefully handle shutting down clients (e.g., using Ctrl+C).

### Client Implementation
  - Socket Creation: Implement a client that creates a socket and connects to the server.
  - User Input: The client should accept user input from the console.
  - Message Sending: Send messages to the server.
  - Receive Messages: Receive echoed messages from the server and display them in the client console.
  - Extra Credit: Allow the user to exit the chat by typing a specific command (e.g., "Escape").

### Technical Specifications
 - Programming Language: C
 - Compilation: Provide clear instructions on how to compile and run both the server and client.

### Simple Testing 
 - Start the Server:
   - Compile and run the server code.
   - The server should output a message indicating it is listening for connections.
 - Start Multiple Clients:
   - Compile and run the client code multiple times in different terminal windows.
   - Each client should connect to the server and allow the user to start typing messages.
   - Messages should be echoed back from the server and displayed on each client.
  
### Grading Criteria
 - Functionality (60%):
   - Server accepts and handles multiple clients concurrently.
   - Messages are correctly received and broadcasted to all connected clients.
 - Code Quality (20%):
   - Clear and organized code structure.
   - Proper use of comments and meaningful variable names.
   - Error handling is implemented for socket operations.
 - Documentation (20%):
   - Clear instructions on how to compile and run the application.
   - A README file that describes the application and its functionality.
  
### Grading
Post your report including source in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.
