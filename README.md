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

## License

MIT
