#include <stdio.h>

#define MAX_ESTUDIANTES 100

typedef struct {
    int id;
    char nombre[50];
    char apellido[50];
    float notas[4];
} Estudiante;

void calcular_promedio_y_estado(Estudiante estudiantes[], int n) {
    for (int i = 0; i < n; i++) {
        float suma = 0;
        for (int j = 0; j < 4; j++) {
            suma += estudiantes[i].notas[j];
        }
        float promedio = suma / 4;
        printf("El promedio del estudiante %d es %.2f, ", estudiantes[i].id, promedio);
        if (promedio > 60) {
            printf("por lo tanto, ha aprobado.\n");
        } else {
            printf("por lo tanto, ha reprobado.\n");
        }
    }
}

int main() {
    int n;
    printf("Ingrese la cantidad de estudiantes: ");
    scanf("%d", &n);

    Estudiante estudiantes[MAX_ESTUDIANTES];

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

    return 0;
}

