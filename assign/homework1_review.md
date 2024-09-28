---
layout: default
course_number: CS330
title: "Homework: Chapter 1 Answers"
---

## Chapter 1 Homework Answers

### Problem 1 (15 pts)
Consider a single router transmitting packets, each of length _L_ bits, over a single link with transmission rate _R_ Mbps to another router at the other end of the link. Suppose that the packet length is _L = 18000 bits_, and that the link transmission rate along the link to router on the right is _R = 800 Mbps_. Round your answer to two decimals after leading zeros.
  - Compute the _one-hop_ transmission delay:
<code>
  L/R = 18,000/800,000,000 = 0.0000225 sec.
</code>

  - What is the maximum number of packets per second that can be transmitted by this link?
<code>
  R/L = 800,000,000/18,000 = 44,444 packets per sec.
</code>

### Problem 2 (25 pts)
Consider a network with three links, each with the specified transmission rate and link length. Link 1 transmission rate is _100 Mbps_ with length of _5 Km_. Link 2 transmission rate is _10 Mbps_ and length _5000 Km_, Link 3 transmission rate is _100 Mbps_ and length is _1 Km_. The packet we are trying to send has a length of _6000 bits_. The speed of light is _3*10<sup>8</sup> m/sec_. Round your answers to two decimals after leading zeros.
  - Calculate the transmission and propagation delays for Link 1, 2 and 3.
<code>
  Transmission Delay: L/R<br/>
  1) 6,000/100,000,000 = 0.00006 sec.<br/>
  2) 0.0006 sec.<br/>
  3) 0.00006 sec.<br/>
  <br/>
  Propagation Delay: d/s<br/>
  1) 5,000/3*10^8 = 0.00016 sec. <br/>
  2) 0.016 sec.<br/>
  3) 0.0000033 sec.<br/>
</code>

  - What is the end to end delay for the packet?
<code>
  Total Delay = ~0.018<br/>
</code>

### Problem 3 (10 pts)
Consider sending a packet from a source host to a destination host over a fixed route.
  - List the delay components in the <b>end-to-end</b> delay.
  <code>
  The delay components are processing delays, transmission delays, propagation delays, and queuing delays.
  </code>

  - Which of these delays are constant and which are variable?
<code>
All of these delays are fixed, except for the queuing delays, which are variable.
</code>

### Problem 4 (45 pts)
Consider the two scenarios below:

A circuit-switching scenario in which _N<sub>cs</sub>_ users, each requiring a bandwidth of _20 Mbps_, must share a link of capacity _150 Mbps_.
A packet-switching scenario with _N<sub>ps</sub>_ users sharing a _150 Mbps_ link, where each user again requires _20 Mbps_ when transmitting, but only needs to transmit _20 %_ of the time. Round your answer to two decimals after leading zeros.

  - When circuit switching is used, what is the maximum number of users that can be supported?
<code>
  Max Users: 150 Mbps / 20 Mbps = 7 Users  
</code>
  - When packet switching is used, if there are 13 packet-switching users, can this many users be supported under circuit-switching?
<code>
  No. 13 Users * 20 Mbps = 260 Mbps, which is greater than 150 Mbps
</code>
  - If there are 13 packet-switching users, what is the probability that a given user is transmitting, and the remaining users are not transmitting?
<code>
p = 0.2
<br/>
𝑝 ∗ (1 − 𝑝)<sup>(13 − 1)</sup> = 0.0137438953472 ~ 0.014
</code>

  - What is the probability that one user (any one among the 13 users) is transmitting, and the remaining users are not transmitting?
<code>
13 ∗ 𝑝 ∗ (1 − 𝑝)<sup>(13 − 1)</sup> = 0.1786706395136 ~ 18%
</code>

  - When one user is transmitting, what fraction of the link capacity will be used by this user? Write your answer as a decimal number.
<code>
20 Mbps over the 150 Mbps link or 13% of the link’s capacity when busy
</code>

  - When packet switching is used, what is the probability that any 7 users (of the total 13 users) are transmitting and the remaining users are not transmitting?
<code>
(13 choose 7) * 𝑝<sup>7</sup> ∗ (1 − 𝑝)<sup>(13-7)</sup> = 0.0057579405312 ~ 0.58
</code>

  - When packet switching is used, what is the probability that more than 7 users are transmitting?
<code>
Sum{(13 choose n) * p <sup>n</sup> * (1 - p)<sup>(13 - n)</sup>}, for n = 8 to 13 => 0.0012456206336 ~ 0.012
</code>

### Problem 5 (5 pts)
What layer in the TCP/IP stack best corresponds to saying: 'handles messages from a variety of network applications'?
<code>
Application layer
</code>

### Submit

Post your solutions in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.
