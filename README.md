# 0x11. C - printf

## Authors
* Ugochi Talabi 
* Oluwadunsin Abisuwa

## Description 
The _printf() function produces output according to a format which is described below. This function write its output to the stdout, the standard output stream. Returns the count of printed characters when the function is successful and -1 when the function fails.
The function _printf writes output to standard output. The function writes under the control of a format string that specifies how subsequent arguments (accessed via the variable-length argument facilities of stdarg) are converted for output.

Prototype: int _printf(const char *format, ...);

## Specifers 
The format string argument is a constant character string composed of zero or more directives: ordinary characters (not %) which are copied unchanged to the output 
stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments. 
Conversion specification is introduced by the character % and ends with a conversion specifier. In between the % character and conversion specifier, there may be (in order) zero or more flags, an optional minimum field width, an optional precision and an optional length modifier. The arguments must correspond with the conversion specifier, and are used in the order given.

The available convertion specifiers are:

* %c: Prints a single character.
* %s: Prints a string of characters.
* %d: Prints integers.
* %i: Prints integers.
* %b: Prints the binary representation of an unsigned decimal.
* %u: Prints unsigned integers
* %x: Prints the hexadecial representation of an unsigned decimal in lowercase letters
* %X:Prints the hexadecial representation of an unsigned decimal in uppercase letters
* %S: prints the string.
* %l and %h:Handle the following length modifiers for non-custom conversion specifiers
* %r: Prints a reversed string
* %R: Prints the Rot13 interpretation of a string


## Return Value
Upon successful return, _printf returns the number of characters printed (excluding the terminating null byte used to end output to strings). If an output error is encountered, the function returns -1.

### Flag Characters
The character % may be followed by zero or more of the following flags:

For o conversions, the first character of the output string is prefixed with 0 if it was not zero already.
For x converions, 0x is prepended for non-zero numbers.
For X conversions, 0X is prepeneded for non-zero numbers.

