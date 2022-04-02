#include<stdio.h>
#define MAX 10
typedef struct{
	int item[MAX];// stack'in dizi ile implemente edilmesi
	int top;//stackde ka� eleman oldu�unu tutan de�i�ken
}STACK;

void initStack(STACK *s){
	s->top = 0; // ba�lang��ta eleman olmad��� i�in 
}

int isEmpty(STACK *s){
	if(s->top==0){
		return 1;// stack bo� ise 1 yan� true anlam�nda bir de�er d�nd�r�yor.
	}
	else{
		return 0;// stack dolu ise 0 d�nd�r�yor.
	}
}

int isFull(STACK *s){
	if(s->top==MAX){
		return 1;// Max dizinin yani stack'in boyutu, �u an stackteki eleman say�s� max a e�it ise stack doludur.
	}
	else{
		return 0;
	}
}

int push(STACK *s , int x){
	if(isFull(s)){
		return 0;//push i�lemi ba�ar�s�z ��nk� stack dolu
	}
	else{
		s->item[s->top++] = x;// �nce stack'e eleman� push ediyoruz sonra top de�erini 1 artt�r�yoruz.
		return 1;
	}
}

int pop(STACK *s , int *x){
	if(isEmpty(s)){
		return 0;// pop yapam�yoruz ��nk� stack bo�
	}
	else{
		*x = s->item[--s->top];// �nce top'u bir azalt�yoruz stackteki son eleman� g�rmek i�in sonra x'e son eleman� at�yoruz.
		return 1;
	}
}

int peek(STACK *s,int *x){// stack'in en �st�ndeki eleman�n de�erini almak i�in bir fonksiyon.
	int adr;
	if(isEmpty(s)){
		return 0;// stack bo� oldu�u i�in de�eri alamd�k.
	}
	else{
		adr = s->top-1;
		*x = s->item[adr];
		return 1;
	}
}
int main(){
	return 0;
}
