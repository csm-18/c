c (v0.0.1)

A build tool for c (like cargo for rust).

(for linux!)

## Status

### Working commands:

version - prints this tools version.

init - creates a new c project in current directory.

run - builds and runs the project (cli args to the output binary, are currently not supported!).

## Generated project structure by init command

### Suppose your project folder is 'hello':

![project-structure](./init-command-generated-project-structure-v0.0.1.png)

Here:

1. src folder - for all c src files (you can nest them in sub-folders).
2. include folder - for all header files.
3. build folder - where the output binary will go.
4. .gitignore - for excluding the build folder from git history.
