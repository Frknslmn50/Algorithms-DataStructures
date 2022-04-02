// Queue Implementaiton
#include<stdio.h>
#define MAX 15
int q[MAX];
int front;
int rear;
int isEmpty(){
	if(front==-1){
		return 1;
	}
	return 0;
}

int isFull(){
	if(rear==MAX-1){
		return 1;
	}
	return 0;
}

int deQueue(int *X){//Dizinin ilk elemanýndan çýkarýrýz.
	if(isEmpty()){
		return 0;
	}
	else{
		*X = q[front++];
		return 1;
	}
}

int enQueue(int value){
	if(isFull()){
		return 0;
	}
	else if(front==-1){
		front=0;
	}
	q[++rear] = value;
	return 1;
}

void initQueue(){
	front = -1,rear = -1;
}
void printQueue(){
	int i;
	printf("\nQueue : \n");
	for(i=front;i<=rear;i++){
		printf("%d\t",q[i]);
	}
	printf("\n");
}
int main(){
	int i,x,y;
	initQueue();
	for(i=0;i<10;i++){
		enQueue(i);
	}
	printQueue();
	deQueue(&x);
	printf("\nX : %d",x);
	deQueue(&y);
	printf("\nY : %d",y);
	printQueue();
	
	return 0;
}
