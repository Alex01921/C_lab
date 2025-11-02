#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for a node in the Binary Search Tree (BST)
struct node {
    char info[20];        // Stores the key (word) in the node
    struct node *left;    // Pointer to the left subtree
    struct node *right;   // Pointer to the right subtree
};

// Typedef for convenience in working with node pointers
typedef struct node *NODEPTR;

// Function declarations
NODEPTR maketree(char word[]);              // Create a new tree with a single node
NODEPTR createtree(char word[]);            // Create a tree (unused function in this code)
void setleft(NODEPTR p, char word[]);       // Attach a node as the left child
void setright(NODEPTR p, char word[]);      // Attach a node as the right child
void intrav(NODEPTR p);                     // Perform in-order traversal
void pretrav(NODEPTR p);                    // Perform pre-order traversal
void posttrav(NODEPTR p);                   // Perform post-order traversal
void search(NODEPTR p, char key[]);         // Search for a key in the tree

// Main function to implement the menu-driven program
void main() {
    NODEPTR ptree;      // Root of the binary search tree
    NODEPTR p, q;       // Temporary pointers for traversal and insertion
    char word[20], key[20]; // Variables to hold input words and keys for searching
    int opt;            // User's menu choice

    do {
        // Display menu options
        printf("\n1->CREATE DICTIONARY 2->TRAVERSE 3->SEARCH 4->EXIT ");
        printf("\nEnter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: // Create dictionary (build BST)
                printf("\nEnter a word: ");
                scanf("%s", word);
                ptree = maketree(word); // Initialize the tree with the first word

                // Keep adding words to the BST until "END" is entered
                while (strcmp(word, "END") != 0) {
                    printf("\nEnter a word (Type END to stop): ");
                    scanf("%s", word);
                    if (strcmp(word, "END") == 0)
                        break; // Stop word entry if "END" is entered

                    p = q = ptree; // Start from the root of the tree

                    // Find the appropriate position for the new word
                    while ((strcmp(word, p->info) != 0) && q != NULL) {
                        p = q; // Keep track of the parent node
                        if (strcmp(word, p->info) < 0) // If word is smaller, move left
                            q = p->left;
                        else // If word is larger, move right
                            q = p->right;
                    }

                    // Attach the new word as a left or right child
                    if (strcmp(word, p->info) < 0)
                        setleft(p, word);
                    else if (strcmp(word, p->info) >= 0)
                        setright(p, word);
                }
                printf("\nDICTIONARY CREATED SUCCESSFULLY");
                break;

            case 2: // Traverse the dictionary in different orders
                printf("\nPREORDER TRAVERSAL OF THE DICTIONARY IS: ");
                pretrav(ptree); // Pre-order traversal

                printf("\nINORDER TRAVERSAL OF THE DICTIONARY IS: ");
                intrav(ptree); // In-order traversal

                printf("\nPOSTORDER TRAVERSAL OF THE DICTIONARY IS: ");
                posttrav(ptree); // Post-order traversal
                break;

            case 3: // Search for a word in the dictionary
                printf("\nEnter the key to search in the dictionary: ");
                scanf("%s", key);
                search(ptree, key); // Call search function
                break;

            case 4: // Exit the program
                printf("\nEXITING BINARY TREE");
                exit(1); // Exit the program
        }
    } while (opt != 4); // Repeat until the user chooses to exit
}

// Function to create a new tree with a single node
NODEPTR maketree(char w[]) {
    NODEPTR t;
    t = (NODEPTR)malloc(sizeof(struct node)); // Allocate memory for the new node
    if (t == NULL) { // Check for memory allocation failure
        printf("\nNode allocation failed");
        exit(0);
    }
    strcpy(t->info, w); // Copy the word into the node
    t->left = NULL;     // Initialize left and right children as NULL
    t->right = NULL;
    return t;           // Return the created node
}

// Attach a node as the left child of the given parent node
void setleft(NODEPTR p, char w[]) {
    if (p == NULL) // Check for invalid parent node
        printf("Void Insertion");
    else if (p->left != NULL) // Check if left child already exists
        printf("Invalid Insertion");
    else
        p->left = maketree(w); // Attach the new node as the left child
}

// Attach a node as the right child of the given parent node
void setright(NODEPTR p, char w[]) {
    if (p == NULL) // Check for invalid parent node
        printf("Void Insertion");
    else if (p->right != NULL) // Check if right child already exists
        printf("Invalid Insertion");
    else
        p->right = maketree(w); // Attach the new node as the right child
}

// Perform in-order traversal (left, root, right)
void intrav(NODEPTR tree) {
    if (tree != NULL) {
        intrav(tree->left);        // Visit left subtree
        printf("%s\t", tree->info); // Visit root
        intrav(tree->right);       // Visit right subtree
    }
}

// Perform pre-order traversal (root, left, right)
void pretrav(NODEPTR tree) {
    if (tree != NULL) {
        printf("%s\t", tree->info); // Visit root
        pretrav(tree->left);        // Visit left subtree
        pretrav(tree->right);       // Visit right subtree
    }
}

// Perform post-order traversal (left, right, root)
void posttrav(NODEPTR tree) {
    if (tree != NULL) {
        posttrav(tree->left);       // Visit left subtree
        posttrav(tree->right);      // Visit right subtree
        printf("%s\t", tree->info); // Visit root
    }
}

// Search for a given word (key) in the tree
void search(NODEPTR tree, char key[]) {
    NODEPTR p = tree; // Start searching from the root
    while (p != NULL && strcmp(key, p->info) != 0) { // Traverse until key is found or tree ends
        if (strcmp(key, p->info) < 0) // If key is smaller, move to left subtree
            p = p->left;
        else // If key is larger, move to right subtree
            p = p->right;
    }
    if (p != NULL) // Key is found
        printf("\nKey %s is found in the dictionary", key);
    else // Key is not found
        printf("\nKey %s is not found in the dictionary", key);
}
