#!/bin/sh
set -e
VER=4.33
URL="https://github.com/enki/libev/archive/refs/tags/v$VER.tar.gz"
if [ ! -f libev-$VER.tar.gz ]; then
  echo "Downloading libev $VER..."
  curl -L "$URL" -o libev-$VER.tar.gz
fi
if [ ! -d libev-$VER ]; then
  tar -xzf libev-$VER.tar.gz
fi
cd libev-$VER
./autogen.sh || true
./configure --disable-shared --enable-static CFLAGS="-fPIC"
make
cd ..
cp libev-$VER/.libs/libev.a .
