/***************************
Colin Derdowski
Computer Science Fall 2026
November 10th 2026
Lab 5: random number game
***************************/

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

//if the guess is = to the random number, then outputs one of the 10 different messages for winning
void correctGuess(int intGuess);
//if the guess is in range, but below the random number, then output an "incorrect" message for being too low
void tooLow();
//if the guess is in range, but greater than the random number, then output an "incorrect" message for being too high
void tooHigh();
//if the geuss is not between 0-100, then output a random message for not being in range
void OutOfRange(int intGuess);
//if the won condition was not triggerd then this function will be called outputting one of the random loss messages
void youSuck(int RandomNum);
//once the number of guesses left is 0, then will display one of the 10 play again messages
void PlayAgainPrompt();

int main()
{
	srand(time(NULL));

	int intGuess; //the input for the user inputted guesses
	int guessnum; //the intiger to keep track of how many guesses are left
	char playAgain; //the character input for the user input to say "Y/N" to playing again

	bool keepPlaying = true; //this is the boolian that as long as it is true will run the loop that plays the game
	int wins = 0; //the integer that tacks #of wins
	int losses = 0; //the integer that tracks the #of losses


	do //while keepPlaying = true
	{
		int RandomNum = rand() % 101; //creates the random number, uses 101 since 0-100 is 101 characters
		guessnum = 20; //sets the initial # of guesses to 20
		bool won = false; //the condition that triggers if the user guesses the correct number

		cout << "You have 20 tries to guess a random number generated that is between 0 and 100.\nOnce you've ran out of guesses, the game will end.\nDon't worry though, you can always play again!\nTo submit a guess, press enter after typing your number.\nFinally, just remember the number can only be between 0 & 100 so don't waste a try by guessing outside of that range!\nGood Luck!";
		cout << endl << endl << "Please enter your guess: ";
		for (int i = 0; i < guessnum; i++) //for loop where as long as the number of times the loop has ran is less than the number of guesses the user has, it will continue to run
		{
			cin >> intGuess; //input statement for the guess

			if (intGuess == RandomNum) //win check
			{
				correctGuess(intGuess);
				guessnum = 0; //sets the remaining guesses to 0 since the user has already won
				wins = wins + 1; //updates the win count
				won = true; //changes the won bool to true bypassing the loss condition
			}

			else if (intGuess < 0 || intGuess > 100) //check if the guess is outside of the range
			{
				OutOfRange(intGuess);
			}

			else if (intGuess < RandomNum) //the check to see if the user's guess was below the random number
			{
				tooLow();
			}

			else //if its in range and not less than the random number, then it must be too high
			{
				tooHigh();
			}

			if (i < 19) //this is the check to make sure that the user still has another guess remaining so that the output does not prompt to play again if the user cannot
			{
				cout << "Guess again: ";
			}
		}

		if(won != true) //intGuess!=RandomNum) <- was my original check but I changed it to if the won condition was not changed to true for if the user lost
		{
			youSuck(RandomNum);
			losses = losses + 1;
		}

		PlayAgainPrompt();
		cin >> playAgain;

		switch (playAgain) //switch case based on the char inputted by the user into playAgain
		{
		case 'y':
		case 'Y': //both uppercase and lowercase y for yes
			cout << endl;
			keepPlaying = true;
			break;
		case 'n':
		case 'N': //both uppercase and lowercase n for no
			keepPlaying = false;
			break;
		default: //if none of the other cases were triggered then it defaults to no
			cout << "Invalid input. Since you can't listen, I'll take that as a no." << endl;
			keepPlaying = false;
			break;
		}

	} while (keepPlaying); //the check to make sure the user wants to play again before the loop is triggerd again

	//the ending message if the user decides they're done, displays the wins and losses count
	cout << "Thanks for playing! You won " << wins << " times and lost " << losses << " times." << endl; 
	return 0;
}

void tooHigh()
{
	int k = rand() % 10 + 1; //generates a random number to pick from the corresponding messages
	switch (k)
	{
	case 1:
		cout << "Too high! "; //Try again: ";
		break;
	case 2:
		cout << "Nope, that's too high! "; //Guess again : ";
		break;
	case 3:
		cout << "Good guess! Unfortunately, it's too high."; //Try again: ";
		break;
	case 4:
		cout << "That's not it! (try a little less) "; //Lower your guess : ";
		break;
	case 5:
		cout << "You're overshooting! "; //Guess lower: ";
		break;
	case 6:
		cout << "Not quite! A little lower. ";
		break;
	case 7:
		cout << "That's too much! "; // Try a smaller number : ";
		break;
	case 8:
		cout << "You're getting somewhere... Still a tad high though. ";
		break;
	case 9:
		cout << "That's not the number! "; //Lower your guess: ";
		break;
	case 10:
		cout << "Que Grande! "; //Guess lower : ";
		break;
	}
}

