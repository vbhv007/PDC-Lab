#include <stdio.h>
#include <omp.h>

int is_prime(int num){
	int i, count = 0;
	for (i = 2; i < num/2; i++){
		if(num%i == 0){
			count++;
		}
	}
	if(count == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int main(void){
	int i;
	#pragma omp parallel
	{
		for(i = 1; i < 100; i++){
			if(is_prime(i)){
				printf("%d by %d\n", i, omp_get_thread_num());
			}
		}
	}
	return 0;
}
