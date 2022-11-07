// Brute Force Soluton For Max Subarray Problem
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int *findIntervalWithMaxSum(int arr[], int n){
	int maxSum = INT_MIN;
	int i , j , sum ,*indexesAndSum;
	indexesAndSum = (int *)malloc(3*sizeof(int));
	// for each subarray starting from ith element.
	for(i=0;i<n;i++){
		sum = 0;
		// for each subarray in between i and j.
		for(j=i;j<n;j++){
			sum += arr[j];
			// if current subarray's sum is larger than maxSum update it.
			if(sum>maxSum){
				maxSum = sum;
				indexesAndSum[0] = i; // current subarray with largest sum's starting point.
				indexesAndSum[1] = j; // ending point.
			}
		}
	}
	indexesAndSum[2] = maxSum;
	return indexesAndSum;
}
int main(){
	int *arr ,*indexesAndSum, i , n;
	// indexes array will take the return value of our function which finds the interval with max sum.
	printf("Please enter the number of elements in your array : ");
	scanf("%d",&n);
	arr = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		printf("Please enter %dth element : " , i);
		scanf("%d" , &arr[i]);
	}
	indexesAndSum = findIntervalWithMaxSum(arr , n);
	printf("Subarray with max sum = %d is between %d - %d" ,indexesAndSum[2] , indexesAndSum[0] , indexesAndSum[1]);
	free(arr);
	free(indexesAndSum);
	return 0;
}
