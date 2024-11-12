---
layout: default
course_number: CS330
title: "Programming Assignment: Three Letter Match"
---

## Lab Summary: Three Letter Match
In this lab, you will modify the existing _tcp_client_ and _tcp_server_ programs to implement the word game *Three Letter Match*. The basic concept is to choose a random three-letter combination and challenge yourself (as the player) to come up with as many valid words as possible that contain that specific three-letter substring.

#### Game Rules and Functionality Overview:
1. Selecting the Substring:
   - The client starts by choosing a three-letter set (substring) which it sends to the server. The substring should consist of letters only (no numbers or symbols), and the comparison should be case-insensitive.
  
2. Dictionary Validation:
   - The server will use a dictionary file [words](files/words.txt) to check whether the words submitted by the client are valid.

3. Submitting Words:
   - The client sends words to the server that it believes contain the chosen substring.
   - The server verifies two things:
     - Validity: The word must be in the dictionary.
     - Substring Match: The word must contain the specified three-letter substring.

4. Scoring:
   - If the word is valid and contains the substring, the client earns 1 point.
   - If the word does not contain the substring or is not in the dictionary, the client loses 1 point.

5. Listing Words:
   - When the client can no longer think of any words, it can send the List command to request a list of all words in the dictionary that contain the current three-letter substring.

6. Ending the Game:
   - The client can quit the game by sending the _Quit_ command, which will stop the game and display the client’s final score.

7. Commands:
   1. __Set__: Choose a new three-letter substring.
   2. __Submit__: Submit a word to the server to check if it’s valid and contains the substring.
   3. __List__: Request a list of all words containing the current three-letter substring.
   4. __Quit__: Exit the game and display the current score.

8. Client Input & Output:
   - All commands are read from the standard input, and the results (validity, score updates, etc.) are displayed on the standard output.

9. Server Behavior:
   -  The server continues running until explicitly told to exit by the client (e.g., using the Quit command).

10. Buffer Limits:
    - The maximum static buffer size for client messages is 512 bytes.

This setup encourages interaction through a simple menu-driven interface, providing an engaging way to test knowledge of words containing specific substrings while also practicing basic network programming concepts.

### Design Decisions
As you work on this lab, you'll need to make a series of design decisions that will shape how the game is implemented. Below are several key considerations that you will need to address:

1. Handling Multiple Clients:
   - How will the server manage multiple clients? For example, will you use multithreading, multiprocessing, or some other method to ensure that the server can handle multiple clients simultaneously? Be sure to explain the method you choose and why it is appropriate for this game.

2. Tracking Client Scores:
   - How will the server keep track of each client's score? Consider using a dictionary or list where each entry maps a client to their score. You should decide on the structure for this and explain why you chose it.

3. Behavior After the 'List' Command:
   - When the client issues the List command to see all words containing the chosen substring, should the game allow them to continue submitting guesses? You need to decide whether the game should continue normally after the List command, or whether the client’s turn should be paused or reset.

4. Handling Invalid Substrings:
   - What should happen if a client submits a substring that is not exactly three letters long (e.g., two or four letters)? You'll need to decide how to handle this, such as rejecting substrings of invalid lengths and asking the client to try again.

5. General Input Validation:
   - How will the server handle unexpected or invalid inputs from the client? For example, if the client submits a word with non-alphabetic characters or an empty string, how will the server respond? Will it prompt the client to fix the input, or will it penalize them?

### Documentation
1. Code Comments:
   - Throughout your code, be sure to include clear comments explaining:
    - Where you modified the original code.
    - Why you made those changes (i.e., the reasoning behind your design choices).
    - How you implemented your changes (e.g., the specific approach or technique you used).
  - Failure to properly document your code will result in point deductions, so make sure to add meaningful comments throughout your code.
2. README File:
   - Include a README file with your submission. This file should provide:
    - Instructions on how to run the program (for both the server and client).
    - A brief explanation of the game rules.
    - A description of your design decisions (e.g., how you handled multiple clients, how scores are tracked, etc.).
    - Any relevant setup instructions

### Pair Work and Submission
  - If you're working in pairs, submit only one set of program files, ensuring both partners' names are included in the code comments and README.
  - Both partners should be involved in all aspects of the project: design decisions, coding, testing, and documentation.
  - Clearly list both names in the README file and in the source code, making sure that the contributions of both individuals are acknowledged.

### Code snippets
  - [tcp_client.c](files/tcp_client.c)
  - [tcp_server.c](files/tcp_server.c)

### References
  - [Linux socket interface](https://linux.die.net/man/7/socket)
  - [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/html/)
  - [Debugging with GDB](https://ftp.gnu.org/old-gnu/Manuals/gdb/html_node/gdb_toc.html)
  - Create a child process [fork](https://linux.die.net/man/2/fork)
  - Synchronous I/O Multiplexing using [select](https://www.man7.org/linux/man-pages/man2/select.2.html)

### Testing
  - [Netcat](http://netcat.sourceforge.net/) is a command line tool that connects to an arbitrary TCP or UDP port and allows you to send and receive data.

### Grading
Post your report including source in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.

### Grading Criteria 
- Readme File
- Compile
- Run
  - Menu
  - Set -> Submit -> List -> Quit
  - Consecutive runs (Set after List)
  - Correct Score
- Multiple Clients 
- Static Buffer Sizes < 512
- Basic Error Handling 
  - Set with fewer than 3 characters
  - Set with more than 3 characters
  - Set with invalid substring
  - Multiple Set Commands
  - Submit after List
  - Submit the same word multiple times
- Test with _ate_ substring
- Client __shouldn't__ know about the _words.txt_ file

<!-- 

cat words.txt | perl -nlE '$_=lc; $l=length; next if $l < 3; m/(.{3,$l})(?{ $freq{$1}++ })^/; END { say "$freq{$_} $_" for keys %freq }' | sort -rg | head -10

 -->

