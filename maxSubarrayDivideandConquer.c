//Divide and Conquer Soluton For Max Subarray Problem
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int *crossingSum(int arr[], int l, int m, int r){
	int sum = 0 , i , *indexesAndSum , leftBound , rightBound;
	int leftSum = INT_MIN , rightSum = INT_MIN , crossingSum;
	// this pointer will keep values of best subarray's indexes and sum.
	indexesAndSum = (int *)malloc(3*sizeof(int));
	// from mid to left side find max subarray.
	for(i=m;i>=l;i--){
		sum += arr[i];
		if(sum>leftSum){
			leftSum = sum;
			leftBound = i; // update from mid to left max subarray's left bound.
		}
	}
	
	sum = 0;
	// from mid to right side find max subarray.
	for(i=m;i<=r;i++){
		sum += arr[i];
		if(sum>rightSum){
			rightSum = sum;
			rightBound = i;
		}
	}
	// we added arr[m] to both leftsum and rightsum so we will extract it.
	crossingSum = leftSum + rightSum - arr[m];
	// return indexes and sum of subarray with max sum.
	if(leftSum<crossingSum && rightSum<crossingSum){
		indexesAndSum[0] = leftBound;
		indexesAndSum[1] = rightBound;
		indexesAndSum[2] = crossingSum;
	}
	else if(leftSum<rightSum){
		indexesAndSum[0] = m;
		indexesAndSum[1] = rightBound;
		indexesAndSum[2] = rightSum;
		
	}
	else{
		indexesAndSum[0] = leftBound;
		indexesAndSum[1] = m;
		indexesAndSum[2] = leftSum;
	}
	return indexesAndSum;
}

int *maxSubarray(int arr[] , int l , int r){
	int m , *crossIndexSum , *leftIndexSum , *rightIndexSum; 
	if(l>=r){ // if its one element.
		int *indexesAndSum = (int *)malloc(3*sizeof(int));
		indexesAndSum[0] = l;
		indexesAndSum[1] = l; 
		indexesAndSum[2] = arr[l];
		return indexesAndSum;
	}
	m = (l+r)/2;// middle point of array.
	leftIndexSum = maxSubarray(arr , l , m-1);// calculate sum and indexes of left side
	rightIndexSum = maxSubarray(arr , m+1 , r);// calculate sum and indexes of right side
	crossIndexSum = crossingSum(arr, l , m , r);// calculate crossing sum and indexes
	// return indexes and sum of subarray with max sum.
	if(leftIndexSum[2]<crossIndexSum[2] && rightIndexSum[2]<crossIndexSum[2]){
		free(rightIndexSum);
		free(leftIndexSum);
		return crossIndexSum;
	}
	else if(leftIndexSum[2]<rightIndexSum[2]){
		free(leftIndexSum);
		free(crossIndexSum);
		return rightIndexSum;
	}
	else{
		free(rightIndexSum);
		free(crossIndexSum);
		return leftIndexSum;
	}
}


int main(){
	int *arr , *indexesAndSum , i , n;
	// indexes array will take the return value of our function which finds the interval with max sum.
	printf("Please enter the number of elements in your array : ");
	scanf("%d",&n);
	arr = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		printf("Please enter %dth element : " , i);
		scanf("%d" , &arr[i]);
	}	
	indexesAndSum = maxSubarray(arr , 0 ,n-1);
	printf("Subarray with max sum : %d is in between %d - %d",indexesAndSum[2],indexesAndSum[0],indexesAndSum[1]);
	free(arr);
	free(indexesAndSum);
	return  0;
}
