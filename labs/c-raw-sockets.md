---
layout: default
course_number: CS330
title: "Programming Assignment: Ping and Traceroute using C raw sockets"
---

### Background
  - ICMP is used by hosts and routers to communicate network-layer information to each other. The most typical use of ICMP is to send error messages and operational information indicating, for example, that a requested service is not available or that a host or router could not be reached.
  - ICMP differs from transport protocols such as TCP and UDP in that it is not typically used to exchange data between systems, nor is it regularly employed by end-user network applications (except for some diagnostic tools like *ping* and *traceroute*).
 - ICMP is often considered part of IP but architecturally it lies just above IP, as ICMP messages are carried inside IP datagrams – meaning ICMP messages are carried as IP payload, just as TCP or UDP segments are carried as IP payload.


### Objective
  - The goal of this lab is to become familiar with low-level network programming by implementing two of the most popular network utilities: _ping_ and _traceroute_. These utilities are essential tools used for network diagnostics and troubleshooting, and this assignment will provide you hands-on experience working with raw sockets in C.
  - Since this assignment requires raw socket manipulation, you must run your program with root privileges.
  - All code must be well-documented. You will lose points if it is not documented properly. Add comments to explain the functionality of each function, variable, and important code block.


### Ping
  - Your ping program should send 10 ICMP Echo Request messages to a target server. The target server's IP address or hostname should be provided as input to your program.
  - For each sent ping message, the client must:
    - Wait for the corresponding ICMP Echo Reply.
    - Calculate and display the Round-Trip Time (RTT) for each received reply, in milliseconds.
  - Handling Packet Loss:
    - Since the network may be unreliable, packets sent by either the client or the server may be lost.
    - Your program should not wait indefinitely for a response to a ping message. Instead, it should set a timeout of 2 seconds for each reply. If a reply is not received within this time frame, the client should assume the packet was lost.
    - In case of packet loss, the program should print a message indicating that the request timed out or the packet was lost.

### Traceroute
  - Extend your *ping* program to create a *traceroute* program.
  - How Traceroute Works:
    - Traceroute operates by sending packets to the destination host, starting with a Time-to-Live (TTL) value of 1 and incrementing the TTL by 1 after each hop, until the destination host responds.
  - Router Behavior:
    - When the n<sup>th</sup> datagram reaches the n<sup>th</sup> router, the router observes that the TTL has expired. 
    - According to the IP protocol, the router discards the packet and sends an ICMP Time Exceeded message (type 11, code 0) back to the source.
    - This ICMP Time Exceeded message contains the IP address and, in some cases, the name of the router that sent the message.
  - Retrieving Information:
    - When the ICMP message reaches the source, the program calculates the round-trip time (RTT) using the timestamp.
    - The program also extracts the IP address and, if available, the hostname of the router from the ICMP message.
  - Stopping Criteria:
    - The traceroute process continues incrementally increasing the TTL until it receives an ICMP message with type 0 (Echo Reply) and code 0.
    - This indicates that the destination host has been reached, and no further probe packets need to be sent.

### Code snippets
  - [checksum.c](files/checksum.c)
  - [get_host.c](files/get_host.c)

### References
  - [RFC 792](http://tools.ietf.org/html/rfc792)
  - [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/html/)
  - [Linux socket interface](https://linux.die.net/man/2/socket). Don't forget to use SOCK_RAW type.
  - [Sends a message to a host](https://linux.die.net/man/3/sendto)
  - [Receive a message from a socket](https://linux.die.net/man/3/recvfrom)
  - Get the IPv4 address corresponding to a given Internet host name: [gethostbyname](https://www.man7.org/linux/man-pages/man3/gethostbyname.3.html)
  - Convert a socket address to a corresponding host: [getnameinfo](https://www.man7.org/linux/man-pages/man3/getnameinfo.3.html)
  - Set Socket Options: [setsockopt](https://linux.die.net/man/3/setsockopt) and [ip](https://www.man7.org/linux/man-pages/man7/ip.7.html)
    - Example of setting TTL (time to live): ```setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(int))```

### Extra Credit
  - In addition to displaying the Round-Trip Time (RTT) for each individual ping, your program should also compute and display the following statistics at the end of the test:
    - Minimum RTT: The shortest round-trip time recorded.
    - Maximum RTT: The longest round-trip time recorded.
    - Average RTT: The average round-trip time for all successful ping replies.
  - Packet Loss Calculation:
    - Your program should calculate and display the packet loss rate. This is determined by comparing the number of successful replies to the total number of packets sent. The packet loss rate should be displayed as a percentage
  - Ping Rate:
    - The standard ping utility sends one ping request per second. Modify your program to mimic this behavior by introducing a delay of 1 second between each ping request.
    - Important: Do **not** send a new ping immediately after receiving a reply; instead, maintain a fixed 1-second interval between sending each request, just like the standard ping command.

### Testing
  - Wireshark will be your friend.

### Grading
Post your report including source in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.
