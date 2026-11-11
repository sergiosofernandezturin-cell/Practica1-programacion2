#include <stdio.h>

// Prototipos de las funciones
int puntoMedio(int minimo, int maximo);
char leerRespuesta();
void actualizarIntervalo(char respuesta, int medio, int *minimo, int *maximo);
void mostrarVeredicto(int intentos);

int main() {
	// inicializamos las variables
    int topemaximo = 100;
    int topeminimo = 1;
    int respuestaMaquina = 0;
    char respuestaintroducida = ' ';
    int contador = 0;
	int minimoAnterior = 0;
	int maximoAnterior = 0;
	
    printf("ADIVINADOR\n");
    printf("Piensa un numero del 1 al 100.\n");

    do {
		//Calculamos que respuesta debe dar la maquina
        respuestaMaquina = puntoMedio(topeminimo, topemaximo);

        printf("\nIntento %d: Es el %d? (< menor, > mayor, = acierto): ",contador + 1, respuestaMaquina);

        // Guardamos el intervalo antes de modificarlo
        minimoAnterior = topeminimo;
        maximoAnterior = topemaximo;

        // Pedimos la respuesta
        respuestaintroducida = leerRespuesta();

        // Modificamos el intervalo
        actualizarIntervalo(respuestaintroducida, respuestaMaquina, &topeminimo, &topemaximo);

        if (topeminimo > topemaximo) {
            // Si el intervalo es imposible, mostramos un error
            printf("Te has equivocado, introduce otro simbolo.\n");

            // Recuperamos el intervalo anterior
            topeminimo = minimoAnterior;
            topemaximo = maximoAnterior;

            // No aumentamos el contador
        } else {
            // Solo contamos los intentos aceptados
            contador++;
        }

    } while (contador < 7 && respuestaintroducida != '=');

    if (respuestaintroducida == '=') {
        printf("He acertado en %d intentos! ", contador);
        mostrarVeredicto(contador);
    } else {
        printf("Me rindo, no se que numero era.\n");
    }

    return 0;
}

// Devuelve el punto medio del intervalo
int puntoMedio(int minimo, int maximo) {
    int medio = 0;

    medio = (minimo + maximo) / 2;

    return medio;
}

// Pide una respuesta hasta que sea valida
char leerRespuesta() {
    char caracter = ' ';
    int c = 0;

    do {
        if (scanf(" %c", &caracter) != 1) {
            caracter = ' ';
        }

        // Limpiamos los caracteres sobrantes
        while ((c = getchar()) != '\n' && c != EOF);

        // Comprobamos si el caracter es correcto
        if (caracter != '<' && caracter != '>' && caracter != '=') {
            printf("Caracter no valido. Introduce <, > o =: ");
        }

    } while (caracter != '<' && caracter != '>' && caracter != '=');

    return caracter;
}

// Actualiza el intervalo utilizando punteros
void actualizarIntervalo(char respuesta, int medio, int *minimo, int *maximo) {

    // Si el numero es menor, reducimos el maximo
    if (respuesta == '<') {
        *maximo = medio - 1;
    }

    // Si el numero es mayor, aumentamos el minimo
    if (respuesta == '>') {
        *minimo = medio + 1;
    }
}

// Muestra el comentario segun los intentos
void mostrarVeredicto(int intentos) {

    if (intentos <= 3) {
        printf("Increible!\n");
    }
    else if (intentos >= 4 && intentos <= 6) {
        printf("Nada mal\n");
    }
    else if (intentos == 7) {
        printf("Por los pelos!\n");
    }
}