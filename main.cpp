#include <bits/stdc++.h>
#include "globalheaders.h"

using namespace std;

int main() {
    string line;
    bool showTree = false;
    int lineNum = 1;

    map<string, void *> variables;

    while (true) {
        cout << lineNum++ << "❯ ";
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

        Parser par(line, &variables);
        SyntaxTree *tree = par.parse();
        ErrorList errors = tree->getErrors();
        Evaluator eval(tree->getRoot(), &variables, &errors);
        void *result = eval.evaluate();

        // if (showTree)
            Utilities::print(tree->getRoot(), "", true);

        Utilities::printResult(result);

        Utilities::printErrors(errors);
    }
    return 0;
}
