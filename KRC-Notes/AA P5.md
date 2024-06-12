## Statements
statements are executed in sequence.
Statements are executed for their effect, and do not have values. They fall into several groups.
```text
statement:
  labeled-statement
  expression-statement
  compound-statement
  selection-statement
  iteration-statement
  jump-statement
```

### Labeled Statements
Statements may carry label prefixes.
for example:
```text
labeled-statement:
  identifier : statement
  case constant-expression : statement
  default : statement
```

A label consisting of an identifier declares the identifier. The only use of an identifier label is as a target of goto. The scope of the identifier is the current function. Because labels have their own name space, they do not interfere with other identifiers and cannot be redeclared.

Case labels and default labels are used with the switch statement.
The constant expression of case must have integral type.

Labels themselves do not alter the flow of control.

### Expression Statement
Most statements are expression statements, which have the form
```text
expression-statement:
  expression(opt);
```

Most expression statements are assignments or function calls. All side effects from the expression are completed before the next statement is executed. If the expression is missing, the construction is called a null statement; it is often used to supply an empty body to an iteration statement to place a label.


### Compound Statement
So that several statements can be used where one is expected, the compound statement (also called `block`) is provided. The body of a function definition is a compound statement.
```text
compound-statement:
  { declaration-listopt statement-list(opt) }

declaration-list:
  declaration
  declaration-list declaration

statement-list:
  statement
  statement-list statemen
```

If an identifier in the declaration-list was in scope outside the block, the outer declaration is suspended within the block, after which it resumes its force. An identifier may be declared only once in the same block. These rules apply to identifiers in the same name space; identifiers in different name spaces are treated as distinct.

Initialization of automatic objects is performed each time the block is entered at the top, and proceeds in the order of the declarators. If a jump into the block is executed, these initializations are not performed. Initialization of static objects are performed only once, before the program begins execution.

### Selection Statements
Selection statements choose one of several flows of control.
```text
selection-statement:
  if (expression) statement
  if (expression) statement else statement
  switch (expression) statement
```

In both forms of the if statement, the expression, which must have arithmetic or pointer type, is evaluated, including all side effects, and if it compares unequal to 0, the first substatement is executed. In the second form, the second substatement is executed if the expression is 0. The else ambiguity is resolved by connecting an else with the last encountered else-less if at the same block nesting level.


The switch statement causes control to be transferred to one of several statements depending on the value of an expression, which must have integral type.

The substatement controlled by a switch is typically compound. Any statement within the substatement may be labeled with one or more case labels.

The controlling expression undergoes integral promotion (Par.A.6.1), and the case constants are converted to the promoted type. No two of these case constants associated with the same switch may have the same value after conversion. There may also be at most one `default` label associated with a switch. Switches may be nested; a `case` or `default` label is associated with the smallest switch that contains it.


When the `switch` statement is executed, its expression is evaluated, including all side effects, and compared with each case constant. If one of the case constants is equal to the value of the expression, control passes to the statement of the matched case label. If no `case` constant matches the expression, and if there is a `default` label, control passes to the labeled statement. If no case matches, and if there is no `default`, then none of the substatements of the swtich is executed.

### Iteration Statements
Iteration statements specify looping.
```text
iteration-statement:
  while (expression) statement
  do statement while (expression);
  for (expressionopt; expression(opt); expression(opt)) statement
```

In the `while` and do statements, the substatement is executed repeatedly so long as the value of the expression remains unequal to 0; the expression must have arithmetic or pointer type. With `while`, the test, including all side effects from the expression, occurs before each execution of the statement; with do, the test follows each iteration.

In the `for` statement, the first expression is evaluated once, and thus specifies initialization for the loop. There is no restriction on its type. The second expression must have arithmetic or pointer type; it is evaluated before each iteration, and if it becomes equal to 0, the for is terminated. The third expression is evaluated after each iteration, and thus specifies a reinitialization for the loop. There is no restriction on its type. Side-effects from each expression are completed immediately after its evaluation. If the substatement does not contain `continue`, a statement.

```c
for(expression1; expression2; expression3) statement
```
is quaivalent to:
```c
expression1;
while (expression2) {
  statement
  expression3;
}
```

Any of the three expressions may be dropped. A missing second expression makes the implied test equivalent to testing a non-zero element.

