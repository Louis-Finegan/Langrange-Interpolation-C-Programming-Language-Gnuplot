#ifndef SPLIT_H
#define SPLIT_H


char *split(char *filename);

char *split(char *filename) {
    const char delimiter1 = '/';
    char *lastSlash = strrchr(filename, delimiter1);

    if (lastSlash != NULL) {
        // Move the pointer to the character after the last "/"
        lastSlash++;
    } else {
        // If no "/" set lastSlash to the beginning of the string
        lastSlash = filename;
    }

    const char delimiter2 = '.';
    char *dot = strchr(lastSlash, delimiter2);

    if (dot != NULL) {
      // Null-terminate the string at the "." character
      *dot = '\0';
    }

    return lastSlash;
}

#endif
