#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct Queue {
	int front, rear;
	int calls[MAX];
};

void initializeQueue(struct Queue *q) {
	q->front = q->rear = -1;
}

int isFull(struct Queue *q) {
	return(q->front == (q->rear+1) % MAX);
}

int isEmpty(struct Queue *q) {
	return(q->front == -1);
}

void enqueue(struct Queue *q, int call) {
	if(isFull(q)) {
		printf("Overflow: Queue is full.\n");
	}
	else {
		if(isEmpty(q)) {
			q->front = q->rear = 0;
		}
		else {
			q->rear = (q->rear+1) % MAX;
		}
		q->calls[q->rear] = call;
		printf("Call added successfully.\n");
	}
}

void dequeue(struct Queue *q) {
	if(isEmpty(q)) {
		printf("Underflow: Queue is empty.\n");
	}
	else {
		printf("Call %d removed.\n",q->calls[q->front]);
		if(q->front == q->rear) {
			initializeQueue(q);
		}
		else {
			q->front = (q->front+1) % MAX;
		}
	}
}

void displayQueue(struct Queue *q) {
	if(isEmpty(q)) {
		printf("Queue is empty.\n");
	}
	else {
		printf("Current status of calls:\n");
		int i = q->front;
		do {
			printf("%d\n",q->calls[i]);
			i = (i+1) % MAX;
		}while(i != (q->rear+1) % MAX);
		printf("\n");
	}
}

int main() {
	struct Queue callQueue;
	initializeQueue(&callQueue);
	int choice, call;
	do {
		printf("\n--- Call Center Simulation ---\n");
		printf("1. Add a call \n2. Delete a call \n3. Display current status of calls \n4. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				printf("Enter the call number:");
				scanf("%d",&call);
				enqueue(&callQueue,call);
				break;
			case 2:
				dequeue(&callQueue);
				break;
			case 3:
				displayQueue(&callQueue);
				break;
			case 4:
				printf("Exiting the program.\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	}while(choice != 4);
	return 0;
}
