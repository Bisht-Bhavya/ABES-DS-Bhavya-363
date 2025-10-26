#include <iostream>
using namespace std;

struct Node {
    int coeff, pow;
    struct Node* next;
};

void insert(struct Node*& head, int coeff, int pow) {
    struct Node* newNode = new Node();
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    if (!head) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 && poly2) {
        if (poly1->pow > poly2->pow) {
            insert(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            insert(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            insert(result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1) {
        insert(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2) {
        insert(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }
    return result;
}

Node* multiplyPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;
    for (Node* ptr1 = poly1; ptr1; ptr1 = ptr1->next) {
        Node* temp = NULL;
        for (Node* ptr2 = poly2; ptr2; ptr2 = ptr2->next) {
            insert(temp, ptr1->coeff * ptr2->coeff, ptr1->pow + ptr2->pow);
        }
        result = addPoly(result, temp);
    }
    return result;
}

void printPoly(Node* poly) {
    bool first = true;
    while (poly) {
        if (poly->coeff != 0) {
            if (!first && poly->coeff > 0) cout << " + ";
            if (poly->pow == 0)
                cout << poly->coeff;
            else if (poly->pow == 1)
                cout << poly->coeff << "x";
            else
                cout << poly->coeff << "x^" << poly->pow;
            first = false;
        }
        poly = poly->next;
    }
    cout << endl;
}

int main() {
    // Example: (2x^2 + 3x + 4) * (1x + 5)
    struct Node* poly1 = NULL;
    insert(poly1, 2, 2); 
    insert(poly1, 3, 1); 
    insert(poly1, 4, 0); 

    struct Node* poly2 = NULL;
    insert(poly2, 1, 1); 
    insert(poly2, 5, 0); 

    struct Node* result = multiplyPoly(poly1, poly2);
    cout << "Resultant polynomial: ";
    printPoly(result);
    return 0;
}