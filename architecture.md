# Step 2 Architecture
This document sketches how Hitch and Balance can be linked into a single binary.

## Layers
1. **TLS termination** via Hitch's SSL library wrappers.
2. **TCP load balancing** reusing Balance's event loop and connection manager.

A wrapper binary will initialize Hitch, accept connections, decrypt TLS, then
pass the plain TCP streams into Balance's balancer functions. This avoids extra
socket hops.

## Configuration
A unified YAML file will specify:
- Listener addresses and TLS certificates
- Backend servers and balancing strategy

The controller will translate Kubernetes Ingress objects into this file.
