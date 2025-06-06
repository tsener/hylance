#!/bin/sh
# Simple entrypoint launching Balance then Hitch
set -e

if [ -f /etc/hylance/balance.conf ]; then
    /usr/local/bin/balance /etc/hylance/balance.conf &
fi

exec hitch "$@"
