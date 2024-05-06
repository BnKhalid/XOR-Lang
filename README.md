# XOR-Lang

## Grammar
```
program ::= statement*
statement ::= expression | declaration
declaration ::= "var" IDENTIFIER "=" expression
expression ::= term (("+" | "-") term)*
term ::= factor (("*" | "/") factor)*
factor ::= unary (("+" | "-") unary)*
unary ::= ("+" | "-") unary | primary
primary ::= NUMBER | STRING | "true" | "false" | "(" expression ")"
```

## if statement
```
if expression then statement
```

