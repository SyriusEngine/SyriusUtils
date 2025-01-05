# SyriusUtils
Repository that contains some useful utilities for the Syrius project. 

# Build
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