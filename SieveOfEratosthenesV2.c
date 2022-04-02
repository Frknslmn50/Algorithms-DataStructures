#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int *arr,i,i_square,j,n,limit;
	printf("What number do you want to find prime numbers up to ? ");
	scanf("%d",&n);
	arr = (int *)malloc((n+1)*sizeof(int));
	
	for(i=1;i<=n;i=i+=2){
		arr[i] = 0;
	}
	arr[2] = 0;
	
	for(i=4;i<=n;i+=2){
		arr[i] = 1;
	}
	
	limit = sqrt(n);
	for(i=3;i<=limit;i+=2){
		if(arr[i]==0){
			i_square = i*i;
			for(j=i_square;j<=n;j+=i){
				arr[j] = 1;
			}
		}
	}
	
	for(i=2;i<=n;i++){
		if(arr[i] == 0){
			printf("%d is prime\n",i);
		}
	}
	return 0;
}
