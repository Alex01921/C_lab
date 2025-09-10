/*3) Stack is a simple linear data structure used for storing data which follows the principle of
Last In First Out. Assume that you are given the details of BOOK with members ISBN, Title,
Author and Price. Design an interactive C program to construct a stack data structure to store
N BOOK items and write C functions to perform the following operations on it: a. PUSH-To
add a new BOOK to the stack b. POP- To remove a BOOK from the stack Also demonstrate
Overflow and Underflow conditions on Stack and display the status of Stack.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5

struct BOOK {
char isbn[20];
char title[50];
char author[50];
float price;
};

struct BOOK stack[MAX];
int top = -1;

void push() {
if(top == MAX-1) {
printf("Stack  overflow! Cannot add more books.\n");
return;
}
top++;
printf("Enter Book Details:\n");
printf("ISBN:");
scanf("%s",stack[top].isbn);
printf("Title: ");
    getchar();
    fgets(stack[top].title, sizeof(stack[top].title), stdin);
    stack[top].title[strcspn(stack[top].title, "\n")] = '\0';

    printf("Author: ");
    fgets(stack[top].author, sizeof(stack[top].author), stdin);
    stack[top].author[strcspn(stack[top].author, "\n")] = '\0';

printf("Price:");
scanf("%f",&stack[top].price);
printf("Book pushed to stack successfully.\n");
}

void pop() {
if(top==-1) {
printf("Stack Underflow! No books to remove. \n");
return;
}
printf("Popped Book Details:\n");
printf("ISBN: %s \n",stack[top].isbn);
printf("Title: %s \n",stack[top].title);
printf("Author: %s \n", stack[top].author);
printf("Price: %.2f \n",stack[top].price);
top--;
}

void displayStack() {
if(top == -1) {
printf("Stack is empty.\n");
return;
}

printf("\n Current stack of Books:\n");
for(int i = top; i>=0;i--) {
printf("\n Book %d : \n", i+1);
printf("ISBN: %s \n",stack[i].isbn);
printf("Title: %s \n",stack[i].title);
printf("Author: %s \n",stack[i].author);
printf("Price: %.2f \n",stack[i].price);
}
}

int main() {
int choice;
printf("Stack Implementation for BOOKs (LIFO) \n");

while(1) {
printf("\n Menu: \n");
printf("1. PUSH \t");
printf("2. POP  \t");
printf("3. Display Stack \t");
printf("4. Exit \n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice) {
case 1: push();break;
case 2: pop();break;
case 3: displayStack();break;
case 4: printf("Exiting program \n"); exit(0);
default: printf("Invalid Choice! Try again. \n");
}
}
return 0;
}
