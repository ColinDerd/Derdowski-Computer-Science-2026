/********************************
Colin Derdowski
Computer Science Fall 2026
October 21 2026
Lab 4: Temperature Output
********************************/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{ 
	int temp;
	int numStars = 0;

	// Function prototypes for the temperature bar chart functions
	void positiveTemp(int temp);
	void negativeTemp(int temp);
	void padding(int temp);

	ifstream infile("temperatures.dat"); //Open the input hourly temperature file
	
	if (!infile) //Check if the file opened successfully
	{
		cout << "Error opening file." << endl;
		return 1;
	}

	//Print the header for the bar chart, including the scale
	cout << "   Temperature Bar Chart (Each star represents 3 degrees)" << endl;
	cout << "   ------------------------------------------------------" << endl;

	//create the scale for the bar chart, starting from -30 to 120, increasing by 15 since it is divisible by 3
	int m = -30; //lowest temperature in the range
	cout << "     ";
	while (m < 121) //makes it so that the scale is printed only up to 120 degrees
	{
		cout << m << "   ";
		m = m + 15;
	}
	cout << endl;

	while (infile >> temp) //runs the loop only while there is still data to store into the temp variable
	{
		if (temp < -30 || temp > 120) //Check if the temperature is within the range
		{
			cout << temp << " [Temperature out of range]" << endl;
			continue; //Skip to the next temperature if the current one is,  out of range
		}

		cout << temp << " "; //Print the temperature to the left of the bar

		padding(temp);
			
		if (temp >= 0) //Check if the temperature is positive
		{
			positiveTemp(temp);
		}

		else //If the temperature is negative
		{
			negativeTemp(temp);
		}
		
		cout << endl; //Move to the next line after printing the bar
		
	}
	infile.close(); //close the input file once all the data has been read (:
	return 0;
}

// Precondition: temp is between -30 and -1.
// Postcondition: Prints the appropriate number of stars for the temperature.
void padding(int temp)
{
	if (temp >= 0 && temp < 10) //Check if the temperature is a single digit
	{
		cout << "  "; //Print two spaces for single digit positive temperatures
	}
	else if (temp >= 10 && temp < 100) //Check if the temperature is a double digit
	{
		cout << " "; //Print one space for double digit positive temperatures
	}
	else if (temp < 0 && temp > -10) //Check if the temperature is a single digit negative
	{
		cout << " "; //Print one space for single digit negative temperatures
	}
}

// Precondition: temp is between 0 and 120.
// Postcondition: Prints the appropriate number of stars for the temperature.
void positiveTemp(int temp)
{
	int numStars = ((temp / 3.0) + 0.5); //to hanle rounding for positive temperatures
	int k = 13;

	while (k > 0)
	{
		cout << " "; //Print spaces to align the stars to the right
		k = k - 1;
	}
	cout << "|"; //represent the 0 degree line
	while (numStars > 0)
	{
		cout << "*";
		numStars = numStars - 1;
	}
}

// Precondition: temp is between -30 and 120.
// Postcondition: Prints the appropriate spaces to align the temperature bar.
void negativeTemp(int temp)
{ 
int numStars = ((temp / 3.0) - 0.5); //to handle rounding for negative temperatures

int k = 13 + numStars; //Adjust the number of spaces based on the number of stars representing negative temperatures

while (k > 0)
{
	cout << " ";
	k = k - 1;
}

while (numStars < 0) //print stars to the left of the 0 degree line for negative temperatures
{
	cout << "*";
	numStars = numStars + 1;
}

cout << "|"; //prints the line representing 0 degrees
}