// Circular Queue Implementaiton
#include<stdio.h>
#define SIZE 15
int q[SIZE];
int front;
int rear;

int isEmpty(){
	if(front==-1){
		return 1;
	}
	return 0;
}

int isFull(){
	if((front==rear+1)||((front=0)&&(rear==SIZE-1))){// ya hi� kuyruk bo�almadan ful ekleyip dizi doldu
		return 1;                                    // ya da kuyru�un sonu kuyru�un ba��n�n bir arkas�na geldi(bu kuyruk ba�a d�nd���nden dolay�)
	}
	return 0;
}

int enQueue(int value){
	if(isFull()){
		return 0;
	}
	else if(front==-1){
		front=0;
	}
	rear = (rear+1)%SIZE;// Kuyruk doldu�unda ba�a d�n�p bo� yere yazmaya ba�layacak
	q[rear] = value;
	return 1;
}

int deQueue(int *X){
	if(isEmpty()){
		return 0;
	}
	else{
		*X=q[front];
		if(front==rear){// front rear � yakaladay�sa kuyruk bo� demektir bu y�zden ilk haline �eviriyoruz.
			front=-1;
			rear=-1;
		}
		else{
			front=(front+1)%SIZE;//Kuyru�un ba��ndan biz �ektik�e front dizide ilerleyip tekrar ba�a d�necek.
			return 1;
		}
	}
}

void initQueue(){
	front=-1;
	rear=-1;
}
int main(){
	return 0;	
}
