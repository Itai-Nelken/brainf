# brainf
A [brainfuck](https://esolangs.org/wiki/Brainfuck) interpreter written in C.

**NOTE:** included in this repo is also a C++ implementation of a stack, but it isn't used anywhere in `brainf`.

## features
- Understands both strings of instructions and single ones, no need for a separator!
- Can read instructions from a file.
- can compile brainfuck code into C code

## Compiling
```
git clone https://github.com/Itai-Nelken/brainf.git
cd brainf
mkdir build
cd build
cmake ..
make
```
### Installing
In the `build` folder run `sudo make install`
### Uninstalling
In the build folder run `sudo make uninstall`

## TODO
- [x] integrate **`b2c`**

# brainfuck tutorial
- https://gist.github.com/roachhd/dce54bec8ba55fb17d3a