### Jump Statements
Jump statements transfer control unconditionally.
```text
jump-statement:
  goto identifier;
  continue;
  break;
  return expression(opt);
```

In the `goto` statement, the indentifier must be a label located in the current function.
Control transfers to the labeled statemnt.

A `continue` statement may appear only within an iteration statement. It causes control to pass to the loop-continuation portion of the smallest enclosing such statement. More precisely, within each of the statements.

```c
while (...) {       do{             for(...){
...                 ...             ...
contin:  ;          contin: ;       contin: ;
}                   } while(...);   }
```
a `continue` not contained in a smaller iteration statement is the same as `goto contin`.


A `break` statement may appear only in an iteration statement or a `switch` statement, and terminates execution of the smallest enclosing such statement; control passes to the statement following the terminated statement.

A function `returns` to its caller by the `return` statement. When return is followed by an expression, the value is returned to the caller of the function. The expression is converted, as by assignment, to the type returned by the function in which it appears.

Flowing off the end of a function is equivalent to a return with no expression. In either case, the returned value is undefined.


## External Declarations
The unit of input provided to the C compiler is called a translation unit; it consists of a sequence of external declarations, which are either declarations or function definitions.
```text
translation-unit:
  external-declaration
  translation-unit external-declaration

external-declaration:
  function-definition
  declaration
```

The scope of external declarations persists to the end of the translation unit in which they are declared, just as the effect of declarations within the blocks persists to the end of the block. The syntax of external declarations is the same as that of all declarations, except that only at this level may the code for functions be given.

### Function Definitions
Function definitions have the form
```text
function-definition:
  declaration-specifiers(opt) declarator declaration-list(opt) compound-statement
```
The only storage-class specifiers allowed among the declaration specifiers are `extern` or `static`;

A function may return an arithmetic type, a structure, a union, a pointer, or `void`, but not a function or an array. The declarator in a function declaration must specify explicitly that the declared identifier has function type; that is, it must contain one of the forms.

```text
direct-declarator ( parameter-type-list )
direct-declarator ( identifier-list(opt) )
```

where the direct-declarator is an identifier or a parenthesized identifier. In particular, it must not achieve function type by means of a `typedef`.

In the second form, the definition is old-style: the identifier list names the parameters, while the declaration list attributes types to them. If no declaration is given for a parameter, its type is taken to be int. The declaration list must declare only parameters named in the list, initialization is not permitted, and the only storage-class specifier possible is `register`.

In both styles of function definition, the parameters are understood to be declared just after the beginning of the compound statement constituting the function's body, and thus the same identifiers must not be redeclared there (although they may, like other identifiers, be redeclared in inner blocks). If a parameter is declared to have type `array of type,` the declaration is adjusted to read `pointer to type;` similarly, if a parameter is declared to have type `function returning type`, the declaration is adjusted to read `pointer to function returning type.` During the call to a function, the arguments are converted as necessary and assigned to the parameters;


A complete example of a new-style function definition is:
```c
int max(int a, int b, int c){
    int m;
    m = (a > b) ? a : b;
  return (m > c) ? m : c;
}
```

Here `int` is the declaration specifier; `max(int a, int b, int c)` is the function's declarator, and { ... } is the block giving the code for the function.

### External Declarations
External declarations specify the characteristics of objects, functions and other identifiers. The term `external` refers to their location outside functions, and is not directly connected with the extern keyword; the storage class for an externally-declared object may be left empty, or it may be specified as `extern` or `static`.

Several external declarations for the same identifier may exist within the same translation unit if they agree in type and linkage, and if there is at most one definition for the identifier.

if the declarations differ because one type is an incomplete structure, union, or enumeration type and the other is the corresponding completed type with the same tag, the types are taken to agree.


> Moreover, if one type is an incomplete array type and the other is a completed array type, the types, if otherwise identical, are also taken to agree. Finally, if one type specifies an old-style function, and the other an otherwise identical new-style function, with parameter declarations, the types are taken to agree.


If the first external declarator for a function or object includes the `static` specifier, the identifier has internal linkage; otherwise it has `external linkage`.


