/***********************************************************************************
Colin Derdowski
COmputer Science Fall 2026
September 29 2026
Calculating Mean and Standard Deviation using Different Forms of Inputs and Outputs
***********************************************************************************/

//inlcudes libraries that I need to pull from throughout my code
#include<iostream>
#include<cmath>
#include<fstream>

float mean(int a, int b, int c, int d); //prototype for mean function for the values from data.dat

float standard_deviation(int a, int b, int c, int d); //prototype for standard deviation function for the values from data.dat

float mean2(int w, int x, int y, int z); //prototype for mean function for the user inputed values

float standard_deviation2(int w, int x, int y, int z); //prototype for standard deviation function for the user inputed values

int main()
{
	int a, b, c, d; //assigning variables as integers to store the values from data.dat
	float e; //creating a float variable to later use for the mean from data.dat

	std::ifstream infile; //pulling from the fstream library to be able to use data from data.dat

	infile.open("data.dat"); //opens the data.dat file to be able to use the values from it in my calculations

	infile >> a >> b >> c >> d; //assigning the values from data.dat to the variables a, b, c, and d which are stored as integers from line 18

	e = mean(a, b, c, d); //assigning the mean function to my variable e

	std::ofstream outfile; //again, pulling from the fstream library, this time to be able to output my results to my out.dat file

	outfile.open("out.dat"); //opens the out.dat file

	//lines 34 & 35 send my results from the calculations to the out.dat file
	outfile << "mean from file: " << e << std::endl;
	outfile << "standard deviation from file: " << standard_deviation(a, b, c, d) << std::endl;

	infile.close();
	outfile.close(); //closes the out.dat file

	//same as lines 18 & 19, but this time for the user inputed values using different variables
	int w, x, y, z;
	float v;

	std::cout << "Enter four numbers, press enter after each number:" << std::endl; //prompts the user to input numbers for my calculation
	std::cin >> w >> x >> y >> z; //takes the user inputs and assigns thoes values into my variables w, x, y, and z
	std::cout << "The inputed values are: " << w << ", " << x << ", " << y << ", and " << z << std::endl; //outputs back the user iputs to the console confirming the input

	v = mean2(w, x, y, z); //assigns the mean function to my variable v for the user inputed values

	// lines 50 & 51 output the results of the user inputed values to the console
	std::cout << "The mean of " << w << ", " << x << ", " << y << ", and " << z << " is " << v << std::endl;
	std::cout << "The standard deviation of " << w << ", " << x << ", " << y << ", and " << z << " is " << standard_deviation2(w, x, y, z) << std::endl;

	return 0;
}

//lines 56 - 76 are assigning equations to all of my functions that I prototyped and referenced throughout my code.
float mean(int a, int b, int c, int d)
{
	return(a + b + c + d) / 4.0;
}

float standard_deviation(int a, int b, int c, int d)
{
	float e = mean(a, b, c, d);
	return std::sqrt(((a - e) * (a - e) + (b - e) * (b - e) + (c - e) * (c - e) + (d - e) * (d - e)) / 4.0);
}

float mean2(int w, int x, int y, int z)
{
	return (w + x + y + z) / 4.0;
}

float standard_deviation2(int w, int x, int y, int z)
{
	float v = mean2(w, x, y, z);
	return std::sqrt(((w - v) * (w - v) + (x - v) * (x - v) + (y - v) * (y - v) + (z - v) * (z - v)) / 4.0);
}

