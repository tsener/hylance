# Step 2 Architecture
This document sketches how Hitch and Balance can be linked into a single binary.

## Layers
1. **TLS termination** via Hitch's SSL library wrappers.
2. **TCP load balancing** reusing Balance's event loop and connection manager.

A Go-based wrapper (`hylance-wrapper`) now reads a YAML configuration at
startup and writes Hitch and Balance config files. It then launches Hitch for
TLS termination and Balance for backend load balancing. Future work may link
the projects into a single binary, but the initial implementation runs both
processes side by side.

## Configuration
A unified YAML file will specify:
- Listener addresses and TLS certificates
- Backend servers and balancing strategy

The controller will translate Kubernetes Ingress objects into this file.
