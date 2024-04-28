#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nombre[50];
    char apellido[50];
    float notas[4];
    float promedio;
    char resultado[20];
} Estudiante;

void calcular_promedio_y_estado(Estudiante *estudiantes, int n) {
    for (int i = 0; i < n; i++) {
        float suma = 0;
        for (int j = 0; j < 4; j++) {
            suma += estudiantes[i].notas[j];
        }
        estudiantes[i].promedio = suma / 4;
        if (estudiantes[i].promedio > 60) {
            strcpy(estudiantes[i].resultado, "Aprobado");
        } else {
            strcpy(estudiantes[i].resultado, "Reprobado");
        }
    }
}

void guardar_datos(Estudiante *estudiantes, int n) {
    FILE *archivo = fopen("notas.dat", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fwrite(estudiantes, sizeof(Estudiante), n, archivo);
    fclose(archivo);
}

int main() {
    int n;
    printf("Ingrese la cantidad de estudiantes: ");
    scanf("%d", &n);

    Estudiante *estudiantes = (Estudiante *)malloc(n * sizeof(Estudiante));

    for (int i = 0; i < n; i++) {
        printf("Ingrese ID del estudiante: ");
        scanf("%d", &estudiantes[i].id);
        printf("Ingrese nombre del estudiante: ");
        scanf("%s", estudiantes[i].nombre);
        printf("Ingrese apellido del estudiante: ");
        scanf("%s", estudiantes[i].apellido);
        printf("Ingrese las 4 notas del estudiante: ");
        for (int j = 0; j < 4; j++) {
            scanf("%f", &estudiantes[i].notas[j]);
        }
    }

    calcular_promedio_y_estado(estudiantes, n);
    guardar_datos(estudiantes, n);
    free(estudiantes);

    return 0;
}

