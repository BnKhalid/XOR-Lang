#include <iostream>
#include "globalheaders.h"

using namespace std;

int main() {
    string line;
    bool showTree = false;

    while (true) {
        cout << "> ";
        getline(cin, line);

        if (line.empty())
            break;

        if (line == "cls") {
            system("clear");
            continue;
        }
        else if (line == "showTree") {
            showTree = !showTree;
            cout << (showTree ? "Showing" : "Hiding") << " syntax tree.\n";
            continue;
        }

        Parser par(line);
        SyntaxTree *tree = par.parse();

        if (tree->getDiagnostics().empty()) {
            Evaluator eval(tree->getRoot());
            cout << eval.evaluate() << '\n';
        }
        else {
            for (auto msg : tree->getDiagnostics())
                cout << msg << '\n';
        }

        if (showTree)
            Utilities::print(tree->getRoot(), "", true);
    }
    return 0;
}
