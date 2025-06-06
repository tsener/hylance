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

## Static Hitch Build
The `vendor/libev` directory contains a helper script to fetch and build a static
`libev` suitable for linking Hitch statically. Run:

```sh
(cd vendor/libev && ./download.sh)
(cd tls && ./static-build.sh)
```

This will produce a static `hitch` binary using the local libev.  If the
download step fails with a `403 CONNECT` error it means the environment has no
outbound network access.  In that case the included GitHub Actions workflow
(`.github/workflows/build.yml`) can be used to run the build on GitHub's
infrastructure where the download succeeds.

The workflow compiles Balance, fetches libev, and builds Hitch statically so
pull requests are automatically verified.

