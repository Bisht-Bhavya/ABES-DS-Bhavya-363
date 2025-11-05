#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

int evalRPN(char* express[], int size) {
    for (int i = 0; i < size; i++) {
        char* t = express[i];

        if (strcmp(t, "+") == 0 || strcmp(t, "-") == 0 ||
            strcmp(t, "*") == 0 || strcmp(t, "/") == 0) {

            int op1 = stack[top--];
            int op2 = stack[top--];
            int result;

            if (strcmp(t, "+") == 0)
                result = op2 + op1;
            else if (strcmp(t, "-") == 0)
                result = op2 - op1;
            else if (strcmp(t, "*") == 0)
                result = op2 * op1;
            else
                result = op2 / op1;

            stack[++top] = result;
        } 
        else {
            stack[++top] = atoi(t);
        }
    }

    return stack[top];
}

int main() {
    char* expres[MAX_SIZE];
    int size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        expres[i] = (char*)malloc(10 * sizeof(char));
    }
    printf("Enter expression:\n");
    while (size < MAX_SIZE) {
        scanf("%s", expres[size]);
        if (strcmp(expres[size], "=") == 0) break;
        size++;
    }
    int result = evalRPN(expres, size);
    printf("Result: %d\n", result);
    return 0;
}
