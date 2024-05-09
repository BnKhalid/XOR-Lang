#include <bits/stdc++.h>
#include "globalheaders.h"

using namespace std;

int main(int argc, char *argv[]) {
    string line;
    bool showAST = argc > 1 && string(argv[1]) == "-ShowAST";
    int lineNum = 1;
    map<string, Value> variables;

    while (true) {
        cout << "\x1B[32m" << lineNum++ << "❯ \x1B[0m";
        getline(cin, line);

        if (line.empty())
            break;

        Parser par(line, &variables);
        SyntaxTree *tree = par.parse();
        ErrorList errors = tree->getErrors();
        Evaluator eval(tree->getRoot(), &variables, &errors);
        Value result = eval.evaluate();

        if (showAST) {
            Utilities::print(tree->getRoot(), "", true);
            Utilities::printResult(result);
        }

        Utilities::printErrors(errors);
    }
    return 0;
}
