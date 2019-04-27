# Easy Tabling

The goal of this program is to create an efficient yet user-friendly table management system.

This table management system aims to help small-scale restaurants in Hong Kong. As they often have limited number of tables and waiters due to high rental and salary cost, it is important for them to maximize their productivity in order to survive in a competitive market.
This program automates the table management process effectively so that waiters can focus on serving customers. 

This is a group project for HKU 2018-2019 (Semester 2) ENGG1340, submitted by To Ming Lok (3035567590) and Yau Herman (3035570054).

## Input

Our program takes 1 input only (config.txt), which stores the number of customers each table can serve. The program will stop if config.txt does not exist.

## Features

1) Occupy a table 
2) Reserve a table
3) Release a table
4) Make changes to the configuration of tables

5) Search for an available table with seats not less than the number of customers
6) Check the status of any tables 

7) Record the amount of each table, reset after checking
8) Issue a notification when a table has been occupied for some time (users can adjust time )
 
Information of every table such as total fee, current table status (A, R, O represent available, reserved, occupied respectively) are displayed in the main menu. Also, overtime notification (features 8) will only be issued every time main menu is visited.

We want our program to be user-friendly, clear instructions are provided while running the program. An erroe message will pop out if target is invalid.

On the other hand, the program allows users to enter consecutive orders if they are used to. For example, users can enter 1+3 directly in the menu to occupy table 3 or enter the order 1 by 1 following instructions.

## Output

When users exit the program, final table configuration total amount of transaction of each table will be output to report.txt We hope this can assist owners in adding up profit.

## Compilation Instruction

To compile the program, clone the whole source code, use "make tabler" command at the root folder, the program "tabler.exe" will be generated.

## Execution Instruction

To execute the program, use "tabler" command at the root folder after compliation is done. On windows, you can double click "tabler.exe" to run execute it.
