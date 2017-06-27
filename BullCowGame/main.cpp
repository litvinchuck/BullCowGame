#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = FString;
using int32 = int;

constexpr int32 WORLD_LENGTH = 5;

void PrintIntro();
FText GetGuess();
void PrintGuess(FText guess);
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
	std::cout << "Welcome to Bulls and Cows, a fun letter game!" << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

FText GetGuess() {
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

void PrintGuess(FText Guess) {
	std::cout << "Your guess was: " << Guess << std::endl;
	return;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	for (int32 turn = 1; turn <= MaxTries; turn++) {
		PrintGuess(GetGuess()); // make loop check valid guess
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
