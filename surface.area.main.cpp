/****************************************************
Colin Derdowski
Computer Science Fall 2026
September 4, 2026
Calculating the volume & surfance area of a cylinder
****************************************************/


#include <iostream>
// I included the <numbers> library so that I could pull the value of pi in my calculations.
#include <numbers>

float calculateVolume(float radius, float height);
// float calculateSurfaceArea() - creates a function to calculate surface area given variables I created (radius & height)
float calculateSurfaceArea(float radius, float height);

int main()
{
	float height = 6;
	float radius = 5.2;
	/* Using std::cout to print out a set of text when I run the code so that the viewer can more easily see what
	my code actually yeilds for answers to the given problem */
	std::cout << "Volume of a Cylinder with height " << height << " and radius " << radius << " is: " << calculateVolume(radius, height) << std::endl;

	std::cout << "Surface Area of the Cylinder is: " << calculateSurfaceArea(radius, height) << std::endl;

	return 0;
}
// V=r²πh
float calculateVolume(float radius, float height)
{
	/* using the formula for volume of a cylinder, I recreated it here using my variables for radius and height,
	using the numbers library, I am also able to use pi by using std::numbers::pi */
	return radius * radius * height * std::numbers::pi;
}
// A=2πrh+2πr2
float calculateSurfaceArea(float radius, float height)
{
	/* using the formula for surface area of a cylinder, I recreated it using the variables radius and height.
	Again, I used std::numbers::pi to get the value of pi.*/
	return 2 * std::numbers::pi * radius * height + 2 * std::numbers::pi * radius * radius;
}