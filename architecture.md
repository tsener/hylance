# Step 2 Architecture
This document sketches how Hitch and Balance can be linked into a single binary.

## Layers
1. **TLS termination** via Hitch's SSL library wrappers.
2. **TCP load balancing** reusing Balance's event loop and connection manager.

A small Python service now reads a YAML configuration at startup and exposes
the Hitch and Balance sections over HTTP as JSON. Future work may still link
the projects into a single binary, but the current implementation focuses on
serving configuration data rather than managing processes.

## Configuration
A unified YAML file will specify:
- Listener addresses and TLS certificates
- Backend servers and balancing strategy

The controller will translate Kubernetes Ingress objects into this file.
