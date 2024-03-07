#include <iostream>
#include "globalheaders.h"

using namespace std;

int main() {
    string line;

    while (true) {
        cout << "> ";
        getline(cin, line);

        if (line.empty())
            break;

        Parser par(line);
        ExpressionSyntax *syntax = par.parse();

        utilities::print(syntax, "", true);
    }
    return 0;
}
