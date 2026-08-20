### So what are we doing ###
In this project the first initial goal was to create a pipeline=>
1. First Our main file will read the .neu file and tokenize it.
2. So the compiler currently is reading the neu file and converting it to its subsequent assembly file 
=> How does assembly work now?
First we define a global start 
Then inside the start we use the registers rax and rdi to do some syscalls in the file we call 21 and 60 is to exit safely
We also learned how to use cmake cmds to build systems.