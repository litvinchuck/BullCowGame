#pragma once
#include <iostream>
#include <string>

using int32 = int;
using FText = std::string;

struct FTextMetrics {
	int32 NumberOfLines = 0;
	int32 MaxLineLength = 0;
};

void PrintCowSay(FText);
FTextMetrics GetTextMetrics(FText);
void PrintCowSpeechBubble(FText);
