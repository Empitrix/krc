## Unary Operators
Expressions with unary operators group right-to-left.
```text
unary-expression:
  postfix-expression
  ++ unary-expression
  -- unary-expression
  unary-operator cast-operator
  sizeof unary-expression
  sizeof ( type-name )

unary-operator: one of
  &  *  +  -  ~  !
```

### Prefix Incrementation Operator
A unary expression preceded by a `++` or `--` operator is a unary expression.
The value of expression is the value after the incrementation (decrementaiont). The operand must be an lvalue; The result is not an lvalue.

### Address Operator
The unary `&` operator takes the address of its operand. The operand ust be an lvalue referring neither to bit-field nor to an object declared as `register`, or must be of function type.
The result is a pointer to the object or function referred to by the lvalue. If the type of the operand is `T`, the type of the result is "Pointer to `T`".

### Indirection Operator
The unary `*` operator denotes indirection, and returns the object or function to which its operand points. It is an lvalue if the operand is a pointer to an object of arithemtic, structure, union, or pointer type.
If the type of the expression is "pointer to `T`", the type of the result is `T`.

### Unary Plus Operator
The operand of the unary `+` operator must have arithemtic type, and the result is the value of the operand. An integral operand undergoes integral promotion. The type of the result is the type of the promoted operand.

### Unary Minus Operaotr
The operand of the unary `-` operator must have arithemitc type, and the reulst is the negative of its operand. An integral operands undergoes integral promotion.
The negative of an unsigned quantity is computed by subtracting the promoted value from the largest value of the promoted type and adding one; but negative zero is zero, The type of the result is the type of the promoted operand.

### One's Complement Operaotr
The operand of the `~` operator must have integral type, and the result is the one's complement of its operand. The integral promotions are preformed. If the operand is unsinged, the reulst is computed by subtracting the value from the largest value of the promoted type. If the operand is signed, the result is computed by converting the promoted operand to the corresponding unsinged type, appling `~`, and convertion back to the signed type, The type of the result is the type of the promoted operand.

### Logical Negation Operand
The operand of the `!` operator must have arithmetic type of be a pointer, and the result is `1` if the vlaue of its operand compares equal to `0`, and `0` otherwise, The type of the result is `int`.

### Sizeof Operator
The `sizeof` operator yeilds the number of bytes required to store an object of the type of its operand. The operand is either an expression, which is not evaluted, or a parenthesized type name, When `sizeof` is applied to a `cahr`, the result is `1`; when applied to an array, the result is the total number of bytes in the array.
Wehn applied to a structure or union, the result is the number of bytes in the object, including any padding required to make the object tile an array: the size of an array of `n` elements is `n` times the size of one element.
The operand my not be applied to an operand of function type, or of incomplete type, or to a bit-filed.
The result is an unsinged integral constant; the particular type is implementation-defined. The standard header `<stddef.h>` defines this type as `size_t`.


## Casts
A unary expression preceded by the paranthesized name of a type causes convertion of the value of the expression to the named type.
```text
cast-expression:
  unary-expression
  ( type-name ) cast-expression
```
This construction is called a _cast_, An expression with a cast is not an lvalue.


## Multiplicative Operators
The mulitplictive operators `*`, `/`, and `%` group left-to-right
```text
multiplicative-expression:
  cast-expression
  multiplicative-expreesion * cast-expression
  multiplicative-expreesion / cast-expression
  multiplicative-expreesion % cast-expression
```
The operand `*` and `/` must have arithemtic type; the operands of `%` must have integral type.
The usual arithmetic conversions are preformed on the operands, and predict the type of the result.
  The binary `*` operator denotes multiplication
  The binary `/` operator yields the quotient, and the `%` operator the remainded, of the division of the first operand by the second; if the second operand is `0`, the result is undefined. Otherwise, is it always tru that `(a/b)*b + a%b = a`
If both operands are non-negative, the the remainded is non-negative and smaller than the divisor; if not, it is guranteed only that the absolute value of the remainder is smaller that the absolute value of the divisor.


## Additive Operators
The additive operantors `+` and `-` group left-to-right.
```text
additive-expression:
  multiplicative-expression
  additive-expreesion + multiplicative-expression
  additive-expreesion - multiplicative-expression
```
The expression `P+1` is a pointer to the next object in the array.
If the sum pointer points outside the bounds of the array. except at the first location beyond the high end, the result is undefined.

