## Objects and Lvalues
An *object* is named region of storage; an *lvalue* is an expression refering to an object.
An obvious example of an lvalue expression is an identifier with suitable type and storage class.

There are operations that yeild lvalues; for example, if `E` is an expreesion of pointer type, then `*E` is an lvalue expression refeering to the object with `E` points.

The name of "lvalue" comes from the assignemnt expression `E1 = E2` in which the left operand `E1` must be an lvalue expression.
The discussion of each operator specifies whether it expects lvalue operands and wheter it yeilds an lvalue.


## Conversion
Some operators mya, depending on their operands, cause conversion of the value of an operand from one type to another.


### Integral Promotion
If an `int` can represent all the values of the original type, then the value is converted to `int`; otherwise the nvalue is converted to `unsiged int`. This process is called **integral promotion**.

### Integral Conversions
Any integer is conveted to a given unsigned type by finding the smalles non-negative value that is congruent to that integer, modulo one more than the largest value that can be represented in the unsinged type.

> In a two's complement representation, this is equivalent to left-turncation if the bit pattern of the unsinged type is narrower, and to zero-filling unsinged values and sign-extending signed values if the unsgined type is wider.

**When any integer is converted to a singed type, the value is unchanged if it can be represented  in the new type and is implementation-defined otherwise.**


### Integer and Floating
When a value of floating type is conveted to integral type, the fractional part is dicarded; if the resutling value cannot be represented in the integral type, the behavior is undefined. In  particular, the result of converting engative floating values to unsinged integral types is not specified.

When a value of integral type is conveted to floating, and the value is in the representable range  but is not exactly representable, then  the result may be either the next higher or next lower representable value. If the result is not out of the range, the behavior is undefined.


### Floating Types
When a less precise floating value is converted to an equally or  more precise floating type, then  value is unchanged.
When a more precise floating value is converted to less precise floating type,  and the value is within representable range, the result may be either the next higher or the next lower representable value, If the result is out of range the behavior is undefined.

### Arithemtic Conversions
The effect is to bring operands into a common type, which is also the type of the result, This patern is called the *usual arighemtic converions*.
```text
long double -> long double
double -> double
float -> float
```
the integral promotions are performed on both operands; then if eighter operand is `unsigedn long int` the other is conveted to `unsinged long int`.

Othwerwise, if one operand is `long int` and the other is `unsigned int`, the effect depends on whether a `long int` can represent all values of an `unsinged int`; if so the `unsinged int` operand is conveted to `long int`; if no, both are conveted to `unsinged long int`.
Otherwise, if one operand is `long int`, the other is conveted to `long int`.
Otherwise, if either operand is `unsinged int`, the other is conveted to `unsinged int`.
Otherwise, both operands have type `int`.


### Pointers and Integers
An expression of integral type may be added to or subtracted from a pointer;

> Two pointers to objects of the same type, in the same array, may be subtracted; the result is converted to an integer.

An integral constnat expression with value 0, or such an expression cast to type `void *`, may be conveted, by a cast, by assignemnt, or by comparsion, to a pointer of any type.
This produces a null pointer that is equal to another null pointer of th same type, but unequal to any pointer to a function or object.

NOTE: A pointer may be conveted to an integral type large enoough to hold it; the required size is implementaion-dependent, The mapping function is also implementation-dependent.

NOTE: *A pointer to one type may bo conveted to a pointer to another type.*

The resulting pointer may cause addressing exceptions if the subject poiinter does not refer to an object suitably aligend in sotrage.
It is guranteed that a pointer to an object may be converted to apointer to an object whose type requires less or qually strict storage alignment and back again without change.

NOTE: A pointer may also be converted to type `void *` and back again without change.

NOTE: A pointer to a function may be converted to a pointer to another funciton type. Calling the function specified by the conveted pointer to implementation-dependent; however, if the conveted pointer is reconveted to its origina type, the result is identical to the original pointer.


### Void
The (nonexistent) value of a `void` object may not be used in any way, and neither explicit nor implicit conversion to any non-void type may be applied.
Because a void expression denotes a nonexistent value, such an expression may be used only where the value is not required.


