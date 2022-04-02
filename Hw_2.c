#include<stdio.h> 
#include<stdlib.h>
#include<math.h>
#define MAX 33
typedef struct{
	char item[MAX];
	int top;
}STACK;

void initStack(STACK *s){
	s->top = 0;
}

int isEmpty(STACK *s){
	if(s->top==0){
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(STACK *s){
	if(s->top==MAX){
		return 1;
	}
	else{
		return 0;
	}
}

int push(STACK *s , char x){
	if(isFull(s)){
		return 0;
	}
	else{
		s->item[s->top++] = x;
		return 1;
	}
}

int pop(STACK *s , char *x){
	if(isEmpty(s)){
		return 0;
	}
	else{
		*x = s->item[--s->top];
		return 1;
	}
}

int peek(STACK *s,char *x){
	int adr;
	if(isEmpty(s)){
		return 0;
	}
	else{
		adr = s->top-1;
		*x = s->item[adr];
		return 1;
	}
}
char *addString(char *string,char tmp,int size) {  
	if(string == NULL){ 
		string=(char*)malloc((size+1)*sizeof(char));
		string[size]='\0';
	}
	else{  
		string=(char*)realloc(string,(size+1)*sizeof(char)); 
		string[size]='\0'; 
	}  
	string[size-1]=tmp; 
	return string;
}
char *complementTwo(char *string,int size){
	int i,carry=1;
	char ones[size+1];
	for(i=0;i<size;i++){
		if(string[i]=='0'){
			ones[i] = '1';
		}
		else{
			ones[i] = '0';
		}
	}
	ones[size] = '\0';// found the one's complement.
	for(i=size-1;i>=0;i--){
		if(ones[i]=='1' && carry==1){
			string[i] = '0';
		}
		else if(ones[i]=='0' && carry==1){
			string[i] = '1';
			carry=0;
		}
		else{
			string[i] = ones[i];
		}
	}
	return string;// found the two's complement.
}
int roundBit(int num){
	if(-128<=num && num<=255){
		return 8;
	}
	else if(-32786<=num && num<=65535){
		return 16;
	}
	else if(-8388608<=num && num<=16777215){
		return 24;
	}
	else{
		return 32;
	}
}
char *convertBinary(STACK *stack,int num){  
	int i,number,digit=0,limit;
	char *string=NULL,tmp;
	number = abs(num);
	
	while(number >= 2){  
		if(number % 2 == 0){ 
			push(stack,'0');
		}
		else{ 
			push(stack,'1');
		}
		number=number/2;  
	}
	
	if(number == 0){  
		push(stack,'0');
	}
	else{  
		push(stack,'1');
	}
	i=stack->top;
	limit = roundBit(num);
	for(i;i<limit;i++){
		push(stack,'0');
	}
	while(!isEmpty(stack)){
		digit++;
		pop(stack,&tmp);
		string = addString(string,tmp,digit);
	}
	if(num<0){
		string = complementTwo(string,digit);
	}
	return string;
}

void countDigits(STACK *stack,char *buffer){
	int i=0;
	char tmp,var;
	while(buffer[i]!='\0'){
		if(isEmpty(stack)){
			push(stack,buffer[i]);
		}
		else{
			peek(stack,&tmp);
			if(buffer[i]==tmp){
				push(stack,buffer[i]);
			}
			else{
				pop(stack,&var);
			}
		}
		i++;
	}
	if(peek(stack,&tmp)){
		if(tmp=='0'){
			printf("\n0'lar daha fazladir.Ek %d adet 1 gereklidir.\n",stack->top);
		}
		else{
			printf("\n1'ler daha fazladir.Ek %d adet 0 gereklidir.\n",stack->top);
		}
	}
	else{
		printf("\n0 ve 1'ler esit sayidadir.\n");
	}
}

int main(){
	STACK *stack=(STACK*)malloc(sizeof(STACK));
	initStack(stack);
    int num;
    char *buffer;
    printf("Bir sayi giriniz : "); 
    scanf("%d",&num);
	buffer = convertBinary(stack,num);
	printf("Girilen sayinin binary gosterimi : ");
	printf("%s\n",buffer);
    countDigits(stack,buffer);
  return 0; 
} 