An external declaration for an object is a definition if it has an initializer. An external object declaration that does not have an initializer, and does not contain the `extern` specifier, is a `tentative definition`. If a definition for an object appears in a translation unit, any tentative definitions are treated merely as redundant declarations. If no definition for the object appears in the translation unit, all its tentative definitions become a single definition with initializer 0. 

Each object must have exactly one definition. For objects with internal linkage, this rule applies separately to each translation unit, because internally-linked objects are unique to a translation unit. For objects with external linkage, it applies to the entire program.


### Scope and Linkage
A program need not all be compiled at one time: the source text may be kept in several files containing translation units, and precompiled routines may be loaded from libraries. Communication among the functions of a program may be carried out both through calls and through manipulation of external data.

Therefore, there are two kinds of scope to consider: first, the `lexical scope` of an identifier which is the region of the program text within which the identifier's characteristics are understood; and second, the scope associated with objects and functions with external linkage, which determines the connections between identifiers in separately compiled translation units.

### Lexical Scope
Identifiers fall into several name spaces that do not interfere with one another; the same identifier may be used for different purposes, even in the same scope, if the uses are in different name spaces. These classes are: objects, functions, typedef names, and `enum` constants; labels; tags of structures or unions, and enumerations; and members of each structure or union individually.

If an identifier is explicitly declared at the head of a block, including the block constituting a function, any declaration of the identifier outside the block is suspended until the end of the block.


### Linkage
Within a translation unit, all declarations of the same object or function identifier with internal linkage refer to the same thing, and the object or function is unique to that translation unit. All declarations for the same object or function identifier with external linkage refer to the same thing, and the object or function is shared by the entire program.

The first external declaration for an identifier gives the identifier internal linkage if the static specifier is used, external linkage otherwise. If a declaration for an identifier within a block does not include the extern specifier, then the identifier has no linkage and is unique to the function. If it does include extern, and an external declaration for is active in the scope surrounding the block, then the identifier has the same linkage as the external declaration, and refers to the same object or function; but if no external declaration is visible, its linkage is external.


## Preprocessing
A preprocessor performs macro substitution, conditional compilation, and inclusion of named files. Lines beginning with #, perhaps preceded by white space, communicate with this preprocessor. The syntax of these lines is independent of the rest of the language; they may appear anywhere and have effect that lasts (independent of scope) until the end of the translation unit. Line boundaries are significant; each line is analyzed individually.

To the preprocessor, a token is any language token, or a character sequence giving a file name as in the `#include` directive; in addition, any character not otherwise defined is taken as a token. However, the effect of white spaces other than space and horizontal tab is undefined within preprocessor lines.

Preprocessing itself takes place in several logically successive phases that may, in a particular implementation, be condensed.

1. Trigraph sequences are replaced by their equivalents. Should the operating system environment require it, newline characters are introduced between the lines of the source file.
2. Each occurrence of a backslash character `\` followed by a newline is deleted, this splicing lines
3. The program is split into tokens separated by white-space characters; comments are replaced by a single space. Then preprocessing directives are obeyed, and macros are expanded.
4. Escape sequences in character constants and string literals are replaced by their equivalents; then adjacent string literals are concatenated.
5. The result is translated, then linked together with other programs and libraries, by collecting the necessary programs and data, and connecting external functions and object references to their definitions.


### Trigraph Sequences
The character set of C source programs is contained within seven-bit ASCII, but is a superset of the ISO 646-1983 Invariant Code Set. In order to enable programs to be represented in the reduced set, all occurrences of the following trigraph sequences are replaced by the corresponding single character. This replacement occurs before any other processing.
```text
??= #     ??( [     ??< {
??/ \     ??) ]     ??> }
??' ^     ??! |     ??- ~
```
No other such replacements occur.

### Line Splicing
Lines that end with the backslash character `\` are folded by deleting the backslash and the following newline character. This occurs before division into tokens.

### Macro Definition and Expansion
A control line of the form
```text
# define identifier token-sequence
```

Causes the preprocessor to replace subsequent instances of the identifier with the given sequence of tokens; leading and trailing white space around the token sequence is discarded. A second `#define` for the same identifier is erroneous unless the second token sequence is identical to the first, where all white space separations are taken to be equivalent.

A line of the form
```text
# define identifier (identifier-list) token-sequence
```

