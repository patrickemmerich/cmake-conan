# Simple example on howto use CMake and Conan

## Prerequisites:

1. Install C++ build tool [cmake](https://cmake.org/)
2. Install C++ package manager [Conan](https://docs.conan.io/en/latest/installation.html)

## Getting started with Conan

1. Check that you have access to a conan remote

   ```bash
   conan remote list
   ```

2. To check that a package, e.g. Poco, is available on the conan remote

   ```bash
   conan search Poco/* -r=conan-center
   ```

## Build and run this project

This follows more or less [Conan: Getting started](https://docs.conan.io/en/latest/getting_started.html)

1. Clone this repo and cd into.

2. Create and cd into build directory

   ```bash
   mkdir build && cd build
   ```

3. Let Conan install dependencies

   ```bash
   conan install .. -s compiler.libcxx=libstdc++11
   ```

   Conan will either downloads pre-built binaries for your platform (if available) or build them from source.

4. Build using cmake

   ```bash
   cmake ..
   cmake --build .
   ```

5. Run

   ```bash
   ./bin/main
   ```