//infix to postfix converter

#include <iostream>
#include <string>
using namespace std;

class linkedlist
{
public:
    struct Node
    {
        char data;
        Node *next;
        Node *prev;
    };

    Node *head = NULL;

    void push(char val) // add node at head
    {
        Node *newnode = new Node;
        newnode->data = val;

        if (head == NULL)
        {
            newnode->next = newnode;
            newnode->prev = newnode;
        }
        else
        {
            Node *temp = head->prev;
            newnode->next = head;
            newnode->prev = temp;
            temp->next = newnode;
            head->prev = newnode;
        }

        head = newnode;
    }

    char pop()
    {
        char s;
        if (head == NULL)
        {
            return '\0';
        }
        else if (head->next == head)
        {
            s = head->data;
            delete head;
            head = NULL;
            return s;
        }
        else
        {
            Node *temp = head->prev;
            s = head->data;

            temp->next = head->next;
            head->next->prev = temp;

            Node *oldHead = head;
            head = head->next;

            delete oldHead;
            return s;
        }
    }

    void display()
    {
        Node *ptr;
        if (head == NULL)
            cout << "Stack is empty";
        else
        {
            ptr = head;

            do
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            } while (ptr != head);
        }
        cout << endl;
    }

    bool isOperand(char c)
    {
        return (c >= '0' && c <= '9');
    }

    bool isOperator(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    int getPrecedence(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return 0;
    }

    string charToString(char c)
    {
        return string(1, c);
    }

    string infixtopostfix(string infix)
    {
        string postfix = "";
        push('(');
        infix += ")";
        for (int j = 0; j < infix.length(); j++)
        {
            if (isOperand(infix[j]))
            {
                postfix += infix[j];
            }
            else if (infix[j] == '(')
            {
                push(infix[j]);
            }
            else if (isOperator(infix[j]))
            {
                while (head != NULL && getPrecedence(head->data) >= getPrecedence(infix[j]))
                {
                    string t = charToString(pop());
                    postfix += t;
                }
                push(infix[j]);
            }
            else if (infix[j] == ')')
            {
                while (head->data != '(')
                {
                    string t = charToString(pop());
                    postfix += t;
                }
                pop();
            }
        }

        return postfix;
    }

    float solver(string postfix)
    {
        for (int i = 0; i < postfix.length(); i++)
        {
            if (isOperand(postfix[i]))
            {
                push(postfix[i] - '0');
            }
            else if (isOperator(postfix[i]))
            {
                float op2 = pop(); // Pop the second operand first
                float op1 = pop(); // Then pop the first operand

                if (postfix[i] == '*')
                    push(op1 * op2);
                else if (postfix[i] == '/')
                    push(op1 / op2);
                else if (postfix[i] == '-')
                    push(op1 - op2);
                else if (postfix[i] == '+')
                    push(op1 + op2);
            }
        }

        return pop();
    }
};

int main()
{
    linkedlist one, two;

    string i, p;

    cout << "Input infix notation: ";
    cin >> i;
    p = one.infixtopostfix(i);
    cout << "Resultant postfix notation: " << p << endl;
    float result;
    result = two.solver(p);
    cout << "The result of the mathematical expression is: " << result;

    return 0;
}
