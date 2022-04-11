// Heap Sort Implementation
#include<stdio.h>
#define MAX 100
void heapify(int *arr,int i,int N){
	int largest,tmp;
	int left = 2*i+1;
	int right = 2*i+2;
	if((left<N) && arr[left] > arr[i]){
		largest = left;
	}
	else{
		largest = i;
	}
	if((right<N) && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest!=i){
		tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
		heapify(arr,largest,N);
	}
}
void swap(int *a,int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void heapSort(int arr[] , int n){
	int i;
	for(i=(n/2)-1;i>=0;i--){
		heapify(arr,i,n);
	}
	for(i=n-1;i>=0;i--){// I accepted 1 as the starting point of array.
		swap(&arr[0],&arr[i]);
		heapify(arr,0,i);
	}
}
int main(){
	int arr[MAX],N,i;
	printf("Enter the number of elements in array : ");
	scanf("%d",&N);
	for(i=0;i<N;i++){
		printf("Enter %dth element : ",i+1);
		scanf("%d",&arr[i]);
	}
	heapSort(arr,N);
	printf("Array after heap sort : \n");
	for(i=0;i<N;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}
