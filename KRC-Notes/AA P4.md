## Declarations
Declarations that reserve storage are called *definitions*. Declarations have the form
```text
declaration:
  declaration-specifiers init-declarator-list(opt);
```
The declarators in the init-declarator-list contain the identifiers being declared; the declaration-specifiers consists of a sequence of type and storage class specifiers
```text
declaration-specifiers:
  storage-class-specifier declaration-specifiers(opt)
  type-specifier declaration-specifiers(opt)
  type-specifier declaration-specifiers(opt)

init-declarator-list:
  init-declarator
  init-declarator-list , init-declarator

init-declarator:
  declarator
  declarator = initializer
```
They contan the names being declared.
A declaration must have at least on declarator, or its type specifier must declare strucutre tag, a nunion tag, or the members of an enumeration; empty declarations are not permitted.

### Storage Class Specifiers
The storage class specifiers are:
```c
storage-calss-specifier:
  auto
  register
  static
  extern
  typedef
```

The `auto` and `register` specifiers give the declared objects automatic storage class, and may be used only within functinos.
Such declarations also serve as definitions and cause storage to be reserved.
A `register` declaration is equivalent to an `auto` declaration.

NOTE: if an object is declared register, the unary & operator may not be applied to it, explicitly or implicitly.

For `static`: Inside a function, this specifier causes storage to be allocated.

A declaration with `extern`, used inside a function, specifies that the storage for the declared objects is defined elsewhere.

NOTE: The `typedef` specifier does not reserve storage and is called a storage class specifier only for syntactic convenience.

NOTE: At most one storage class specifier may be given in a declaration. If none is given, these rules are used: objects declared inside a function are taken to be `auto`; functions declared within a function are taken to be `extern`; objects and functions declared outside a function are taken to be `static`, with external linkage.

### Type Specifiers
The type-specifiers are:
```text
type specifier:
  void
  char
  short
  int
  long
  float
  double
  signed
  unsigned
  struct-or-union-specifier
  enum-specifier
  typedef-name
```

`short` and `long` or `signed` and `unsigned` may be used together as `int`, `double`...

NOTE: The signed specifier is useful for forcing char objects to carry a sign.

If the type-specifier is missing from a declaration, it is taken to be `int`.

Types may also be qualified, to indicate special properties of the objects being declared.
```text
type-qualifier:
  const
  volatile
```
> Type qualifiers may appear with any type specifier.

NOTE 1: The purpose of `const` is to announce objects that may be placed in read-only memory.
NOTE 2: The purpose of `volatile` is to force an implementation to suppress optimization that could otherwise occur.

about usage of `volatile`:
```example
For example, for a machine with memory-mapped input/output, a pointer to a
device register might be declared as a pointer to volatile, in order to prevent the compiler from
removing apparently redundant references through the pointer. Except that it should diagnose explicit
attempts to change const objects, a compiler may ignore these qualifiers.
```
### Structure and Union Declarations
A structure is an object consisting of a sequence of named members of various types. A union is an object that contains, at different times, any of several members of various types. Structure and union specifiers have the same form.
```text
struct-or-union-specifier:
  struct-or-union identifieropt{ struct-declaration-list }
  struct-or-union identifier

struct-or-union:
  struct
  union
```

A struct-declaration-list is a sequence of declarations for the members of the structure or union:
```text
struct-declaration-list:
  struct declaration
  struct-declaration-list struct declaration
  struct-declaration: specifier-qualifier-list struct-declarator-list;

specifier-qualifier-list:
  type-specifier specifier-qualifier-list(opt)
  type-qualifier specifier-qualifier-list(opt)

struct-declarator-list:
  struct-declarator
  struct-declarator-list , struct-declarator
```

Usually, a struct-declarator is just a declarator for a member of a structure or union. A structure member may also consist of a specified number of bits. Such a member is also called a bit-field; its length is set off from the declarator for the field name by a colon.
```text
struct-declarator:
  declarator declaratoropt : constant-expression
```

A type specifier of the form
```text
struct-or-union identifier { struct-declaration-list }
```

NOTE (**incomplete type**): If a specifier with a tag but without a list appears when the tag is not declared, an incomplete type is specified.
NOTE: Objects with an incomplete structure or union type may be mentioned in contexts where their size is not needed.
AS EXAMPLE: for example in declarations (not definitions), for specifying a pointer, or for creating a typedef, but not otherwise. The type becomes complete on occurrence of a subsequent specifier with that tag, and containing a declaration list. Even in specifiers with a list, the structure or union type being declared is incomplete within the list, and becomes complete only at the } terminating the specifier

