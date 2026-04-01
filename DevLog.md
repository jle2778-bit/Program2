3/30/2026 ArrayStack methods and testing
# Bugs and Issues: 
Had trouble using a forloop to pop the stack, the issue was that the stack size was updating during the popping, I 
fixed this issue by creating another variable to store the original stack size and use inside the forloop, 
preventing the stop condition from being updated during the forloop.
# Code Testing:
Created a stack and used methods Top and Size to see the stack details, after using push, called on Top and Size to see if stack 
details changed to validate the test. Tested pop by emptying the stack with a forloop. Used the emptied stack to test Pop and Top errors. Tested empty boolean
by calling it on the stack before and after it got emptied. 

3/31/26 Developing tokenizer 
# Bug and Issues
Comparison issues stemming from mismatched types (character and string) threw errors when I was comparing inputs and assigning characters.
The errors were fixed by converting types properly. 

Testing exposed another error where I was not able to detect multi-digit numbers.
I solved this by switching out a forloop for a whileloop, added a temp string that would append numbers if the next character was a digit, and added a i++ because it was
infinite looping because no iteration was happening inside the whileloop. Outside of the whileloop, I used num to assign th digit values. 

After testing again, operations and paretheses would disappear and this was because the whileloop would continue until it would get to a non-number, and then 
return to the forloop which would i++ again, effectively skipping over anything that wasn't a number. I solved this by backtracking(i--) once after exiting the whileloop. 