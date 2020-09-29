/* Sharon Omenda
C++ Fall 2020
Due 09/28/2020
Lab 3 User and File I/O.
This lab is designed to compute and output the mean and population standard deviation of a set of four integers using C++.
*/
#include <iostream>
#include <fstream> // File input and out
#include <string> // string input
#include <iomanip> // used for set precision and fixed reserved words
#include <cmath> // used for power function

using namespace std;

float meanFunction(int, int, int, int); // prototype for mean function
float stdFunction(int, int, int, int, float); //prototype for th epopulation standard deviation

int main()
{
	int value1;
	int value2;
	int value3;
	int value4;

	ifstream inputFilename; //input identifiers
	ofstream outputFilename;

	inputFilename.open("inMeanStd.dat.txt"); // opens the files
	outputFilename.open("outMeanStd.dat.txt");

	inputFilename >> value1 >> value2 >> value3 >> value4; // read integers from inMeanstd.dat into num input variabes

	outputFilename << "The population standard deviation of the four integers: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << fixed << setprecision(6) << endl;

	//Calculations
	outputFilename << "The mean of the integers user entered: " << meanFunction(value1, value2, value3, value4) << endl;
	outputFilename << "The population standard deviation of the four integers: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4));

	inputFilename.close();
	outputFilename.close();

	// prompt for user
	cout << "Enter four integers. Kindly make sure to then hit enter between your integers" << endl;
	cin >> value1 >> value2 >> value3 >> value4;

	
	cout << "The program calculated the following values:" << endl;
	cout << " The mean of the four integers is: " << meanFunction(value1, value2, value3, value4) << fixed << setprecision(4) << endl;
	cout << " The population standard deviation of the four integers: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << fixed << setprecision(6) << endl;

	return 0;

}

float meanFunction(int value1, int value2, int value3, int value4) //function definition for the mean
{
	return (float(value1 + value2 + value3 + value4) / float(4));
}

float stdFunction(int value1, int value2, int value3, int value4, float average) // function definition for the standard deviation
{
	return sqrt((float(pow((value1 - average), 2) + pow((value2 - average), 2) + pow((value3 - average), 2) + pow((value4 - average), 2)) / 4));
}