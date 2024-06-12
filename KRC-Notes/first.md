the main reason that in programming language we can't use`5/9` as a result of devision is because the result will written as int and the ambout of 5/9 in int is 0;


printf is not part of the C language. because in c there is no I/O
behavior of printf is defined by ANSI(American National Standard Institute) it should have same behavior with any library or compiler


to make more prettier output in c we can use right-justified, which means we can define the `width` of number for example:
```c
printf("%3d %6d\n", fahr, celsius);
```
the `%3d`: 3 width and the number (number can fill the empty space)
the `%6d`: 6 width and the number (number can fill the empty space)

by 3:
```plaintext
-->(number with 1 digit)
->(number with 2 digit (fill emptyness))
```
width number can be set by `*`:
```c
printf("%*s", <width>, "a");
```

---

> [!NOTE]
> you can define type of variables (int/float) by adding floating points to them.



in an arithmetic operator if ther is one integer and one float the integer will turn into float before the operation is done.



## Format Specifiers
|    Specifier   |    Data Type   |    Description         |
|----------------|----------------|------------------------|
|    %d or %i    |      int       |   digit  or integer    |
|     %f         |      float     |     dobule             |
|      %lf       |      float     | long float (double)    |
|     %c         |      char      |  character             |
|     %s         |      string    |  String                |
|     %p         |      pointer   |  Pointers              |
|     %ld        |     long int   | long integer(10^38)    |
|     %o         |     octal      | unsigned int in base 8 |
|     %x         |   hexadecimal  | unsigned int in base 16|


and for writing `%` just use `%%`.



### curly braces are not necessary!?
if tehre is only 1 statement

```c
for(fahr = 0; fahr <= 300; fahr = fahr + 20){
  printf("%3f %6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
}
```

```c
for(fahr = 0; fahr <= 300; fahr = fahr + 20)
  printf("%3f %6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
```


---

use loops if statements are logically related otherwise use while.




## Character Input Output

the following code caputues on character at the time (what comes after `getchar`)
```c
char c;
c = getchar();
```

following line of code print a character each time
```c
char c;
c = "A";
putchar(c);
```

`putchar` print the contents of the integer variable.

chars are stored as a bit pattern.



---

`getchar` returns an **END OF FILE (EOF)** when there is not valid char.
- EOF: is an int defined in `<stdio.h>`



the reason that we set return type of `getchar` to int is that the value should be big enought to hold any possible char.



in C any assignment such as `c = getchar()` is an expression and have a value (can be used in a larger expressions like while loop etc...)

for example:
```c
int c;
while((c = getchar()) != EOF)
  putchar(c);
```

which is called `Walrus Operator` in python and the test value of while loop can be assign in a varialbe.



The `getchar() != EOF` operation is always possitive in c until program ends with `<C-c>` (terminated!).
The value of **EOF** is a (-1) which is a negative number and any return char of `getchar` is positive until program ends.
