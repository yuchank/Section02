/*
	This is the console executable, that makes used of the BullCow class
	This acts as the view int a MVC pattern, and is responsible for all user interaction.
	For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;	// instantiate

// the entry poing for our application.
int main() 
{
	do {
		PrintIntro();
		PlayGame();
		// TODO add a game summary
	} while (AskToPlayAgain());
	
	return 0;	// exit the application
}


// introduce the game
void PrintIntro() 
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	for (int32 count = 0; count < MaxTries; count++) {
		FText Guess = GetGuess();		// TODO make loop checking valid
		// submit valid guess to the game.
		// print number of bulls and cows
		std::cout << "Your guess was: " << Guess << std::endl;	
		std::cout << std::endl;
	}

	// summarise game here
	return;
}


FText GetGuess() 
{
	int32 CurrentTry =  BCGame.GetCurrentTry();

	// get a guess from the player
	FText Guess = "";
	
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);

	return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return tolower(Response[0]) == 'y';
}

