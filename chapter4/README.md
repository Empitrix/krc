# Functions and Program Structure
- C suggest to use small functions instead of big ones.
- source files can compile separately and loaded together. along with previously compiled function from libraries.

## Basics of Functions

- `strstr`: is function taht returns a pointer when string s contains str t, like.

A do-nothing function like below is somethins useful as a place holder during program development.

```c
// a miminal function
// which does nothing and returns nothing.
dummy(){}
```

> [!NOTE]
> If the return type is omitted, int is assumed.

> A program is just a set of definitions of variables and functions.

---

Any expression can follow return
```c
return expression;
```

- expression will be converted to the return type.

NOTE: The Calling function is free to ignore the return value

### FALL OF THE END
In a function by reaching to the closing right brace. it is not illegal, but probably a sign of trouble.

> If the function return a value from one place and no value from another. if function fails to return a value it "value" is certain to be grabade.

### Compiling
In UNIX, if there is 3 file of code, you can compile them together and the compiler will put all of them in main.c and and export it as `a.out`, like:

```bash
cc main.c getline.c strindex.c
```

## Functions Returning Non-Integers
If a function is returning non-integers the type should be declare.

you can declare a returning type of a function like:
```c
double sum, atof(char []);
// function atof returns a double, and take a char[] as arg
```

the `atof` function must be declared and define consistently.

> NOTE: If a function not getting any argument use "void", otherwise declare the arguments.

if there is no function prototype it could be a mistach; if function not declared previously the defulat is not arugment as input and int as output. (page 86)

## External Variables
C have some external variables & functions.
The adjective _external_ is used in contrast to _internal_ which describe the arguments and variables defined inside functions.

NOTE: External variables are definde outside of functions and available to many functions.
NOTE: functinos themselves are always external (unline TS :laugh:)
NOTE: C does ot allow functions to be defined inside other functinos.

### external linkage
By default external variables and functions have the property that all references to them by the same name, even from functions compiled separately, are refrences to the same thing.

NOTE: any function may access an external varialbe by referring to it by name, if the name has been declraed somehow.

> [!NOTE]
> If a large number of varialbes must be shared among functions, external varialbes are more convenient and efficient than long argument lists.

NOTE: Automatic variables are internal to a function.(they come into existence when the function is entered, and disappear when it is left), external varialbes on the other hand is permanent,

- In function invocatinos is more efficent if the data saved into a external variable rather than pass in and out via arguments.

> In reverse polish notation, each operator follows its operands; an infix expression like
> 
> (1 - 2) * (4 + 5)
> is entered as
> 1 2 - 4 5 + *
> 
> Praenthesese are not needed; the notation is unambiguous as long as we know how many operand each operator expects.

Eaach operand is pushed onto a stack; when an oprands arrives the proper number of oprands (two for binary operators) is popped, the operator is applied to them, and the result is pushed back onto the stack. (p-88)

> [!NOTE]
> %g is simplifiers of the scientific notation floats.

> [!NOTE]
> The standard librarly includes a function ungetc that provides one character of pushback;


## Scope Rules
The functions and external varialbes that make up a C program need not all be compiled at the same time.

```questions
- How are declarations written so that variables are properly declared during compilation
- How are declarations arranged so that all the pieces will be properly connected when the program is loaded?
- How are declarations organized so there is only one copy?
- How are external variabes initialized?
```

variables that defined outside of function, can be used inside of them by just naming them.

NOTE: On ther other hand if an external varialbe is to be referred to before it is defined, or if it is defined in a different source file from the one where it is begin used, then _extern_ declaration is mandatory.

---
if the lines
```c
int sp;
double val[MAXVAL];
```
appear outside of any function, they *define* the external varilabes sp and val, cause storage to be set aside, and alsoe serve as the declration for the rest of the source file, on ther other hand the lines

```c
extern int sp;
extern double val[];
```
declare for the rest of the source file that sp is an int and that val is a double array, bu they do not create the variables or reserve storage for them.

> other files may contain "extern" declarations to access it.

