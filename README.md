# ft_printf

```ft_printf``` is a 42 Project that aims to mimic libc printf function.

## Project Overview

Subject -> [EN](https://github.com/tina-ak47/ft_printf/blob/master/links/ft_printf_en.pdf) | [FR](https://github.com/tina-ak47/ft_printf/blob/master/links/ft_printf_fr.pdf)

### Basics, requested from subject:

Conversion specifier : ```%c``` ```%s``` ```%p``` ```%d``` ```%i``` ```%u``` ```%x``` ```%X``` ```%%```.
Parsing for flags ```0``` & ```-```, width and precision.

### Format specification syntax

A conversion specification consists of optional and required fields in this form:

```
%[flags][width][.precision][size][type]
```

The ```size``` is not requested in the subject.

### Type field character

|Type character|Argument|Output format|
|--------------|--------|-------------|
|```c```|char|Displays UTF-8 characters. Specifies a single-byte character.|
|```d```|int|Displays signed decimal.|
|```i```|int|Displays signed decimal.|
|```u```|unsigned int|Displays unsigned decimal.|
|```x```|int|Converts in base 16 unsigned hexadecimal integer. Uses "abcdef"|
|```X```|int|Converts in base 16 unsigned hexadecimal integer. Uses "ABCDEF"|
|```p```|Pointer type|Displays the argument as an address in hexadecimal digits.|
|```s```|char*|specifies a single-byte or multi-byte character string. Characters are displayed up to the first null character or until the precision value is reached.|
|```%```|None|Displays a '%'.|

## Flags

### Minus

Left align the result within the given field width. Default : right align.

### Zero

If width is prefixed by 0, leading zeros are added until the minimum width is reached.
If both 0 and - appear -> the 0 is ignored.
For an integer format (i, u, x, X, o, d) :
If 0 is specified and a precision specification is also present -> the 0 is ignored. 

## Width specification

The optional width specification field appears after any flags characters.

* ```Width``` is a non-negative decimal integer.
* ```Width``` controls the minimum number of characters that are output.
* If ```width value > number of characters in the output``` blanks (zeros if flag ```zero``` is present) are added to the right until the minimum width is reached. To the left if flag ```minus``` is present.
* The width specification never causes a value to be truncated.
* If the width specification is an asterisk (*), an int argument from the argument list supplies the value. /!\ if ```width value < 0```.

```
Examples :
printf("%5d", 42); --> '   42'
printf("%*d", 5, 42); --> '   42'
printf("%5d", 123456); --> '123456'
printf("%05d", 42); --> '00042'
printf("%-5d", 42); --> '42   '
```

## Precision specification

The precision depends on the conversion type.

* ```Precision``` consists of a period (.) followed by a non-negative decimal integer.
* For ```%s``` it specifies the number of string characters. The precision can cause either truncation of the string.
* For ```%p``` ```%d``` ```%i``` ```%u``` ```%x``` ```%X``` it specifies the number of digits to be output. If precision is specified as 0, and the value to be converted is 0, the result is no characters output.

```
Examples :
printf("%.5d", 42); --> '00042'
printf("%.*d", 5, 42); --> '00042'
printf("%.5d", -42); --> '-0042'
printf("%.5d", 123456); --> '123456'
printf("%.0d", 0); --> '' /* No characters output */
```

## Installation & Tests

```
$> make
$> gcc -Iincludes libftprintf.a main.c && ./a.out
```

## Bitwise operator

Bitwise operator are usefull to parse the format string. 
You can check the presence of ```-```, ```0```, ```width``` and ```precision``` very easy in a ```mask```.

```
define IS_MINUS		1 << 0
define IS_ZERO		1 << 1
define IS_WIDTH		1 << 2
define IS_PRECISION	1 << 3
```
The type of the ```mask``` depends of the number of informations you need to stock. For example in a type ```char``` you can have 8.

If ```-``` and ```0``` are present in the format string :
```
mask |= IS_MINUS;
mask |= IS_ZERO;
mask --> 0000 0011
```

|Operator|Meanning|
|--------|--------|
|```&```|Bitwise AND operator|
|```|```|Bitwise OR operator|
|```^```|Bitwise exclusive OR operator|
|```~```|Binary One's Complement Operator is a unary operator|
|```<<```|Left shift operator|
|```>>```|Right shift operator|

The result of the computation of bitwise logical operators :

|```a```|```b```|```a&b```|```a|b```|```a^b```|
|-------|-------|---------|---------|---------|
|0|0|0|0|0|
|0|1|0|1|1|
|1|0|0|1|1|
|1|1|1|1|0|

## Useful links 🤙

* About [printf](https://docs.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2019)
* Another [man printf](http://www.cplusplus.com/reference/cstdio/printf/)
* Basics about [Bitwise operator](https://www.guru99.com/c-bitwise-operators.html)
* Try out the [Bitwise commands](http://bitwisecmd.com/)