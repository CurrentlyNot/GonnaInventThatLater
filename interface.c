#include <stdio.h>
#include "custom.h"

int interface()
{
	/*Rysowanie ramek np. do tekstu i wyborów, do których potem trzeba będzie
	 * się dostosować w wypisywaniu historii i choice'ów. */
	/*Ona powinna być generowana osobno, bo mogą być momenty że np będziemy
	 * chcieli stworzyć ciemność, czy coś i wtedy wnętrze ramki powinno
	 * być puste*/
	printFrame();
	/*W każdym momencie wybierania choice'a, gracz powinien mieć prawo do
	 * wyłącznie gry, żeby program mógł skończyć pętle*/
	while(choice != EXIT)
	{
		/*Printuje historie na podstawie choice, który dostał od funkcji
		 * selectChoice, w środku powinna być też funcja definiująca
		 * wybory które można podjąć*/
		showHistory(&choice);
		/*Printuje stworzone wyżej wybory*/
		showChoices(&define);
		/*Czeka na naciśnięcie klawisza i przypisuje do zmiennej wybór*/
		selectChoice(&choice);
		/*To może printować rzeczy po zatwierdzeniu wyboru. Przydało by się
		 * zdefiniować np odstępy czasowe między printowaniem, prinotwanie
		 * znak po znaku .*/
		printContent();
	}
	printf("Goodbye!\n");
	return EXIT;
}
/*Koniec funkcji interface*/

/*Info*/
/*Mój pomysł na pętle interface'u, co o nim myślisz?*/
