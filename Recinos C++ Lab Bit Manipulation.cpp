// Recinos C++ Lab Bit Manipulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


// global declarations

int number;

int x;


void Toggle(int bit)

{

	number = number ^ (1 << bit);

}



void TurnOn(int bit)

{

	number = number | (1 << bit);

}


void TurnOff(int bit)

{

	number = (number & ~(1 << bit));

}


void negate()

{

	for (int j = 0; j < x; j++)

	{

		Toggle(j);

	}

}

void left_shift()

{

	number <<= 1;

	TurnOff(20);

}

void right_shift()

{

	number >>= 1;

}


string int_to_binary()

{


	int temporary = number;

	string str = "";

	for (int i = 0; i < x; i++)

	{

		if ((temporary & 1) == 1)

			str += '1';

		else

			str += '0';

		temporary /= 2;

	}

	reverse(str.begin(), str.end());

	return str;

}

string caret = "^ ";


int main()
{
	//std::cout << "Hello World!\n";


	number = (1 << 20) - 1;
	int temp = number;

	x = (int)log2(number) + 1;

	std::cout << x << "\n\n\n\n";

	std::cout << "Welcome to number destroyer!!!!!!" << std::endl

		<< "Rules are simple ";

	std::cout << "You have to destroy the number given below completely";

	std::cout << "Press F1 to Turn on any digit" << std::endl;

	std::cout << "Press F2 to Toggle any digit" << std::endl;

	std::cout << "Press F3 to Turn off any digit" << std::endl;

	std::cout << "Press F4 to invert all digit" << std::endl;

	std::cout << "Press L to left shift " << std::endl;

	std::cout << "Press R to right shift " << std::endl;

	std::cout << "Press e to exit at any time " << std::endl;

	std::cout << "Use left and right arrow to move on Bits" << std::endl;

	int user_exit = 0;

	int cur = 0;

	int z = 0;


	while (number)

	{



		z++;
		string binaryConversion = int_to_binary();

		if ((z & 1) == 1)
			std::cout << "\rBITS:" << binaryConversion

			<< "\n " << caret << flush;

		char key_press = _getch();

		int ascii_value = key_press;

		if (ascii_value == 75) {

			

			caret[cur] = ' ';

			cur = max(0, cur - 1);

			caret[cur] = '^';

		}

		else if (ascii_value == 77)

		{

			

			caret[cur] = ' ';

			cur = min(x - 1, cur + 1);

			caret[cur] = '^';

		}

		else if (ascii_value == 84)

		{

			

			TurnOn(x - 1 - cur);

		}

		else if (ascii_value == 85)

		{

			

			Toggle(x - 1 - cur);

		}

		else if (ascii_value == 86)

		{

			

			TurnOff(x - 1 - cur);

		}

		else if (ascii_value == 87)

		{

			

			negate();

		}

		else if (ascii_value == 76 or ascii_value == 108)

		{

			
			z++;

			left_shift();

		}

		else if (ascii_value == 114 or ascii_value == 82) {

			
			z++;

			right_shift();
		}

		else if (ascii_value == 69 or ascii_value == 101)

		{

			

			user_exit = 1;

			break;

		}

	}

	cout << std::endl;

	string binaryConversion = int_to_binary();

	if (user_exit == 1)

		std::cout << std::endl

		<< std::endl

		<< "Exiting program !! Thank you for playing" << std::endl

		<< std::endl;

	else {

		std::cout << "NUMBER now :0\n" "BITS:" << binaryConversion << std::endl;

		number = temp;

		binaryConversion = int_to_binary();

		std::cout << "NUMBER before :" << number << "\nBITS:" << binaryConversion << std::endl;
		std::cout << std::endl

			<< std::endl

			<< "Congratulations !! You destroyed the number !! Thank you for playing" << std::endl

			<< std::endl;
	}

}


























// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
