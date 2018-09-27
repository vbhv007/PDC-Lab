#include<stdio.h>
#include<mpi.h>

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

int is_armstrong(int num){
	int sum = 0, rem = 0, cube = 0, temp;
	temp = num;
	while (num != 0){
		rem = num % 10;
		cube = rem*rem*rem;
		sum = sum + cube;
		num = num / 10;
	}
	if (sum == temp){
		return 1;
	}
	else{
		return 0;
	}
}

int main(int argc, char *argv[]){
	MPI_Init(&argc, &argv);
	int rank, size;
	char prime, armstrong;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        int number;
        if (rank == 0){
                number = 1399;
                MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("The number %d is sent by process %d\n", number, rank);
        }
        else if (rank == 1){
                MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("The number %d is recieved by process %d, Checking if the number is prime\n", number, rank);
		if (is_prime(number)){
			prime = 'Y';
			printf("The number %d is prime\n", number);
		}
		else{
			prime = 'N';
			printf("The number %d is not prime\n", number);
		}
		MPI_Send(&prime, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
		if (is_armstrong(number)){
			armstrong = 'Y';
                        printf("The number %d is armstrong\n", number);
                }
                else{
			armstrong = 'N';
                        printf("The number %d is not armstrong\n", number);
                }
                printf("The number %d is sent by process %d\n", number, rank);
        }
	else if (rank == 2){
		MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("The number %d is recieved by process %d, Checking if the number is armstrong\n", number, rank);
		if (is_armstrong(number)){
			printf("The number %d is armstrong\n", number);
		}
		else{
			printf("The number %d is not armstrong\n", number);
		}
	}
        MPI_Finalize();
	return 0;
}
