#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

constexpr int32 MAX_TRIES = 8;
const FString HIDDEN_WORD = "planet";

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLenght() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) {
		return EGuessStatus::Not_Isogram;
	}
	else if (false) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLenght()) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}

void FBullCowGame::Reset()
{
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	return;
}

/*
 * Returns the number of bulls and cows in guessed word
 * Increments the current try
 * Assumes the guess length is the same as hidden word length
 */
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BCCount;
	int32 WordLength = MyHiddenWord.length();
	for (int32 i = 0; i < WordLength; i++) {
		for (int32 j = 0; j < WordLength; j++) {
			if ((i == j) && (MyHiddenWord[i] == Guess[j])) {
				BCCount.Bulls++;
			}
			else if ((MyHiddenWord[i] == Guess[j])) {
				BCCount.Cows++;
			}
			else {
				continue;
			}
		}
	}
	return BCCount;
}
