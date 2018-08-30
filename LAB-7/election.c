#include <stdio.h>
#include <omp.h>

int main(void){
	int n, i, A = 0, B = 0, C = 0;
	printf("Enter n: ");
	scanf("%d", &n);
	#pragma omp parallel num_threads(5)
	{
		#pragma omp parallel for
		for(i = 0; i < n; i++){
			int temp;
			scanf("%d", &temp);

	
