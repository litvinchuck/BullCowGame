#pragma once

#include "FBullCowGame.h"
#include <map>
#include <time.h>
#include <vector>

// Make syntax Unreal friendly
#define TMap std::map
using FString = std::string;
using int32 = int;

constexpr int32 MAX_TRIES = 3;
// Words must be isograms
const std::vector<FString> HIDDEN_WORDS { "cow", "guy", "sky", "rum", "oil", "seal", "slew", "silk", "rage", "view", "bruno", "quart", "throb", "planet"};
const int32 GUESS_PERCENTAGE = 30;

FBullCowGame::FBullCowGame()
{
	Reset();
}

/*
 * Computes the number of tries based on hidden word length
 */
int32 FBullCowGame::GetMaxTries() const
{
	return GetHiddenWordLenght() + std::ceil((GUESS_PERCENTAGE / 100.0) * GetHiddenWordLenght());
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

/*
 * Randomly chooses and returns a hidden word
 */
FString FBullCowGame::ChooseHiddenWord() const
{
	srand(time(NULL));
	int32 index = HIDDEN_WORDS.size();
	return HIDDEN_WORDS[rand() % HIDDEN_WORDS.size()];
}

int32 FBullCowGame::GetHiddenWordLenght() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bWordGuessed;
}

/*
 * Checks whether submitted guess is valid, whether guess is an isogram,
 * whether guess is lowercase, whether guess is the same length as hidden word.
 */
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLenght()) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}

/*
 * Resets the game to starting state
 */
void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	MyHiddenWord = ChooseHiddenWord();
	bWordGuessed = false;
	return;
}

/*
 * Returns the number of bulls and cows in guessed word
 * Increments the current try
 * Checks whether the word was guessed
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
	if (BCCount.Bulls == WordLength) {
		bWordGuessed = true;
	}
	return BCCount;
}

/*
 * Checks whether a word is an isogram (has no repeating letters in it)
 */
bool FBullCowGame::IsIsogram(FString Word) const {
	if (Word.length() <= 1) {
		return true;
	}
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) {
		Letter = tolower(Letter);
		if (LetterSeen[Letter] == true) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
	}
	return true;
}


/*
 * Checks whether word is all lowercase
 */
bool FBullCowGame::IsLowercase(FString Word) const {
	for (auto Letter : Word) {
		if (!islower(Letter) && !isspace(Letter)) {
			return false;
		}
	}
	return true;
}
