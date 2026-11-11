// Sergio Fernandez Turin 11/11/2026 numero de granizos
#include <stdio.h>

// Prototipos de las funciones
void mostrarSecuencia(int n);
int contarPasos(int n);
int maximoSecuencia(int n);

int main() {
	//iniciamos las variables
    int numero = 0;
    int pasos = 0;
    int maximo = 0;
    int c = 0;

    do {
        printf("Numero (0 para salir): ");

        // Comprobamos si se ha introducido un numero
        if (scanf("%d", &numero) != 1) {
            printf("Error: introduce un numero entero.\n");
            numero = -1;
        }

        // Limpiamos los caracteres del bufer
        while (getchar() != '\n');

        // Comprobamos si el numero es negativo
        if (numero < 0) {
            printf("Error: debe ser positivo.\n");
        }

        // Si el numero es positivo, ejecutamos las funciones
        if (numero > 0) {
            printf("Secuencia: ");
            mostrarSecuencia(numero);

            pasos = contarPasos(numero);
            maximo = maximoSecuencia(numero);

            printf("\nPasos: %d\n", pasos);
            printf("Maximo: %d\n", maximo);
        }

    } while (numero != 0);

    return 0;
}

// Muestra la secuencia de numeros hasta llegar a 1
void mostrarSecuencia(int n) {

    printf("%d ", n);

    // Caso base: cuando llegamos a 1 termina
    if (n == 1) {
        return;
    }

    // Si es par dividimos entre 2
    if (n % 2 == 0) {
        mostrarSecuencia(n / 2);
    } else {
        // Si es impar multiplicamos por 3 y sumamos 1
        mostrarSecuencia(3 * n + 1);
    }
}

// Cuenta cuantos pasos hay hasta llegar a 1
int contarPasos(int n) {

    // Caso base
    if (n == 1) {
        return 0;
    }

    // Si es par
    if (n % 2 == 0) {
        return 1 + contarPasos(n / 2);
    } else {
        // Si es impar
        return 1 + contarPasos(3 * n + 1);
    }
}

// Devuelve el numero mayor de la secuencia
int maximoSecuencia(int n) {
    int maximo = 0;

    // Caso base
    if (n == 1) {
        return 1;
    }

    // Calculamos el maximo del resto de la secuencia
    if (n % 2 == 0) {
        maximo = maximoSecuencia(n / 2);
    } else {
        maximo = maximoSecuencia(3 * n + 1);
    }

    // Comparamos el numero actual con el maximo
    if (n > maximo) {
        maximo = n;
    }

    return maximo;
}
