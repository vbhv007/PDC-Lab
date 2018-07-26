#include <stdio.h>
#include <omp.h>

int main(void){
	int i;
	#pragma omp parallel for schedule(static, 10)
	for (i = 0; i< 100; i++){
		printf("Iteration %d by %d\n", i, omp_get_thread_num());
	}
	return 0;
}
