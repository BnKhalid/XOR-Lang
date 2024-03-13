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
        SyntaxTree *tree = par.parse();

        Utilities::print(tree->getRoot(), "", true);

        if (tree->getDiagnostics().empty()) {
            Evaluator eval(tree->getRoot());
            cout << eval.evaluate() << '\n';
        }
        else {
            for (auto msg : tree->getDiagnostics())
                cout << msg << '\n';
        }
    }
    return 0;
}
