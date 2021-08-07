# avifmin

Attempt at minifying AVIF files. Very early work in progress.

## Usage

Prerequisites: make and clang.

Run `make` to compile avifmin, then run `./avifmin`.

## Development

Other Make targets are available:

- `clean`: deletes the compiled binary and all object files
- `scan-build`: recompiles avifmin while running the [scan-build](https://clang-analyzer.llvm.org/scan-build.html) static analyzer
- `format`: runs clang-format on all source files

Eventually I will add a git hook to run `make format` before committing.
