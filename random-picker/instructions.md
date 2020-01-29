# Instructions for random-gen.c

This Program is used for picking something you cant decide on.
With this Program you can pick elements of a list with cryptographic security.
Thanks to the Libsodium developers.

## Prerequisites

You need to have the Clang C Compiler, in case you dont, you cant change the Compiler in the `CMakeLists.txt` file. 
[libsodium](https://libsodium.org) is also required.

## Set up 

```bash
wget -O libsodium-1.0.18.tar.gz https://download.libsodium.org/libsodium/releases/libsodium-1.0.18.tar.gz
tar xfz libsodium-1.0.18.tar.gz
cd libsodium-1.0.18
./configure
make && make check
sudo make install
```

So now there is a working libsodium library on your system

## Build

```bash
mkdir bin; cd bin
cmake ..
make
cp ../list.txt .
```

And finally you can edit the list and execute the program with:
```bash
./random-picker
```

