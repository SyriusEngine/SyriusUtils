# SyriusUtils
Repository that contains some useful utilities for the Syrius project. Utilities include:
- logger + macros
- Random number generator
- Timer
- Simple memory allocation tracker
- Macros for determining the platform
- Commonly used enums.

# Build
## Dependencies
This repo has no dependencies (except for the build utils submodule). When building the tests, gtest is required but is pulled automatically by CMake.

## Building
When cloning the repository, make sure you enable the submodules by running the following command:
```
git clone --recurse-submodules
```
or by running the following commands:
```
git submodule init
git submodule update
```
Building the project is done by running the following commands:
```
mkdir build
cd build
cmake ..
make
```
Optionally, you can build the tests by adding the following flag to the cmake command:
```
cmake -DBUILD_TESTS=ON ..
```
Note that when building the tests, the address sanitizer is enabled by default. This can be disabled by adding the following flag to the cmake command:
```
cmake -DBUILD_TESTS=ON -DNO_SANITIZER=ON ..
```
