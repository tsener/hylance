# Step 4 Integration
The Hitch and Balance sources will be placed in `tls` and `tcp` directories.
Common connection handling code should be extracted into a shared module.

Performance testing will use `perf` and `ab` to measure throughput after each
significant refactor. If profiling reveals heavy cost in the handshake code,
that portion may be rewritten in Rust with FFI bindings.