Where there is no space between the first identifier and the (, is a macro definition with parameters given by the identifier list. As with the first form, leading and trailing white space arround the token sequence is discarded, and the macro may be redefined only with a definition in which the number and spelling of parameters, and the token sequence, is identical.

A control line of the form
```text
# undef identifier
```
causes the identifier's preprocessor definition to be forgotten. It is not erroneous to apply `#undef` to an unknown identifier.

When a macro has been defined in the second form, subsequent textual instances of the macro identifier followed by optional white space, and then by (, a sequence of tokens separated by commas, and a ) constitute a call of the macro. The arguments of the call are the commaseparated token sequences; commas that are quoted or protected by nested parentheses do not separate arguments. During collection, arguments are not macro-expanded. The number of arguments in the call must match the number of parameters in the definition. After the arguments are isolated, leading and trailing white space is removed from them. Then the token sequence resulting from each argument is substituted for each unquoted occurrence of the corresponding parameter's identifier in the replacement token sequence of the macro. Unless the parameter in the replacement sequence is preceded by #, or preceded or followed by ##, the argument tokens are examined for macro calls, and expanded as necessary, just before insertion.

Two special operators influence the replacement process. First, if an occurrence of a parameter in the replacement token sequence is immediately preceded by #, string quotes (") are placed around the corresponding parameter, and then both the # and the parameter identifier are replaced by the quoted argument. A \ character is inserted before each " or \ character that appears surrounding, or inside, a string literal or character constant in the argument.

Second, if the definition token sequence for either kind of macro contains a ## operator, then just after replacement of the parameters, each ## is deleted, together with any white space on either side, so as to concatenate the adjacent tokens and form a new token. The effect is undefined if invalid tokens are produced, or if the result depends on the order of processing of the ## operators. Also, ## may not appear at the beginning or end of a replacement token sequence.

In both kinds of macro, the replacement token sequence is repeatedly rescanned for more defined identifiers. However, once a given identifier has been replaced in a given expansion, it is not replaced if it turns up again during rescanning; instead it is left unchanged.

Even if the final value of a macro expansion begins with with #, it is not taken to be a preprocessing directive.


For example, this facility may be used for `manifest-constants`, as in
```c
#define TABSIZE 100
int table[TABSIZE];
```

The definition

```text
#define ABSDIFF(a, b) ((a)>(b) ? (a)-(b) : (b)-(a))
```

Defines a macro to return the absolute value of the difference between its arguments. Unlike a function to do the same thing, the arguments and returned value may have any arithmetic type or even be pointers. Also, the arguments, which might have side effects, are evaluated twice, once for the test and once to produce the value.

Given the definition
```c
#define tempfile(dir) #dir "%s"
```

the macro call `tempfile(/usr/tmp)` yields

```c
"/usr/tmp" "%s"
```

which will subsequently be catenated into a single string. After
```c
#define cat(x, y) x ## y
```

the `call cat(var, 123)` yields var123. However, the call `cat(cat(1,2),3)` is undefined: the presence of ## prevents the arguments of the outer call from being expanded. Thus it produces the token string

```c
cat ( 1 , 2 )3
```

and `)3` (the catenation of the last token of the first argument with the first token of the second)
is not a legal token. If a second level of macro definition is introduced,

```c
#define xcat(x, y) cat(x,y)
```

things work more smoothly; `xcat(xcat(1, 2), 3)` does produce 123, because the expansion of `xcat` itself does not involve the `##` operator.

Likewise, `ABSDIFF(ABSDIFF(a,b),c)` produces the expected, fully-expanded result.


### File Inclusion
A control line of the form
```c
# include <filename>
```
Causes the replacement of that line by the entire contents of the file filename. The characters in the name filename must not include > or newline, and the effect is undefined if it contains any of `"`, `'`, `\`, or `/*`. The named file is searched for in a sequence of implementation-defined places.

Similarly, a control line of the form
```c
# include "filename"
```

Searches first in association with the original source file (a deliberately implementation-dependent phrase), and if that search fails, then as in the first form. The effect of using `'`, `\`, or `/*` in the filename remains undefined, but `>` is permitted.

Finally, a directive of the form
```c
# include token-sequence
```
Not matching one of the previous forms is interpreted by expanding the token sequence as for normal text; one of the two forms with <...> or "..." must result, and is then treated as previously described.

```c
#include files may be nested.
```
