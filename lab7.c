#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char song[25];
    struct node *next;
};

typedef struct node *NODEPTR;
NODEPTR list = NULL;

/* getnode() */
NODEPTR getnode() {
    NODEPTR r;
    r = (NODEPTR)malloc(sizeof(struct node));
    if (r == NULL) {
        printf("Allocation failed\n");
        return NULL;
    }
    return r;
}

// create a list
NODEPTR create(NODEPTR list, char song[]) {
    NODEPTR p, q;
    p = getnode();
    if (p == NULL)
        return list; // in case malloc fails

    strcpy(p->song, song);
    p->next = NULL;

    if (list == NULL)
        list = p;
    else {
        for (q = list; q->next != NULL; q = q->next)
            ;
        q->next = p;
    }
    return list;
}

void playbegin(NODEPTR list) {
    if (list == NULL)
        printf("Empty playlist\n");
    else
        printf("\nPlaying %s\n", list->song);
}

void playend(NODEPTR list) {
    NODEPTR p = list;

    if (list == NULL)
        printf("Empty playlist\n");
    else {
        while (p->next != NULL)
            p = p->next;
        printf("\nPlaying %s\n", p->song);
    }
}

NODEPTR deletebegin(NODEPTR list) {
    NODEPTR p = list;

    if (list == NULL) {
        printf("\nEmpty playlist\n");
    } else {
        printf("\nSong deleted = %s\n", p->song);
        list = p->next;
        free(p);
    }
    return list;
}

NODEPTR deleteend(NODEPTR list) {
    NODEPTR p, q;
    p = list;
    q = NULL;

    if (list == NULL) {
        printf("Empty playlist\n");
    } else if (list->next == NULL) {
        printf("\nSong deleted = %s\n", p->song);
        list = p->next;
        free(p);
    } else {
        while (p->next != NULL) {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        printf("\nSong deleted = %s\n", p->song);
        free(p);
    }
    return list;
}

void display(NODEPTR list) {
    NODEPTR p;

    if (list == NULL) {
        printf("Empty list\n");
    } else {
        printf("The playlist contains:\n");
        for (p = list; p != NULL; p = p->next)
            printf("%s -> ", p->song);
        printf("NULL\n");
    }
}

int main() {
    int choice;
    char cont;
    char song[25];

    do {
        printf("\n1->CREATE PLAYLIST  2->PLAY FROM BEGINNING  3->PLAY FROM END\n");
        printf("4->DELETE FROM BEGINNING  5->DELETE FROM END  6->DISPLAY  7->QUIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("Enter a song: ");
                    scanf("%s", song);
                    list = create(list, song);
                    printf("Do you want to enter another song [Y/N]: ");
                    scanf(" %c", &cont);
                } while (cont == 'Y' || cont == 'y');
                break;

            case 2:
                playbegin(list);
                break;

            case 3:
                playend(list);
                break;

            case 4:
                list = deletebegin(list);
                break;

            case 5:
                list = deleteend(list);
                break;

            case 6:
                display(list);
                break;

            case 7:
                exit(0);

            default:
                printf("\nNo such option\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
