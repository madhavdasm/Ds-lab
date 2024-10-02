#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 50

int top = -1, i, j, k = 0, value1, value2, re[10], num,m;
char str[50], a[50], b[MAX];

int get_precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int associativity(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1; // L to R
        case '^':
            return 2; // R to L
    }
}

void push(char item) {
    top = top + 1;
    a[top] = item;
}

void pop() {
    top = top - 1;
}

void infix_to_prefix(char str[]) {
    for (i = strlen(str) - 1; i >= 0; i--) {

        if (isalnum(str[i])) {
            while (isalnum(str[i])) {
                b[k] = str[i];
                k++;
                i--;
            }
            b[k] = ' ';
            k++;
            i++;
        } else if (top == -1 || a[top] == ')' || str[i] == ')') {
            push(str[i]);
        } else if (str[i] == '(') {
            for (j = top; a[j] != ')'; j--) {
                b[k] = a[j];
                k++;
                pop();
            }
            top--;
        } else if (get_precedence(str[i]) > get_precedence(a[top])) {
            push(str[i]);
        } else if (get_precedence(str[i]) < get_precedence(a[top])) {

            int flag = 0;
            while (flag == 0) {
                if (get_precedence(str[i]) > get_precedence(a[top])) {
                    push(str[i]);
                    flag = 1;
                } else if (get_precedence(str[i]) == get_precedence(a[top])) {
                    if (associativity(str[i]) == 2) {
                        b[k] = a[top];
                        k++;
                        pop();
                        push(str[i]);
                        flag = 1;
                    } else if (associativity(str[i]) == 1) {
                        push(str[i]);
                        flag = 1;
                    }

                } else {
                    b[k] = a[top];
                    k++;
                    pop();
                }
            }
        } else if (get_precedence(str[i]) == get_precedence(a[top])) {
            if (associativity(str[i]) == 2) {
                b[k] = a[top];
                k++;
                pop();
                push(str[i]);
            } else if (associativity(str[i]) == 1) {
                push(str[i]);
            }
        }
    }
    while (top != -1) {
        b[k] = a[top];
        k++;
        pop();
    }
}

int main() {
    printf("Enter the infix expression:");
    fgets(str, sizeof(str), stdin);
    printf("Infix expression: %s\n", str);
    infix_to_prefix(str);
    printf("\nAfter converting to prefix: ");
    for(m=k-1;m>=0;m--) {
        printf("%c", b[m]);
    }
    return 0;
}

