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

## Useful links 🤙

* About [printf](https://docs.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2019)
* Or a [man printf](http://www.cplusplus.com/reference/cstdio/printf/)
* Try out the [Bitwise commands](http://bitwisecmd.com/)

