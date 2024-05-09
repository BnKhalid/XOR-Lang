# XOR-Lang

## Introduction

**XOR-Lang** is a simple, **interpreted**, and **dynamically typed** programming language. It is implemented in **C++** language from scratch.

## Features

- **Simple**: XOR-Lang is a simple language with a minimalistic syntax.
- **Interpreted**: XOR-Lang is an interpreted language.
- **Dynamically Typed**: XOR-Lang is a dynamically typed language.
- **Variables**: XOR-Lang supports variables.
- **Arithmetic Operators**: XOR-Lang supports arithmetic operators.
- **Logical Operators**: XOR-Lang supports logical operators.
- **Scoping**: XOR-Lang supports scoping.
- **If-Else Statements**: XOR-Lang supports if-else statements.
- **Loops**: XOR-Lang supports while and for loops.
- **Print Statement**: XOR-Lang supports print statements.
- **Error Handling**: XOR-Lang has a simple error handling mechanism.
- **Showing The AST**: XOR-Lang can show the abstract syntax tree (AST) of the source code.

## Main Layesrs of XOR-Lang

- **Lexer**: The lexer reads the source code and converts it into tokens.
- **Parser**: The parser reads the tokens and converts them into an abstract syntax tree (AST).
- **Evaluator**: The evaluator reads the AST and executes the code.

## Syntax

- ### Arithmetic Operators:
#### The following arithmetic operators are supported in XOR-Lang:
  - Addition: `+`
  - Subtraction: `-`
  - Multiplication: `*`
  - Division: `/`

#### Each operator has its own precedence level. The precedence levels are as follows:
  - Multiplication and Division
  - Addition and Subtraction

#### Example:
``` c++
a = 1 + 2 * 3   // a = 7
```
#### The precedence level can be changed by using parentheses.
``` c++
a = (1 + 2) * 3 // a = 9
```

#### There are also unary operators:
  - Unary Plus: `+` for positive sign
  - Unary Minus: `-` for negative sign

``` c++
a = -1      // a = -1
b = +1      // b = 1

a = -+-+-1  // -1
```

- ### Variables

#### To declare a variable in XOR-Lang, You must assign a value to it.
``` c++
a = 10
b = 20
```

#### You can declare multiple variables in a single assign statment.
``` c++
a = b = c = d = 10
```

#### Variables in XOR-Lang are dynamically typed. This means that you can assign any type of value to a variable.


``` c++
a = 10
b = "Hello, World!"
c = true
d = [1, "Hello", true, [1, 2, 3]] // List of different types

```
#### You can also reassign a variable with a different type of value.
``` c++
a = 10
a = "Hello, World!"
```

#### You can also use variables in arithmetic operations.
``` c++
a = 10
b = 20
c = a + b   // c = 30
```

- ### Logical Operators

#### XOR-Lang supports the following logical operators:
  - AND: `&&`
  - OR: `||`
  - NOT: `!`

#### Example:
``` c++
a = true
b = false
c = a && b      // c = false
d = a || b      // d = true
e = !a          // e = false
```

#### XOR-Lang also supports comparison operators:
  - Equal: `==`
  - Not Equal: `!=`
  - Greater Than: `>`
  - Less Than: `<`
  - Greater Than or Equal: `>=`
  - Less Than or Equal: `<=`

#### Example:
``` c++
a = 10
b = 20
c = a == b      // c = false
d = a != b      // d = true
e = a > b       // e = false
f = a < b       // f = true
g = a >= b      // g = false
h = a <= b      // h = true
```

#### You can also use logical operators in arithmetic operations.
``` c++
a = 10
b = 20
c = a + b > 30  // c = true
```

- ### If-Else Statements

#### XOR-Lang supports if-else statements.
the syntax is as follows:

``` c++
a = 10
b = 20

if a > b then 
    a = a + b
else 
    a = a - b
```

#### You can also use nested if-else statements.
``` c++
a = 10
b = 20

if a > b then
    if a == 10 then
        a = a + b
    else
        a = a - b
else
    a = a * b
```

#### You can use if-else statements with logical operators.
``` c++
a = 10
b = 20

if a > b || a == 10 then
    a = a + b
else
    a = a - b
```

#### You can also use only if statements.
``` c++
a = 10
b = 20

if a > b then
    a = a + b
```

- ### Loops

#### XOR-Lang supports while and for loops.
``` c++
a = 0

while a < 10 do
    a = a + 1
```

#### You can use for loops to specify the number of iterations.

``` c++
a = 0
for i : 10 do
    a = a + i
```

#### You can also use nested loops.
``` c++
a = 0
for i : 10 do
    for j : 10 do
        a = a + i + j
```

#### You can also use break and continue statements in loops.
``` c++
a = 0
for i : 10 do
    if i == 5 then
        break
    else 
        a = a + i
```

#### You can also use continue statement.
``` c++
a = 0
for i : 10 do
    if i == 5 then
        continue
    else 
        a = a + i
```

- ### Print Statement

#### XOR-Lang supports print statements.
``` c++
a = 10
print : a // 10

b = [1, "Hello", true, [1, 2, 3]] 
print : b // [ 1, Hello, true, [ 1, 2, 3 ] ]
```
