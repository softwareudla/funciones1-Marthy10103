#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresar_productos(char nombres[][50], float precios[],int cantidades[], int *num_productos) {
  do {
        printf("¿Cuantos productos desea ingresar (max 10)? ");
        scanf("%d", num_productos);
        
        if (*num_productos > 10 || *num_productos < 1) {
            printf("Error: Solo se permiten entre 1 y 10 productos. Intentelo nuevamente.\n");
        }
    } while (*num_productos > 10 || *num_productos < 1);
    
    for (int i = 0; i < *num_productos; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
       (fgets(nombres[i], 50, stdin));
       fflush (stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0';

        printf("Ingrese el precio del producto %d: ", i + 1);
        while (scanf("%f", &precios[i]) != 1) {
            printf("Error: Ingrese un número válido para el precio del producto %d: ", i + 1);
            while (getchar() != '\n');
        }

        while (getchar() != '\n');

        printf("Ingrese la cantidad del producto %d: ", i + 1);
        while (scanf("%d", &cantidades[i]) != 1 || cantidades[i] < 1) {
            printf("Error: Ingrese un número válido para la cantidad del producto %d: ", i + 1);
    
            while (getchar() != '\n');
        }

        while (getchar() != '\n');
    }
}
float calcular_total(float precios[], int cantidades [],int num_productos) {
    float total = 0.0;
    for (int i = 0; i < num_productos; i++) {
        total += precios[i] * cantidades [i];
    }
    return total;
}

void encontrar_mas_caro(char nombres[][50], float precios[], int num_productos) {
    int indice_mas_caro = 0;

    for (int i = 1; i < num_productos; i++) {
        if (precios[i] > precios[indice_mas_caro]) {
            indice_mas_caro = i;
        }
    }

    printf("Producto mas caro: %s con un precio de %.2f\n", nombres[indice_mas_caro], precios[indice_mas_caro]);
}

void encontrar_mas_barato(char nombres[][50], float precios[], int num_productos) {
    int indice_mas_barato = 0;

    for (int i = 1; i < num_productos; i++) {
        if (precios[i] < precios[indice_mas_barato]) {
            indice_mas_barato = i;
        }
    }

    printf("Producto mas barato: %s con un precio de %.2f\n", nombres[indice_mas_barato], precios[indice_mas_barato]);
}
float calcular_promedio(float precios[],int cantidades, int num_productos) {
    float total = calcular_total(precios, cantidades, num_productos);
    return total / num_productos;
}
void buscar_producto(char nombres[][50], float precios[], int num_productos) {
    char producto_buscado[50];
    printf("Ingrese el nombre del producto que desea buscar: ");
    scanf("%s", producto_buscado);

    for (int i = 0; i < num_productos; i++) {
        if (strcmp(nombres[i], producto_buscado) == 0) {
            printf("El precio de %s es %.2f\n", nombres[i], precios[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}