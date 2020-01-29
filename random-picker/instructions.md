# Instructions

This Program is used for picking something you cant decide on.
With this Program you can pick elements of a list with cryptographic security.
Speical thanks to the Libsodium developers.

## Prerequisites

- cmake
- clang or gcc
- unpacking software (for tar.gz files)
[libsodium](https://libsodium.org) is also required.

optional:
- wget (makes it easier to download stuff)

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

