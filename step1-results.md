# Step 1 Evaluation
## Build Verification

- `make -C tcp` built the **Balance** source successfully.
- `./configure` for **Hitch** failed due to missing dependencies (`libev`).

## Findings

- Balance is small and compiles without external dependencies.
- Hitch requires additional libraries which complicates static compilation.


Since `libev` was not present on the system, a vendored copy is now managed
under `vendor/libev`. The helper scripts there build a static library so Hitch
can be linked without external dependencies. On restricted networks the
`download.sh` script may fail with a 403 error. Running the GitHub Actions
workflow will fetch the sources and complete the static build.
