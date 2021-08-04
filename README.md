# brainf
A [brainfuck](https://esolangs.org/wiki/Brainfuck) interpreter written in C.

**NOTE:** included in this repo is also a C++ implementation of a stack, but it isn't used anywhere in `brainf`.

## features
- Understands both strings of instructions and single ones, no need for a separator!
- Can read instructions from a file.

## Compiling
```
git clone https://github.com/Itai-Nelken/brainf.git
cd brainf
mkdir build
cd build
cmake ..
make
```

## TODO
- [ ] integrate **`b2c`**


# b2c
Brainfuck to C compiler
# Compiling
same as **`brainf`**
**running:** `./b2c <in.b> <out.c>`

# brainfuck tutorial
- https://gist.github.com/roachhd/dce54bec8ba55fb17d3a
