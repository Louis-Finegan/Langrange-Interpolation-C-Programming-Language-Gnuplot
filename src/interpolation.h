#ifndef LAGRANGE_INTERPOLATION_H
#define LAGRANGE_INTERPOLATION_H

double lagrange_basis_polynomial(double x_val, double nodes_x[], int index_xj, int nodes_len) {
    double polynomial = 1.0;

    for (int i = 0; i < nodes_len; i++) {
        if ( i != index_xj ) {
            polynomial *= (x_val - nodes_x[i])/(nodes_x[index_xj] - nodes_x[i]);
        }
    }
    return polynomial;
}

double lagrange_interpolation(double x_val, double nodes_x[], double nodes_y[], int nodes_len) {
    double estimate = 0.0;

    for (int j = 0; j < nodes_len; j++) {
        estimate += nodes_y[j]*lagrange_basis_polynomial(x_val, nodes_x, j, nodes_len);

    }
    return estimate;
}

#endif
