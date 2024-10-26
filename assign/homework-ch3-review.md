---
layout: default
course_number: CS330
title: "Homework: Chapter 3"
---

## Chapter 3 Homework (50 pts)

### Problem 1 (8 pts)
What is the purpose of the length field in the UDP header, and why is it important for data transmission?
<code>
Indicates Total Length - which includes both the UDP header and the UDP payload (data). The payload can be of variable length, and this lets UDP know where the segment ends.
</code>

### Problem 2 (8 pts)
Which set of bytes is used to compute the checksum field in the UDP header, and how does this process work?
<code>
The entire UDP segment, except the checksum field itself, and the IP sender and receive address fields.
</code>

### Problem 3 (9 pts)
How does a cumulative acknowledgment, ACK(n), function in networking, and what does it signify?
<code>
A cumulative _ACK(n)_ acks all packets with a sequence number up to and including _n_ as being received.
</code>

### Problem 4 (10 pts)
True or False: When multiple TCP clients send segments to the same destination port at a receiving host, those segments from different senders will always be directed to the same socket at the receiving host. Does the same principle apply to UDP as well?
<br/>
<code>
TCP - False
UDP - True
</code>

### Problem 5 (5 pts)
True or False: It is possible for two UDP segments to be sent from the same socket with source port 1234 at a server to two different clients. 
<br/>
<code>
True
</code>

### Problem 6 (5 pts)
True or false: It is possible for two TCP segments with source port 8080 to be sent by the server to different clients.
<br/>
<code>
True
</code>

### Problem 7 (5 pts)
How does a networked application on a server determine the client's IP address and port number to use when replying to a received datagram?
<br/>
<code>
**UDP**: The client's IP address and port are included in the UDP header, which is accessible at the time the datagram is received.
**TCP**: When the server calls _accept()_, it retrieves the client's details from the underlying transport layer. The information is derived from the TCP segment header, which includes the source IP address and port number of the client.
</code>

### Submit

Post your solutions in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.


