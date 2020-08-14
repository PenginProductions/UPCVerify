/*
	Robert Giglio III
	9/29/2016

	Exercise #1 UPC check-digit checker
*/

#include<iostream>
using namespace std;

int main()
{
	//user entered upc code variables
	bool isValid = 0;
	int firstNumber, lastNumber,manNum, prodNum, oddParings, evenParings, totalValue, checkDigit;
	//Manufacturer and Product number variables
	int mDigit1, mDigit2, mDigit3, mDigit4, mDigit5, pDigit1, pDigit2, pDigit3, pDigit4, pDigit5;

	//sentinel value
	char test = 'z';

	while (test == 'z')
	{
		cout << "Do you have a number to test? (y or n): ";
		cin >> test;
		if(test == 'Y' || test == 'y')
		{
			//user entry
			cout << "Enter the very first number of the UPC: ";
			cin >> firstNumber;
			cout << "Enter the very last number of the UPC: ";
			cin >> lastNumber;
			cout << "Enter your manufacturer number (the first set of 5 digits) ";
			cin >> manNum;
			cout << "Enter your Product number (The second set of 5 digits) ";
			cin >> prodNum;

			//extract Manufacturer number digits
			mDigit1 = manNum / 10000;
			manNum = manNum % 10000;
			mDigit2 = manNum / 1000;
			manNum = manNum % 1000;
			mDigit3 = manNum / 100;
			manNum = manNum % 100;
			mDigit4 = manNum / 10;
			manNum = manNum % 10;
			mDigit5 = manNum;
			//extract Product Number digits
			pDigit1 = prodNum / 10000;
			prodNum = prodNum % 10000;
			pDigit2 = prodNum / 1000;
			prodNum = prodNum % 1000;
			pDigit3 = prodNum / 100;
			prodNum = prodNum % 100;
			pDigit4 = prodNum / 10;
			prodNum = prodNum % 10;
			pDigit5 = prodNum;

			oddParings = (3 * (firstNumber + (int)mDigit2 + (int)mDigit4 + (int)pDigit1 + (int)pDigit3 + (int)pDigit5));
			evenParings = ((int)pDigit2 + (int)pDigit4 + (int)mDigit1 + (int)mDigit3 + (int)mDigit5);
			totalValue = oddParings + evenParings;
			checkDigit = 10 - (totalValue % 10);
			if (checkDigit == 10)
				checkDigit = 0;
			if (checkDigit == (int)lastNumber)
				cout << "\nUPC code " << firstNumber << mDigit1 << mDigit2 << mDigit3 << mDigit4 << mDigit5 << pDigit1 << pDigit2 << pDigit3 << pDigit4 << pDigit5 << lastNumber << " is valid." << endl;
			else
				cout << "\nUPC code " << firstNumber << mDigit1 << mDigit2 << mDigit3 << mDigit4 << mDigit5 << pDigit1 << pDigit2 << pDigit3 << pDigit4 << pDigit5 << lastNumber << " is invalid." << endl;
		}
		else if (test == 'n' || test == 'N')
			break;
		test = 'z';
	}
	system("pause");
	return 0;
}