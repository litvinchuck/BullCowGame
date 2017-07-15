/*
 * Game View
 */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "FBullCowGame.h"
#include "cowsay.h"

// Make syntax Unreal friendly
using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();

const FText WIN_MESSAGE = "You won!\n";
const FText LOSE_MESSAGE = "Better luck next time!\n";

FBullCowGame BCGame;

int main() {
	do {
		BCGame.Reset();
		PrintIntro();
		PlayGame();
		PrintGameSummary();
	} while (AskToPlayAgain());

	return 0;
}

void PrintIntro() {
	std::stringstream IntroText;
	IntroText << "\n\nWelcome to Bulls and Cows, a fun letter game!\n" <<
				 "Can you guess the " << BCGame.GetHiddenWordLenght() <<
				 " letter isogram I'm thinking of?\n\n";
	PrintCowSay(IntroText.str());
	return;
}

/*
 * Gets a guess from a user and checks its validity.
 */
FText GetValidGuess() {
	EGuessStatus Status= EGuessStatus::Invalid_Status;
	FText Guess = "";
	do {
		std::cout << "Try " << BCGame.GetCurrentTry();
		std::cout << " of " << BCGame.GetMaxTries();
		std::cout << ". Your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLenght() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter your guess in lowercase.\n\n";
			break;
		default:
			Status = EGuessStatus::OK;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;
}

/*
 * Plays a single game to completion
 */
void PlayGame() {
	int32 MaxTries = BCGame.GetMaxTries();
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();
		FBullCowCount BCCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BCCount.Bulls;
		std::cout << ". Cows = " << BCCount.Cows << "\n\n";
	}
	return;
}

bool AskToPlayAgain () {
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

/*
 * Display whether game was won or not
 */
void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << WIN_MESSAGE;
	}
	else {
		std::cout << LOSE_MESSAGE;
	}
}