If two pointers to objects of the smae type are subtracted, the result is a signed integral value representing the displacement between the pointed-to objects; pointers to successive objects differ by 1. The type of the result depends on the implementation, but is defined as `prtdiff_t` in the standard header `<stddef.h>`.
The vlaue is undefined unless the pointers point to objects within the same array; however if `P` points to the last memeber of an array, then `(P+1)-P` has value 1.


## Shift Operators
The shift operators `<<` and `>>` group left-to-right. For both operators, each operand must be integral, and is subject to the integral promotions, The type of the result is that of the promoted left operand.
The result is undefined if if the right operand is negative, or greater than or equal to the number of bits in the left expression's type.
```text
shift-expression:
  additive-expression
  shift-expression << additive-expression
  shift-expression >> additive-expression
```
The value of `E1<<E2` is `E1` (interpreted as a bit pattern) left-shifted `E2` bits; in the absence of overflow, this is quivalent ot multiplication by `2^E2`. The value of `E1>>E2` is `E1` right-shifted `E2` bit positions. The rift shift is equivalent to division by `2^E2` if `E1` is unsigend or if it has a non-negative value; othwerwise the result is implementation-defined.

## Relational Operators
The relational operators group left-to-right, but this fact is not useful; `a<b<c` is parsed as `(a<b)<c` and `a<b` evalutes to either 0 or 1.
```text
relational-expression:
  shift-expression
  relational-expression < shift-expression
  relational-expression > shift-expression
  relational-expression <= shift-expression
  relational-expression >= shift-expression
```
The operators `<` (elss), `>` (graeter), `<=` (less or equal) and `>=` (greater or equal) all yeild 0 if the specification relation is false and 1 if it is true. The type of the result is `int`.

Pointres to objects of the same type (ignoring any qualifires) may be compared; the result depends on the relative location in the address space of the pointed-to objects.
Pointer comparsion is defined only for parts of the same object; if two pointers point to the same simple object, they compare qual; if the pointers are to memebers of the smae structure, pointrs to objects declared later in the structure compare higher; if the pointers are to memebers of the same union, they compare qual; if the pointers refer to members of an array, the comparsion is equivalent to comparsion of the corresponding subscripts.
If `P` points to the last memeber of an array, then `P+1` compares higher than `P`, even through `P+1` points outside the array. Otherwise, pointer comparsion is undefined.


## Equality Operators
```text
equality-expression:
  relational-expression
  quality-expression == relational-expression
  quality-expression != relational-expression
```
The `==` (qual to) and the `!=` (not equal to) operators are analogus to the relational operators except for their lower precedence. (Thus `a<b == c<d` is 1 whenever `a<b` and `c<d` have the same trugh-value.)
Teh quality operators follow the same rules as the relational operators, but permitaddional possibilities: a pointer may be compared to a constant integral expression with value 0, or to a pointer to `void`.


## Bitwise AND Operator
```text
AND-expression:
  equality-expression
  AND-expression & equality-expression
```
The usual arithmetic conversions are performed; the result is the bitwise AND function of the operands. The operator applies only to integral operands.

## Bitwise XOR Operator
```text
exclusive-OR-expreesion:
  AND-expression
  exclusive-Or-expression ^ AND-expression
```
The usual arithemtic conversions are performed; the result is the bitweise excusive OR function of the operands. The operator applies only to integral operands.

## Bitwise Inclusive OR Operator
```text
inclusive-OR-expression:
  exclusive-OR-expression
  inclusive-OR-expression | exclusive-OR-expression
```
The usual arithemtci conversions are performed; the result is the bitwise inclusive OR function of its operands. The operator applies only to integral operands.

## Logical AND Operator
```text
logical-AND-expression:
  inclusive-OR-expression
  logical-AND-expression && inclusive-Or-expression
```
It returns 1 if both its operands compare unequal to zero, 0 otherwise.
Unlike `&`, `&&` guarantees left-to-right evalution: the first operand is evaluted, including all side effects; if it is qual to 0, the value of the expression is 0.
Otherwise, the right operand is evaluted, and if it is equal to 0, the expressions, value is 0, otherwise 1.

The operands need not have the same type but each must have arithemtic type or be a poiner, The result is `int`.

