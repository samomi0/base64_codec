# base64_codec

a base64 encoder/decoder with C++

练习项目，使用了googleTest CMake 以及 Conan

## build (example on MacOS)

~~~sh
mkdir build && cd build
~~~

~~~sh
conan install .. --build=missing -s build_type=Release -s compiler.cppstd=17
~~~

~~~sh
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=build/Release/generators/conan_toolchain.cmake
~~~

~~~sh
make
~~~