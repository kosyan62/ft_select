[![42](https://img.shields.io/badge/-Project-black?logo=42&logoColor=white)](https://42.fr/)
[![Test](https://github.com/kosyan62/libft/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/kosyan62/libft/actions/workflows/c-cpp.yml)
![C](https://img.shields.io/badge/Language-%2300599C.svg?logo=c&logoColor=white)
# Libft - C Standard Library Reimplementation


Libft is a foundational project developed as part of the 42 School curriculum. Its objective is to recreate essential C standard library functions from scratch while following strict coding standards. This library provides a reusable collection of C functions that are designed to be used in future projects.

## Project Overview

- Language: C
- Goal: Implement a static C library (`libft.a`) containing re-implemented standard C functions, along with additional utility and linked list functions.
- Purpose: Gain a deep understanding of memory management, string manipulation, and basic data structures in C.
- [Original task](static/libft.en.pdf)

## Features

### Standard C Library Reimplementations (Prefixed with `ft_`)

#### Memory Functions
- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memccpy`
- `ft_memmove`
- `ft_memchr`
- `ft_memcmp`

#### String Functions
- `ft_strlen`
- `ft_strdup`
- `ft_strcpy`
- `ft_strncpy`
- `ft_strcat`
- `ft_strncat`
- `ft_strlcat`
- `ft_strchr`
- `ft_strrchr`
- `ft_strstr`
- `ft_strnstr`
- `ft_strcmp`
- `ft_strncmp`

#### Character Checks and Conversions
- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_toupper`
- `ft_tolower`

#### Miscellaneous
- `ft_atoi`

### Additional Utility Functions

#### Memory Allocation and Deallocation
- `ft_memalloc`
- `ft_memdel`

#### String Manipulation
- `ft_strnew`
- `ft_strdel`
- `ft_strclr`
- `ft_striter`
- `ft_striteri`
- `ft_strmap`
- `ft_strmapi`
- `ft_strequ`
- `ft_strnequ`
- `ft_strsub`
- `ft_strjoin`
- `ft_strtrim`
- `ft_strsplit`

#### Numeric Conversion
- `ft_itoa`

#### Output Functions
- `ft_putchar`
- `ft_putstr`
- `ft_putendl`
- `ft_putnbr`
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

### Bonus: Linked List Functions

Includes utilities to manipulate singly linked lists using the following structure:

```c
typedef struct s_list
{
    void            *content;
    size_t          content_size;
    struct s_list   *next;
} t_list;
```

#### Linked List Operations
- `ft_lstnew`
- `ft_lstdelone`
- `ft_lstdel`
- `ft_lstadd`
- `ft_lstiter`
- `ft_lstmap`

## Compilation and Usage

Clone the repository and build the library using `make`:

```bash
git clone https://github.com/kosyan62/libft.git
cd libft
make
```

This will produce the `libft.a` static library.

### Makefile Targets

| Target   | Description                      |
|----------|----------------------------------|
| `all`    | Compile the library               |
| `clean`  | Remove object files               |
| `fclean` | Remove object files and library   |
| `re`     | Rebuild the library from scratch  |

## Project Guidelines

- Compliant with the 42 School Norm (strict coding standards).
- No use of global variables.
- Allowed standard functions: `malloc`, `free`, and `write`.
- Static helper functions are used where applicable.
- Proper memory management and error handling.

## License

This project is developed as part of the 42 School curriculum and is intended for educational purposes only.