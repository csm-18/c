c (v0.0.1)

A build tool for c (like cargo for rust).

(for linux!)

## Status

### Working commands:

version - prints this tools version.

init - creates a new c project in current directory.

run - builds and runs the project (cli args to the output binary, are currently not supported!).

## Dependencies

- os: linux

- compiler: gcc

## Building the project

I assume you know how to compile a single c file(src/main.c) into output file called c.

If not then you can just google it or gpt it!

After that, just place the output binary where you like and add it to the PATH environment variable.

## Generated project structure by init command

### Suppose your project folder is 'hello':

![project-structure](./init-command-generated-project-structure-v0.0.1.png)

Here:

1. src folder - for all c src files (you can nest them in sub-folders).
2. include folder - for all header files.
3. build folder - where the output binary will go.
4. .gitignore - for excluding the build folder from git history.

## License

MIT
