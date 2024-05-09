# Grammar

Here is the grammar that specify the syntax of the language:

```
Stmt       → Assign | Print | If | For | While | Expr
Assign     → Identifier = Expr | Identifier = Assign
Identifier → /[a-zA-Z_]+[0-9]*/
Expr       → (Expr) | Operand | UOperator Operand | Operand Operator Operand | Expr Operator Operand | Expr Operator Expr
UOperator  → + - !
Operator   → + - * / && || == != > < >= <=
Operand    → Identifier | Value
Value      → Bool | Int | String | List
Bool       → true | false
Int        → /[0-9]+/
String     → /\w*\s*/
List       → [ListValue]
ListValue  → Value | Value, ListValue
Print      → print : Expr
If         → if Expr then Stmt | if Expr then Stmt else Stmt
LoopStmt   → Stmt | continue | break
LoopIf      → if LoopStmt then LoopStmt | if LoopStmt then LoopStmt else LoopStmt
For        → for Identifier : Int do LoopStmt | for identifier : Int do LoopIf
While      → while Expr do LoopStmt | while Expr do LoopIf
```
