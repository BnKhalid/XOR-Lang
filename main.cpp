#include <iostream>
#include "headers/utils/lexer.h"
#include "enums/syntaxkind.h"

using namespace std;

int main() {
    string line;

    while (true) {
        cout << "> ";
        getline(cin, line);

        if (line.empty())
            break;

        Lexer lex(line);

        while (true) {
            SyntaxToken token = lex.nextToken();

            if (token.getKind() == EndOfLineToken)
                break;

            token.print();
        }
    }
    return 0;
}

