#ifndef GNUPLOT__H
#define GBUPLOT__H

void plot(double *X, double *nodes, double *values, int nodes_len, int nsteps, const char *filename);

// Create and save a plot of the lagrange interpolation polynomial with a domain of 
// values X, as a .png file.
void plot(double *X, double *nodes, double *values, int nodes_len, int nsteps, const char *filename) {
    FILE *gnuplot = popen("gnuplot", "w");
    if (!gnuplot) {
        perror("popen");
        exit(EXIT_FAILURE);
    }

    fprintf(gnuplot, "set terminal png\n");
    fprintf(gnuplot, "set output 'img/%s'\n", filename);
    fprintf(gnuplot, "set object 1 rectangle from screen 0,0 to screen 1,1 fillcolor rgb 'white' behind\n");
    fprintf(gnuplot, "set title 'Lagrange Interpolation'\n");
    fprintf(gnuplot, "plot '-' u 1:2 t 'Lagrange Interpolation' w lp lc rgb 'black'\n");

    for (int i = 0; i < nsteps; ++i) {
        fprintf(gnuplot, "%lf %lf\n", X[i], lagrange_interpolation(X[i], nodes, values, nodes_len));
    }
    fprintf(gnuplot, "e\n");

    fprintf(stdout, "Plot saved as 'img/%s'\n", filename);
    fflush(gnuplot);

    pclose(gnuplot);
}

#endif
