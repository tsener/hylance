# K8s Ingress Controller: Hitch + Balance Hybrid Implementation Plan

## Objective

Create a highly performant Kubernetes ingress controller that:

* Combines SSL/TLS termination capabilities of **Hitch**.
* Utilizes the lightweight, TCP-focused load-balancing of **Balance**.
* Results in a single, statically-compiled binary optimized for high performance.

## Step 1: Feasibility Evaluation

### 1.1 Review Hitch and Balance Source

* Clone and compile both codebases independently.
* Evaluate build dependencies and portability of both projects.
* Confirm possibility for static compilation and single-binary linking.

### 1.2 Assess Integration Potential

* Evaluate the complexity of combining Hitch (SSL/TLS offloading) with Balance (TCP load balancing).
* Check API compatibility and potential communication overhead.
* Identify overlapping functionality (connection handling, threading).

### 1.3 Performance Assessment

* Benchmark both Hitch and Balance independently.
* Identify bottlenecks or inefficiencies that could compound when combined.
* Consider whether a full rewrite or partial rewrite (e.g., critical paths in Rust/C/ASM) would significantly improve performance.

## Step 2: Architecture & Wrapper Design

### 2.1 Single Binary Architecture

* Design wrapper architecture:

  * Initial SSL termination layer (Hitch-derived).
  * Subsequent load balancing layer (Balance-derived).
  * Shared socket/connection handling for performance optimization.

### 2.2 Cross-Communication Layer

* Decide how Hitch will pass connections transparently to Balance.
* Evaluate shared-memory approaches or internal function calls vs. network sockets.

### 2.3 Configuration Interface

* Create a unified YAML-based configuration:

  * SSL certificates configuration.
  * Backend service definition and balancing strategy.
* Ensure integration with standard Kubernetes ingress manifests.

## Step 3: Kubernetes Ingress Integration

### 3.1 Define CRDs and Controllers

* Define Custom Resource Definitions (CRD) to configure SSL termination and load balancing specifics.
* Implement a Kubernetes operator/controller to watch for ingress objects.

### 3.2 Dockerization and Static Binary Compilation

* Create Dockerfile using multi-stage builds for producing a statically linked binary.
* Ensure minimal container footprint for quick deployments.

### 3.3 Helm Chart and Deployment Templates

* Provide Helm chart to simplify Kubernetes deployments and upgrades.
* Ensure proper RBAC, service definitions, and ingress resources.

## Step 4: Source Code Integration and Optimization

### 4.1 Source Code Merge and Refactor

* Merge Hitch and Balance codebases in a maintainable way:

  * Modularize SSL handling, balancing, and networking layers.
* Address redundant functionalities to streamline codebase.

### 4.2 Performance-critical Rewrites

* Identify hotspots through profiling (e.g., eBPF, perf).
* Rewrite critical paths in a performant language (C, Rust, or ASM).
* Iterative benchmarking to validate improvements.

### 4.3 Continuous Integration and Delivery (CI/CD)

* Implement automated build, test, and benchmark CI pipeline.
* Include automated benchmarks to prevent performance regressions.

## Step 5: Documentation & Open-Source Preparation

### 5.1 Comprehensive Documentation

* Document architecture, usage, configuration, performance characteristics.

### 5.2 Contribution Guidelines and Licensing

* Clearly define contribution process.
* Maintain clear license compliance (both Hitch and Balance licensing).

## Deliverables

* Single statically compiled ingress binary.
* Docker image and Helm chart.
* Kubernetes CRDs and controller implementation.
* Comprehensive documentation.
* CI/CD pipeline setup with automated benchmarking.

