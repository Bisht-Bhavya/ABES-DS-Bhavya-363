#include <stdio.h>
#include <ctype.h>
#define N 100

char s[N]; 
int top = -1;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char in[N], out[N];
    int j = 0;
    scanf("%s", in);

    for (int i = 0; in[i]; i++) {
        char c = in[i];
        if (isalnum(c)) {
            out[j++] = c;
        } else if (c == '(') {
            s[++top] = c;
        } else if (c == ')') {
            while (top != -1 && s[top] != '(')
                out[j++] = s[top--];
            top--;
        } else {
            while (top != -1 && prec(s[top]) >= prec(c))
                out[j++] = s[top--];
            s[++top] = c;
        }
    }

    while (top != -1)
        out[j++] = s[top--];

    out[j] = '\0';
    printf("%s\n", out);
    return 0;
}
