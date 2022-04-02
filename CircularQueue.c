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
	if((front==rear+1)||((front=0)&&(rear==SIZE-1))){// ya hiç kuyruk boþalmadan ful ekleyip dizi doldu
		return 1;                                    // ya da kuyruðun sonu kuyruðun baþýnýn bir arkasýna geldi(bu kuyruk baþa döndüðünden dolayý)
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
	rear = (rear+1)%SIZE;// Kuyruk dolduðunda baþa dönüp boþ yere yazmaya baþlayacak
	q[rear] = value;
	return 1;
}

int deQueue(int *X){
	if(isEmpty()){
		return 0;
	}
	else{
		*X=q[front];
		if(front==rear){// front rear ý yakaladayýsa kuyruk boþ demektir bu yüzden ilk haline çeviriyoruz.
			front=-1;
			rear=-1;
		}
		else{
			front=(front+1)%SIZE;//Kuyruðun baþýndan biz çektikçe front dizide ilerleyip tekrar baþa dönecek.
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
