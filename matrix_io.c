#include "matrix.h"
#include "matrix_io.h"
#include <stdio.h>
#include <stdlib.h>

void init_matrix(struct matrix *mat, int lines, int cols)
{
    mat->lines = lines;
    mat->cols = cols;

    // Allocation des lignes (tableau de pointeurs)
    mat->m = (int **)malloc(lines * sizeof(int *));

    // Allocation des colonnes pour chaque ligne
    for (int i = 0; i < lines; i++)
    {
        mat->m[i] = (int *)malloc(cols * sizeof(int));
    }
}

void print_matrix(struct matrix *mat)
{
    for (int i = 0; i < mat->lines; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            printf("%d ", mat->m[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(struct matrix *mat)
{
    for (int i = 0; i < mat->lines; i++)
    {
        free(mat->m[i]); // Libère chaque ligne
    }
    free(mat->m); // Libère le tableau de pointeurs
}

// Fonction pour lire la matrice à partir d'un fichier
int read_matrix_from_file(const char *filename, struct matrix *mat)
{
    FILE *flot = fopen(filename, "r");
    if (!flot)
    {
        printf("Impossible d'ouvrir le fichier %s\n", filename);
        return 0;
    }

    // Lire les dimensions de la matrice
    fscanf(flot, "%d %d", &mat->lines, &mat->cols);

    // Initialiser la matrice avec les dimensions lues
    init_matrix(mat, mat->lines, mat->cols);

    // Lire les valeurs de la matrice
    for (int i = 0; i < mat->lines; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            fscanf(flot, "%d", &mat->m[i][j]);
        }
    }

    fclose(flot);
    return 1;
}
int write_matrix_to_file(const char *filename, struct matrix *mat)
{
    FILE *flot = fopen(filename, "w");
    if (!flot)
    {
        printf("Impossible d'écrire le fichier %s\n", filename);
        return 0;
    }

    // Lire les dimensions de la matrice
    fprintf(flot, "les dimensions de la matrice sont :%d %d \n", mat->lines, mat->cols);

    // Lire les valeurs de la matrice
    for (int i = 0; i < mat->lines; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            fprintf(flot, "%d ", mat->m[i][j]);
        }
        fprintf(flot, "\n");
    }
    fclose(flot);
    return 1;
}

matrix addition(struct matrix *mat1,struct matrix *mat2){
    struct matrix resultat;
    init_matrix(&resultat, mat1->lines, mat1->cols);
    for (int i = 0; i < mat1->lines; i++)
    {
        for (int j = 0; j < mat1->cols; j++)
        {
            resultat.m[i][j]= mat1->m[i][j]+mat2->m[i][j];
        }
    }
    return resultat;
}

int is_triangular(struct matrix *mat){
	int i,j;
    int ph=0;
    int pb=0;
	if (mat->lines != mat->cols){
		return 0; //la matrice n'est pas carré 
	}
    //on regarde la partie haute,
	for(i=0;i<(mat->lines)-1;i++){
		for(j=1+i;j<(mat->lines);j++){
            if(mat->m[i][j] != 0){
                printf("pas haute \n");
                ph = 1;
			}
		}
	}
    //on regarde la partie basse, 	
    for(j=0;j<mat->lines;j++){
		for(i=(mat->lines)-1;i>j;i--){
            if(mat->m[i][j] != 0){
                printf("pas basse \n");
                pb = 1;
			}
		}
	}
    //resulat : 
    if(pb==ph){
        if(ph==1){
            return 1; //matrice diagonale
        }
            return 0; //matrice non trianguraire
    }
    if(pb ==1){
        return 2; //matrice triangualaire en bas
    }
    return 3; //matrice triangulaire en haut 
}
// Fonction pour écrire la matrice dans un fichier
