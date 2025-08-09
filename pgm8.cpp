#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, data[4], recv;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        for (int i = 0; i < 4; i++)
            data[i] = i + 1;
    }

    MPI_Scatter(data, 1, MPI_INT, &recv, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received %d\n", rank, recv);

    recv *= 2;

    MPI_Gather(&recv, 1, MPI_INT, data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Gathered values: ");
        for (int i = 0; i < 4; i++)
            printf("%d ", data[i]);
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
