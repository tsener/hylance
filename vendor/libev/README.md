This directory holds a vendored copy of **libev** so Hitch can be built
statically. Run `./download.sh` to fetch the source code and build a static
library. If the script reports a `403 CONNECT` tunnel error your environment is
blocking outbound HTTP requests. The GitHub Actions build workflow performs the
same steps on GitHub infrastructure where network access is available.