### Pointers to Void
Any pointer to an object may be converted to type `void *` without loss of information.
If the result is converted back to the original pointer type.
pointers may be assigned to and from pointers of type `void *`, and may be compared with them.


## Expressions
The precedence of expression operators is the same as the order of the major subsections of this section, highest precedence first.

each operator combines the values produced by its operands in a way compatible with the parsing of the expression in which it appears.

The handling of overflow, divide check, and other exceptions in expression evaluation is not defined by the language. Most existing implementations of C ignore overflow in evaluation of signed integral expressions and assignments, but this behavior is not guaranteed. Treatment of division by 0, and all floating-point exceptions, varies among implementations; sometimes it is adjustable by a non-standard library function.


### Pointer Generation
If the type of an expression or subexpression is "array of *T*", for some type *T*, the the value of the expression is a pointer to the first object in the array, and the type of the expression is alterd to "pointer to *T*".
This eonvertions does not take palce if the expression is the operand of the unary `&` operator, or of `++`, `--`, `sizeof`, or as the left operand of an assignementt operator or the `.` operator.


### Primary Expressions
Primary expression are identifiers, constants, strings, or expressions in parentheses.
```text
primary-expression:
  identifer
  constant
  string
  ( expression )
```

An identifer is an lvalue if ti refers to an object and if its type is arithemtic, strucutre, union, or pointer.

String: Its type is originally "array of char", but this is usually modified to "pointer to char" (wchar_t) and the result is a pointer t othe first character in the string, The conversion also does not occur in certain initializers.

A parenthesized expression is a primary expression whose type and value are identical to those of the unadoraned expression. The presence of parentheses does not affect whether the expression is an lvalue.


### Postfix Expressions
The oprators in postfix expressions group left to right.
```text
postfix-expression:
  primary-expression
  postfix-expression [ expression ]
  postfix-expression ( argument-expression-list )
  postfix-expression . identifer
  postfix-expression -> identifier
  postfix-expression ++
  postfix-expression --

argument-expression-list:
  assignemnt-expression
  argument-expression-list , assignemnt-expression
```


#### Array Refrences
A postfix expression followd by an expression in square brackets is a postfix expression denoting a subscripted array reference. One of the two expressions must have type "pointer to *T*", where *T* is some type, and the other must have integral type; the type of the subscript expression is *T*. The expression `E1[E2]` is identical (by definition) to `*((E1)+(E2))`.

#### Funciont Calls
A function call is a postfix expression, called the funciton designator, followed by parentheses constaining a possibly empty, comma-spearatored list of assignemnt expressions sists of an identifer for which no declaration exists in the current scope, the identifier is implicitly declared as if the declaration
```c
extern int identifier();
```
had been given in the innermost block containing the function call.
The postfixt epxression (after possible implicit declration and pointer generation) must be of type "pointer to functino returning *T*", for some type *T*, and the value of the function call has type *T*.

The term *arguemnt* is used for an expression passed by a function call; the term *parameter* is used for an input object (or its identifer) recived by a functino definition, or descibed in a function declaration.
The terms "actual argument (parameter)" and "formal arguemnt (parameter)" respectively are sometimes used for the same distinction.


the new way of calling function is with making a prototype out of it.

Integral promotion is preformed on each argument of ingetral type, and each `float` argument is conveted to `double`.

If the function declration is scope for call is new-style, then the arguments are conveted, as if by assignemnt, to the type of the correspoinding parameters of the functions's prototype.

The order of evalution of arguments is unspecedifed; various compiles differ.
The arguments and the functin designator are completely evaluated, including all side effects, before the function is entred, Recursive calls to any function are permitted.

### Strucutre Refrences
The expression is an lvalue if the first expression is an lvalue, and if the type of the second expression is not any array type.

A postfix expression followed by an arrow (`->`) followed by an identifer is a postfix expression
The expression `E1->MOS` is the same as `(*E1).MOS`.


### Postfix Incrementation
A postfix expreesion followed by `++` or `--` operator is a postfix expression. The value of the expression is the vlaue of the operand. after the value is noted. the operand is incremented (`++`) or decremented (`--`) by `1`. The operand must be an lvalue; The result is not an lvalue.
