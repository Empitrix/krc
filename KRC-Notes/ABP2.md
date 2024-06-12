## Utility Functions: stdlib.h
The header `<stdlib.h>` declares functions for number conversion, storage allocation, and similar tasks. `double atof(const char *s)`
    `atof` converts s to double; it is equivalent to `strtod(s, (char**)NULL)`.

```c
int atoi(const char *s)
```
converts s to `int`; it is equivalent to `(int)strtol(s, (char**)NULL, 10)`.

```c
long atol(const char *s)
```
converts `s` to `long`; it is equivalent to `strtol(s, (char**)NULL, 10)`.

```c
double strtod(const char *s, char **endp)
```
`strtod` converts the prefix of s to `double`, ignoring leading white space; it stores a pointer to any unconverted suffix in `*endp` unless endp is `NULL`. If the answer would overflow, `HUGE_VAL` is returned with the proper sign; if the answer would underflow, zero is returned. In either case `errno` is set to `ERANGE`.

```c
long strtol(const char *s, char **endp, int base)
```

`strtol` converts the prefix of `s` to `long`, ignoring leading white space; it stores a pointer to any unconverted suffix in `*endp` unless `endp` is `NULL`. If `base` is between 2 and 36, conversion is done assuming that the input is written in that base.

If `base` is zero, the base is 8, 10, or 16; leading 0 implies octal and leading `0x` or `0X` hexadecimal.

Letters in either case represent digits from 10 to `base-1`; a leading `0x` or `0X` is permitted in base 16. If the answer would overflow, `LONG_MAX` or `LONG_MIN` is returned, depending on the sign of the result, and `errno` is set to `ERANGE`.


```c
unsigned long strtoul(const char *s, char **endp, int base)
```
`strtoul` is the same as `strtol` except that the result is unsigned long and the error value is `ULONG_MAX`.

```c
int rand(void)
```
rand returns a pseudo-random integer in the range 0 to `RAND_MAX`, which is at least 32767.

----

```c
void srand(unsigned int seed)
```
srand uses seed as the seed for a new sequence of pseudo-random numbers. The initial seed is 1.


```c
void *calloc(size_t nobj, size_t size)
```
calloc returns a pointer to space for an array of nobj objects, each of size size, or NULL if the request cannot be satisfied. The space is initialized to zero bytes.


```c
void *malloc(size_t size)
```
malloc returns a pointer to space for an object of size size, or NULL if the request cannot be satisfied. The space is uninitialized.


```c
void *realloc(void *p, size_t size)
```
realloc changes the size of the object pointed to by p to size. The contents will be unchanged up to the minimum of the old and new sizes. If the new size is larger, the new space is uninitialized. realloc returns a pointer to the new space, or NULL if the request cannot be satisfied, in which case *p is unchanged.


```c
void free(void *p)
```
free deallocates the space pointed to by p; it does nothing if p is NULL. p must be a pointer to space previously allocated by calloc, malloc, or realloc.

```c
void abort(void)
```
abort causes the program to terminate abnormally, as if by raise(SIGABRT).


```c
void exit(int status)
```
exit causes normal program termination. atexit functions are called in reverse order of registration, open files are flushed, open streams are closed, and control is returned to the environment. How status is returned to the environment is implementationdependent, but zero is taken as successful termination. The values EXIT_SUCCESS and EXIT_FAILURE may also be used.


```c
int atexit(void (*fcn)(void))
```
atexit registers the function fcn to be called when the program terminates normally; it returns non-zero if the registration cannot be made.

```c
int system(const char *s)
```
system passes the string s to the environment for execution. If s is NULL, system returns non-zero if there is a command processor. If s is not NULL, the return value is implementation-dependent.


```c
char *getenv(const char *name)
```
getenv returns the environment string associated with name, or NULL if no string exists. Details are implementation-dependent.

```c
void *bsearch(const void *key, const void *base,
  size_t n, size_t size,
  int (*cmp)(const void *keyval, const void *datum))
```
bsearch searches base[0]...base[n-1] for an item that matches *key. The function cmp must return negative if its first argument (the search key) is less than its second (a table entry), zero if equal, and positive if greater. Items in the array base must be in ascending order. bsearch returns a pointer to a matching item, or NULL if none exists.


```c
void qsort(void *base, size_t n, size_t size,
 int (*cmp)(const void *, const void *))
```
qsort sorts into ascending order an array base[0]...base[n-1] of objects of size size. The comparison function cmp is as in bsearch.

```c
int abs(int n)
```
abs returns the absolute value of its int argument.

```c
long labs(long n)
```
labs returns the absolute value of its long argument.

```c
div_t div(int num, int denom)
```
div computes the quotient and remainder of num/denom. The results are stored in the int members quot and rem of a structure of type div_t.


```c
ldiv_t ldiv(long num, long denom)
```
ldiv computes the quotient and remainder of num/denom. The results are stored in the long members quot and rem of a structure of type ldiv_t.


