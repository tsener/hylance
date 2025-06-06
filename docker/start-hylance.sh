#!/bin/sh
# Entrypoint launching the hylance wrapper which spawns Balance and Hitch
set -e

exec /usr/local/bin/hylance-wrapper "$@"

