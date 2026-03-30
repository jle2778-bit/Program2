3/30/2026 ArrayStack methods and testing
# Bugs and Issues: 
Had trouble using a forloop to pop the stack, the issue was that the stack size was updating during the popping, I 
fixed this issue by creating another variable to store the original stack size and use inside the forloop, 
preventing the stop condition from being updated during the forloop.
# Code Testing:
Created a stack and used methods Top and Size to see the stack details, after using push, called on Top and Size to see if stack 
details changed to validate the test. Tested pop by emptying the stack with a forloop. Used the emptied stack to test Pop and Top errors. Tested empty boolean
by calling it on the stack before and after it got emptied. 

