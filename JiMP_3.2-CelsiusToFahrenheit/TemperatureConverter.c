//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99

#include <stdio.h>

void wybor(void);
void conversionFromCelsius(double);
void conversionFromFahrenheit(double);

int main(void){

    wybor();

    return 0;
}

void wybor(void){
    int n = 0;
    double temperature = 0;
	printf("Wybierz skale temperatur: (1-Celsjusza, 2-Fahrenheita): ");
	scanf("%d", &n);
	switch (n)
	{
    case 1:
        printf("Podaj temperature do konwersji: ");
        scanf("%lf", &temperature);
        conversionFromCelsius(temperature);
        break;
	case 2:
	    printf("Podaj temperature do konwersji: ");
        scanf("%lf", &temperature);
        conversionFromFahrenheit(temperature);
		break;
	default:
        printf("Bledna wartosc!\n");
		wybor();
		break;
	}
}
void conversionFromCelsius(double celsiusTemperature){
    double fahrenTemperature = celsiusTemperature*1.8+32;
    printf("%.2f stopni Celsjusza to %.2f stopni Fahrenheita", celsiusTemperature, fahrenTemperature);
}
void conversionFromFahrenheit(double fahrenTemperature){
    double celsiusTemperature = (fahrenTemperature-32)/1.8;
    printf("%.2f stopni Fahrenheita to %.2f stopni Celsjusza", fahrenTemperature, celsiusTemperature);
}



