# Step 1 Evaluation
## Build Verification

- `make -C tcp` built the **Balance** source successfully.
- `./configure` for **Hitch** failed due to missing dependencies (`libev`).

## Findings

- Balance is small and compiles without external dependencies.
- Hitch requires additional libraries which complicates static compilation.


The initial attempt to build Hitch showed that `libev` was missing.  A
workflow on GitHub installs the required dependencies so the build succeeds even
if local environments lack network access.
