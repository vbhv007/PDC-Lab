#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main()
{
	int i,n = 0,votes[100],candidate_1=0,candidate_2=0,candidate_3=0, v;
	printf("Enter the number of voters: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
        printf("Enter vote number %d: ", i + 1);
        scanf("%d", &v);
        votes[i] = v;
    }

	#pragma omp parallel for
	for(i=0;i<n;i++)
	{
		#pragma omp critical
	        {
			if(votes[i]==0)
			candidate_1=candidate_1+1;
			else if(votes[i]==1)
			candidate_2=candidate_2+1;
			else
			candidate_3=candidate_3+1;
        	}
    	}
	printf("The number of votes for candiadte one: %d\n",candidate_1);
	printf("The number of votes for candidate two: %d\n",candidate_2);
	printf("The number of votes for candidate three: %d\n",candidate_3);
	if(candidate_1>candidate_2 && candidate_1>candidate_3)
	printf("\nCandidate One is the winner\n");
	else if(candidate_1<candidate_2 && candidate_1>candidate_3)
	printf("\nCandidate Two is the winnner\n");
	else
	printf("\nCandidate Three is the winner\n");
}
