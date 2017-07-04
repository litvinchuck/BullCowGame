#include "cowsay.h"
#include <string>
#include <sstream>

using int32 = int;
using FText = std::string;

const FString Cow = "    \\   ^__^ \n"
					"     \\  (oo)\\_______ \n"
					"        (__)\\       )\\/\\ \n"
					"            ||----w | \n"
					"            ||     || \n";

void PrintCowSay(FString Text) {
	//TODO: cow speech bubble
	int32 TextSize = Text.size();
	std::cout << Text;
	std::cout << Cow << '\n';
}