NOTE: A structure may not contain a member of incomplete type. Therefore, it is impossible to declare a structure or union containing an instance of itself.
NOTE: Tags allow definition of self-referential structures.
NOTE: A structure or union may contain a pointer to an instance of itself, because pointers to incomplete types may be declared.


---
```text
struct-or-union identifier;
```

that declare a structure or union, but have no declaration list and no declarators. Even if the identifier is a structure or union tag already declared in an outer scope, this declaration makes the identifier the tag of a new, incompletely-typed structure or union in the current scope.

NOTE: A structure or union specifier with a list but no tag creates a unique type; it can be referred to directly only in the declaration of which it is a part.

A field member interpreted as an object of integral type of the specified length in bits;
and `int` field is treated as signed.


NOTES:
- The members of a structure have addresses increasing in the order of their declarations.
- A non-field member of a structure is aligned at an addressing boundary depending on its type
- If a pointer to a structure is cast to the type of a pointer to its first member, the result refers to the first member.

- A union may be thought of as a structure all of whose members begin at offset 0 and whose size is sufficient to contain any of its members.
- At most one of the members can be stored in a union at any time
- If a pointr to a union is cast to the type of a pointer to a member, the result refers to that member.


- In general, a member of a union may not be inspected unless the value of the union has been assigned using the same member

---


NOTE: If a union contains several structures that share a common initial sequence, and the union currently contains one of these structures, it is permitted to refer to the common initial part of any of the contained structures.
For example, the following is a legal fragment
```c
union {
  struct {
   int type;
  } n;
  struct {
   int type;
   int intnode;
  } ni;
  struct {
    int type;
    float floatnode;
  } nf;
} u;
...

u.nf.type = FLOAT;
u.nf.floatnode = 3.14;

...

if (u.n.type == FLOAT)
... sin(u.nf.floatnode) ...
```

### Enumerations
Enumerations are unique types with values ranging over a set of named constants called enumerators.
The form of an enumeration specifier borrows from that of structures and unions.

```text
enum-specifier:
  enum identifieropt { enumerator-list }
  enum identifier

enumerator-list:
  enumerator
  enumerator-list , enumerator

enumerator:
  identifier
  identifier = constant-expression
```

NOTE: The identifiers in an enumerator list are declared as constants of type `int`.

NOTE:
- If no enumerations with = appear, then the values of the corresponding constants begin at 0 and increase by 1 as the declaration is read from left to right
- An enumerator with = gives the associated identifier the value specified; subsequent identifiers continue the progression from the assigned value.
- Enumerator names in the same scope must all be distinct from each other and from ordinary variable names, but the values need not be distinct.
- incomplete enumeration types do not exist; the tag of an enum-specifier without an enumerator list must refer to an in-scope specifier with a list.


### Decliarators
Declarators have the syntax:
```text
Declarators have the syntax: 
  declarator:
  pointer(opt) direct-declarator

direct-declarator:
  identifier
  (declarator)
  direct-declarator [ constant-expressionopt ]
  direct-declarator ( parameter-type-list )
  direct-declarator ( identifier-list(opt) )

pointer:
  * type-qualifier-list(opt)
  * type-qualifier-list(opt) pointer

type-qualifier-list:
  type-qualifier
  type-qualifier-list type-qualifier
```

### Meaning of Declarators
A list of declarators appear after a sequence of type and storage class specifiers.
The storage class specifiers apply directly to this identifier, but its type depends on the form of its declarator.

In a declaration T D where D has the form 
```text
( D1 )
```
then the type of the identifier in D1 is the same as that of D. The parentheses do not alter the type, but may change the binding of complex declarators.


### Pointer Declarators
In a declaration T D where D has the form
```text
* type-qualifier-list(opt) D1
```

and the type of the indentifer in the declaration `T D1` is `type-modifier T`, the type of the identifier of `D` is `type-modifier type-qualifier-list` pointer to `T`. Qualifiers following `*` apply to pointer itself, rather than to the object ot which the pointer points.

for example:
```text
int *ap[];
      D1
```
Here `ap[]` plays the role of `D1`; a declaration `int ap[]` (below) would give `ap` the type `array of int`, the type-qualifier list is empty, and the type-modifier is `array of`. Hence the actual declaration gives `ap` the type `array to points to int`

### Array Declarators
In a declaration `T D` where `D` has the form
```text
D1 [constant-expression(opt)]
```

