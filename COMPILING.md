# Lugormod v3

## Dependencies
You will need `i386` build support for 32-bit builds. As an example using `dpkg` for debian based systems:
```
dpkg --add-architecture i386
apt update
```

The required dependencies for building are as follows:
- build-essential
- cmake
- gcc-multilib
- g++-multilib

Using `apt` as an example:
```
apt-get install build-essential cmake gcc-multilib g++-multilib
```

## Compilation

Make a `build` folder located at the root of the project and move to it:
```
mkdir build
cd build
```

Run `CMake` to make build scripts:
```
cmake ../
```

Run `make` to build the project. Specify `-j4` to use 4 cpu-cores and speed up the process.