## Logical OR Operator
```text
logical-OR-expression:
  logical-AND-expression
  logical-OR-expression || logical-AND-expression
```
The `||` operator gourps left-to-right.
It returns 1 if either of its operands compares uneuql to zero, and 0 otherwise.
Unlike `|`, `||` guarantees left-to-right evaluation: the first operand is evalueted, including all side effects; if it is unequel to 0, the expression's value is 1, otherwise 0.
The operands need not have the same type, but each must have arithmetic type or be a pointer, The result is `int`.


## Conditional Operator
```text
conditional-expression:
  logical-OR-expression
  logical-OR-expression ? expression : conditional-expression
```
The first expression is evaluated, including all side effects; if it compares unequal to 0, the result is the value of the second expression, otherwise that of the third expression. Only one of the second and third operands is evaluated. If the second and third operands are arithmetic, the usual arithmetic conversions are performed to bring them to a common type, and that type is the type of the result. If both are `void`, or structures or unions of the same type, or pointers to objects of the same type, the result has the common type. If one is a pointer and the other the constant 0, the 0 is converted to the pointer type, and the result has that type. If one is a pointer to `void` and the other is another pointer, the other pointer is converted to a pointer to `void`, and that is the type of the result.

In the comparsion for pointers, any type qualifiers in the type to which the pointer points are insignificant, but the result type inherits qualifieres from both arms of the conditional.

## Assignemnt Expressions
There are several assignemnt operators; all group right-to-left.
```text
assignment-expression:
  conditional-expression
  unary-expression assignemnt-operator assignment-expression

assignmet-operators: one of
 =  *=  /=  %=  +=  -=  <<=  >>=  &=  ^=  !=
```
All require an lvalue as left operand, and the lvalue must be modifiable: it must not be an array, and must not have an incomplete type, or be function.
Also, its type must not be qualified with `const`; if it is a structure or union, it must not have any member or, recusively, submember qualified with `const`. The type of an assignemnt expression is that of its left operand, and the value is the value stroed in the left operand after the assignemnet has taken place.

```partOfTheBook
In the simple assignment with =, the value of the expression replaces that of the object referred
to by the lvalue. One of the following must be true: both operands have arithmetic type, in
which case the right operand is converted to the type of the left by the assignment; or both
operands are structures or unions of the same type; or one operand is a pointer and the other is
a pointer to void, or the left operand is a pointer and the right operand is a constant
expression with value 0; or both operands are pointers to functions or objects whose types are
the same except for the possible absence of const or volatile in the right operand. 
```

An expression of form `E1 op= E2` is euivalent ot `E1 = E2 op (E2)` except that `E1` is evaluted only once.

## Comma Operator
```text
expression:
  assignemnt-expression
  expression , assignemnt-expression
```
A pair of expressions separated by a comma is evaluated left-to-right.
The value of the left expression is discarded, The type and value of the resutl are the type and value of the right operand. All side effects from the evaluation of the left-operand are completed before beggining the evalution of the right operand. In context where comma is given a special meaning, for example in lists of function arguments and lists of initilizers appear only in a parenthetical grouping, for example,
```c
f(a, (t=3, t+2), c)
```
has three argument, the second of which has the value 5.

## Constant Expressions
Syntacically, a constant expression is an expression restricted to a subset of operators:
```text
constant-expression:
  conditional-expression
```

Expressions that evaluete to a constant are reuiqed in several contexts: after case, as array bounds and bit-field length, as the value of an enumeration constant, in initializers, and in cetain preprocessor expressions.

Constnat expressions may not contain assignments, increment or decrement operators, function calls, or comma operators, ecept in an operand of `sizeof`.
If the constant expression is required to be integral, its operand must consist of integer, enumation, character, and floating constants; casts must specify an integral type, and any floating constant must be cast to an integer.
This neccessary rules out arrays, indirection, address-of, and strucutre memeber operations, (However, any operand is permitted for `sizeof`)

More latitude is permitted for the constant expression of initializers; the operands may be any type of constant, and the unary `&` operator may be applied to external or static objects, and to external or static array subscripted with a constnat expression.
The unar y`&` operator can also be applied implicitly by appearance of unsubscripted arrya and functions.
Initializers must evalute either to a constant or to the address of a previously declraed external or static object plus or minus a constst.

Less latitude is allowed for the integral constnat expressions after `#if`; `sizeof` expressions, enumation constants, and casts are not permitted.
