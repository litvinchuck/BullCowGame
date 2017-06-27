#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// Holds the count value of bulls and cows in a word
// All values initialise to 0
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

// Game controller class
class FBullCowGame {
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO: make a more rich return value
	bool CheckGuessValidity(FString); // TODO: make a more rich return value
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyMaxTries;
	int32 MyCurrentTry;
	FString MyHiddenWord;
};
