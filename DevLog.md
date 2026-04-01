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
# Code Testing
Testing exposed another error where I was not able to detect multi-digit numbers.
I solved this by switching out a forloop for a whileloop, added a temp string that would append numbers if the next character was a digit, and added a i++ because it was
infinite looping because no iteration was happening inside the whileloop. Outside of the whileloop, I used num to assign th digit values. 
After testing again, operations and parentheses would disappear and this was because the whileloop would continue until it would get to a non-number, and then 
return to the forloop which would i++ again, effectively skipping over anything that wasn't a number. I solved this by backtracking(i--) once after exiting the whileloop.

3/31/26 Worked on isValidPostfix
# Developmental Choices
Paired two numbers per operator, and reduced the count of numbers by 1 to indicate a successful operation, when operations are succesfull until the very end, return 
1 indicating that we have one number, which is the theoretically computed result.

3/31/26 Worked on IsValidInfix
# Developmental Choices 
Tried to mimic the format of IsValidPostFix and change around some conditions to cater to the alternating nature of InValidInfix because I thought they could be done similarly. However, they 
do perform different processes, the IsValidPostFix method checks to see if we have enough numbers to preform operations properly, while IsValidInfix, checks to see if the string 
follows the pattern "number operator number". I abandoned my past idea because the format was not about matching numbers and operators. I switched my format to an alternating "case" 
format, which uses the boolean numberNext to validate and choose which case it would progress to. After it reaches a case, it alternates between true or false, with true meaning 
that we expect a number to be next. Our final return statement being boolean != nextNumber, which indicates that if the last read in character is an operator, this InFix is invalid.

3/31/26 Worked on PostFixToInFix
# Developmental Choices
To convert to infix to postfix, I pushed all numbers immediately to output when scanned. To implement precedence with operations, I allocated a temporary stack that held only 
opperations. Afterwards, the loop would compare the current operation being read and the operation on top of the stack, if the operation of top of the stack had a higher
precedence, it would be outputted first, if it has the same precedence it would join the stack. After we finish pushing higher precedent operations are pushed, the 
operation stack is completely pushed if there are any leftover operations.

