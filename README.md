# ft_printf

```ft_printf``` is a 42 Project that aims to mimic libc printf function.

## Project Overview

Subject -> [EN](https://github.com/tina-ak47/ft_printf/blob/master/links/ft_printf_en.pdf) | [FR](https://github.com/tina-ak47/ft_printf/blob/master/links/ft_printf_fr.pdf)

### Basics, requested from subject:

Conversion specifier : ```%c``` ```%s``` ```%p``` ```%d``` ```%i``` ```%u``` ```%x``` ```%X``` ```%%```
Parsing for flags ```0``` & ```-```, width and precision.

* ```%c``` & ```%s``` : displaying UTF-8 characters. 
* ```%x``` & ```%X``` : computing unsigned numbers in base 16.
* ```%d``` & ```%i``` : displaying signed numbers.
* ```%u``` : displaying unsigned numbers.
* ```%p``` : displaying pointer address.
* ```%p``` : displaying a '%'.

### Format specification syntax

A conversion specification consists of optional and required fields in this form:

```
%[flags][width][.precision][size][type]
```

The ```size``` is not requested in the subject.

### Type field characters

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

### Minus ```%-c``` ```%-s``` ```%-d``` ...



## Useful links

* About [printf](https://docs.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2019)
* Or a [man printf](http://www.cplusplus.com/reference/cstdio/printf/)
* Try out the [Bitwise commands](http://bitwisecmd.com/)

