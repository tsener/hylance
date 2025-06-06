#!/bin/sh
# Entrypoint launching the hylance service
set -e

exec python3 /usr/local/bin/hylance-service.py "$@"
