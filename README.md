Resources
Read or watch:
•    Unix shell
•    Thompson shell
•    Ken Thompson
•    Everything you need to know to start coding your own shell
man or help:
•   sh (Run sh as well)
Learning Objectives
•	 Who designed and implemented the original Unix operating system
•	 Who wrote the first version of the UNIX shell
•	 Who invented the B programming language (the direct predecessor to the C programming language)
•	 Who is Ken Thompson
•	 How does a shell work
•	 What is a pid and a ppid
•	 How to manipulate the environment of the current process
•	 What is the difference between a function and a system call
•	 How to create processes
•	 What are the three prototypes of main
•	 How does the shell use the PATH to find the programs
•	 How to execute another program with the execve system call
•	 How to suspend the execution of a process until one of its children terminates
•	 What is EOF / “end-of-file”?



Requirements
•	All your files will be compiled on Ubuntu 14.04 LTS
•	The  C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
•	Files should end with a new line
•	Use the Betty style.
•	The shell should not have any memory leaks
•	No more than 5 functions per file
•	All  header files should be include guarded
•	Use system calls only when you need to (why?)
List of allowed functions and system calls
•    access (man 2 access)
•    chdir (man 2 chdir)
•    close (man 2 close)
•    closedir (man 3 closedir)
•    execve (man 2 execve)
•    exit (man 3 exit)
•    _exit (man 2 _exit)
•    fflush (man 3 fflush)
•    fork (man 2 fork)
•    free (man 3 free)
•    getcwd (man 3 getcwd)
•    getline (man 3 getline)
•    isatty (man 3 isatty)
•    kill (man 2 kill)
•    malloc (man 3 malloc)
•    open (man 2 open)
•    opendir (man 3 opendir)
•    perror (man 3 perror)
•    read (man 2 read)
•    readdir (man 3 readdir)
•    signal (man 2 signal)
•    stat (__xstat) (man 2 stat)
•    lstat (__lxstat) (man 2 lstat)
•    fstat (__fxstat) (man 2 fstat)
•    strtok (man 3 strtok)
•    wait (man 2 wait)
•    waitpid (man 2 waitpid)
•    wait3 (man 2 wait3)
•    wait4 (man 2 wait4)
•    write (man 2 write)



The Shell
Recently, we was tasked to make a  simple shell. During this process, we  learned all about how the shell works and what happens when a command is typed into the command line. In this file we will explain what happens when “ls -l” is typed in.
we like to think of the shell having 3 phases:
Reading Phase, Searching Phase and Execution Phase.
During the Reading Phase, the command line is read and put into a buffer. After that happens, the shell will search for the command in the Searching Phase. After the Searching Phase completes, the command is then executed in the Execution Phase.

The shell runs in an infinite loop, always waiting for the next command to be entered. Once a command is entered, the standard input is read and put into a buffer using getline.

getline(&line, &bufsize, stdin);


With the written command, the shell will initiate a tokenization, which is basically separating the words you have entered. The next step your shell does is execute the env command (command that lists the environment variables).

and it is located where the PATH is, once there the shell returns to perform a tokenized to separate the addresses contained in PATH and thus be able to concatenate the ls command with a path.
For example:
/usr/local/sbin/ls

This is done to identify the route in which ls is located and thus be able to execute it. In the previous example, the shell checks that the command is not there, so you must concatenate it with the following one until you find the path.
Once the route is found, you can execute the command with the function;

execve(result, tokenizado, NULL);

which contains three parameters, the first one contains the path and the command to execute, the second one contains the arguments that you had entered as -l and the third one ends. This makes your shell so you can get:

ls [option ...]

Among the many processes that are executed after each command, this is the most summarized way to define it.
