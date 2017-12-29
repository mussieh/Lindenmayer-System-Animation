#ifndef SYNTAXCONVERTER_H_
#define SYNTAXCONVERTER_H_
#include <string>
#include <list>
using namespace std;

class SyntaxConverter
{
public:
    SyntaxConverter(int n, string start,  string rule);
    string expandSymbol();
private:
    string startSymbol;
    string derivationRule;
    int numberOfDerivations;
};

#endif
