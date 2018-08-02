#include <stdio.h>
#include <omp.h>

int main(void){
	int i, j;
	#pragma omp parallel for collapse(2)
	for(i = 0; i < 10; i++){
		for(j = 0; j < 4; j++){
			printf("I = %d, J = %d, T = %d\n", i, j, omp_get_thread_num());
		}
	}
}
