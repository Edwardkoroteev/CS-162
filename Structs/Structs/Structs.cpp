/*=======================================================================
Program Name: Structs
Created by: Edward Koroteev
Date: 1/20/2015
IDE: Visual Studios 2012
Purpose: Store 10 students. Their first name, last name, and Gpa
========================================================================*/
#include<iostream>
#include<string>

using namespace std;

//Define a struct to store data in for the students
struct Student
{
	string FirstName;
	string LastName;
	float GPA;
};

//constant
const int NUMBER_OF_STUDENTS = 3;

//Function Prototypes
void PromptUserForInput(Student StudentData[], int& PositionIndex);
void Menu(int& UserInput);
void ListStudents( Student StudentStruct[], int PositionIndex);
void UserPromptForListing(Student StudentInformation);
float DeterminingLargestGPA(Student StudentsGPA[], int PriceIndex);

void main()
{
	// variable to store data for the students
	Student StudentData[NUMBER_OF_STUDENTS];
	int UserInput;
	int PositionIndex = 0;
	
	do
	{
		//display manu
	Menu(UserInput);

	//if user wants to add students to the list
	if(UserInput == 1)
	{
		PromptUserForInput(StudentData, PositionIndex);
		PositionIndex++;
	}

	//if user wants to list the students entered
	if (UserInput == 2)
	{
	
		 ListStudents(StudentData, PositionIndex);
	}

	//if user wants to know what student has the highest GPA
	if (UserInput == 3)
	{
		cout << "The student with the highest GPA are" << endl;

		for (int i = 0; i < PositionIndex; i ++)
		{
			if (StudentData[i].GPA == DeterminingLargestGPA(StudentData, PositionIndex))
			{
				cout << i+1;
				UserPromptForListing(StudentData[i]);
				cout << endl;
			}

		}
		cout << endl;
	}
	}
	while(PositionIndex < NUMBER_OF_STUDENTS);
	
	//When the list is filled up
	cout << "______________You Have Filled Your Student Spots____________" <<
		endl << endl;
		 ListStudents(StudentData, PositionIndex);

	//display highest GPA
		 cout << "The student with the highest GPA are" << endl;
		 for (int i = 0; i < PositionIndex; i ++)
		{
			if (StudentData[i].GPA == DeterminingLargestGPA(StudentData, PositionIndex))
			{
				cout << i+1;
				UserPromptForListing(StudentData[i]);
				cout << endl;
			}

		}
	
	cin.get();
	cin.ignore();
}


/*============================================================
Function Name: PromptUserForInput
Description: This will prompt the user to enter
the students first name, last name and GPA
Input: Students		(Struct)
Position Index	(int)
output: Array is pass by reference 
position index is pass by reference 
==============================================================*/
void PromptUserForInput(Student StudentData[], int& PositionIndex)
{	

			cin.ignore(); 
			cout << "Please enter the student's first name: ";
			getline(cin, StudentData[PositionIndex].FirstName);
			
			cout << "Please enter the student's last name: ";
			getline(cin, StudentData[PositionIndex].LastName);


			cout << "Please enter the student's GPA: ";
			cin >> StudentData[PositionIndex].GPA;

			cout << endl;
}


/*============================================================
Function Name: Menu
Description: This will prompt the user for instructions
Input: UserInput	(int)
output: UserInput is pass by reference 
==============================================================*/
void Menu(int& UserInput)
{
	cout << "==========================================" << endl;
	cout << "1. Add a student" << endl; 
	cout << "2. List Students" << endl;
	cout << "3. List student(s) with highest GPA" << endl;
	cout << "==========================================" << endl;
	cin >> UserInput;
	cout << endl;
}


/*======================================================================
Function Name: List Students
Description: This will Loop through the user inputs and diplsay them
Input: Student			(struct)
	   Position index	(int)
output: void
======================================================================*/
void ListStudents( Student StudentStruct[], int PositionIndex)
{
	//Additional display to console (formatting)
	cout << "Student List ";
	cout << "(First, Last, GPA)" << endl;

	//loop through user inputs
	for(int i = 0; i < PositionIndex; i++)
	{
		 cout << i + 1;
		 UserPromptForListing(StudentStruct[i]);
		cout << endl;
	}
	cout << endl;
}


/*======================================================================
Function Name: UserPromptForListing
Description: Contains the prompts for user menu 2, which is listing
				all the students
Input: Student	(struct)
output: void
======================================================================*/
void UserPromptForListing(Student StudentInformation)
{
	//displays
	cout << ". "<< StudentInformation.FirstName << " ";
	cout << StudentInformation.LastName << " ";
	cout << StudentInformation.GPA;

}


/*======================================================================
Function Name: DeterminingLargestGPA
Description: Determining which student has the largest GPA
Input: Student		(struct)
	   PriceIndex	(int)
output: void
======================================================================*/
float DeterminingLargestGPA(Student StudentsGPA[], int PriceIndex)
{
	//variables
	float HighestGPA = StudentsGPA[0].GPA;
	
	//loop through the indexes
	for (int i = 0; i < PriceIndex; i++)
	{
		if(StudentsGPA[i].GPA > HighestGPA)
		{
			HighestGPA = StudentsGPA[i].GPA;
		}
	}
	return HighestGPA;
}