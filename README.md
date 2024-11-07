Voting System - README

Project Overview

This project is a simple voting system implemented in C. The program allows users to vote for candidates by entering their voter ID and selecting a candidate from the displayed options. The system also includes functionality to view current vote counts, reset votes, and restrict certain actions using a password. The program uses external data storage in a text file to maintain voter records and vote tallies.

Files

1. B23ME1066_B23ME1047.c: Contains the main() function and implements the core logic for voting and interacting with the user.
2. B23ME1066_B23EE1065.c: Contains supporting functions for tasks like verifying voter IDs, storing votes, displaying candidate information, and resetting votes.
3. B23ME1066_B23EE1065.txt: Data file used to store votes and voter IDs. Do not delete or modify this file manually.

Instructions to Run the Voting System:

Step 1: Setup the Project

1. Download and save the project files into a folder on your desktop. The folder should contain the following:
    a. B23ME1066_B23ME1047.c
    b. B23ME1066_B23EE1065.c
    c. B23ME1066_B23EE1065.txt (data file for storing voting data)

2. Open the folder in an IDE (such as VSCode or CodeBlocks). Make sure all the files are in the same directory.

Step 2: Compile and Run the Program:

1. Compile the C program using your IDE's built-in compiler or from the command line:
    a. If using the command line, use a C compiler like gcc:

       bash
       gcc B23ME1066_B23ME1047.c B23ME1066_B23EE1065.c -o VotingSystem
3. Run the program:

a. In the IDE, simply run the B23ME1066_B23ME1047.c file (the one containing main()).
b. If using the command line, run:

    bash
    ./VotingSystem

Step 3: Interacting with the Program
Once the program is running, you'll see a menu with several options. Choose from the following actions:

1. Caste a Vote:
   a. Enter your 3-digit voter ID (between 101 and 199).
   b. Choose a candidate by entering the corresponding letter (A, B, C, D) or select N for NOTA (None of the Above).
   c. The system will confirm your vote.

2. Show Current Status of Votes:
   a. Admins can enter the 4-digit passcode 1920 to view the current vote counts for all candidates.

3. Reset Votes to Zero:
   a. Admins can enter the 4-digit passcode 1920 to reset all votes to zero and clear the voter records. Warning: This action is irreversible.

4. Exit:
   Exit the program.

Step 4: Special Notes:

1. 4-Digit Passcode: The admin can access special features (viewing votes, resetting votes) by entering the passcode 1920.
2. 3-Digit Voter ID: A valid voter ID should be between 101 and 199.
3. Voter ID Check: The system will check if the voter ID is valid and whether the user has already voted. Duplicate voter IDs are not allowed.
4. Data Files: The vote data and voter records are stored in B23ME1066_B23EE1065.txt. Do not delete or modify this file manually.

Step 5: Important Considerations:

1. Correct Data Input: When entering data:
   
   a. Enter an integer when prompted for a voter ID or passcode.
   b. Enter a character when prompted for a candidate (A, B, C, D, or N for NOTA).
   c. Failure to enter the correct type of data may cause the program to fail.

2. File Handling: The program relies on files for storing votes and voter IDs. Do not delete or modify these files as it may cause data loss or corrupt the program's functionality.

3. Security: The passcode 1920 is used to allow admin functions like viewing and resetting votes. Keep this passcode secure.

File Descriptions:

1. B23ME1066_B23ME1047.c:
   This file contains the main program logic, including:
   
   a. Displaying the menu for user interaction.
   b. Handling user input to cast votes, view current votes, or reset votes.
   c. Managing the interaction with the voting system.

2. B23ME1066_B23EE1065.c:
   This file contains supporting functions that support the main logic:
   
   a. voter_id_checker(): Verifies voter IDs and checks for duplicates.
   b. vote_counter(): Increments vote counts for selected candidates.
   c. reset_votes(): Resets vote counts and clears voter records.
   d. display_votes(): Displays the current vote counts and percentages.
   e. password_checker(): Validates the admin passcode.

Conclusion:
This voting system allows users to cast votes, track vote counts, and provides administrative functions to manage and reset the voting data. Ensure that all files are intact and secure for proper functionality.
