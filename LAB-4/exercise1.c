#include <stdio.h>
#include <omp.h>

int is_prime(int num){
	int i, counter = 0;
	for(i = 2; i < num/2; i++){
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

int sum_digits(int num){
	int sum = 0;
	while(num > 0){
		sum += num%10;
		num = num/10;
	}
	return sum;
}

int main(void){
	int i, total = 0;
	#pragma omp parallel for schedule(static, 100)
	for(i = 1000; i <= 2000; i++){
		int s = sum_digits(i);
		if(is_prime(s)){
			printf("The sum of %d is %d and is prime with thread no %d\n", i, s, omp_get_thread_num());
			total++;
		}
	}
	printf("Total primes = %d\n", total);
}
