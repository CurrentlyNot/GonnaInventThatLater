#ifndef CUSTOM_H_
#define CUSTOM_H_

/*Tutaj wpisuj rzeczy, które będą przekazywane pomiędzy funkcjami np: externy*/
#define	TRUE	1
#define	FALSE	0
#define	EXIT	"exit"

/*Funkcje, które będą używane (kompilator musi najpierw przeskanować, czy
 * wszystkie są i mają przekazane odpowiednie rodzaje zmiennych*/
extern printFrame();
extern 	showHistory(int* choice);
extern showChoices(struct choices* define);
extern selectChoice(int* choice);
extern printContent();

/*Externowe zmienne, które będą wysyłane między funkcjami*/
extern int choice;

/*Definiowanie foremki na wybory*/
typedef struct choices
{
	char	choice1[100];
	char	choice2[100];
	char	choice3[100];
	char	choice4[100];
	char	choice5[100];
};

#endif

/*INFO*/
/*Teraz pytanie - robimy to w jednym pliku C czy dzielimy to na pare osobnych
 * plików? Jak to pierwsze to cała ta biblioteka nie ma sensu, bo ona jest po to
 * żeby łączyć osobne pliki*/
