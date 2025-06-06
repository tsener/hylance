#!/bin/sh
# Build Hitch with static libev from ../vendor/libev
set -e
EV_DIR="../vendor/libev"
if [ ! -f "$EV_DIR/libev.a" ]; then
  echo "libev.a not found; run $EV_DIR/download.sh first" >&2
  exit 1
fi
CFLAGS="-static" LDFLAGS="$EV_DIR/libev.a" ./configure --disable-shared --enable-static
make clean
make
