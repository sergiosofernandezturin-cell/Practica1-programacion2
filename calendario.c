// Sergio Fernandez Turin 11/11/2026 Calendario
#include <stdio.h>

// Prototipos de las funciones
int esBisiesto(int anio);
int diasDelMes(int mes, int anio);
void imprimirCalendario(int dias, int diaInicio);

int main() {
	// inicializamos las funcioines
    int mes = 0;
    int anio = 0;
    int diaInicio = 0;
    int dias = 0;

    // Pedimos los datos al usuario
    printf("Mes (1-12): ");
    scanf("%d", &mes);

    printf("Anio: ");
    scanf("%d", &anio);

    printf("Dia de la semana del dia 1 (1=lunes ... 7=domingo): ");
    scanf("%d", &diaInicio);

    // Comprobamos que los datos sean correctos
    if (mes < 1 || mes > 12 || anio <= 0 || diaInicio < 1 || diaInicio > 7) {
        printf("Error: datos fuera de rango.\n");
    } else {
        // Calculamos los dias del mes
        dias = diasDelMes(mes, anio);

        // Imprimimos el calendario
        imprimirCalendario(dias, diaInicio);
    }

    return 0;
}

// Devuelve 1 si el anio es bisiesto y 0 si no
int esBisiesto(int anio) {
    int resultado = 0;

    if (anio % 400 == 0) {
        resultado = 1;
    } else if (anio % 4 == 0 && anio % 100 != 0) {
        resultado = 1;
    }

    return resultado;
}

// Calcula cuantos dias tiene el mes
int diasDelMes(int mes, int anio) {
    int dias = 0;

    // Meses de 31 dias
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 ||mes == 8 || mes == 10 || mes == 12){
        dias = 31;
    }

    // Meses de 30 dias
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        dias = 30;
    }

    // Febrero
    if (mes == 2) {
        if (esBisiesto(anio) == 1) {
            dias = 29;
        } else {
            dias = 28;
        }
    }

    return dias;
}

// Imprime el calendario del mes
void imprimirCalendario(int dias, int diaInicio) {
    int posicion = 0;

    // Cabecera del calendario
    printf("  L  M  X  J  V  S  D\n");

    // Dejamos espacios hasta el primer dia del mes
    for (int i = 1; i < diaInicio; i++) {
        printf("   ");
    }

    // Empezamos en la posicion del dia 1
    posicion = diaInicio;

    // Mostramos todos los dias del mes
    for (int dia = 1; dia <= dias; dia++) {
        printf("%3d", dia);

        // Si es domingo, pasamos a la siguiente linea
        if (posicion == 7) {
            if (dia != dias) {
                printf("\n");
            }
            posicion = 1;
        } else {
            posicion++;
        }
    }

    // Si el mes no termina en domingo, cerramos la linea
    if (posicion != 1) {
        printf("\n");
    }
}
