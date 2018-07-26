#include <stdio.h>
#include <omp.h>

int main(void){
	long i;
	#pragma omp parallel for schedule(static, 100)
	for (i = 0; i < 1000000; i++);
	return 0;
}