## Diagnostics: assert.h
The `assert` macro is used to add diagnostics to programs:
```c
void assert(int expression)
```

If expression is zero when
```c
assert(expression)
```

is executed, the `assert` macro will print on stderr a message, such as:
```text
Assertion failed: expression, file filename, line nnn
```

It then calls `abort` to terminate execution. The source filename and line number come from the preprocessor macros `__FILE__` and `__LINE__`.

If `NDEBUG` is defined at the time `<assert.h>` is included, the assert macro is ignored.


## Variable Argument Lists: stdarg.h
The header `<stdarg.h>` provides facilities for stepping through a list of function arguments of unknown number and type.

Suppose `lastarg` is the last named parameter of a function f with a variable number of arguments. Then declare within f a variable of type `va_list` that will point to each argument in turn:

```c
va_list ap;
```
`ap` must be initialized once with the macro `va_start` before any unnamed argument is accessed:

```c
va_start(va_list ap, lastarg);
```

Thereafter, each execution of the macro `va_arg` will produce a value that has the type and value of the next unnamed argument, and will also modify `ap` so the next use of `va_arg` returns the next argument:

```c
type va_arg(va_list ap, type);
```
The macro
```c
void va_end(va_list ap);
```
must be called once after the arguments have been processed but before `f` is exited.



##  Non-local Jumps
The declarations in `<setjmp.h>` provide a way to avoid the normal function call and return sequence, typically to permit an immediate return from a deeply nested function call.
```c
int setjmp(jmp_buf env)
```
The macro `setjmp` saves state information in `env` for use by `longjmp`. The return is zero from a direct call of `setjmp`, and non-zero from a subsequent call of `longjmp`. A call to `setjmp` can only occur in certain contexts, basically the test of `if`, `switch`, and loops, and only in simple relational expressions.
```c
if (setjmp(env) == 0)
  /* get here on direct call */
else
  /* get here by calling longjmp */
```

```c
void longjmp(jmp_buf env, int val)
```
`longjmp` restores the state saved by the most recent call to `setjmp`, using the information saved in `env`, and execution resumes as if the `setjmp` function had just executed and returned the non-zero value val. The function containing the `setjmp` must not have terminated. Accessible objects have the values they had at the time `longjmp` was called, except that `non-volatile` automatic variables in the function calling `setjmp` become undefined if they were changed after the `setjmp` call.


## Signals: signal.h
The header `<signal.h>` provides facilities for handling exceptional conditions that arise during execution, such as an interrupt signal from an external source or an error in execution.

```c
void (*signal(int sig, void (*handler)(int)))(int)
```
`signal` determines how subsequent signals will be handled. If `handler` is `SIG_DFL`, the implementation-defined default behavior is used, if it is `SIG_IGN`, the signal is ignored; otherwise, the function pointed to by `handler` will be called, with the argument of the type of signal. Valid signals include

- `SIGABRT`: abnormal termination, e.g., from abort
- `SIGFPE`: arithmetic error, e.g., zero divide or overflow
- `SIGILL`: illegal function image, e.g., illegal instruction
- `SIGINT`: interactive attention, e.g., interrupt
- `SIGSEGV`: illegal storage access, e.g., access outside memory limits
- `SIGTERM`: termination request sent to this program

`signal` returns the previous value of `handler` for the specific signal, or `SIG_ERR` if an error occurs.


When a signal `sig` subsequently occurs, the signal is restored to its default behavior; then the signal-handler function is called, as if by `(*handler)(sig)`. If the handler returns, execution will resume where it was when the signal occurred.

The initial state of signals is implementation-defined. 

```c
int raise(int sig)
```
`raise` sends the signal `sig` to the program; it returns non-zero if unsuccessful.


## Date and Time Functions: time.h
The header `<time.h>` declares types and functions for manipulating date and time. Some functions process *local time*, which may differ from calendar time, for example because of time zone.
`clock_t` and `time_t` are arithmetic types representing times, and `struct tm` holds the components of a calendar time:

- `int tm_sec;`: seconds after the minute (0,61)
- `int tm_min;`: minutes after the hour (0,59)
- `int tm_hour;`: hours since midnight (0,23)
- `int tm_mday;`: day of the month (1,31)
- `int tm_mon;`: months since January (0,11)
- `int tm_year;`: years since 1900
- `int tm_wday;`: days since Sunday (0,6)
- `int tm_yday;`: days since January 1 (0,365)
- `int tm_isdst;`: Daylight Saving Time flag

`tm_isdst` is positive if Daylight Saving Time is in effect, zero if not, and negative if the information is not available.

```c
clock_t clock(void)
```
clock returns the processor time used by the program since the beginning of execution, or -1 if unavailable. `clock()/CLK_PER_SEC` is a time in seconds.

```c
time_t time(time_t *tp)
```
`time` returns the current calendar time or `-1` if the time is not available. If `tp` is not `NULL`, the return value is also assigned to `*tp`.


```c
double difftime(time_t time2, time_t time1)
```
`difftime` returns `time2-time1` expressed in seconds.


