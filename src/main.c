#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "interpolation.h"
#include "ReadCSV.h"
#include "split.h"
#include "gnuplot_.h"

// function returns pointer of array containing equal distant doubles
// with step size (x_end - x_start)/numofsteps
double * linspace(double x_start, double x_end, int numofsteps) {
    double * array = malloc(numofsteps*sizeof(double));
    
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed for linspace array.\n");
        exit(EXIT_FAILURE);
    }

    double step = (x_end - x_start)/(numofsteps -1);

    for (int iargs = 0; iargs < numofsteps; iargs++) {
        array[iargs] = x_start + iargs*step;
    }

    return array;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];

    double * column1 = NULL;
    double * column2 = NULL;

    struct data_frame df = readCSV(filename, &column1, &column2);

    if (df.rowCount < 2) {
        fprintf(stderr, "Error: There must be at least 2 data points.\n");
        return EXIT_FAILURE;
    }
    

    // data preview
    int MAX_PRINTABLE_ROWS = 6;
    int max_printable_rows;

    if (df.rowCount > MAX_PRINTABLE_ROWS) {
        max_printable_rows = MAX_PRINTABLE_ROWS;
    } else {
        max_printable_rows = df.rowCount;
    }

    fprintf(stdout, "Data read successfully\n");
    
    fprintf(stdout, "Nodes:  Values:\n");

    for (int i = 0; i < max_printable_rows; i++) {
        fprintf(stdout, "%.2f    %.2f\n", df.column1[i], df.column2[i]);
    }

    fprintf(stdout, "Initializing Lagrange Interpolation\n");


    //Gnuplot stuff
    int nsteps = 100;

    double *X = linspace(df.column1[0], df.column1[df.rowCount-1], nsteps);

    if (X == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for linspace array.\n");
        return EXIT_FAILURE;
    }
    
    fprintf(stdout, "Creating plot\n");

    char *imgfilename = split(filename);

    strcat(imgfilename, ".png");

    plot(X, df.column1, df.column2, df.rowCount, nsteps, imgfilename);

    free(X);
    free(df.column1);
    free(df.column2);

    return EXIT_SUCCESS;
}
