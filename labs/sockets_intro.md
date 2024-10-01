---
layout: default
course_number: CS330
title: "Programming Lab - Introduction to Sockets"
---

# Programming Lab - Introduction to Sockets

### Download and compile _individually_ the following files:
  - [tcp_client.c](files/tcp_client.c)
  - [udp_client.c](files/udp_client.c)
  - [tcp_server.c](files/tcp_server.c)
  - [udp_server.c](files/udp_server.c)

#### Example:
  - Compile with: ```gcc tcp_client.c -o tcp_client``` 
    - Note the name after ```-o``` flag 
  - Run with: ```./tcp_client```

### We use the following simple client/server applications do demonstrate UDP and TCP socket programming.
  - The client reads a line from its standard input and sends it to the server via its socket.
  - The server receives the line through its socket and processes it.
  - The server converts the line to uppercase.
  - The server sends the modified line back to the client through its socket.
  - The client receives the modified line via its socket and prints it to the standard output.
  
To ensure proper execution of each exercise, please remember to __stop and recompile both the server and client before running__. This helps to clear any previous configurations and ensures a clean environment for accurate results.

### Please respond to the following questions:
  - Suppose you run `tcp_client` before you run `tcp_server`. Enter a value.
    - What happens?
    - Why?
  - Suppose you run `udp_client` before you run `udp_server`. Enter a value.
    - What happens?
    - Why?
  - What occurs if different port numbers are used for the UDP client and UDP server? Please ensure that both programs are running before providing your response. 
  - What occurs if different port numbers are used for the TCP client and TCP server? Please ensure that both programs are running before providing your response. 
  - UDP Test Instructions
    - Start the `udp_server`.
    - Launch the `udp_client` and send a message to the server.
    - While the `udp_server` is still running, rerun the `udp_client` again, but this time send a shorter message.
      - What happens?
      - Why?
      - Fix it. Make sure to include your code fix as part of your submission. 
    - Modify the _send_msg_ function in `udp_client` to allocate 5 bytes instead of 50.
    - Restart both the `udp_server` and the updated `udp_client`. Don’t forget to recompile the `udp_client` before restarting!
    - Use the `udp_client` to send a message that exceeds 5 bytes in length.
      - What happens?
      - Why?
    - Revert your changes in `udp_client` and modify the allocation size of _recv_msg_ to 5. After making this adjustment, rerun the `udp_client` and send a message that exceeds 5 bytes in length.
      - What outcomes do you anticipate from this change?
      - What was the actual outcome? 
      - Why?

### Programming Section: 
  - Update `tcp_client`, `udp_client`, `tcp_server` and `udp_server` to accept the **client and server** port numbers as _user_ input.
  - Modify `tcp_client` and `udp_client` to accept the **server** IP Address as _user_ input.
  - Implement functionality that allows both clients to continuously send messages until a QUIT command is entered.
 
### Extra Credit:
  - Enhance the `tcp_server` to support multiple clients.
  - Feel free to experiment with the code and surprise me! Don't hesitate to explore and push boundaries—breaking things can lead to valuable learning experiences. Embrace the process!

### References
  - [Linux socket interface](https://linux.die.net/man/7/socket)
  - [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/html/)
  - [Debugging with GDB](https://ftp.gnu.org/old-gnu/Manuals/gdb/html_node/gdb_toc.html)

### Testing
  - [Netcat](http://netcat.sourceforge.net/) is a command line tool that connects to an arbitrary TCP or UDP port and allows you to send and receive data.
  - To see what TCP ports are in use: ```netstat -antop```, for UDP: ```netstat -anoup```
  - To kill a process: ```kill PID``` or ```pkill PATTERN```

### Grading
Post your report __including source__ in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.