NOTE: Array sizes must be specifed with the definition, but are optional with an extern declaration.
NOTE: Initialization of an external varialbe goes only with the definition.

---


*file1*
```c
extern int sp;
extern double val[];
```

*file2*
```c
int sp = 0;
double val[];
```
IMPORTANT: Because the *extern* declarations in file1 lie head of and outside the function definitions, the apply to all functions.


## Header Files
We will place common material in a *header file*. which wiil be included as neccessary.

NOTE: each file have access only to the information it needs for its job and the practical reality that it is header to maintain more header files.

NOTE: It is probably best to have one header file that contains everything that is to be shared between any two parts of the program.


## Static Varialbes (Private)

varialbes that not meant to be accessd by anything else.

NOTE: the `static` declaration applied to an external varialbe or function.

external `static` thus provides a way to hide names which must be external so they can be shared, yet which should not be visible to users.

NOTE: Static storage is spdecified by prefiing the normal declaration with the word `static`.
NOTE: If varialbes are complied in one file then no other will be albe to access them, and those names will not conflict with the same names in toher files of the same program.

The external `static` declaration is most often used for varialbes, but it can be applied to functions as well, normaly function names are global.
if the funtion is declared static however its name is invisible outside of the file in which it is declared

NOTE: the static declration can also be applied to interla varialbes. Internal static varialbes are local to a particular function just as automatic varialbes are, but unlike automatics, they remain in existence rather than coming and going each time the function is activated.

## Register Varialbes
A `register` declaration advises the compiler that the varialbe in question will be heavily used.
The idea is that `register` varialbes are to be placed in matchine registers, which may result in smaller and fater programs.
But compilers are free to ignore the advice.
example:
```c
register int x;
register char c;
```
(The register varialbes can only be applied to automatcivarialbes and to the formal parameters of a function)

like:
```c
f(register unsigned m, register long n){
  register int i;
  ...
}
```

Restrictions:
- Only a few varialbes in each function may be kep in registers
- Only certain type allowed, 
- It is not possible to take the address of a register varilabe.
- The specific restriction on number and type of register varialbes vary from mathine to matchine.

