#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

constexpr auto MAX_TRIES = 8;

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

bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
