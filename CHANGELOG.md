# brainf changelog

#### DD/MM/YY

### A few weeks before 04/08/2021
- Initial discovery of brainfuck.
- Initial attempts at creating a interpreter.
- First interpreter is done: you enter one instruction each time, loops aren't supported.
- 2nd version of the interpreter: reads instructions string by string, loops sort of work.
- 1st version of **b2c** - a Brainfuck to C compiler: works better then anything I did until now, but the C code generated isn't efficient at all.
- 3rd version of the interpreter: this time its called **brainf**. it parses the instructions one by one, and has proper loop support.

### 04/08/2021
- Initial commit: the interpreter mostly works but doesn't accept comments (any character other than ><+-.,[]) and because of a memory allocation problem it exits with a 'free(): invalid pointer' and 'Aborted' errors.
- **brainf** is now fully functional: the memory allocation error and a problem with newlines when reading from a file where fixed, and comments where added.
- Command line flags where added (`-h`|`--help` `-p`|`--program`).
- The README is written.
- **b2c** is integrated (it still generates very inefficient C code).
- Building packages with `CPack` is added.
- Tests with `CTest` are added.
- Github actions are added: a build test that runs on every commit and a workflow that builds a amd64 Debian package for every new release.
- Nothing to do with brainf, but the C++ inplementation of a stack is updated to use `new` and `delete` instead of `malloc()` and `free()`.

### 05/08/2021
- Comments now work properly.
- Use `getopt_long` instead of an `if/else if/else` ladder with `strcmp` for argument parsing.
- Released version 1.0!
- Improved Documentation

### 06/08/2021
- Make `struct option long_options[]` global (for no reason other than it makes the code look nicer...).
- Add `--version|-v` command line option.
- Create `examples` folder, move `hello.b` to it, and create `examples/cat.b`.

### 07/08/2021
- Move all run* functions to `src/run.c`.

### 16/08/2021
- Add ability to change memory and stack size during configuration with `cmake`.
- Make version flag print memory and stack sizes.

### 05/09/2021
- Add `TODO` to readme.

### 18/09/2021
- use `argc<2` instead of `!argv[1]` to check if there are no command line arguments.
- [not related] improve C++ implementation of a stack.
- Update this changelog.
- Release version 1.1!
