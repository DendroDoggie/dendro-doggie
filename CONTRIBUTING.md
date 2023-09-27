# Contributing to DendroDoggie

Thank you for your interest in contributing to DendroDoggie! There are many
ways to contribute and we appreciate all of them.

## Bug reports

## Documentation and Style Guide

### Specifics on indentation and line width

- Use spaces
- Every indentation must be 4 spaces
- A max of 80 character should appear on a line, this includes comments

### Naming conventions

Variables and function names should follow snake case. This will ensure
cohesivness with other C libraries used throughout the project.

```c
char a_character = 'a';

int a_function(int a)
{
    return 0;
}
```

When defining structs or enums, make use of camel case to better
differentiated between variables and functions and structs and enums. The
`typedef` keyword should also be avoided to add an extra layer of
differentiation for structs.

```c
struct MyStruct
{
    int field_a;
    char field_b;
};

enum MyEnum
{
    FIRST,
    SECOND,
    THIRD
};
```

### Formatting

Block indents are preferred over any other indentation convention with the
closing bracket, brace, or parenthesis on a line by itself.

```c
// start and end of function call can be clearly seen
func(
    var_a, // variables are easily picked out
    var_b
);

// aligning variables is also acceptable, but is limited to functions with a
// minimal number of parameters
long_func_name(
    var_a, var_b,
    var_c
);


// having the opening brace on its own line adds extra white space which
// strengthens readability of a function's beginning line
int func(int a, int b)
{
    return a + b;
}


int long_func_name(int a, int b, int c)
{
    return (a - b) / c;
}
```

When initializing or updating variables, or initializing arrays, it is
important to stick to block indentation. The advantage to block indentation
is preventing any chance of tab-space mixing which would hurt readability in
other text editors with dissimilar configuration.

```c
char* char_arr[3] = { "Array", "of", "c-strings" };

struct Bar* bar;
struct_bar_init(
    &bar,
    for_field_a, for_field_b,
    for_field_c, for_field_c,
    and_field_d
);
```

### Branching, Looping, and Multi-line operations

The style of if, else if, and else statements, in conjunction with for and
while loops should adhere to the style of structs, enums, and functions set
forth above.

```c
bool flag = false;

if (flag)
{
    // do stuff
}
```

Writing branching statements in a way which promotes readability is of the
utmost importance; in addition, writing in such a way helps debugging efforts
since operators can be easily identified.

Long strings of conditions, or strings with many small checks should split
their conditions amongst multiple lines with the operator preceeding the
condition. The programmer should use their best discretion to make if and
looping statements as readable as possible.

```c
if (long_condition
    && another_long_condition
    && third_long_condition
    || compound_condition
) {
    // do other stuff
}
```

When using a string of if-then-else statements, each statement should be on a
new line following the closing brace of the preceeding branch of code.

```c
if (first_condition)
{
    // do stuff
}
else if (second_condition)
{
    // do other stuff
}
else
{
    // do default stuff
}
```

It is expected that flags are kept concise making use of the `!` operator when
checking for falsity.

For loops are unique in the sense they utilize semicolons (;) and can have
multiple looping conditions. Therefore, the programming should be extra
sensitive to make effective use of white space to make explicit the dictation
of a for loop's initialization, maintainance, and termination.

```c
// multiple conditions
for (int some_var = 0;
    condition && other_condition;
    some_var += 1
) {
    // do stuff
}

// a string of conditions
for (int some_var = 0;
    really_long_condition
    && another_condition
    && some_other_condition;
    some_var += 1
) {
    // do stuff
}
```

Carrying out lengthy calculations is also a point where white space and
operator placement is crucial for maintenance and debugging. To effectively
carry out calculations, we ask that a new, indented line which starts at the
operator.

```c
double res = (4 - long_calculation + another_long_calculation)
    / (some_other_calculation * 100);
```

### Blank lines

Blanks lines are useful for conveying the relationship between lines of code.
The programmer should use their best discretion to separate two or more lines
of code; however, it is recommended to keep highly related lines together, and
to separate another highly related group of lines from another by a single
blank line.

```c
double curve_area(a1, b1, a2, b2, dx)
{
    // each line works to get the area of the first trapezoid
    double a1_y = f(a1);
    double b1_y = f(b1);
    double area1 = trapezoid_area(a1_y, b1_y, dx);

    // a blank line helps reinforce the following block is for the second
    // trapezoid's area
    double a2_y = f(a2);
    double b2_y = f(b2);
    double area2 += trapezoid_area(a2_y, b2_y, dx);

    // returns should always be separated by one blank line
    return area1 + area2;
}
```

### Including external libraries

When bringing in code from other libraries, or elsewhere in the project,
statements should be sorted alphabetically.

```c
#include <stdio.h>
#include <stdlib.h>

#include "some_library.h"
#include "some_otner_library.h"
```

### Comments

A comment maybe on its own line, above the line of code on which it comments;
or the comment maybe inline. 
Comments describing a line or block of code are no expected to follow any
specific format structures except for clearly conveying the goal being
accomplished.

```c
// a comment describing a variable
int a = 4;
int b = 0; // a comment on the variable b

// take the sum of a and b
int sum = a + b;
```

When documenting a struct or function, comments should follow multi-line,
or "block", convention. In addition, documentation for each field or function
parameter should be provided having the field name immediately preceeded by an
at-sign (@) and followed by a short description of the information the field
contains or tries to communicate.

```c
/**
 * this is documentation for struct `Foo`
 * @a used for some purpose
 * @b used for some other purpose
 */
struct Foo
{
  int a;
  int b;
};

/**
 * documentation for function `bar`
 * @foo pointer to a struct Foo
 * @returns functions should also describe the data they return
 */
int bar(struct Foo* foo);
```

### Specifics

A very specific convention to keep in mind is to always use the update
operator (+=, -=). The choice to force this convention is the fact that other
operators commonly used for incremending and decrementing (++, --) can affect
when a variable gets updated depending on whether it preceeds or exceeds
(++i, i++). To avoid this the update operators should be used everywhere they
are applicable.

```c
for (int i = 0; i < 100; i += 1)
{
    // do stuff
}
```

```c
int i = 0;

while (condition)
{
    // do stuff

    i += 1;
}
```
