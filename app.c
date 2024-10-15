#include "matrix.h"
#include "matrix_io.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct matrix mat;
    struct matrix mat2;
    // Lire la matrice à partir d'un fichier
    if (read_matrix_from_file("matrix.txt", &mat))
    {
        printf("Matrice lue :\n");
        print_matrix(&mat);
    }
    if (read_matrix_from_file("matrix.txt", &mat2))
    {
        printf("Matrice lue :\n");
        print_matrix(&mat2);
    }
    /* 
    // Libérer la mémoire
    free_matrix(&mat);
    free_matrix(&mat2);
    // Initialiser une matrice (exemple avec des valeurs fixes)
    init_matrix(&mat, 3, 4);
    init_matrix(&mat2, 3, 4);
    // Remplir la matrice avec des valeurs
    int values[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat.m[i][j] = values[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat2.m[i][j] = values[i][j];
        }
    }
    */
    struct matrix somme; 
    somme = addition(&mat,&mat2);

    // Écrire la matrice dans un fichier
    if (write_matrix_to_file("output_matrix.txt", &somme))
    {
        printf("Matrice écrite dans le fichier 'output_matrix.txt'\n");
    }
    else{
        printf("La matrice n'a pas pus être crée");
    }
    printf("%i",is_triangular(&somme));
    // Libérer la mémoire
    free_matrix(&somme);
    free_matrix(&mat);
    free_matrix(&mat2);
    
    return 0;
}
