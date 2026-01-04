#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    stack[++top] = c;
}


char pop() {
    return stack[top--];
}


int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {


        if (isalnum(ch)) {
            postfix[k++] = ch;
        }


        else if (ch == '(') {
            push(ch);
        }


        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop();
        }


        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }


    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
