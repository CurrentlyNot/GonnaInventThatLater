Returning multiple values:

	1: By struct (reference):

		struct someStruct
		{
			unsigned int total;
		};

		int test(struct someStruct* state)
		{
			state->total = 4;
		}

		int main ()
		{
			struct someStruct s;
			s.total = 5;
			test(&s);
			printf("\ns.total = %d\n", s.total);
		}

	2: Use pointers to pass out values:

		void getPair(int* a, string* b) {
			// Check that these are not pointing to NULL
			assert(a);
			assert(b);
			*a = 1;
			*b = getString();
		}

		void foo() {
			int a, b;
			getPair(&a, &b);
		}

	3: If-ing returning value:

		if(condition)
		{
		   ...
		   return A;
		}
		else
		{
		   ...
		   return B;
		}

Returning arrays:

	1: Static array:
	
		char *itoa(int n)
		{
		static char retbuf[25];
		sprintf(retbuf, "%d", n);
		return retbuf;
		}
	
	2: Caller:
	
		char *itoa(int n, char buf[])
		{
		sprintf(buf, "%d", n);
		return buf;
		}
		
		Passing a value:
		
		int i = 23;
		char buf[25];
		char *str = itoa(i, buf);
		
	3: Malloc:
	
		char *itoa(int n)
		{
		char *retbuf = malloc(25);
		if(retbuf == NULL)
		return NULL;
		sprintf(retbuf, "%d", n);
		return retbuf;
		}
		
		Calling:
		
		char *p = itoa(i);
	
Passing by pointer:

	1: Simple variables

		int main(){
			int x;
			int y;
			/*Call function task, and give it access to those variables adresses*/
			tast(&x,&y);
		}
		/*Function will take adresses of passed values*/
		/*Remember that those function works as a template which shows what to do
		 * with passed values in that case*/
		void task(int* p1, int* p2){
			/*In order to return values through pointers you need to pass them
			 *  just like this*/
			*p1=1;
			*p2=*p1;
		}

	2: Structs:

		void function(struct rect *r) {
		    struct rect temp;
		    *r = temp;
		}
		void main(){
			function(&r);
		}

Defining some macro:

	1: Converting what normally seems to be a variable into a string:

		#define call_function(a,b) function(#a,#b)
		//then
		call_function(rough,friction);
		//The C preprocessor will turn this into
		function("rough","friction");
	
	2: Omiting quotation marks with strings:
	
		#define ROUGH    "rough"
		#define FRICTION "friction"
		//Then you can call
		f_texture(ROUGH, FRICTION);

Working with files:

	1: Opening and closing:

		FILE *name_pointer_to_your_file = fopen("path or name", "mode");
		fclose(pointer_to_your_file);

	2: Modes:

		r (read only), w (clear file and write only), a (write only on end of the file),
		r+ (read and write), w+ (clear file and read and write), a+ ??

	3: Usage of fgets:

		fgets (array_which_will_store_data, sizeof(array), pointer_to_your_file)
		//Each time you call this command, it will copy consecutive line

Ncurses:
	
	1: On Windows (using MinGW compilator)
		
		Download:
			pdc34dllw.zip: http://sourceforge.net/projects/pdcurses/files/
			
		Installation:
			pdcurses.lib to MinGW�s �/lib� folder
			cursors.h and panels.h to MingW�s �/include� folder
			pdcures.dll to MinGW�s �/bin� folder
			
	2: Usage:
			
		/*Include this library*/
		#include <curses.h>
		/*Initialize the main screen(put it on the beginning of main)*/
		initscr();
		/*Clear the window*/
		wclear(stdscr);
		/*Print things into a buffer. It won't be shown in terminal
		 until screen is refreshed*/
		printw("blabla");
		/*Refresh the screen*/
		wrefresh(stdscr);
		/*Move the output cursor to the specific place in the window*/
		move(row,column);
		/*Close the window, end the function*/
		endwin();
		/*Compile in gcc with this suffix included*/
		gcc -o code code.c -lpdcurses