/*
 * Game logic
 * The game is a simple guess word game
 */

#pragma once

#include <string>

// Make syntax Unreal friendly
using FString = std::string;
using int32 = int;

/*
 * Holds the count value of bulls and cows in a word
 * All values initialise to 0
 */
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

/*
 * Status of the checked word
 */
enum class EGuessStatus {
	OK,
	Invalid_Status,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

/*
 * Game controller class
 *
 * Attributes:
 *  int32 MyCurrentTry - players current try
 *  FString MyHiddenWord - word that is being guessed
 *  bool bWordGuessed - whether or not word was guessed
 */
class FBullCowGame {
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	FString ChooseHiddenWord() const;
	int32 GetHiddenWordLenght() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bWordGuessed;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};
