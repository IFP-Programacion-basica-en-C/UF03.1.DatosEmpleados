/*  Autor: PAULA MARTINS DE SOUSA       Fecha de creación: 16/12/2022  */

/*
**  ENUNCIADO DEL PROGRAMA
**  Hacer un programa en C, que sea capaz de leer el fichero
de texto datosEmpleado.txt y lo almacene en una estructura definida a continuación.
Debes crear un array de esta estructura de dimensión máxima de 100.

**
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXCADENA 20
#define MAXTRABAJADORES 100

typedef struct
{
    char nombre[MAXCADENA];
    char apellidos[MAXCADENA];
    int edad;
    char departamento[MAXCADENA];
} TRABAJADOR;

void importarDatos(FILE *, TRABAJADOR[], int *);
int calculoLineasFichero(FILE *);
void mostrarDatos(TRABAJADOR[], int);

int main()
{
    TRABAJADOR trabajador[MAXTRABAJADORES];
    int numE = 0;

    FILE *f;

    f = fopen("datosEmpleado.txt", "r");
    if (f == NULL)
    {
        puts("Error: No se encontró el archivo.");
    }
    else
    {

        printf("\nPulsa un tecla para importar los datos de empleados.");
        getch();
        importarDatos(f, trabajador, &numE);
        printf("\nSe han importado %d datos de empleados.", numE);
        printf("\nPulsa una tecla para mostrar los datos importados.");
        getch();

        mostrarDatos(trabajador, numE);
        printf("\nTOTAL TRABAJADORES: %d\n", numE);

        fclose(f);
    }

    printf("\n");
    system("pause");
    return 0;
}

void importarDatos(FILE *f, TRABAJADOR trabajador[], int *numE)
{
    int i = 0;
    char edadAux[10];
    *numE = calculoLineasFichero(f);

    for (i = 0; i < *numE; i++)
    {
        fgets(trabajador[i].nombre, MAXCADENA, f);
        eliminaBarraN(trabajador[i].nombre);
        fgets(trabajador[i].apellidos, MAXCADENA, f);
        eliminaBarraN(trabajador[i].apellidos);
        fgets(edadAux, MAXCADENA, f);
        trabajador[i].edad = atoi(edadAux);
        fgets(trabajador[i].departamento, MAXCADENA, f);
        eliminaBarraN(trabajador[i].departamento);
    }
    
}

int calculoLineasFichero(FILE *f)
{
    int numLineas = 0;
    char car;
    while ((car = fgetc(f)) != EOF)
    {
        if (car == '\n')
            numLineas++;
    }
    rewind(f);
    return (numLineas + 1) / 4;
}

void mostrarDatos(TRABAJADOR trabajador[], int numE)
{

    printf("\n\n******* LISTADO DATOS EMPLEADOS *********\n\n");

    for (int i = 0; i < numE; i++)
    {
        printf("%s  %s \t%d\t%s\n", trabajador[i].nombre, trabajador[i].apellidos, trabajador[i].edad, trabajador[i].departamento);
    }
}
void eliminaBarraN(char cad[MAXCADENA])
{
    if (cad[strlen(cad) - 1] == '\n')
        cad[strlen(cad) - 1] = '\0';
}
