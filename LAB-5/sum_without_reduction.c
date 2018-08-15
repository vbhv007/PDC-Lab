#include<stdio.h>
#include<omp.h>

int main(void){
	long i, sum = 0;
	omp_set_num_threads(4);
	#pragma omp parallel for lastprivate(sum)
	for(i = 1; i < 100; i++){
		sum += i;
	}
	printf("The sum of natural number from 1 to 10 is: %d\n", sum);
	return 0;
}
