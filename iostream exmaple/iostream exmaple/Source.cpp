/*
File Name: File IO Example
Created by: 
Date: 3/5/15
Description: Demonstrate File input and output
*/
#include<string>
#include<iostream>
#include <fstream> //for file I/O 
using namespace std; 

void main() { 
	ofstream Userinputfile;
	string input[3];
	string temp;
	Userinputfile.open("myOutputFile.txt", ios::out);

	for(int i = 0; i < 3;i++)
	{
		cin >> input[i];
		//getline(Userinputfile, temp);
		Userinputfile << input[i];
	}
	
	
	Userinputfile.close();
	
	ifstream outputFile; 
	string output;

	//open the file 
	outputFile.open("myOutputFile.txt"); 

	//cin >> userinput;
	//write the data 
	getline(outputFile,output);
	//outputFile >> userinput;
	//outputFile << 10 << endl << 3.45 << endl; 

	//close the file 
	outputFile.close(); 

	cout << output;

	cin.get();
	cin.ignore();
} 