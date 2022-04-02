/*Sieve of Eratosthenes implementation (my version , it might be not optimized but I figured it out myself)*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int x , *arr , i , j;
	printf("Enter a positive integer and program will measure and tell the prime ones till that integer : ");
	scanf("%d",&x);
	arr = (int*)calloc((x+1),sizeof(int)); // calloc automatically allocate x*intsize memory and fill it with 0's.
	arr[1] = 1; // Because 1 isn't prime.
	i = 2;
	while((i*i)<=x){
		if(arr[i] == 0){
			j = x/i;
			while((i*i)<=(i*j)){
				if(arr[j] == 0){
					arr[i*j] = 1;
				}
				j=j-1;
			}
		}
		i=i+1;
	}
	printf("The prime numbers are marked with '0' and non-primes with '1' :\n");
	for(i=1;i<=x;i++){
		printf("%d -> %d\t",i,arr[i]);
		if(arr[i]==0){
			printf("is Prime number");
		}
		printf("\n");
	}
	return 0;
}
