#include <iostream>
#include "globalheaders.h"

using namespace std;

int main() {
    string line;
    bool showTree = false;
    int lineNum = 1;

    while (true) {
        cout << lineNum++ << "> ";
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

        if (showTree)
            Utilities::print(tree->getRoot(), "", true);

        if (tree->getErrors().empty()) {
            Evaluator eval(tree->getRoot());
            cout << "The answer is: " << eval.evaluate() << '\n';
        }
        else {
            auto errors = tree->getErrors();
            for (int i = 0; i < errors.size(); i++) {
                Error *err;

                err = dynamic_cast<RuntimeError *>(errors[i]);
                if (err) {
                    cout << err->getMessage() << '\n';
                    continue;
                }

                err = dynamic_cast<IlligalCharacterError *>(errors[i]);
                if (err) {
                    cout << err->getMessage() << '\n';
                    continue;
                }

                err = dynamic_cast<SyntaxError *>(errors[i]);
                if (err) {
                    cout << err->getMessage() << '\n';
                    continue;
                }
            }
        }
    }
    return 0;
}
