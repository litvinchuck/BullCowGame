#include "cowsay.h"
#include <string>
#include <sstream>

using int32 = int;
using FText = std::string;

const FText Cow = "    \\   ^__^ \n"
					"     \\  (oo)\\_______ \n"
					"        (__)\\       )\\/\\ \n"
					"            ||----w | \n"
					"            ||     || \n";

void PrintCowSay(FText Text) {
	std::cout << "\n\n";
	PrintCowSpeechBubble(Text);
	std::cout << Cow << '\n';
	return;
}

/*
 * Computes the number of lines and maximum line length in a given String
 */
FTextMetrics GetTextMetrics(FText Text) {
	FText Line;
	std::istringstream Stream(Text);
	FTextMetrics TextMetrics;
	while (std::getline(Stream, Line)) {
		int32 LineLength = Line.length();
		if (LineLength > 0) {
			TextMetrics.NumberOfLines++;
		}
		if (LineLength > TextMetrics.MaxLineLength) {
			TextMetrics.MaxLineLength = LineLength;
		}
	}
	return TextMetrics;
}

/*
 * Completes the String empty space untill its meets the given Length
 * Returns unchanged String if Length is smaller or equalls to String length
 */
FText FillStringToLength(FText String, int32 Length) {
	if (String.length < Length) {
		return String + FText(Length - String.length(), ' ');
	}
	else {
		return String;
	}
}

void PrintCowSpeechBubble(FText Text) {
	FText Line;
	int32 LineIndex = 0;
	std::istringstream Stream(Text);
	FTextMetrics TextMetrics = GetTextMetrics(Text);

	while (std::getline(Stream, Line)) {
		if (Line.length() > 0) {
			if (LineIndex == 0) {
				std::cout << "/ " << FillStringToLength(Line, TextMetrics.MaxLineLength) << " \\ \n";
			}
			else if (LineIndex == (TextMetrics.NumberOfLines - 1)) {
				std::cout << "\\ " << FillStringToLength(Line, TextMetrics.MaxLineLength) << " / \n";
			}
			else {
				std::cout << "| " << FillStringToLength(Line, TextMetrics.MaxLineLength) << " |\n";
			}
			LineIndex++;
		}
	}
	return;
}
