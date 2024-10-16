## Galop
described in `EBNF` from.

### Alphabet:
- **Letters**: `a-z`, `A-Z`
- **Digits**: `0-9`
- **Word Separators**: `_` and `-`

1. **Lexical rules**:
   - Special symbols:
      - Operators:
        - `+`, `-`, `*`, `/`,`:`, `$eq`, `$ne`, `$lt`, `$gt`, `$le`, `$ge`, `$and`, `$or`;
      - Separators:
        - `()`, `[]`, `{}`, `;`,` `(space); 
      - Key/Reserved words:
        - **type**: `Bool`, `Number`, `Char`, `String`, `Array`, `Any`;
        - **constants**: `true`, `false`;
        - **loops**: `onEach`, `onEachReverse`, `onRange`, `onRangeReverse`, `next`;
        - **conditionals**: `probe`, `otherwise`, `otherwise probe`;
    - Identifiers:
        - a sequence of letters, digits, `_` and `-` that starts with a letter:
        ```EBNF
        identifier = letter { letter | digit | word_separator } ;
        letter = "a" | "b" | ... | "z" | "A" | "B" | ... | "Z" ;
        digit = "0" | "1" | ... | "9" ;
        word_separator = "_" | "-" ;
        ```
    - Constants:
        - **Boolean**: `true`, `false`;
        - **Number**: a sequence of digits;
        - **Char**: a single character;
        - **String**: a sequence of characters starts with **"** and ends with **"**;
        - **Array**: a collection of elements;
        ```EBNF
        bool = true | false ;
        number = digit { digit } ;
        char = "'" letter | digit "'" ;
        string = '"' { char } '"' ;
        array = "[" type "," { constant [","] } "]" ;
        type = "Bool" | "Number" | "Char" | "String" | "Array";
        constant = bool | number | char | string | array ;
        ```

### DataTypes:
- **Boolean**: A value that can be either `true` or `false`.
    | constant | variable    |
    | -------- | ----------- |
    | true     | Bool(true)  |
    | false    | Bool(false) |
- **Number**: A sequence of digits.
    | constant | variable    |
    | -------- | ----------- |
    | 123      | Number(123) |
- **Char**: A single character.
    | constant | variable  |
    | -------- | --------- |
    | 'a'      | Char('a') |
    | '1'      | Char('1') |
    | ' '      | Char(' ') |
- **String**: A sequence of characters starts with **"** and ends with **"**.
    | constant | variable        |
    | -------- | --------------- |
    | "Hello"  | String("Hello") |
- **Array**: A collection of elements.
    | constant       | variable                                         |
    | -------------- | ------------------------------------------------ |
    | [1, 2]         | Array(Number, [1, 2])                            |
    | ['a', 'b']     | Array(Char, ['a', 'b'])                          |
    | [1,'a',"test"] | Array(Any, [Number(1),Char('a'),String("test")]) |
  