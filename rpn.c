#include "stack.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LINE_LENGTH 100

/* Inputs/Actions: 
Int -> add number to top of stack (inputs are all decimal integers)
	   if 5, then add 5/1
+   -> Pop top 2 off stack & place sum at top
-   -> Pop top 2 off stack, subtract first/top from 2nd, place result at top
*   -> Pop top 2 off stack, multiply, add result to top of stack
/   -> pop top 2 off stack, divide 2nd entry by first/top & add result to top
	   if divide by 0 -> print out "DIVIDE BY ZERO" and terminate, freeing memory
dup -> duplicate value at top of stack
swap -> swap order of two 2 entries
quit -> exit program freeing all entires on stack
drop -> delete entry at top
clear -> delete all entires on stack
*/

/* Further notes
fgets -> to read command line
- case should not matter 
- extra whitespace characters can appear before/after
- extra non-whitespace characters -> print "INVALID COMMAND", ignore input
- not enough entries to perform operation -> print "STACK ERROR", then wait
- after entry/command w/out error, code should print value at top of stack w/ newline ("%d/%d\n")
*/ 

int gcd(int num1, int num2) {
	int gcd;


}


int main() {

	char input[MAX_LINE_LENGTH];
	char command[MAX_LINE_LENGTH];
	int num;
	int denom;
	Stack the_stack;
	Stack_Init(&the_stack);

	while (1) {

		printf("Enter command\n");
		fgets (input, MAX_LINE_LENGTH, stdin);

		if (sscanf(input, " %d ", &num) == 1) {
			denom = 1;
			Stack_Add(&the_stack, num, denom);
			Stack_Print(&the_stack);
		}


		printf("Converted input to lower case\n");
		for (int i = 0; i < strlen(input); ++i) {
        	input[i] = tolower(input[i]);
    	}

    	if (sscanf(input, " %s ", &command) == 1) {

    		// Add command
    		if (strcmp(command, "+") == 0) {
    			if (Stack_Contains(&the_stack)) {
    				Tuple * val1 = Stack_Peek(&the_stack);
    				Stack_Pop(&the_stack);
    				if (Stack_Contains(&the_stack)) {
    					Tuple * val2 = Stack_Peek(&the_stack);
    					Stack_Pop(&the_stack);
    					if (val1 -> second == val2 -> second) {
    						int top = (val1 -> first) + (val2 -> first);
    						int bottom = val1 -> second;
    						Stack_Add(&the_stack, top, bottom);
    					} else {
    						int top = (val1 -> first)(val2 -> second) + (val2 -> first)(val1 -> second);
    						int bottom = (val1 -> second)(val2 -> second);
    						int gcd = gcd(top, bottom);
    						Stack_Add(&the_stack, top/gcd, bottom/gcd);
    					}

    					Print_Top(&the_stack);

    					//free tuple1 & tuple2
    				} else {
    					printf("STACK ERROR");
    					Stack_Add(&the_stack, val1 -> first, val1 -> second);
    				}

    			} else {
    				printf("STACK ERROR");
    			}

    		// Subtract command
    		} else if (strcmp(command, "-") == 0) {
    			if (Stack_Contains(&the_stack)) {
    				Tuple * val1 = Stack_Peek(&the_stack);
    				Stack_Pop(&the_stack);
    				if (Stack_Contains(&the_stack)) {
    					Tuple * val2 = Stack_Peek(&the_stack);
    					Stack_Pop(&the_stack);

    					if (val1 -> second == val2 -> second) {
    						int top = (val2 -> first) - (val1 -> first);
    						int bottom = val1 -> second;
    						Stack_Add(&the_stack, top, bottom);
    					} else {
    						int top = (val2 -> first)(val1 -> second) - (val1 -> first)(val2 -> second);
    						int bottom = (val1 -> second)(val2 -> second);
    						int gcd = gcd(top, bottom);
    						Stack_Add(&the_stack, top/gcd, bottom/gcd);
    					}

    					Print_Top(&the_stack);

    					//free tuple1 & tuple2


    				} else {
    					printf("STACK ERROR");
    					Stack_Add(&the_stack, val1 -> first, val1 -> second);

    				}

    			} else {
    				printf("STACK ERROR");
    			}
    			
    		// Multiply command
    		} else if (strcmp(command, "*") == 0) {

    			if (Stack_Contains(&the_stack)) {
    				Tuple * val1 = Stack_Peek(&the_stack);
    				Stack_Pop(&the_stack);
    				if (Stack_Contains(&the_stack)) {
    					Tuple * val2 = Stack_Peek(&the_stack);
    					Stack_Pop(&the_stack);

    					int top = (val1 -> first)(val2 -> first);
    					int bottom = (val1 -> second)(val2 -> second);
    					int gcd = gcd(top, bottom);
    					Stack_Add(&the_stack, top/gcd, bottom/gcd);
    					Print_Top(&the_stack);
    					


    				} else {
    					printf("STACK ERROR");
    					Stack_Add(&the_stack, val1 -> first, val1 -> second);

    				}

    			} else {
    				printf("STACK ERROR");
    			}
    			
    		// Divide command
    		} else if (strcmp(command, "/") == 0) {

    			if (Stack_Contains(&the_stack)) {
    				Tuple * val1 = Stack_Peek(&the_stack);
    				Stack_Pop(&the_stack);
    				if (Stack_Contains(&the_stack)) {
    					Tuple * val2 = Stack_Peek(&the_stack);
    					Stack_Pop(&the_stack);

    					// val2 / val1
    					int top = (val2 -> first)(val1 -> second);
    					int bottom = (val2 -> second)(val1 -> first);
    					int gcd = gcd(top, bottom);
    					Stack_Add(&the_stack, top/gcd, bottom/gcd);
    					Print_Top(&the_stack);

    				} else {
    					printf("STACK ERROR");
    					Stack_Add(&the_stack, val1 -> first, val1 -> second);
   				
    				}

    			} else {
    				printf("STACK ERROR");
    			}
    			
    		} else if (strcmp(command, "dup") == 0) {

    			if (Stack_Contains(&the_stack)) {
    				Tuple * val1 = Stack_Peek(&the_stack);
    				Stack_Add(&the_stack, val1 -> first, val1 -> second);
    				Print_Top(&the_stack);

    				//free tuple1

    			} else {
    				printf("STACK ERROR");
    			}
    			
    		} else if (strcmp(command, "swap") == 0) {

    			if (Stack_Contains(&the_stack)) {
    				Tuple * val1 = Stack_Peek(&the_stack);
    				Stack_Pop(&the_stack);
    				if (Stack_Contains(&the_stack)) {
    					Tuple * val2 = Stack_Peek(&the_stack);
    					Stack_Pop(&the_stack);

    					Stack_Add(&the_stack, val1 -> first, val1 -> second);
    					Stack_Add(&the_stack, val2 -> first, val2 -> second);
    					Print_Top(&the_stack);

    					// free two tuples

    

    				} else {
    					printf("STACK ERROR");
    					Stack_Add(&the_stack, val1 -> first, val1 -> second);
    				}

    			} else {
    				printf("STACK ERROR");
    			}
    			
    		} else if (strcmp(command, "quit") == 0) {

    			Stack_Clear(&the_stack);
    			break;
    			
    		} else if (strcmp(command, "drop") == 0) {

    			if (Stack_Contains(&the_stack)) {
    				Tuple * val1 = Stack_Peek(&the_stack);
    				Stack_Pop(&the_stack);
    				Print_Top(&the_stack);

    				// free val1
    				
    			} else {
    				printf("STACK ERROR");
    			}
    			
    		} else if (strcmp(command, "clear") == 0) {

    			Stack_Clear(&the_stack);
    			
    		} else {
    			printf("INVALID COMMAND\n");
    		}
    	} else {
    		printf("INVALID COMMAND\n");
    	}





	}

	
	return 0;

}