//Fast Linked List Implementation
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct node{
	int data;
	struct node *next;
	struct node *below;
}NODE;
int randInt(int limit){
	return (1+rand()%limit);
}
NODE *createNode(){
	NODE *node;
	node = (NODE *)malloc(sizeof(NODE));
	node->next = NULL;
	node->below = NULL;
	return node;
}
NODE *randomList(NODE *head , int n){
	int i=0,j,randint, limit = ((n+1)/2),top=0;
	NODE *prev , *p , *curr,*head_new = createNode();
	head_new->below = head;
	prev = head_new;
	p = head;
	while(i<limit){
		randint = randInt((n-top)/(limit-i));
		top+=randint;
		curr = createNode();
		for(j=0;j<randint;j++){
			p = p->next;
		}
		curr->data = p->data;
		curr->below = p;
		prev->next = curr;
		prev = curr;
		i++;
	}
	return head_new;
}
NODE *constructList(NODE *head , int n){
	NODE *head_new;
	if(n<=1){
		return head;
	}
	head_new = randomList(head,n);
	return constructList(head_new,((n+1)/2));
}
void printList(NODE *head){
	NODE *tmp,*p;
	p = head;
	for(p;p!=NULL;p=p->below){
		printf("\n");
		tmp = p->next;
		for(tmp;tmp!=NULL;tmp=tmp->next){
			printf("%d\t",tmp->data);
		}	
	}
	printf("\n");
}
int inputList(NODE *head){
	int i,n;
	NODE *curr,*prev;
	prev = head;
	printf("Dizideki eleman sayisini giriniz : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		curr = createNode();
		printf("%d. elemanin degerini giriniz : ",i+1);
		scanf("%d",&curr->data);
		prev->next = curr;
		prev = curr;
	}
	return n;
}
int listLevel(NODE *head){
	int count=0;
	NODE *p=head;
	while(p!=NULL){
		p = p->below;
		count++;
	}
	return count;
}
int searchElement(NODE *head,int data){
	NODE *prev=head, *curr=head->next;
	int level = listLevel(head);
	printf("Aranacak elemani giriniz : ");
	scanf("%d",&data);
	while(prev!=NULL){
		if(curr!=NULL){
			if(curr->data==data){
				return level;
			}
			else if(curr->data<data){
				prev = curr;
				curr = curr->next;
			}
			else{
				prev = prev->below;
				if(prev!=NULL){
					curr = prev->next;
					level--;	
				}
			}
		}
		else{
			prev = prev->below;
			if(prev!=NULL){
				curr = prev->next;
				level--;	
			}
		}
	}
	return -1;
}
void addElement(NODE *head){
	NODE *prev=head, *curr=head->next,*node;
	int data;
	printf("Eklenecek elemanin degerini giriniz : ");
	scanf("%d",&data);
	node = createNode();
	node->data = data;
	while(curr!=NULL && curr->data<data){
		prev = curr;
		curr = curr->next;
	}
	prev->next = node;
	node->next = curr;
}
int deleteElement(NODE *head){
	NODE *prev=head , *curr=head->next;
	int data;
	printf("Silinecek elemanin degerini giriniz : ");
	scanf("%d",&data);
	while(curr!=NULL && curr->data!=data){
		prev = curr;
		curr = curr->next;
	}
	if(curr!=NULL){
		prev->next = curr->next;
		free(curr);
		return 1;
	}
	else{
		return 0;
	}
}
void freeList(NODE *head){
	NODE *next_head=head,*curr,*next;
	while(next_head!=NULL){
		curr = next_head;
		while(curr!=NULL){
			next = curr->next;
			free(curr);
			curr = next;
		}
		next_head = next_head->below;
	}
}
int main(){
	NODE *head_constructed,*head_base = createNode();
	int n,data,level,secim=1;
	srand(time(0));
	n = inputList(head_base);
	printf("Girilen liste :\n");
	printList(head_base);
	head_constructed = constructList(head_base,n);
	printf("Insa edilen liste :\n");
	printList(head_constructed);
	while(secim!=0){
		printf("Yapmak istediginiz islemi seciniz :\nListede eleman arama : (1)\nListeye eleman ekleme : (2)\nListeden eleman silme : (3)\nProgrami sonlandirmak icin : (0)\n");
		scanf("%d",&secim);
		if(secim==1){
			level = searchElement(head_constructed,data);
			if(level==-1){
				printf("Aradiginiz eleman bulunamadi!\n");
			}
			else{
				printf("Aranan eleman %d. seviyede bulundu\n",level);
			}
		}
		else if(secim==2){
			addElement(head_base);
			head_constructed = constructList(head_base,++n);
			printf("Eleman ekleme sonucu insa edilen liste : \n");
			printList(head_constructed);
		}
		else if(secim==3){
			if(deleteElement(head_base)){
				head_constructed = constructList(head_base,--n);
				printf("Eleman basariyla silinmistir.\nEleman silme islemi sonucu elde edilen liste : \n");
				printList(head_constructed);
			}
			else{
				printf("Silmek istediginiz eleman listede bulunmamaktadir!\n");
			}
		}
	}
	freeList(head_constructed);
	return 0;
}
