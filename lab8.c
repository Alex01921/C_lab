#include <stdio.h>
#include <stdlib.h>

// Structure definition for a doubly linked list node
struct node {
    int page;              // Page number
    struct node *left;     // Pointer to the previous node
    struct node *right;    // Pointer to the next node
};

typedef struct node *NODEPTR;
NODEPTR list = NULL; // Global pointer to the head of the list

// Function prototypes
NODEPTR createlist(NODEPTR list, int page);
NODEPTR moveforward(NODEPTR list, int cp, int steps);
NODEPTR movebackward(NODEPTR list, int cp, int steps);
void display(NODEPTR list);
NODEPTR getnode();

// Function to create a new node in the list
NODEPTR createlist(NODEPTR list, int page) {
    NODEPTR p, q;
    p = getnode(); // Allocate memory for a new node
    p->page = page; // Set the page number
    p->left = NULL;
    p->right = NULL;

    if (list == NULL) { // If the list is empty
        list = p; // Set the new node as the head
    } else {
        // Traverse to the last node
        for (q = list; q->right != NULL; q = q->right)
            ;
        q->right = p; // Link the new node to the end of the list
        p->left = q;  // Link back to the previous node
    }
    return list; // Return the updated list
}

// Function to move forward in the list by a specified number of steps
NODEPTR moveforward(NODEPTR list, int cp, int steps) {
    NODEPTR p, q;
    int count = 0, s;

    if (list == NULL) { // Handle an empty list
        printf("\n Empty list");
        return NULL;
    }

    // Locate the current page node (cp)
    p = list;
    for (count = 1; p != NULL && count < cp; count++) {
        p = p->right;
    }

    if (p == NULL) { // If the current page is invalid
        printf("\n Invalid current page!");
        return NULL;
    }

    // Move forward by the specified number of steps
    for (q = p, s = 0; s < steps && q->right != NULL; s++) {
        q = q->right;
    }

    // Return the last valid node reached
    return q;
}

// Function to move backward in the list by a specified number of steps
NODEPTR movebackward(NODEPTR list, int cp, int steps) {
    NODEPTR p, q;
    int count = 0, s;

    if (list == NULL) { // Handle an empty list
        printf("\n Empty list");
        return NULL;
    }

    // Locate the current page node (cp)
    p = list;
    for (count = 1; p != NULL && count < cp; count++) {
        p = p->right;
    }

    if (p == NULL) { // If the current page is invalid
        printf("\n Invalid current page!");
        return NULL;
    }

    // Move backward by the specified number of steps
    for (q = p, s = 0; s < steps && q->left != NULL; s++) {
        q = q->left;
    }

    // Return the last valid node reached
    return q;
}

// Function to display the contents of the list
void display(NODEPTR list) {
    NODEPTR p = list;

    if (p == NULL) { // Handle an empty list
        printf("\nEmpty list");
    } else {
        printf("\n The page list contains: ");
        while (p != NULL) { // Traverse the list
            printf("%d", p->page);
            if (p->right != NULL) {
                printf("<->"); // Print a bidirectional arrow
            }
            p = p->right;
        }
        printf("\n");
    }
}

// Function to allocate memory for a new node
NODEPTR getnode() {
    NODEPTR r = (NODEPTR)malloc(sizeof(struct node));
    if (r == NULL) { // Handle memory allocation failure
        printf("\n Node allocation failed");
        exit(0);
    }
    return r;
}

// Main function with a menu-driven interface
void main() {
    int page, choice, steps, cp;
    char cont;
    NODEPTR p;

    do {
        // Display menu
        printf("\n ...........MENU...........");
        printf("\n 1->CREATE LIST\t 2->MOVE FORWARD\t 3->MOVE BACKWARD\t 4->DISPLAY\t 5->EXIT");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Create list of pages
                printf("\n CREATION OF DOUBLY LINKED LIST OF PAGES IS IN PROGRESS:\n");
                do {
                    printf("Enter a page number: ");
                    scanf("%d", &page);
                    list = createlist(list, page);
                    printf("Do you want to enter another page [Y/N]: ");
                    scanf(" %c", &cont);
                } while (cont == 'Y' || cont == 'y');
                display(list);
                break;

            case 2: // Move forward
                printf("\n MOVE FORWARD:\n");
                printf("Enter the current page: ");
                scanf("%d", &cp);
                printf("Enter the number of steps to move forward: ");
                scanf("%d", &steps);
                p = moveforward(list, cp, steps);
                if (p != NULL) {
                    printf("\n Moved forward to page %d from %dth page", p->page, cp);
                }
                break;

            case 3: // Move backward
                printf("\n MOVE BACKWARD:\n");
                printf("Enter the current page: ");
                scanf("%d", &cp);
                printf("Enter the number of steps to move backward: ");
                scanf("%d", &steps);
                p = movebackward(list, cp, steps);
                if (p != NULL) {
                    printf("\n Moved backward to page %d from %dth page", p->page, cp);
                }
                break;

            case 4: // Display the list
                display(list);
                break;

            case 5: // Exit the program
                printf("\n Quitting operation List.....\n");
                break;

            default: // Handle invalid choices
                printf("\n Invalid choice");
                break;
        }
    } while (choice != 5);
}
