#include "SyntaxConverter.h"

SyntaxConverter::SyntaxConverter(int n, string start,  string rule)
{
    startSymbol = start;
    derivationRule = rule;
    numberOfDerivations = n;
}

string SyntaxConverter::expandSymbol() {

	string current = startSymbol;
	string expandedString = "";

	if ( numberOfDerivations == 0 ) {
		return startSymbol;
	}

	while (numberOfDerivations > 0) {

		// "F" stands for forward movement specified in the direction determined by the given angle
		for (unsigned int i = 0; i < current.size(); i++) {

			if ( current.at(i) == 'F' && current.size() == 1) {
				expandedString += derivationRule;
			}
			else {

				if ( current.at(i) == 'F' ) {
					expandedString += derivationRule;
				}
				else {
					expandedString += current.at(i);
				}

			}
		}

		current = expandedString;
		expandedString = "";
		numberOfDerivations--;
	}

	return current;
}

