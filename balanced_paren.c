#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000
char stack[MAX_SIZE];
int top = -1;

int check(const char *s) {

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            stack[++top] = ch;
        } else {
            if (top == -1) return 0;
            char topChar = stack[top--];
            if ((ch == ')' && topChar != '(') ||
                (ch == ']' && topChar != '[') ||
                (ch == '}' && topChar != '{')) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    char s[100];
    printf("Enter expression: ");
    scanf("%s", s);

    if (check(s))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}
