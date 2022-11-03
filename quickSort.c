#include<stdio.h>
void quickSort(int A[], int l, int r){
	if(l < r){
		int s = partition(A, l, r); // first, determine the right position of pivot and place it, return the index of pivot.
		quickSort(A, l, s-1); // do it for left side until one element is left.
		quickSort(A, s+1, r); // do it for right side.
	}
}
int partition(int A[], int l, int r){
	int pivot, i, j, tmp, pivot_index;
	pivot = A[l]; // choose first element as a pivot
	i = l+1; // start an index from the second element 
	j = r; // start an index from the last element
	while(i < j){
		while(i < j && A[i] < pivot){
			i++; // as long as indexes didn't meet and indexed element is smaller than pivot increment index.
		}
		while(i < j && A[j] >= pivot){
			j--; // as long as indexes didn't meet and indexed element is larger or equal than pivot decrement index.
		}
		if(i < j){ // if indexes didn't meet swap the element larger than pivot (A[i]) with smaller than pivot (A[j]).
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;	
		}
	}// if indexes met then we're done with swapping elements.
	tmp = A[i-1]; // here we place the pivot in it's position where left elements are smaller and right elements are bigger than pivot.
	A[i-1] = pivot;
	pivot_index = i-1; 
	A[l] = tmp;
	return pivot_index;
}
int main(){
	int i;
	int arr[8] = {5,3,1,4,2,8,9,7};
	quickSort(arr, 0, 7);
	for(i=0;i<8;i++){
		printf("A[%d] = %d\n", i, arr[i]);
	}	
	return 0;
}
