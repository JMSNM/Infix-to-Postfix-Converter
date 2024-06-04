# Description
This C++ program converts an infix mathematical expression to postfix notation and evaluates the result. It uses a linked list to implement a stack, which is used to parse the infix expression and generate the postfix expression.


# Classes
linkedlist
A class that represents a linked list used as a stack.
Methods:
push(val): Adds a new node with the given value to the head of the list.
pop(): Removes the head node and returns its value.
display(): Prints the contents of the list.
isOperand(c): Checks if a character is an operand (0-9).
isOperator(c): Checks if a character is an operator (+, -, *, /, ^).
getPrecedence(c): Returns the precedence of an operator.
charToString(c): Converts a character to a string.
infixtopostfix(infix): Converts an infix expression to postfix notation.
solver(postfix): Evaluates a postfix expression and returns the result.


# Usage
Compile the program.
Run the program.
Input an infix mathematical expression (e.g., 2+3*4).
The program will output the equivalent postfix expression and the result of the evaluation.


# Example
Input: 2+3*4
Output:
Resultant postfix notation: 234*+
The result of the mathematical expression is: 14