and the type of the identifier in the declaration `T D1` is type-modifier, the type of the identifier of `D` is type-modifier array of `T`, If the constant-expression is present, it must have integral type, and value greater than 0. iF the constant expression specifying the bound is missing, the array has an incomplete type.

NOTE: Any type from which an array is constructed must be complete; it must not be an array of structure of incomplete type.
This implies that for a multi-dimensional array, only the first dimension may be missing.

NOTE: The type of an object of incomplete aray type is completed by another, complete, declaration for the object.

for example:
```c
float fa[17], *afp[17];
```
declares an array of `float` numbers and an array of pointers to `float` numbers. Also
```c
static int x3d[3][5][7];
```
declares a static three-dimensional array of integers, with rank 3 X 5 X 7.

example `x3d[i] [j] [k]` is equivalent to `*(x3d[i] [j] + k)`.

### Function Declarators
In a new-style function declaration `T D` where `D` has the form
```text
D1 (parameter-type-list)
```
and the type of the identifier isn the declaration `T D1` is type-modifier, the type of the identifer of `D` is type-modifier function with arguemtns `paramter-type-list` returning `T`.

The syntax of the parameters is:
```text
parameter-type-list:
  parameter-list
  parameter-list , ...

parameter-list:
  parameter-declaration
  parameter-list , parameter-declaration

parameter-declaration:
  declaration-specifiers declarator
  declaration-specifiers abstract-declarator(opt)
```

NOTES:
- The only storage class specifier permitted in a parameter's declaration is `register`.

> Function declarators with parameter prototypes are, by far, the most important language change introduced by the ANSI standard

The ellipsis notation `...` from `<stdarg.h>` where adapted from the C++ language.


### Initialazation
The initializer is preceded by =, and is either an expression, or a list of initializers nested in braces. A list may end with a comma, a nicety for neat formatting.
```text
initializer:
  assignment-expression
  { initializer-list }
  { initializer-list , }

initializer-list:
  initializer
  initializer-list , initializer
```

NOTEs:
- All the expressions in the initializer for a static object or array must be constant expressions
- The expressions in the initializer for an auto or register object or array must likewise be constant expressions if the initializer is a brace-enclosed list. owever, if the initializer for an automatic object is a single expression, it need not be a constant expression.
- The initial value of an automatic object not explicitly intialized is undefined.

- Unnamed bit-filed memebers are ignored, adn are not initialized.

- The initializer for a union is either a single expression of the same type, or a brace-enclosed initializer for the first member of the union.


An `aggregate` is a structure or array. If an aggregate contains members of aggregate type, the initialization rules apply recursively.


```c
char msg[] = "Syntax error on list %s\n";
```
hows a character array whose members are initialized with a string; its size includes the terminating null character.


### Type Names
`type name`, which is syntactically a declaration for an object of that type omitting the name of the object.
```text
type-name:
    specifier-qualifier-list abstract-declarator(opt)

abstract-declarator:
  pointer
  pointer(opt) direct-abstract-declarator

direct-abstract-declarator:
  ( abstract-declarator )
  direct-abstract-declaratoropt [constant-expression(opt)]
  direct-abstract-declaratoropt (parameter-type-list(opt))
```

The named type is then the same as the type of the hypothetical identifier.

For example:
```c
int
int *
int *[3]
int (*)[]
int *()
int (*[])(void)
```
for two last one:
1. Function of unspecified parameters returning pointer to integer.
2. array, of unspecified size, of pointers to functions with no parameters each returning an integer.


## Typedef
Declarations whose storage class specifier is typedef do not declare objects; instead they define identifiers that name types. These identifiers are called typedef names.
```text
typedef-name:
  identifier
```
NOTES:
- each such `typedef` name is syntactically equivalent to a type specifier keyword for the associated type.
- `typedef` does not introduce new types, only synonyms for types that could be specified in another way

Typedef names may be redeclared in an inner scope, but a non-empty set of type specifiers must be given.
for example:
```c
extern Blockno;
```
does not redeclare `Blockno`, but
```c
extern int Blockno;
```
does.


### Type Equivalence
Two type specifier lists are equivalent if they contain the same set of type specifiers, taking into account that some specifiers can be implied by others (for example, `long` alone implies `long int`). Structures, unions, and enumerations with different tags are distinct, and a tagless union, structure, or enumeration specifies a unique type.

Two types are the same if their abstract declarators, after expanding any typedef types, and deleting any function parameter specifiers, are the same up to the equivalence of type specifier lists. Array sizes and function parameter types are significant.
