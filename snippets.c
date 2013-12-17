Returning multiple values:

	1: Return a struct which contains all the types you need:

		struct Tuple {
			int a;
			string b;
		};

		struct Tuple getPair() {
			Tuple r = { 1, getString() };
			return r;
		}

		void foo() {
			struct Tuple t = getPair();
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
