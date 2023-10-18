SIMPLE SHELL 
DESCRIPTION
This repository contains a version of shell in C programming language which is a basic for learners to pursue in Alx-low_programming in Alx-Africa school, (https://www.alxafrica.com/). 

Authors
This project was collaborated by two  students of Alx Software Engineering program.
. Malcom Nyaranga <Kibisu14@icloud.com>
. Stephen Wambua <wambuastephen97@gmail.com>

Requirements.
To be able to use this project , you must have a gcc compiler on a 64-bit operating system computer.
Get started.
1. git clone this repository to your local terminal in your machine using this command:
$ git clone https://github.com/Malckom/simple_shell.git

2 Compile The Shell Project.
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

3.Run shell
$ ./hsh
4. Test shell
$ ls
# Lists files and directories in the current directory

$ env
# Prints environment variables

$ exit
# Quits the shell

Use.
In this shell, you can use number of commands both in interactive and non-interactive modes.
1. Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
md.c   errorh.c    getbt.c    listops.c  readline.c

2.  in non-interactive mode:

$ echo "/bin/ls" | ./hsh
cd.c    errorh2.c   ext.c      list2.c


Project Structure
The project structure is organized as follows:

main.c: Main shell logic
functions.c: Utility functions

Contributing.
As much as we encourage collaboration and we know the power in it, the guidelines required onlytwo contributors, and only them have write permissions.

Gitignore.
No file or directories to ignore.
Acknowledgments
We'd like to acknowledge the following for their support and inspiration:

Alx-Africa School
Contributors and open-source community
