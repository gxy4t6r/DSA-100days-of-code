#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

// Create new node
struct Node* createNode(int c, int p) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insert(struct Node* head, int c, int p) {
    struct Node* newNode = createNode(c, p);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Display polynomial
void display(struct Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->pow);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
}

// Add two polynomials
struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {

        if (p1->pow > p2->pow) {
            result = insert(result, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else if (p1->pow < p2->pow) {
            result = insert(result, p2->coeff, p2->pow);
            p2 = p2->next;
        }
        else {
            result = insert(result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insert(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insert(result, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // First polynomial: 5x^2 + 4x^1 + 2
    poly1 = insert(poly1, 5, 2);
    poly1 = insert(poly1, 4, 1);
    poly1 = insert(poly1, 2, 0);

    // Second polynomial: 5x^1 + 5
    poly2 = insert(poly2, 5, 1);
    poly2 = insert(poly2, 5, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("\nPolynomial 2: ");
    display(poly2);

    result = addPoly(poly1, poly2);

    printf("\nResult: ");
    display(result);

    return 0;
}
