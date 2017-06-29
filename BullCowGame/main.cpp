#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = FString;
using int32 = int;

void PrintIntro();
FText GetValidGuess();
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main() {
	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}

void PrintIntro() {
	std::cout << "Welcome to Bulls and Cows, a fun letter game!\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght();
	std::cout << " letter isogram I'm thinking of?\n\n";
	return;
}

FText GetValidGuess() {
	EGuessStatus Status= EGuessStatus::Invalid_Status;
	FText Guess = "";
	do {
		std::cout << "Try " << BCGame.GetCurrentTry();
		std::cout << ". Your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLenght() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter your guess in lowercase.\n";
			break;
		default:
			Status = EGuessStatus::OK;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
}

void PlayGame() {
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();
	for (int32 turn = 1; turn <= MaxTries; turn++) {
		FText Guess = GetValidGuess();
		FBullCowCount BCCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BCCount.Bulls;
		std::cout << ". Cows = " << BCCount.Cows << "\n\n";
	}

	// TODO: summarize game
	// TODO: cow say

	return;
}

bool AskToPlayAgain () {
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
