# Step 3 Kubernetes Integration
The project will define a simple Custom Resource Definition (CRD) named `HylanceIngress`.
It maps to a YAML config consumed by the wrapper binary.

A controller written in Go will watch for standard `Ingress` objects and
produce `HylanceIngress` resources. An initial stub of this controller lives in
`cmd/controller`. The controller will write the unified YAML file into the pod
running the wrapper.

Helm charts will provide templates for deploying the controller and the binary
with RBAC rules and Service definitions.
