# Step 1 Evaluation
## Build Verification

- `make -C tcp` built the **Balance** source successfully.
- Hitch is no longer compiled from source in this repository. Earlier attempts failed because `libev` was missing.

## Findings

- Balance is small and compiles without external dependencies.
- Hitch requires additional libraries which complicates static compilation, so we rely on the prebuilt Docker image instead.


The initial attempt to build Hitch showed that `libev` was missing. The project now uses the official Hitch Docker image in the CI workflow.
