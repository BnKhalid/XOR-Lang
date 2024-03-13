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
        SyntaxTree *syntax = par.parse();

        Utilities::print(syntax->getRoot(), "", true);

        if (syntax->getDiagnostics().empty() == false) {
            for (auto msg : par.getDiagnostics())
                cout << msg << '\n';
        }
    }
    return 0;
}
