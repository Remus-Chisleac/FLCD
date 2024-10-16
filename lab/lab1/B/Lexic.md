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
        - **loops**: `onEach`, `onEachReverse`, `next`;
        - **conditionals**: `probe`, `otherwise`, `otherwise probe`;
        - **functions**: `fn`, `trigger`, `trigger-end`, `#[EntryPoint]`
    - Identifiers:
        - a sequence of letters, digits, `_` and `-` that starts with a letter:
        ```EBNF
        identifier = letter { letter | digit | word_separator } ;
        letter = "a" | "b" | ... | "z" | "A" | "B" | ... | "Z" ;
        digit = "0" | "1" | ... | "9" ;
        word_separator = "_" | "-" ;
        ```
    - Constants:
        - **Bool**: `true`, `false`;
        - **Number**: a sequence of digits;
        - **Char**: a single character;
        - **String**: a sequence of characters that starts with **"** and ends with **"**;
        ```EBNF
        bool = true | false ;
        number = ["+"|"-"] digit { digit } ;
        char = "'" letter | digit "'" ;
        string = '"' { char } '"' ;
        ```