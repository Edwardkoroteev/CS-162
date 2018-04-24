/*==========================================================================
Name: Edward Koroteev
Program Name: Strings
Date: 1/8/2015
Purpose: The purpose of this program is for the user to guess my name
and let them know if the user input is a match. Later, add
The Barbarian at the end
=============================================================================*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

//constants
const int SIZE_OF_CSTRING = 30;

//Function prototypes
void CstringDemo();
void StringTypeDemo();
string RemoveVowels(string OriginalString);
void RemoveVowels(const char Cstring[], char CstringWithoutVowels[]);

void main()
{
	//Calling Function with string
	StringTypeDemo();
	
	//Callinf function with C-string
	CstringDemo();

	//Make sure consol stays open
	cin.get();
	cin.ignore();
}


/*============================================================
Function Name: cStringDemo
Description: using a c-string, have the user guess your name
			 and if it matches let them know. Then add
			 a civilian time name
input:	- none
output:	- none
=============================================================*/
void CstringDemo()
{
	//variables
	char MyNameCstring[SIZE_OF_CSTRING] = "Edward Koroteev";
	char UserGuessCstring[SIZE_OF_CSTRING] = "";
	char CstringWithoutVowels[SIZE_OF_CSTRING] = "";
	char TheBarbarianCstring[2*SIZE_OF_CSTRING] = " the Barbarian ";
	char ConcatenatedCstring[2*SIZE_OF_CSTRING] = "";
	
	//prompt user
	cout << "Guess My Name (First and Last): ";
	cin.get(UserGuessCstring, SIZE_OF_CSTRING);
	cin.ignore();

	//Compare the user input to the name
	if (strcmp(MyNameCstring, UserGuessCstring) != 0)
	{
		cout << endl << "Nice try! But you're incorrect!" << endl << endl
			<< "You guessed: " << "'" << UserGuessCstring << "'" << " and the correct name is: "
			<< MyNameCstring << endl;
	}
	else
	{
		cout << endl << "You guessed correct! " << UserGuessCstring
			<< " is the right answer!" << endl;
	}

	//Display the word entered by the user without vowels
	RemoveVowels(UserGuessCstring, CstringWithoutVowels);
	cout << endl << "Without Vowels, that's " << CstringWithoutVowels
		<< endl;

	//Concatenate user input with " the barbarian "
	strcpy(ConcatenatedCstring, strcat(UserGuessCstring, TheBarbarianCstring));
	cout << endl << "And in less civilized times, it would be " << ConcatenatedCstring
		<< endl << endl;
}


/*====================================================
Function Name: stringTypeDemo();
Description: Store string from user input
input:	- none
output:	- none
====================================================*/
void StringTypeDemo()
{
	//Variables
	string MyNameString = "Edward Koroteev";
	string UserInputString;
	string VowelessString;
	string ConcatedString;
	string TheBarbarianString = " the Barbarian";

	//Output to user
	cout << "Guess My Name (First and Last): ";
	getline(cin, UserInputString);

	//Compare the user input to my original name
	if (MyNameString != UserInputString)
	{
		cout << endl << "Nice try! But you're incorrect!" << endl << endl
			<< "You guessed: " << "'" << UserInputString << "'" ;
		cout << " and the correct name is: "
			<< MyNameString;
	}
	else
	{
		cout << endl << "You guessed correct! " << UserInputString
			<< " is the right answer!" ;
	}

	//Removing the vowels
	cout << endl << endl << "Without Vowels, that's " << RemoveVowels(UserInputString) << endl;

	//concated
	ConcatedString = UserInputString + TheBarbarianString;
	cout << endl << "And in less civilized times, it would be " << ConcatedString << endl << endl;

	cout << "______________________________________________________________" << endl << endl;
}
/*==============================================
Function Name: Vowel Remover
Description: Removes vowels from C-string
Input:	-  UserGuessCstring (intput cString)
output:	-  Pass by reference
============================================*/
void RemoveVowels(const char Cstring[], char CstringWithoutVowels[])
{
	//Variables
	int PlaceHolder1 = 0;
	int PlaceHolder2 = 0;

	//Check if word guessed has any vowels
	while (Cstring[PlaceHolder1] != '\0')
	{
		if (Cstring[PlaceHolder1] == 'A')
		{
			
		}
		else if (Cstring[PlaceHolder1] == 'E')
		{
			
		}
		else if (Cstring[PlaceHolder1] == 'I')
		{
			
		}
		else if (Cstring[PlaceHolder1] == 'O')
		{
			
		}
		else if (Cstring[PlaceHolder1] == 'U')
		{
			
		}
		
		//Lowercase Vowels
		else if (Cstring[PlaceHolder1] == 'a')
		{
			
		}
		else if (Cstring[PlaceHolder1] == 'e')
		{
			
		}
		else if (Cstring[PlaceHolder1] == 'i')
		{
			
		}
		else if (Cstring[PlaceHolder1] == 'o')
		{
			
		}
		else if (Cstring[PlaceHolder1] == 'u')
		{
			
		}
		else
		{
			CstringWithoutVowels[PlaceHolder2] = Cstring[PlaceHolder1];
			PlaceHolder2++;
		}



		PlaceHolder1++;
	}

}


/*==============================================
Function Name: Vowel Remover
Description: Removes vowels from string
Input:	-  UserGuessCstring (intput String)
output:	-  Pass by reference
============================================*/
string RemoveVowels(string OriginalString)
{
	//Variables
	string StringWithoutVowel = OriginalString;

	//Looping and checking for vowels of the word
	//entered by the user
	for (int loop = 0; loop < StringWithoutVowel.length(); loop++)
	{
		if(StringWithoutVowel.at(loop) == 'a')
		{
			StringWithoutVowel.erase(loop,1);
			loop--;
		}
		else if(StringWithoutVowel.at(loop) == 'e')
		{
			StringWithoutVowel.erase(loop,1);
			loop--;
		}
		else if(StringWithoutVowel.at(loop) == 'i')
		{
			StringWithoutVowel.erase(loop,1);
			loop--;
		}
		else if(StringWithoutVowel.at(loop) == 'o')
		{
			StringWithoutVowel.erase(loop,1);
			loop--;
		}
		else if(StringWithoutVowel.at(loop) == 'u')
		{
			StringWithoutVowel.erase(loop,1);
			loop--;
		}
		//uppercase
		else if(StringWithoutVowel.at(loop) == 'A')
		{
			StringWithoutVowel.erase(loop,1);
			loop--;
		}
		else if(StringWithoutVowel.at(loop) == 'E')
		{
			StringWithoutVowel.erase(loop,1);
			loop--;
		}
		else if(StringWithoutVowel.at(loop) == 'I')
		{
			StringWithoutVowel.erase(loop,1);
			loop--;
		}
		else if(StringWithoutVowel.at(loop) == 'O')
		{
			StringWithoutVowel.erase(loop,1);
			loop--;
		}
		else if(StringWithoutVowel.at(loop) == 'U')
		{
			StringWithoutVowel.erase(loop,1);
			loop--;
		}

	}
	return StringWithoutVowel;
}



