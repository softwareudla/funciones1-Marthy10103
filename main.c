#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[10][50];
    float precios[10];
    int cantidades [10];
    int num_productos = 0;
    int opcion;
    ingresar_productos(nombres, precios, cantidades, &num_productos);
    do {
        printf("\n--- Menú de Inventario ---\n");
        printf("1. Mostrar el producto más caro\n");
        printf("2. Mostrar el producto más barato\n");
        printf("3. Buscar producto por nombre\n");
        printf("4. Calcular el precio total del inventario\n");
        printf("5. Calcular el precio promedio\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                encontrar_mas_caro(nombres, precios, num_productos); 
                break;
            case 2:
                encontrar_mas_barato(nombres, precios, num_productos);
                break;
            case 3:
                buscar_producto(nombres, precios, num_productos); 
                break;
            case 4:
                printf("Total del inventario: %.2f\n", calcular_total(precios,cantidades, num_productos));
                break;
            case 5:
                printf("Precio promedio: %.2f\n", calcular_promedio(precios,cantidades, num_productos));
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 6); 

return 0;
}