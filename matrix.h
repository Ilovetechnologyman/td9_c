#ifndef MATRIX_H
#define MATRIX_H
typedef struct matrix
{
    int **m;   // Matrice dynamique (pointeur vers pointeurs)
    int lines; // Nombre de lignes
    int cols;  // Nombre de colonnes
} matrix;

#endif