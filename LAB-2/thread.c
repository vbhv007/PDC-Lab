#include<stdio.h>
#include<omp.h>

int is_prime(int num){
	int counter = 0, i;
	for(i = 2; i < num; i++){
		if(num%i == 0){
			counter++;
		}
	}
	if(counter == 0){
		return 1;
	}
	else{
		return 0;
	}
}

main(void){
	int diff = 0;
	#pragma omp parallel
	{
		int i, first = 2, temp = 0;
		#pragma omp parallel for
		for(i = 3; i < 5000; i++){
			if(is_prime(i)){
				temp = i - first;
				first = i;
				if(temp > diff){
					diff = temp;
				}
			}		
		}
	}
	printf("%d\n", diff);
}

