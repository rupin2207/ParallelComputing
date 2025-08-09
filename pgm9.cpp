#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, val, max, min, sum, prod;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    val = rank + 1;

    MPI_Reduce(&val, &max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Reduce(&val, &min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&val, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&val, &prod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Max: %d\nMin: %d\nSum: %d\nProduct: %d\n", max, min, sum, prod);
    }

    MPI_Finalize();
    return 0;
}