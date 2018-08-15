#include<stdio.h>
#include<omp.h>

int main(void){
	omp_set_num_threads(4);
	long i, sum = 0;
	#pragma omp parallel for reduction(+:sum)
	for(i = 10000; i < 20000; i++){
		sum += i;
	}
	printf("Sum of the natural numbers from 10000 and 20000 is: %d\n", sum); 
	return 0;
}

