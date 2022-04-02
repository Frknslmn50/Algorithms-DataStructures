//Binary Tree Traversal Implementation
#include<stdio.h>
typedef struct node{
	int data;
	struct node *left;// sol çocuk için pointer
	struct node *right;// sað çocuk için pointer
}NODE;

void inOrderTraversal(NODE *root){//önce sol , sonra kök , sonra sað
	if(root==NULL){
		return;
	}
	inOrderTraversal(root->left);
	printf("%d\t",root->data);
	inOrderTraversal(root->right);
}

void preOrderTraversal(NODE *root){//önce kök , sonra sol , sonra sað
	if(root==NULL){
		return;
	}
	printf("%d\t",root->data);
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void postOrderTraversal(NODE *root){//önce sol , sonra sað , sonra kök
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
