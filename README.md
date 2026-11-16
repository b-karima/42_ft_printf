*This activity has been created as part of the 42 curriculum by kkarima.*

# ft_printf

## Description

**ft_printf** is a foundational C programming project from the 42 Common Core curriculum. Its main goal is to replicate the behavior of the standard C library function `printf()` by creating a static library named `libftprintf.a`.

Through this project, we learn how to handle an arbitrary number of arguments of varying types using variadic functions (`<stdarg.h>`), parse format strings sequentially, and manage low-level output formatting without relying on standard buffered I/O functions.

### Supported Conversions
This implementation supports the mandatory conversion specifiers:
* **`%c`**: Prints a single character.
* **`%s`**: Prints a string of characters (displays `(null)` if the pointer is `NULL`).
* **`%p`**: Prints a `void *` pointer address in hexadecimal format prefixed with `0x` (displays `(nil)` if the pointer is `NULL`).
* **`%d` / `%i`**: Prints a signed decimal integer (base 10).
* **`%u`**: Prints an unsigned decimal integer (base 10).
* **`%x` / `%X`**: Prints an unsigned integer in hexadecimal format (base 16), using lowercase (`0-9a-f`) or uppercase (`0-9A-F`) characters.
* **`%%`**: Prints a literal percent sign (`%`).

---

## Instructions

### Compilation
The project includes a `Makefile` that compiles the source files using `cc` with the flags `-Wall -Wextra -Werror` and archives them into `libftprintf.a` using `ar rcs`.

To compile the library, run the following command at the root of the repository:
```bash
make
```

Additional Makefile rules available:
* `make clean`: Removes compiled object files (`.o`).
* `make fclean`: Removes object files and the `libftprintf.a` archive.
* `make re`: Forces a full recompilation from scratch.

### Usage & Execution
To use `ft_printf` in your own C program, include the header `"ft_printf.h"` and link `libftprintf.a` during compilation:

```c
#include "ft_printf.h"

int	main(void)
{
	int	count;

	count = ft_printf("Hello %s! Hex: %x | Ptr: %p | Number: %d%%\n",
			"42", 255, &count, 100);
	ft_printf("Total characters printed: %d\n", count);
	return (0);
}
```

Compile your test file with the library:
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf
```

---

## Algorithm & Data Structure

### Data Structures
* **Variadic Argument List (`va_list`)**: Rather than allocating dynamic data structures (such as linked lists or buffers), the function relies directly on `<stdarg.h>` macros (`va_start`, `va_arg`, and `va_end`) to traverse variadic arguments sequentially from the call stack/registers.
* **Lookup Strings for Base Conversion**: Hexadecimal conversions (`%x` and `%X`) use constant character arrays (`"0123456789abcdef"` and `"0123456789ABCDEF"`) as direct index lookup tables to map remainders (`nb % 16`) to their corresponding ASCII characters in $O(1)$ time.

### Chosen Algorithm
1. **Linear Single-Pass Parsing**: `ft_printf` iterates through the input `format` string once ($O(n)$ time complexity relative to string length). Standard characters are written immediately to standard output (`fd = 1`) via the `write()` system call, incrementing a running character counter (`ret`).
2. **Specifier Dispatching**: Whenever a `%` character is encountered, control is delegated to a dispatcher function (`ft_convert_print`) that inspects the following specifier character, extracts the next argument via `va_arg` using the appropriate promoted type (e.g., reading `int` for `%c` due to default argument promotion in C, and casting pointers to `unsigned long long` for `%p` to preserve 64-bit addresses), and invokes the corresponding formatting helper.
3. **Recursive Base Conversion**: Numeric conversions (`ft_putnbr`, `ft_putnbr_u`, `ft_putnbr_hexa_low`, `ft_putnbr_hexa_up`) use recursion to decompose integers from least significant to most significant digit (`nb / base`) before printing each digit (`nb % base`) on the stack unwind. This naturally outputs digits in left-to-right order without requiring dynamic memory allocation (`malloc`) or temporary string buffers, keeping space complexity proportional solely to the recursion depth ($O(\log_{\text{base}}(N))$, at most 16 stack frames for 64-bit hexadecimal values).

---

## Resources

### Classic References
* **Linux Programmer's Manual**: `man 3 printf` and `man 3 stdarg` for official specifications on format specifiers, return values, and variadic macros (`va_start`, `va_arg`, `va_end`).
* **The C Programming Language (K&R, 2nd Edition)**: Section 7.2 (*Formatted Output - Printf*) and Section 7.3 (*Variable-length Argument Lists*).
* **42 Docs & Peer Discussions**: Documentation regarding C default argument promotions, two's complement representation for signed/unsigned conversions, and 64-bit pointer casting.

### AI Usage
AI tools (Claude / Gemini) were used during the learning and documentation phases of this project for the following tasks:
* **Conceptual Understanding**: Clarifying how `<stdarg.h>` macros interact with memory/registers, understanding C integer promotion rules for `char` arguments in `va_arg`, and reviewing edge cases (`NULL` strings/pointers and `INT_MIN`).
* **Practice Exercises**: Generating progressive exercises on variadic functions (`ft_sum`, `ft_prints`, and a mini-dispatcher) prior to writing the project code.
* **Documentation**: Assisting in structuring and drafting this `README.md` file to ensure clarity and compliance with the curriculum requirements.