void tooLow()
{
	int k = rand() % 10 + 1; //generates a random number to pick from the corresponding messages
	switch (k)
	{
	case 1:
		cout << "Too low! ";// Try again : ";
		break;
	case 2:
		cout << "Ehh, that's too low! ";// Guess again : ";
		break;
	case 3:
		cout << "I would love that if it were higher! Unfortunately, it's too low. ";// Try again : ";
		break;
	case 4:
		cout << "Nope! Raise your guess. ";
		break;
	case 5:
		cout << "You're undershooting! ";//Guess higher : ";
		break;
	case 6:
		cout << "That would be a good guess if that was the number but its too low. "; //Give me something else: ";
		break;
	case 7:
		cout << "That's too small! "; // Try a bigger number : ";
		break;
	case 8:
		cout << "I mean... I dont hate it... ";//Guess higher : ";
		break;
	case 9:
		cout << "That's not the number! (Raise your guess) ";
		break;
	case 10:
		cout << "Que Pequeno! "; //Guess higher : ";
		break;
	}
}

void correctGuess(int intGuess)
{
	int k = rand() % 10 + 1; //generates a random number to pick from the corresponding messages
	switch (k)
	{
	case 1:
		cout << "Congratulations! " << intGuess << " is the correct number!" << endl;
		break;
	case 2:
		cout << "You did it! " << intGuess << " is the right answer!" << endl;
		break;
	case 3:
		cout << "Well done! You've guessed the number: " << intGuess << endl;
		break;
	case 4:
		cout << "Fantastic! " << intGuess << " is the correct number!" << endl;
		break;
	case 5:
		cout << "Wow! You've smashed it with " << intGuess << endl;
		break;
	case 6:
		cout << "I was starting to doubt you! But you've done it with " << intGuess << "!" << endl;
		break;
	case 7:
		cout << "You got it! The correct number is " << intGuess << endl;
		break;
	case 8:
		cout << "I'm so proud of you! You've guessed the right number: " << intGuess << endl;
		break;
	case 9:
		cout << "Come on down! You've correctly guessed " << intGuess << " as the answer!" << endl;
		break;
	case 10:
		cout << "Amazing! You've found the correct number: " << intGuess << endl;
		break;
	}
}

void youSuck(int RandomNum)
{
	int k = rand() % 10 + 1; //generates a random number to pick from the corresponding messages
	switch (k)
	{
	case 1:
		cout << "You're really bad at this! The correct number was " << RandomNum << "." << endl;
		break;
	case 2:
		cout << "I'm sorry, but you've failed. The number was " << RandomNum << "." << endl;
		break;
	case 3:
		cout << "Looks like you're not very good at this. The correct number was " << RandomNum << "." << endl;
		break;
	case 4:
		cout << "This is embarrassing. The correct number was " << RandomNum << "." << endl;
		break;
	case 5:
		cout << "I can't believe you missed that. The correct number was " << RandomNum << "." << endl;
		break;
	case 6:
		cout << "You're doing a great job of failing. The correct number was " << RandomNum << "." << endl;
		break;
	case 7:
		cout << "Well, that was a fantastic failure. The correct number was " << RandomNum << "." << endl;
		break;
	case 8:
		cout << "I'm starting to think you're just here to make me mad. The correct number was " << RandomNum << "." << endl;
		break;
	case 9:
		cout << "This is getting old. The correct number was " << RandomNum << "." << endl;
		break;
	case 10:
		cout << "I give up on you. The correct number was " << RandomNum << "." << endl;
		break;
	}
}

void PlayAgainPrompt()
{
	int k = rand() % 10 + 1; //generates a random number to pick from the corresponding messages
	switch (k)
	{
	case 1:
		cout << "Would you like to play again? (Y/N): ";
		break;
	case 2:
		cout << "Do you want to try your luck again? (Y/N): ";
		break;
	case 3:
		cout << "Are you ready for another round? (Y/N): ";
		break;
	case 4:
		cout << "Care to give it another shot? (Y/N): ";
		break;
	case 5:
		cout << "Feeling lucky? Play again? (Y/N): ";
		break;
	case 6:
		cout << "Want to test your guessing skills again? (Y/N): ";
		break;
	case 7:
		cout << "How about another go at it? (Y/N): ";
		break;
	case 8:
		cout << "Think you can do better this time? (Y/N): ";
		break;
	case 9:
		cout << "Ready for a rematch? (Y/N): ";
		break;
	case 10:
		cout << "Up for another challenge? (Y/N): ";
		break;
	}
}


void OutOfRange(int intGuess)
{
	int k = rand() % 10 + 1; //generates a random number to pick from the corresponding messages
	switch (k)
	{
	case 1:
		cout << "I thought I told you the number can only be between 0 & 100! ";
		break;
	case 2:
		cout << "Seriously?? " << intGuess << " is not within the range! Please enter a number between 0 and 100. ";
		break;
	case 3:
		cout << "Out of bounds! Remember, the number is between 0 and 100. ";
		break;
	case 4:
		cout << "That's not even close! Enter a number between 0 and 100. ";
		break;
	case 5:
		cout << "You're really bad at this! Pick a number between 0 and 100. ";
		break;
	case 6:
		cout << "This is ridiculous! A number between 0 and 100, please. ";
		break;
	case 7:
		cout << "I'm starting to doubt your intelligence! Enter a valid number. ";
		break;
	case 8:
		cout << "You're going to make me tired with these invalid guesses! ";
		break;
	case 9:
		cout << "Let's try this again. Enter a number between 0 and 100. ";
		break;
	case 10:
		cout << "I'm done with you. Enter a valid number between 0 and 100. ";
		break;
	}
}