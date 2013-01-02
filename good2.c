#include <stdio.h>
#include <mpi.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv) {
	const int N = 10;
	int nprocs = -1;
	int rank = -1;
	int i;

	MPI_Status status;
	MPI_Request request;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	srand(time(NULL) + rank);

	if (rank == 0) {
		int finished[N], data[N];

		for(i=1; i<nprocs; i=i+1) {
			MPI_Recv(&(finished[i]), 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
			printf("Master: %d finished execution\n", finished[i]);
		}
		MPI_Barrier(MPI_COMM_WORLD);
		for(i=1; i<nprocs; i=i+1)
			MPI_Recv(&(data[i]), 1, MPI_INT, finished[i], 0, MPI_COMM_WORLD, &status);
		
		printf("The data is: ");
		for(i=1; i<nprocs; i=i+1)
			printf("%d ", data[i]);
		printf("\n"); 
	}else{
		int data = rand() % 10000000;
		printf("Client %d: the data is %d\n", rank, data);
		for(i=0; i<data; i=i+1);
		MPI_Send(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);
		MPI_Send(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}
