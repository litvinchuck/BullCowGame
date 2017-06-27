#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = FString;
using int32 = int;

void PrintIntro();
FText GetGuess();
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
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

FText GetGuess() {
	std::cout << "Try " << BCGame.GetCurrentTry();
	std::cout << ". Your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	for (int32 turn = 1; turn <= MaxTries; turn++) {
		FText Guess = GetGuess();
		FBullCowCount BCCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BCCount.Bulls;
		std::cout << ". Cows = " << BCCount.Cows;
		std::cout << std::endl;
	}

	// TODO: summarize game

	return;
}

bool AskToPlayAgain () {
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
