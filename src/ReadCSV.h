#ifndef READCSV_H
#define READCSV_H



struct data_frame {
    double * column1;
    double * column2;
    int rowCount;
};


// reads and saves a two column .csv file into two arrays.
struct data_frame readCSV(char *filename, double **column1, double **column2) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[100]; // Adjust the buffer size according to your needs

    // Read and discard the header if there is one
    fgets(line, sizeof(line), file);
    
    int rows = 0;
    int *rowCount = &rows;


    while (fgets(line, sizeof(line), file) != NULL) {

        *column1 = realloc(*column1, (*rowCount + 1) * sizeof(double));
        if (*column1 == NULL) {
            fprintf(stderr, "Memory allocation failed for column1.\n");
            exit(EXIT_FAILURE);
        }

        *column2 = realloc(*column2, (*rowCount + 1) * sizeof(double));
        if (*column2 == NULL) {
            fprintf(stderr, "Memory allocation failed for column2.\n");
            exit(EXIT_FAILURE);
        }


        char *token = strtok(line, ",");
        if (token != NULL){
            (*column1)[*rowCount] = atof(token);
        } else {
            fprintf(stderr, "Error: Unexpected end of line in the CSV file.\n");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            (*column2)[*rowCount] = atof(token);
        } else {
            fprintf(stderr, "Error: Unexpected end of line in the CSV file.\n");
            exit(EXIT_FAILURE);
        }

        (*rowCount)++;
    }

    fclose(file);
    
    struct data_frame df;
    df.column1 = *column1;
    df.column2 = *column2;
    df.rowCount = *rowCount;

    return df;
}

#endif