## Block Structure (98)
C is not a block structure language (functions can't define in another functions).

NOTE: A `static` varialbe is initialized only the first time the block is enterd.
NOTE: An automatci variable declared and initialized in a block is initialized each the block is enterd.

**As a matter of style, it's best to avoid varialbe names that conceal names in an outer scope; the potentional for confusion and error is too grea.**


## Initialization
In absent of explicit Initialization, external and static varialbes are guaranteed to be initialized to zero, automatic and register varialbes have undefined (garbage) initial values.
Scalar varialbes may be initialized when they are defined.
like:

```c
int x = 1;
char sqoute = '\'';
```

NOTE: for external and static varialbes, the initializer must be contatn expression.
The initialization is done once, (befor the program begins execution)

for automatic and register varialbes:
- it is done each time the function or block is enterd.
- the initializer is not registerd to being a constnat.

initialazation of automatic vairalbes are just shorthand for assignemtn statements.

> When the size of the array is omitted, the compiler will compute the lenght by counting the initializers.
> 
> If there are fewer initializers for an array than the nubmer specifed, the missing  elements will be zero for external, static and auto varialbes.

---

arrays are different:

```c
char pattern[] = "ould";
```
is a shorthand for the longer but equivalent


```c
char pattern[] = {'o', 'u', 'l', 'd', '\0'};
```
in this case, the array size is five.


## Recursion
When a function calls itsefl recursively, each invocations gets a fresh set of all automatic varialbes, independednt of the previous set.

### Q@uicksort (C.A.R. Hoare 1962)
split list in half and check so on... (p-101)

the standrad library includes a verion of `qsort` that can sort objects of any type.

Recursion may provide no saving in storage, since somewhere a stack of the values bein proccessed, must be maintained.
Nor will it be faster. but recursive code is more compact.


## The C Preprocessor
- (#include): to include the contents of a file dring compilation.
- (#define): to replace a token by an arbitarry sequence of charactes.

### File Including
any source line of the form

```c
#include "filename"
// or
#include <filename>
```

is replaced by the contetns of the file `filename`.
NOTE: If the `filename` is qouted, searching for the file typically begins where the source program was found.
NOTE: if the name is enclosed in `< and >` seaching follows an implementatino-defined rule to find the file.

An include file may itself contain `#include` lines.

(Strictly there need not be files)

> #include is the preferred way to tie the declarations together for a large program.

**Naturally, when an included file is changed, all the files that dpeend on it must be recompiled.**


### Macro Substitution
A definition has the form
```c
#define name replacement-text
```

token name will be replace with replacement-text, the name is in a #define has the same form as a varialbe name.

NOTE: the replacement text is arbitrary.
NOTE: a long definition may be continued onto several lines by placing a \ at the end of each line to be continued.

The scope of a name defined with `#define` is from its point of definition to the end of the source file being compiled.

If YES is a defined name, there would be no substution in printf("YES")

Any name may be defined with any replacement text, for example:

```c
#define forever for(;;)  /* infinite loop */
```

defines a new word, `forever` for an infinite loop.

It is also possible to define macros with arguments, so the replacement text can be different for diffrent calls of the macro.

define macro called max:
```c
#define  max(A, B) ((A) > (B) ? (A) : (B))
```
Although it looks like a function call, use of max expands into in-line code,
Each occurrence of a formal paramter (here A or B) will be repalced by the corresponding acutal argument. Thus the line

```c
x = max(p+q, r+s);
```

will be replaced by the line

```c
x = ((p+q) > (r+s) ? (p+q) : (r+s));
```

So long as the arguments are treated consistently, this macro will server for any data type.

If you examine the expansion of `max` tou will notice some pitfalls.
The expressions are evaluated twice; this is bad if tehy involve side effects like increament opreator  or input and output for instance.

```c
max(i++, j++)  /* wrong */
```
Will increment the large value twice.

Make sure that order of evaluation is presserved,
```c
#define squre(x) x * x  /* WRONG */
```
but they are valuable, for example (`<stdio.h>`) uses *getchar* and *putchar* as maxros to avoid the run-time overhead of a function call per character processed.
The functions in `<ctype.h>` are also usualy implemented as macros.

Names may be undeinfed with `#undef`, usually to ensue that a routing is rally a function, not a macro.

example:
```c
#undef getchar

int getchar(void){...}
```

A paramter name is preceded by a # in the repalcement text, the combination will be  cpanded into a quoted string  with the paramter repalced by the actual argument.

for example:
```c
#define dprint(expr) printf(#expr "%g\n", expr)
```
when invoked as: 
```c
dprint(x/y);
```

the macro is expaned into
```c
printf("x/y" " = %g\n", x/y);
```
Witing the acutal arguemtn, each `"` is repalced by `\"` and each `\` by `\\`.

The preprocessor opreator ## provides a way to concatenate actual argument during macro expanion.

### Conditional Inclusion
It is possible to control preprocessing itsefl with conditional statements that are evaluted during preprocessing.

The `#if` line evalutes a constant integer expression (which may not include sizeof, casts, or enums constant).
if the expression is non-zero subsequent lines until an `#endif` or `#elif` or `#else` are included.
(The preprocessor statement `#elif` is like else if)

The expression `defined(name)` is a `#if` is 1 if the name has been defined, and 0 otherwise.

for example to make sure that the constant of a file `hdr.h` are included only once, the constant of the file are sorrounded with a conditional like this:

```c
#if !defined(HDR)
#define HDR
/* contents of hdr.h go here */
#endif
```

you can uses this to inlude a header or not, to make sure not include some headers twice.

to define a header use:

```c
#define HDR "something.h"
```

The `#ifdef` and `#ifndef` lines are specialized form that test whether a name is defined. (p-105)

example:
```c
#ifdef HDR
#define HDR
/* contents of hdr.h go here */
#endif
```
