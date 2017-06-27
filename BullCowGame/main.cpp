#include <iostream>
#include <string>
#include "FBullCowGame.h"

constexpr auto WORLD_LENGTH = 5;

void PrintIntro();
std::string GetGuess();
void PrintGuess(std::string guess);
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

std::string GetGuess() {
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

void PrintGuess(std::string guess) {
	std::cout << "Your guess was: " << guess << std::endl;
	return;
}

void PlayGame() {
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	for (int turn = 1; turn <= MaxTries; turn++) {
		PrintGuess(GetGuess()); // make loop check valid guess
		std::cout << std::endl;
	}

	// TODO: summarize game

	return;
}

bool AskToPlayAgain () {
	std::cout << "Do you want to play again? (y/n) ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
