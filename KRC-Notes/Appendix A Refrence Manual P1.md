# APPENDIX A: Refrecne Manual
## A1. Introduction
This is about effect of ANSI into the C programming language.

## A2. Lexical Conventions
A program consits of one or more *translation units* stoed in files.
It is translated in several phases,
The first phases do low-level lexical transformations, carry out directives introduced by lines beginning with the `#` character, and preform macro definition and expansion.

When the preprocessing is complete, the program has been reduced to a sequence of tokens.


### Tokens
there are six classes of tokens:
1. identifires
1. keywords
1. constants
1. string literals
1. operators
1. other separators

> White space: blanks, tabs, formfeeds, comments, new lines...

> If the input stream has been seperated inot tokens up  to a given character, the next token is the longest string of characters that could constitute a token.

### Comments
Comments do not ocur within string or character literals.
Comments can be defined like:
```c
/*
This is a multi line comment
that contains a second line
*/

// This is a single line comment
```

### Indentifires
An identifier is a sequence of letters and digits, The first character must be letter.
the underscore (`_`) counts as a letter, Upper and lower case letters are differents.
Identifires may have any length, and for internal identifiers, at least the first 31 character are significant; some implementation may make more characters significant.
Internal identifires include preprocessor macro names and all other names that do no have external linkage.
Identifires with external linkage are more restricted: implementatinos may make as few as the first six characters as significant, and may ignore case distinctions.

### Keywords
The following identifires are reserved for use as keywords, and may not be used otherwise:
```c
auto      double    int       struct
break     else      long      switch
case      enum      register  typedef
char      extern    return    union
const     float     short     unsigned
continue  for       signed    void
default   goto      sizeof    volatile
do        if        static    while
```

NOTE: Some implementation also reseve the words `fortran` and `asm`
The keywords `const`, `signed` and `voltile` are new with the ANSI standatd, `enum` and `void` are new since the first edition, but in common use; `entry`, formerly reseved but newver used, is no longer reserved.

### Constants
There are severla kinds of constatn, Each has a data type.
```plaintext
constant:
  integer-constant
  character-constant
  floating-constatn
  enumeration-constant
```

### Ingeter Constants
An integer constant consisting of a sequence of digits is taken to be octal if it begins with 0 (digit zero), decimal otherwise.
Octalconstants do not contain the digtis `8` or `9`.
A sequence of digits preceded by `0x` or `0X` (digit zero) is taken to be hexadecimal integer.
The hexadecimal digits include `a` or `A` through `f` or `F` with values 10 trough 15.

you can use letter `u` or `U` for specify that it is *unsigned* and letter `l` or `L` for *long*.
they can be `singed`, `unsigned`, `unsigned long` ...

large integer constants are just `long`.


### Character Constants
The value of a character constant iwth only one character is the numerci value of the character in the machine's character set at execution time.
The value of a multi-character constant is implementation-defined.

NOTE: character constants do not contain the `'`,
The following escape sequnces may be used.
```documentation
newline         NL (LF)    \n          backslash         \      \\
horizontal tab  HT         \t          question mark     ?      \?
vertical tab    VT         \v          single quote      '      \'
backspace       BS         \b          double quote      "      \"
carriage return CR         \r          octal number      ooo    \ooo
formfeed        FF         \f          hex number        hh     \xhh
audible alert   BEL        \a
```

A common example of this construction is `\0` (not followed by a digit), which specifies  the character `NUL`.

in hexadecimal there is no limit for number of digits, but the behavior is undefined if the resulting charcter value exceeds that of the larges character.
For hexadecimal and octal the type of char will  be `signed`, the value is sign-extended as if cat to `char` type.

