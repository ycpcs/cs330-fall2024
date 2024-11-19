---
layout: default
course_number: CS330
title: "Exam 3 - Study Guide"
---

Exam 3 - Nov 21, 2024
-----------------------

### Study Guide:

#### Network Layer
- Intra-AS vs. Inter-AS Routing:
  - Understand the difference between Intra-AS (Interior Gateway Protocols - IGP) and Inter-AS (Exterior Gateway Protocols).
  - Why are both types of routing needed in a network? (Intra-AS is for routing within a single Autonomous System, while Inter-AS is for routing between different ASes).
- Traceroute and ICMP:
  - Know how Traceroute works and how it uses ICMP (Internet Control Message Protocol) to find the path from one host to another.
  - Be able to explain the purpose and function of each step in the Traceroute process.
- Routing Forwarding Table:
  - Understand how to build a routing table based on routing information, including the key components like destination address, next-hop, and metric.
- Routing Algorithms:
  - Link-State Algorithm (Dijkstra's Algorithm):
    - Know the key steps of Dijkstra's algorithm and how it is used to find the shortest path in a network.
    - Understand the concept of a Link-State Database (LSDB) and how routers share information using Link-State Advertisements (LSAs).
  - Distance Vector Algorithm (Bellman-Ford Algorithm):
    - Understand how the Bellman-Ford algorithm works and the concept of distance vectors.
    - Be familiar with the algorithm's convergence properties and its limitations (e.g., count-to-infinity problem).
- Resources
  - [Dijkstra's Algorithm](..\schedule\slides\dijkstra_algorithm.pdf)
  - [CS360: Bellman-Ford Algorithm](https://ycpcs.github.io/cs360-spring2019/lectures/lecture21.html)
  - [CS360: Dijkstra's Algorithm](https://ycpcs.github.io/cs360-spring2019/lectures/lecture22.html)

#### Link Layer
- Services Provided by the Data Link Layer:
  - Be able to list and explain the main services that the Data Link Layer provides, such as error detection, error correction, framing, and medium access control.
- Multiple Access Protocols:
  - Understand the characteristics of an ideal Multiple Access Protocol (efficiency, fairness, collision avoidance).
  - Be able to explain different multiple access techniques such as ALOHA, CSMA/CD, and CSMA/CA.
- Error Detection and Correction:
  - Parity Checking:
    - Know how even and odd parity work for error detection.
  - Internet Checksums:
    - Understand how checksums are used for error detection in the internet layer (e.g., in TCP/UDP headers).
- Random Access Protocols and Collisions:
  - Be familiar with how Random Access Protocols (like CSMA/CD) handle collisions, including collision detection and backoff mechanisms.
- Address Resolution Protocol (ARP):
  - Know how ARP works to map IP addresses to MAC addresses. Be able to describe how a host can determine the MAC address of a destination machine when it only knows the destination's IP address.
- Ethernet Switches:
  - Understand the role of Ethernet switches in a network.
  - Know the differences between switches and routers (e.g., switches operate at Layer 2, while routers operate at Layer 3).
  - Understand how switches forward frames based on MAC addresses.
- Switch Tables:
  - Be able to explain how switch tables (also known as MAC address tables) are built and used to forward frames in a switched Ethernet network.
- Switched vs. Bus-based Ethernet:
  - Know the differences between switched Ethernet (using a switch to forward data) and bus-based Ethernet (using a shared medium where all devices can hear traffic).

Exam Guidelines
---------------
- __Format:__ Exams will be open-book and closed-notes.
- __Duration:__ Each exam will last approximately 60 minutes and will take place at the beginning of the class period.
- __Content:__ Exams may include a programming component, as well as practical exercises using Wireshark for network analysis. The latter half of the class may be dedicated to instruction and/or laboratory work.
- __Number of Exams:__ A total of four exams will be administered, with the lowest score being dropped.
- __Make-Up Exams:__ Make-up exams will only be granted with prior approval from the instructor, except in cases of extreme emergency or illness, which must be documented.
