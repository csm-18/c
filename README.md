# c

c compiler and build tool in rust for linux.

## Status

Nothing currently!

(Just got started on preprocessor)

## Project Structure

This repo is a rust workspace.
It has three binary packages in src directory:

1. c - the driver program that invokes other tools (like clang or gcc)
2. cpp - c preprocessor
3. cc - c compiler

---

- **musl-build** directory contains musl libc which is used by the c compiler.

## License

This project is under MIT license.

But, this project uses musl libc library as dependency, which has its own license.
