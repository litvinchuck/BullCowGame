/*
 * Code needed to generate and print a cowsay
 */
#pragma once

#include <iostream>
#include <string>

// Make syntax Unreal friendly
using int32 = int;
using FText = std::string;

/*
 * Holds the number of lines and max line length in a String
 * Used for generating cow speech bubble in PrintCowSpeechBubble
 */
struct FTextMetrics {
	int32 NumberOfLines = 0;
	int32 MaxLineLength = 0;
};

void PrintCowSay(FText);
FTextMetrics GetTextMetrics(FText);
void PrintCowSpeechBubble(FText);
