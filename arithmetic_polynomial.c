#include <stdio.h>
#include <stdlib.h>

struct eqa {
    int coeff;
    int exp;
    struct eqa* next;
};

void inserteqa(struct eqa** head, int coeff, int exp) {
    if (coeff == 0) return;
    struct eqa* neweqa = (struct eqa*)malloc(sizeof(struct eqa));
    neweqa->coeff = coeff;
    neweqa->exp = exp;
    neweqa->next = NULL;

    if (!(*head)) {
        *head = neweqa;
        return;
    }
    struct eqa* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = neweqa;
}

void display(struct eqa* head) {
    struct eqa* temp = head;
    while (temp) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// ---------- Addition ----------
struct eqa* addPolynomials(struct eqa* poly1, struct eqa* poly2) {
    struct eqa* result = NULL;
    while (poly1 && poly2) {
        if (poly1->exp == poly2->exp) {
            inserteqa(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            inserteqa(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else {
            inserteqa(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }
    while (poly1) { inserteqa(&result, poly1->coeff, poly1->exp); poly1 = poly1->next; }
    while (poly2) { inserteqa(&result, poly2->coeff, poly2->exp); poly2 = poly2->next; }
    return result;
}

// ---------- Subtraction ----------
struct eqa* subsPolynomials(struct eqa* poly1, struct eqa* poly2) {
    struct eqa* result = NULL;
    while (poly1 && poly2) {
        if (poly1->exp == poly2->exp) {
            inserteqa(&result, poly1->coeff - poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            inserteqa(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else {
            inserteqa(&result, -poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }
    while (poly1) { inserteqa(&result, poly1->coeff, poly1->exp); poly1 = poly1->next; }
    while (poly2) { inserteqa(&result, -poly2->coeff, poly2->exp); poly2 = poly2->next; }
    return result;
}

// ---------- Multiplication (uses addPolynomials) ----------
struct eqa* multiplyPoly(struct eqa* poly1, struct eqa* poly2) {
    struct eqa* result = NULL;
    for (struct eqa* p1 = poly1; p1; p1 = p1->next) {
        struct eqa* temp = NULL;
        for (struct eqa* p2 = poly2; p2; p2 = p2->next) {
            inserteqa(&temp, p1->coeff * p2->coeff, p1->exp + p2->exp);
        }
        // reuse existing addPolynomials() for accumulation
        result = addPolynomials(result, temp);
    }
    return result;
}

// ---------- Main with Switch Menu ----------
int main() {
    struct eqa* poly1 = NULL;
    struct eqa* poly2 = NULL;
    int n1, n2, i, coeff, exp, choice;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Enter coeff and exp for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        inserteqa(&poly1, coeff, exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Enter coeff and exp for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        inserteqa(&poly2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);

    printf("\nChoose Operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    struct eqa* result = NULL;

    switch (choice) {
        case 1:
            result = addPolynomials(poly1, poly2);
            printf("Sum: ");
            break;
        case 2:
            result = subsPolynomials(poly1, poly2);
            printf("Difference: ");
            break;
        case 3:
            result = multiplyPoly(poly1, poly2);
            printf("Product: ");
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    display(result);
    return 0;
}
