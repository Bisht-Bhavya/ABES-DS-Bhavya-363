#include <iostream>
using namespace std;

struct eqa{
    int coeff;
    int exp;
    eqa* next;   
};

void inserteqa(struct eqa*& head, int coeff, int exp) {
    if (coeff == 0) return;
    struct eqa* neweqa = new eqa{coeff, exp, nullptr};
    if (!head) {
        head = neweqa;
        return;
    }
    struct eqa* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = neweqa;
}

struct eqa* subsPolynomials(struct eqa* poly1, struct eqa* poly2) {
    eqa* result = nullptr;
    while (poly1 && poly2) {
        if (poly1->exp == poly2->exp) {
            int diffCoeff = poly1->coeff - poly2->coeff;
            inserteqa(result, diffCoeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            inserteqa(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else {
            inserteqa(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }
    while (poly1) {
        inserteqa(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2) {
        inserteqa(result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

void display(eqa* head) {
    struct eqa* temp = head;
    while (temp) {
        cout << temp->coeff << "x^" << temp->exp;
        if (temp->next) cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Example polynomials: 3x^4 + 2x^2 + 1 and 5x^3 + 2x^2 + 4
    struct eqa* poly1 = NULL;
    inserteqa(poly1, 3, 4);
    inserteqa(poly1, 2, 2);
    inserteqa(poly1, 1, 0);

    struct eqa* poly2 = NULL;
    inserteqa(poly2, 5, 3);
    inserteqa(poly2, 2, 2);
    inserteqa(poly2, 4, 0);

    cout << "Polynomial 1: ";
    display(poly1);
    cout << "Polynomial 2: ";
    display(poly2);

    struct eqa* Subs = subsPolynomials(poly1, poly2);
    cout << "Difference: ";
    display(Subs);
    return 0;
}