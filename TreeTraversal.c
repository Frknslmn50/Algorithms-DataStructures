//Binary Tree Traversal Implementation
#include<stdio.h>
typedef struct node{
	int data;
	struct node *left;// sol �ocuk i�in pointer
	struct node *right;// sa� �ocuk i�in pointer
}NODE;

void inOrderTraversal(NODE *root){//�nce sol , sonra k�k , sonra sa�
	if(root==NULL){
		return;
	}
	inOrderTraversal(root->left);
	printf("%d\t",root->data);
	inOrderTraversal(root->right);
}

void preOrderTraversal(NODE *root){//�nce k�k , sonra sol , sonra sa�
	if(root==NULL){
		return;
	}
	printf("%d\t",root->data);
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void postOrderTraversal(NODE *root){//�nce sol , sonra sa� , sonra k�k
	if(root==NULL){
		return;
	}
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	printf("%d\t",root->data);
}
int main(){
	return 0;
}
