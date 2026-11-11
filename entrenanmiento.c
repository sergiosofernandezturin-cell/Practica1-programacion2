// Sergio Fernandez Turin 11/11/2026 Entrenamiento de pista

#include <stdio.h>

// Prototipos de las funciones
int leerTiempo();
float calcularMedia(int suma, int vueltas);
int esMejora(int anterior, int actual);
int registrarVuelta(int tiempo, int vueltas, int *mejor, int *peor, int *suma, int *bajo90);

int main() {
	// inicializamos las funcioines
    int tiempo = 0;
    int anterior = 0;
    int vueltas = 0;
    int mejor = 0;
    int peor = 0;
    int suma = 0;
    int bajo90 = 0;
    int racha = 0;
    int rachaMaxima = 0;
    int nuevoMejor = 0;
    float media = 0;

    printf("REGISTRO DE VUELTAS\n");

    // Pedimos tiempos hasta que el usuario introduzca 0
    do {
        tiempo = leerTiempo();

        if (tiempo > 0) {

            // Aumentamos el numero de vueltas
            vueltas++;

            // Registramos el tiempo y actualizamos estadisticas
            nuevoMejor = registrarVuelta(tiempo, vueltas, &mejor, &peor, &suma, &bajo90);

            // Comprobamos si es un nuevo record
            if (nuevoMejor == 1) {
                printf("Nuevo mejor tiempo!\n");
            }

            // Comprobamos la racha de mejoras
            if (vueltas > 1) {

                if (esMejora(anterior, tiempo) == 1) {
                    racha++;
                } else {
                    racha = 0;
                }

                // Actualizamos la racha maxima
                if (racha > rachaMaxima) {
                    rachaMaxima = racha;
                }
            }

            // Guardamos el tiempo para la siguiente vuelta
            anterior = tiempo;
        }

    } while (tiempo != 0);

    // Comprobamos si se han registrado vueltas
    if (vueltas == 0) {
        printf("Sin vueltas registradas\n");
    } else {

        // Calculamos la media
        media = calcularMedia(suma, vueltas);

        // Mostramos las estadisticas
        printf("\nRESULTADOS\n");
        printf("Numero de vueltas: %d\n", vueltas);
        printf("Mejor tiempo: %d segundos\n", mejor);
        printf("Peor tiempo: %d segundos\n", peor);
        printf("Tiempo medio: %.1f segundos\n", media);
        printf("Vueltas por debajo de 90 segundos: %d\n", bajo90);
        printf("Mayor racha de mejoras: %d\n", rachaMaxima);
    }

    return 0;
}

// Pide un tiempo hasta introducir uno valido
int leerTiempo() {
    int tiempo = -1;
    int c = 0;

    do {
        printf("Introduce el tiempo de la vuelta (0 para terminar): ");
        
        if (scanf("%d", &tiempo) != 1) {
            printf("Error: introduce un numero entero.\n");
            tiempo = -1;
        } else if (tiempo < 0) {
            printf("Error: el tiempo no puede ser negativo.\n");
        }

        // Limpiamos la entrada
       while (getchar() != '\n');

    } while (tiempo < 0);

    return tiempo;
}

// Calcula la media de los tiempos
float calcularMedia(int suma, int vueltas) {
    float resultado = 0;

    if (vueltas > 0) {
        resultado = (float)suma / vueltas;
    }

    return resultado;
}

// Comprueba si una vuelta es mas rapida que la anterior
int esMejora(int anterior, int actual) {
    int resultado = 0;

    if (actual < anterior) {
        resultado = 1;
    }

    return resultado;
}

// Actualiza las estadisticas de las vueltas
int registrarVuelta(int tiempo, int vueltas, int *mejor, int *peor, int *suma, int *bajo90) {

    int nuevoMejor = 0;

    // Si es la primera vuelta, inicializamos mejor y peor
    if (vueltas == 1) {
        *mejor = tiempo;
        *peor = tiempo;
        nuevoMejor = 1;
    } else {

        // Comprobamos si mejora el mejor tiempo
        if (tiempo < *mejor) {
            *mejor = tiempo;
            nuevoMejor = 1;
        }

        // Comprobamos si es el peor tiempo
        if (tiempo > *peor) {
            *peor = tiempo;
        }
    }

    // Sumamos el tiempo
    *suma = *suma + tiempo;

    // Contamos las vueltas inferiores a 90 segundos
    if (tiempo < 90) {
        (*bajo90)++;
    }

    return nuevoMejor;
}