If character following the `\` is not one of those specified, the behaviro is undefined.

A constnat in this extended set is written with  a preceding `L`, for example `L'x'`, and is called a wide character constant. Such a constat has type  `wchar_t` an ingeter type defind in the standard header `<stddef.h>`, As with ordinary characters constants, octal or hexadecimal escapes may be used; the effect is undefined if the specifed  value  exceeds that representable  with `wchar_t`.

NOTE: the main intent in adding `wchar_t` was to accommodate Asian languages.


### Floating Constants
A floating constant consists of an ingeter part, a decimal point, a fractio part, an `e` or `E`, an optionally signed integer exponent and an optional type suffix, one of `f`, `F`, `l` or `L`.
The type is determined by teh suffix; `F` or `f` makes it `flaot`, `L` or `l` makes it `long double`; otherwise it is `double`.


### Enumeration Constants
Idnetifires declared as enumerators are constant of type `int`.


### String Literals
A string literal also called string constant, is a sequnce of characters surrounded by double qoutes, as in `"..."`. A string has  type "array of characters" and stroage calss `static`, and is initialized with the given cahracter. Whether identical string literals are distinct is implementation-defiend, asn the behavior of a program that attemps to later a string literals is undefined.
And the end of the string is `'\0'` so the program can detect the end of it.

As with character constants, string literals in an extended character set are wirtten with a preceding `L`, as in `L"..."`. Wide-character string literals have type "array of `wchar_t`".
Concatenation of ordinary and wide string literals is undefined.


## Syntax Notation
Nothing important and it is just aobut the book that how the syntax part is written in *italic*.

## Meaning of identifires
Identifiers or names refer to a variety of things: functions; tags of structures, unions, and enumerations; memebers of structures or uniongs; enumeration constants; typedef names; and objects,
An object, sometimes called a variable, is a location in storage, and its interpretation depends on two main attributs: its *storage* class and its *type*.

- The stroage clas determines the lifetime of the storage associated with the indentified object
- The type determines the meaning of the values found in the identified object.

A name aslo has ascope, whic is the region of the program in which it is knowsn, and a linkage, which determines whether the smae name in another scope refers to the same object or function.


### Storage Class
There are two storage classes: atomatic and static, Severl keywords, together with the context of an object, declration, specify its storage calss.
Declrations withing a block create automatic objects if no storage class specification is mentioned, or if the `auto` specifier is used. Objecst declared `register` are automatic, and are (if possible) stored in fast registes of the machine.

Static objects may be local to a block or external to all blocks, but in eigher case retain their values across exit from and reentry to function, static objects are declared with the keyword `static`.
The objects declared outside all blocks at the same levl as function definitions, are always static, The objects declraed outside all blocks, att the same level as function definitions, are always static.
They may be made local to a particular translation unit by use of the `static` keyword; this gives them *intenal linkage*.
They become global to an entire program by omitting an exlicit storage class, or by using teh keyword `extern`; this gives them *external linkage*.

### Basic Types
The standrad header `<limits.h>` defines the largest and smallest values of each type in the local implementation.
`unsinged char` consume the same amount of space as plain characters, but always appear non-negative; explicitly signed characters declared `signed char` likewise take the same space as plain characters.

besides the char types there is `short int`, `int`, `long int`

NOTE: unsigned quantities can never overflow

*Enumerations* are unique types that have integral values.
It is common for a compiler to issue a warning when an object of a particular enumarion type is assigned something other than one of its constants, or an expression of its type.

The `void` types specifies an empty set of values, It is used as the type returned by functinos that generate no value.

### Derived Types
Besides the basic types, there is a conceptually infinite calss of derived types constructed from the fundemental types in the following ways:
```struction
arrays of objects of a given type;
functions returning objects of a given type;
pointers to objects of a given type;
structures containing a sequence of objects of various types;
unions capable of containing any one of several objects of various types.
In general these methods of constructing objects can be applied recursively.
```

### Type Qualifiers
An object's type may have additional qualifiers, Declraing an object `const` announced that its value will not be chagned; declaring it `volatile` annouces that is has special properties relevant to optimizatio.
Neigher qualifires affect the range of values or arithmetic properties of the object.
