#include <stdio.h>
#include <omp.h>

int main(void){
	int n, i, A = 0, B = 0, C = 0, winner;
	printf("Enter n: ");
	scanf("%d", &n);
	int vote[n];
	for(i = 0; i < n; i++){
		int temp;
		scanf("%d", &temp);
		vote[i] = temp;
	}
	#pragma omp parallel num_threads(5)
	{
		#pragma omp parallel for
		for(i = 0; i < n; i++){
			if(vote[i] == 1){
				A += 1;
			}
			else if(vote[i] == 2){
				B += 1;
			}
			else if(vote[i] == 3){
				C += 1;
			}
		}
	}
	if(A > B && A > C){
		winner = 1;
	}
	else if(A < B && A > C){
		winner = 2;
	}
	else{
		winner = 3;
	}
	printf("Votes for candidate 1: %d\nVotes for candidate 2: %d\nVotes for candidate 3: %d\nWinner: Candidate %d\n", A, B, C, winner); 
	return 0;
}

	
