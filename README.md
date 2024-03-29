# NOTE: this project is superseded by [Brainf2](https://github.com/Itai-Nelken/Brainf2) and so isn't maintained anymore.

# brainf
[![Build](https://github.com/Itai-Nelken/brainf/actions/workflows/build.yml/badge.svg)](https://github.com/Itai-Nelken/brainf/actions/workflows/build.yml)
[![Release](https://img.shields.io/github/v/release/Itai-Nelken/brainf?include_prereleases)](https://github.com/Itai-Nelken/brainf/releases/latest)<br>
A [brainfuck](https://esolangs.org/wiki/Brainfuck) interpreter written in C.

**NOTE:** included in this repo is also a C++ implementation of a stack, but it isn't used anywhere in `brainf`.

## features
- Understands both strings of instructions and single ones, no need for a separator!
- Can read instructions from a file.
- can compile brainfuck code into C code

## Installation
If you are using Debian and derivatives, you can download Debian packages for amd64 and arm64 in the [latest release](https://github.com/Itai-Nelken/brainf/releases/latest).<br>
Otherwise compile manually (its not hard!).

## Compiling
```
git clone https://github.com/Itai-Nelken/brainf.git
cd brainf
mkdir build
cd build
cmake ..
make
```
#### Installing
In the `build` folder run `sudo make install`

#### Uninstalling
In the build folder run `sudo make uninstall`

# brainfuck tutorial
- https://gist.github.com/roachhd/dce54bec8ba55fb17d3a

### TODO
- [ ] dynamic memory size.
- [ ] dynamic stack size.
