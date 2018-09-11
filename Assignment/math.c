/*
 * math.c
 *
 *  Created on: Sep 10, 2018
 * 	Last Edited: Sept 10, 2018
 *      Author: Kyle Rettig
 */
#include <stdio.h>
#include "math.h"
#include "time.h" //extra library if using random number
#include "stdlib.h" //extra library if using random number

int main() {
	srand(time(NULL)); //generates the rand() function
	int num1 = rand(); //applies a random number to the two int's used, replace with a decimal to set numbers
	int num2 = rand();
	char Operator; //this calculator will require an operator character in order to know which functions to do

	printf("Number 1: %d\n", num1); //showing what numbers were input
	printf("Number 2: %d\n", num2);

	//listing out all required functions
	Operator = '+'; //addition
	math(num1, num2, Operator); //inputs the numbers and operator into the math function to be computed

	Operator = '-'; //subtraction
	math(num1, num2, Operator);

	Operator = '*'; //multiplication
	math(num1, num2, Operator);

	Operator = '/'; //division
	math(num1, num2, Operator);

	Operator = '%'; //mod
	math(num1, num2, Operator);

	Operator = '<'; //left shift
	math(num1, num2, Operator);

	Operator = '>'; //right shift
	math(num1, num2, Operator);

	Operator = '&'; //bitwise AND
	math(num1, num2, Operator);

	Operator = '|'; //bitwise OR
	math(num1, num2, Operator);

	Operator = '^'; //bitwise XOR
	math(num1, num2, Operator);

	Operator = '~'; //bitwise inverse
	math(num1, num2, Operator);

	return 0;
}

int math(int num1, int num2, char Operator) //Function to perform calculations
{
	//a case switch statement is one of the easier methods for doing different calculations with the same inputs
	switch (Operator) {
	case '+':
		ans = num1 + num2; //this line and the following lines denote all of the logic for the functions listed above
		printf("Sum: %d\n", ans); //the ans int is referenced in math.h as the int that holds the calculation
		break; //break end the specific case

	case '-':
		ans = num1 - num2;
		printf("Difference: %d\n", ans);
		break;

	case '*':
		ans = num1 * num2;
		printf("Product: %d\n", ans);
		break;

	case '/':
		if (num2 == 0) {
			printf("Divide by zero ERROR, please restart program");//Some operations will crash, so an if statement for certain inputs has to be made
			ans = 0;
		} else {
			ans = num1 / num2;
			printf("Quotient: %d\n", ans);
		}
		break;

	case '%':
		if (num2 == 0) {
			printf("Divide by zero ERROR, please restart program");
			ans = 0;
		} else {
			ans = num1 % num2;
			printf("Mod: %d\n", ans);
		}
		break;

	case '<':
		ans = num1 << num2;
		printf("Left Shift of %d by %d: %d\n", num1, num2, ans);
		break;

	case '>':
		ans = num1 >> num2;
		printf("Right shift of %d by %d: %d\n", num1, num2, ans);
		break;

	case '&':
		ans = num1 & num2;
		printf("Bitwise AND: %d\n", ans);
		break;

	case '|':
		ans = num1 | num2;
		printf("Bitwise OR: %d\n", ans);
		break;

	case '^':
		ans = num1 ^ num2;
		printf("Bitwise XOR: %d\n", ans);
		break;

	case '~':
		ans = ~num1;
		printf("Bitwise Invert: %d\n", ans);
		break;
	default: //default case for if an operation is not entered
		printf("Error with input, please restart program.");
	}
	return ans;
}
