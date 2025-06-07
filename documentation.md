# Usage Guide

This document explains how to build and run the Hylance service as well as how to configure it.

## 1. Building

Balance is included in the `tcp` directory. Compile it by running:

```sh
make -C tcp
```

The Docker image builds Balance automatically, so compiling manually is only required for local testing.

## 2. Configuration File

Hylance expects a YAML configuration file with two sections:

```yaml
hitch:
  frontend: "[0.0.0.0]:443"
  backend: "127.0.0.1:8080"
  pemFile: "/etc/hitch/certs/default"
  clientCA: "/etc/hitch/ca/ca.pem"

balance:
  listen: "0.0.0.0 8080"
  backends:
    - "10.0.0.1:80"
    - "10.0.0.2:80"
```

* `hitch` defines the TLS listener and certificates.
* `balance` lists the TCP backends to load balance across.

Save this file and mount it into the container at `/etc/hylance/hylance.yaml`.

## 3. Running With Docker

Build and start the container:

```sh
docker build -t hylance:latest .
docker run -p 8080:8080 \
  -v $PWD/example-config.yaml:/etc/hylance/hylance.yaml \
  hylance:latest
```

The Python service listens on port `8080` and serves the configuration.

## 4. HTTP Endpoints

- `GET /config/hitch` returns the Hitch section as JSON.
- `GET /config/balance` returns the Balance section as JSON.

These endpoints can be queried from inside the cluster to configure Hitch and Balance or for debugging purposes.

## 5. Kubernetes Controller

A stub controller is located in `cmd/controller`. When completed it will watch for Ingress resources and write the YAML file consumed by the service. The controller can be built with:

```sh
go build ./cmd/controller
```

## 6. Development Tips

- `go test ./...` runs the Go unit tests.
- `pytest` runs the Python tests (skipped if dependencies are missing).
- The `.github/workflows/build.yml` file shows the commands used in CI.
