# Step 4 Integration
Balance is stored in the `tcp` directory. Hitch is provided by the Docker base
image rather than checked into this repository. Common connection handling code
should be extracted into a shared module.

Performance testing will use `perf` and `ab` to measure throughput after each
significant refactor. If profiling reveals heavy cost in the handshake code,
that portion may be rewritten in Rust with FFI bindings.
