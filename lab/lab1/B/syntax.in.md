```EBNF
(* "" - terminals*)
(* all caps - reference from another file*)

program = [{function}] "#[EntryPoint]" function [{function}];

function = [fn-identifier] "fn" "(" fn-parameter ")" "{" { statement } "trigger-end(" [NUMBER] ")" "}";
fn-parameter = [parameter { "," parameter }]
fn-identifier = IDENTIFIER;
parameter = IDENTIFIER [":" types];
types = simple-types |  "Array";
simple-types = "Bool" | "Number" | "Char" | "String";

statement = declaration-stmt | assignment-stmt | loop-stmt | conditional-stmt | IO-stmt | function-stmt;

declaration-stmt = "alloc" IDENTIFIER { "," IDENTIFIER} ":" types "(" declaration-expression ")" ";";
declaration-expression = [simple-expression | array-expression];
simple-expression = constant | IDENTIFIER;
constant = BOOL | NUMBER | CHAR | STRING;
array-expression = types "[" {declaration-expression} "]";

assignment-stmt = IDENTIFIER ":" assignment-expression ";";
assignment-expression = simple-expression | array-assignment-expression;
array-assignment-expression = "Array(" array-expression")";

loop-stmt = "onEach"|"onEachReverse" "(" IDENTIFIER "," function ")"

conditional-stmt = "probe" "(" condition ")" "{" { statement } "}" [("otherwise" "{" { statement } "}") | ("otherwise" conditional-stmt)];
condition = simple-expression relation simple-expression 
relation = "$eq" | "$ne" | "$lt" | "$gt" | "$le" | "$ge" | "$and" | "$or";

IO-stmt = "console." ("push"| "cr"| "read") "(" simple-expression ")" ";";

function-stmt = [IDENTIFIER ":"] "trigger" fn-identifier "(" fn-parameter ")"  ";";

```