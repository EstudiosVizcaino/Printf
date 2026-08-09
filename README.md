# ft_printf

A reimplementation of the C standard library's `printf`, written for the 42 curriculum.

The project compiles to a static library, `libftprintf.a`, which exposes one public
function, `ft_printf`. It parses a format string, writes the result to standard output
and returns the number of characters written. Nothing from `stdio` is used: the only
external pieces are `write` from `unistd.h` and the variadic macros from `stdarg.h`.

```c
int ft_printf(const char *s, ...);
```

## Supported conversions

| Specifier | Output |
| --- | --- |
| `%c` | A single character. |
| `%s` | A NUL-terminated string. Prints `(null)` when the pointer is `NULL`. |
| `%d`, `%i` | A signed decimal integer. |
| `%u` | An unsigned decimal integer. |
| `%x` | An unsigned integer in lowercase hexadecimal. |
| `%X` | An unsigned integer in uppercase hexadecimal. |
| `%p` | A pointer as `0x` followed by lowercase hexadecimal. Prints `(nil)` when the pointer is `NULL`. |
| `%%` | A literal percent sign. |

## Building

```sh
make
```

That leaves `libftprintf.a` in the project root. The usual housekeeping rules are
available too:

| Rule | Effect |
| --- | --- |
| `all` | Builds the library (default). |
| `clean` | Removes the object files. |
| `fclean` | Removes the object files and the library. |
| `re` | `fclean` followed by `all`. |

Everything is compiled with `-Wall -Wextra -Werror`.

## Usage

Include the header and link against the archive:

```c
#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("%s scored %d points, 100%% of them at %p\n", "Ada", 42, &len);
	ft_printf("that line was %d bytes long\n", len);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror example.c libftprintf.a -o example
./example
```

## Testing

`main.c` is a small test driver that is deliberately kept out of the library sources.
It runs one dense format string through `ft_printf`, then the identical string through
the real `printf`, and finally prints both return values. Any difference in the output
or in the character count shows up immediately on screen.

```sh
make
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf
```

The string it exercises covers consecutive conversions, `INT_MIN`, negative values
passed to `%u`, a `NULL` pointer and escaped percent signs.

## Layout

| File | Contents |
| --- | --- |
| `ft_printf.c` | The parsing loop, and the routine that sends each specifier to its handler. |
| `ft_printf.h` | Public prototype plus the internal helper prototypes. |
| `ft_putchar.c` | Writes one character. |
| `ft_putstr.c` | Writes a string, or `(null)`. |
| `ft_putnbr.c` | Signed decimal conversion. |
| `ft_putdecun.c` | Unsigned decimal conversion. |
| `ft_putnbr_hexa.c` | Hexadecimal conversion in either case. |
| `ft_putptr.c` | Pointer conversion. |
| `ft_strlen.c` | String length. |
| `main.c` | Test driver, not part of the archive. |

## Implementation notes

Every helper takes a pointer to the running character counter and increments it with
whatever `write` actually returned, rather than with the number of bytes it was asked
to send. A short or failed write therefore cannot inflate the value `ft_printf` hands
back.

`INT_MIN` is the one signed value that cannot be negated inside an `int`, so
`ft_putnbr` emits its leading digit first and negates the remainder, which fits.
`%u` reaches the same result from the other direction by adding 2^32 to a negative
argument before converting it.

The hexadecimal and pointer conversions are recursive. Each call divides by 16 and
recurses before printing, so the digits come out most significant first without
needing a buffer to reverse.

The source follows the 42 Norm: no `for` loops, at most 25 lines per function and
5 functions per file, and declarations grouped at the top of each block.

## Limitations

The scope is the mandatory part of the assignment, so the format grammar stops at the
conversion character. Not implemented:

- Flags (`-`, `0`, `+`, ` `, `#`)
- Field width and precision
- Length modifiers (`l`, `ll`, `h`, `hh`)
- Floating point conversions

Output always goes to file descriptor 1. A specifier that is not in the table above
produces no output at all.

## Author

[cvizcain](https://profile.intra.42.fr/users/cvizcain), 42 Madrid.

This is coursework. If you are working through the same project, read it for ideas but
write your own, since 42 runs plagiarism checks on submissions.
