/*Suppose that you are given a list of integers stored in consecutive memory locations(arrays). Perform the following operations. (Note : Use pointers)
a.	Create an array of N Integer Elements by allocating memory dynamically
b.	Display of array Elements with Suitable Headings
c.	Insert an Element (ELEM) at a given valid Position (POS)
d.	Delete an Element at a given valid Position (POS)
e.	Search an element in the array  */

#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr;                  // Pointer to store array elements
    int n, i, choice, pos, x, key, found = 0;

    // Step 1: Input size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Step 2: Dynamic memory allocation for 'n' integers
    arr = (int *)malloc(n * sizeof(int));

    // Step 3: Input array elements
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", (arr + i));

    // Step 4: Display the array elements
    printf("The elements of the array are:\n");
    for (i = 0; i < n; i++) {
        printf("*(arr+%d)=%d\n", i, *(arr + i));
    }

    // Step 5: Menu-driven operations (insert, delete, search, exit)
    while (1) {
        printf("\n1-> INSERT  2-> DELETE  3-> SEARCH  4-> EXIT\n");
        printf("Give your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Insert operation
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            printf("Enter the position to insert (1 to %d): ", n + 1);
            scanf("%d", &pos);

            // Validate position
            if (pos < 1 || pos > n + 1) {
                printf("Invalid position!\n");
                break;
            }

            // Increase memory size by 1 using realloc
            arr = realloc(arr, (n + 1) * sizeof(int));

            // Shift elements to the right from the given position
            for (i = n; i >= pos; i--)
                *(arr + i) = *(arr + i - 1);

            // Place new element at given position
            *(arr + pos - 1) = x;
            n++; // Increase array size

            // Display updated array
            printf("After insertion the array is:\n");
            for (i = 0; i < n; i++)
                printf("*(arr+%d)=%d\n", i, *(arr + i));
            break;

        case 2: // Delete operation
            printf("Enter the position of the element to be deleted (1 to %d): ", n);
            scanf("%d", &pos);

            // Validate position
            if (pos < 1 || pos > n) {
                printf("Invalid position!\n");
                break;
            }

            // Shift elements to the left to remove element
            for (i = pos; i < n; i++)
                *(arr + i - 1) = *(arr + i);

            n--; // Decrease array size

            // Display updated array
            printf("After deletion the array is:\n");
            for (i = 0; i < n; i++)
                printf("*(arr+%d)=%d\n", i, *(arr + i));
            break;

        case 3: // Search operation
            found = 0;
            printf("Enter the element to be searched: ");
            scanf("%d", &key);

            // Linear search
            for (i = 0; i < n; i++) {
                if (*(arr + i) == key) {
                    found = 1;
                    printf("Search key %d is found at position %d\n", key, i + 1);
                }
            }

            if (found == 0)
                printf("Search key %d is not found\n", key);
            break;

        case 4: // Exit
            free(arr); // Free dynamically allocated memory
            exit(0);

        default: // Wrong choice handling
            printf("Invalid choice!\n");
        }
    }
}

/*sample output
Enter the number of elements in the array:5
Enter the elements5 7 8 3 2
The elements of the array are :
*(arr+0)=5
*(arr+1)=7
*(arr+2)=8
*(arr+3)=3
*(arr+4)=2

1-> INSERT  2-> DELETE   3-> SEARCH    4->EXIT
Give your choice:1
Enter the element to be inserted:4
Enter the position to be inserted:1
After insertion, the elements of the array are :
*(arr+0)=4
*(arr+1)=5
*(arr+2)=7
*(arr+3)=8
*(arr+4)=3
*(arr+5)=2

1-> INSERT  2-> DELETE   3-> SEARCH    4->EXIT
Give your choice:2
Enter the position of the element to be deleted:3
After deletion, the elements of the array are :
*(arr+0)=4
*(arr+1)=5
*(arr+2)=8
*(arr+3)=3
*(arr+4)=2
1-> INSERT  2-> DELETE   3-> SEARCH    4->EXIT
Give your choice:3
Enter the  element to be searched:3
Search key 3 is found at position 3

1-> INSERT  2-> DELETE   3-> SEARCH    4->EXIT
Give your choice:3
Enter the  element to be searched:10
Search key 10 is not found

1-> INSERT  2-> DELETE   3-> SEARCH    4->EXIT
Give your choice:4
*/
