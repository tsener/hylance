# hylance
Kubernetes  ingress controller for fast IoT SSL termination with  mTLS support

This repository also contains `plan.md`, which outlines a hybrid ingress controller
built from the Hitch TLS proxy and the Balance TCP load balancer. The plan
covers steps for feasibility evaluation, architecture, Kubernetes integration,
and deployment.

## Progress

- `step1-results.md` describes current build attempts for Hitch and Balance.
- `architecture.md` outlines the proposed single-binary design.
- `k8s-integration.md` shows the planned CRD and controller approach.
- `integration.md` covers merging the sources and performance considerations.
- `documentation.md` notes contribution guidelines and licensing.

## Building
Balance lives in the `tcp` directory and can be compiled with:

```sh
make -C tcp
```

Hitch is no longer built from source in this repository. The Docker image uses
the official [`hitch`](https://hub.docker.com/_/hitch) container as its base.


## Docker Image

The project provides a `Dockerfile` that builds on top of the official
[`hitch`](https://hub.docker.com/_/hitch) image. Balance is compiled in a
separate build stage and copied into the final container. Use the following
command to build the combined image locally:

```sh
docker build -t hylance:latest .
```

The image entrypoint invokes the `hylance-wrapper` binary. The wrapper reads a
YAML configuration (default `/etc/hylance/hylance.yaml`), writes Hitch and
Balance configuration files, then launches both processes. Balance is started
only when backends are specified.
An example configuration is provided in `example-config.yaml`.

