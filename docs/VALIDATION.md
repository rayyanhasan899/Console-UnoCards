# Validation and limitations

## Observed locally — 6 November 2026

- CMake configure/build succeeded on Windows with MSVC 19.50.35730 and C++17.
- CTest: 1/1 executable passed (`structures_test`), covering stack order, exhaustion, invalid hand access and hand insertion/removal.
- Windows Application Control initially prevented the test executable from launching. A later normal build/test run succeeded; no security setting was changed.
- Compiler warnings remain. A complete interactive match, all special-card combinations, EOF at every menu, and long-session memory handling were not exhaustively tested.

Run: `cmake -S . -B build`, `cmake --build build --config Debug`, then `ctest --test-dir build -C Debug --output-on-failure`.

The finite deck now reports exhaustion instead of indexing outside its storage. Invalid card positions are rejected. Discard recycling and new rule variants are not added.
