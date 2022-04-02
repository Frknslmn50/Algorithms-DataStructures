#include<stdio.h>
#define MAX 10
typedef struct{
	int item[MAX];// stack'in dizi ile implemente edilmesi
	int top;//stackde kaç eleman olduğunu tutan değişken
}STACK;

void initStack(STACK *s){
	s->top = 0; // başlangıçta eleman olmadığı için 
}

int isEmpty(STACK *s){
	if(s->top==0){
		return 1;// stack boş ise 1 yanş true anlamında bir değer döndürüyor.
	}
	else{
		return 0;// stack dolu ise 0 döndürüyor.
	}
}

int isFull(STACK *s){
	if(s->top==MAX){
		return 1;// Max dizinin yani stack'in boyutu, şu an stackteki eleman sayısı max a eşit ise stack doludur.
	}
	else{
		return 0;
	}
}

int push(STACK *s , int x){
	if(isFull(s)){
		return 0;//push işlemi başarısız çünkü stack dolu
	}
	else{
		s->item[s->top++] = x;// önce stack'e elemanı push ediyoruz sonra top değerini 1 arttırıyoruz.
		return 1;
	}
}

int pop(STACK *s , int *x){
	if(isEmpty(s)){
		return 0;// pop yapamıyoruz çünkü stack boş
	}
	else{
		*x = s->item[--s->top];// önce top'u bir azaltıyoruz stackteki son elemanı görmek için sonra x'e son elemanı atıyoruz.
		return 1;
	}
}

int peek(STACK *s,int *x){// stack'in en üstündeki elemanın değerini almak için bir fonksiyon.
	int adr;
	if(isEmpty(s)){
		return 0;// stack boş olduğu için değeri alamdık.
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
