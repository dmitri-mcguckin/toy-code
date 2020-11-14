# DmitriString
A custom string library, intended to obfuscate interactions with cstrings when dealing with higher-level/user-level programming.

Makes use of IOStream, and string.h *(The CString Library)*

**IOStream:** http://www.cplusplus.com/reference/iostream/

**String.h:** http://www.cplusplus.com/reference/cstring/?kw=string.h

## Overloaded Operators:
*For your enjoyment*

1. `=` Assignment Operator

	Copies the second DString operand to the first.
2. `[]` Subscript Operator

	Returns the char value at the index in the DString array.
3. `+` Addition Operator

	Concatenates two DStrings togeather, and returns a new DString of the concatination.
	Supports concatenating `const char *` values too.
4. `-` Subtraction Operator

	Removes all instances of a given char in a DString, and returns the reference to the DString modified.
5. `<<` Insertion Operator

	Passes the value of DString to a given buffer, returns the buffer.
6. `>>` Extraction Operator

	Not yet implemented
7. `<` Less Than Operator

	Adds the char values of each char in a DString and compares it to the sum of a similar sum in another DString.
8. `<=` Less Than Equal To Operator

	Adds the char values of each char in a DString and compares it to the sum of a similar sum in another DString.
9. `>` Greater Than Operator

	Adds the char values of each char in a DString and compares it to the sum of a similar sum in another DString.
10. `>=` Greater Than Equal To Operator

	Adds the char values of each char in a DString and compares it to the sum of a similar sum in another DString.
11. `==` Equality Operator

	Adds the char values of each char in a DString and compares it to the sum of a similar sum in another DString.
12. `!=`  Non-Equality Operator

	Adds the char values of each char in a DString and compares it to the sum of a similar sum in another DString.

## Functions

1. `const int length() const`

	Returns a non-modifieable number of characters in a DString
