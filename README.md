# hylance

Hylance is a lightweight ingress controller that combines the Hitch TLS proxy with the Balance TCP load balancer. A small Python service exposes configuration data over HTTP and is intended to be driven by a Kubernetes controller written in Go.

Extensive usage instructions are available in [documentation.md](documentation.md).

## Building Balance

Balance lives in the `tcp` directory and can be compiled with:

```sh
make -C tcp
```

## Docker Image

The provided `Dockerfile` builds on top of the official [`hitch`](https://hub.docker.com/_/hitch) image. Balance is compiled in a separate build stage and copied into the final container. Build the image locally with:

```sh
docker build -t hylance:latest .
```

Run the container and mount a configuration file:

```sh
docker run \
  -v $PWD/example-config.yaml:/etc/hylance/hylance.yaml \
  -p 8080:8080 hylance:latest
```

The service exposes two read-only endpoints:

- `GET /config/hitch` – returns the Hitch configuration in JSON.
- `GET /config/balance` – returns the Balance configuration in JSON.

A sample configuration is provided in `example-config.yaml`.