```c
time_t mktime(struct tm *tp)
```
`mktime` converts the local time in the structure `*tp` into calendar time in the same representation used by `time`. The components will have values in the ranges shown. `mktime` returns the calendar time or `-1` if it cannot be represented.


The next four functions return pointers to static objects that may be overwritten by other calls.:
```c
char *asctime(const struct tm *tp)
```
asctime</tt< converts the time in the structure *tp into a string of the form
```text
Sun Jan 3 15:14:13 1988\n\0
```

---

```c
char *ctime(const time_t *tp)
```
ctime converts the calendar time *tp to local time; it is equivalent to 
```c
asctime(localtime(tp))
```

---


```c
struct tm *gmtime(const time_t *tp)
```
gmtime converts the calendar time *tp into Coordinated Universal Time (UTC). It returns NULL if UTC is not available. The name gmtime has historical significance.


---


```c
struct tm *localtime(const time_t *tp)
```
localtime converts the calendar time *tp into local time.

---

```c
size_t strftime(char *s, size_t smax, const char *fmt, const struct tm *tp)
```

strftime formats date and time information from `*tp` into s according to fmt, which is analogous to a printf format. Ordinary characters (including the terminating `'\0'`) are copied into s. Each `%c` is replaced as described below, using values appropriate for the local environment. No more than smax characters are placed into s. strftime returns the number of characters, excluding the `'\0'`, or zero if more than smax characters were produced.


- `%a`: abbreviated weekday name.
- `%A`: full weekday name.
- `%b`: abbreviated month name.
- `%B`: full month name.
- `%c`: local date and time representation.
- `%d`: day of the month (01-31).
- `%H`: hour (24-hour clock) (00-23).
- `%I`: hour (12-hour clock) (01-12).
- `%j`: day of the year (001-366).
- `%m`: month (01-12).
- `%M`: minute (00-59).
- `%p`: local equivalent of AM or PM.
- `%S`: second (00-61).
- `%U`: week number of the year (Sunday as 1st day of week) (00-53).
- `%w`: weekday (0-6, Sunday is 0).
- `%W`: week number of the year (Monday as 1st day of week) (00-53).
- `%x`: local date representation.
- `%X`: local time representation.
- `%y`: year without century (00-99).
- `%Y`: year with century.
- `%Z`: time zone name, if any.
- `%%`: %


## Implementation-defined Limits: limits.h and float.h
The header `<limits.h>` defines constants for the sizes of integral types. The values below are acceptable minimum magnitudes; larger values may be used.

- `CHAR_BIT`:`8`: bits in a char
- `CHAR_MAX`:`UCHAR_MAX` or `SCHAR_MAX`: maximum value of char
- `CHAR_MIN`:`0` or `SCHAR_MIN`: maximum value of char
- `INT_MAX`:`32767`: maximum value of int
- `INT_MIN`:`-32767`: minimum value of int
- `LONG_MAX`:`2147483647`: maximum value of long
- `LONG_MIN`:`-2147483647`: minimum value of long
- `SCHAR_MAX`:`+127`: maximum value of signed char
- `SCHAR_MIN`:`-127`: minimum value of signed char
- `SHRT_MAX`:`+32767`: maximum value of short
- `SHRT_MIN`:`-32767`: minimum value of short
- `UCHAR_MAX`:`255`: maximum value of unsigned char
- `UINT_MAX`:`65535`: maximum value of unsigned int
- `ULONG_MAX`:`4294967295`: maximum value of unsigned long
- `USHRT_MAX`:`65535`: maximum value of unsigned short

The names in the table below, a subset of `<float.h>`, are constants related to floating-point arithmetic. When a value is given, it represents the minimum magnitude for the corresponding quantity. Each implementation defines appropriate values.

- `FLT_RADIX`: `2` radix of exponent, representation, e.g., 2, 16
- `FLT_ROUNDS`: floating-point rounding mode for addition
- `FLT_DIG`:`6`: decimal digits of precision
- `FLT_EPSILON`:`1E-5`: smallest number x such that 1.0+x != 1.0
- `FLT_MANT_DIG`: number of base FLT_RADIX in mantissa
- `FLT_MAX`:`1E+37`: maximum floating-point number
- `FLT_MAX_EXP`: maximum n such that FLT_RADIXn-1 is representable
- `FLT_MIN`:`1E-37`: minimum normalized floating-point number
- `FLT_MIN_EXP`: minimum n such that 10^n is a normalized numbe
- `DBL_DIG`:`10`: decimal digits of precision
- `DBL_EPSILON`: `1E-9`: smallest number x such that 1.0+x != 1.0
- `DBL_MANT_DIG`: number of base FLT_RADIX in mantissa
- `DBL_MAX`:`1E+37`: maximum double floating-point number
- `DBL_MAX_EXP`: maximum n such that `FLT_RADIX^n-1` is representable
- `DBL_MIN`:`1E-37` minimum normalized `double` floating-point number
- `DBL_MIN_EXP`: minimum n such that 10^n is a normalized number
