# PNGP

A C++20 project for learning algorithms by building a PNG decoder. The goal is
to explore how binary parsing, checksums, compression and image reconstruction
work together in one practical project.

## Progress

- **In place:** binary file I/O, a byte reader, CRC-32 and initial PNG header parsing.
- **Planned:** DEFLATE decoding (Huffman coding and LZ77), scanline filter reversal
  and pixel reconstruction.

Work in progress: the parser is incomplete, and tests currently expose a bug
in big-endian reads.

## Build and test

Requires a C++20 compiler, CMake 3.20+ and Ninja. Google Test is fetched automatically.

```sh
cmake -S . -B build-tests -G Ninja
cmake --build build-tests --target PNGP_tests
ctest --test-dir build-tests --output-on-failure
```
