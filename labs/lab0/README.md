
```
mkdir build 
cd build
conan profile new default --detect
conan profile update settings.compiler.libcxx=libstdc++11 default
conan install ../ --build
cmake ../
make
./build/bin/lab0
./build/bin/accumulator_test
```