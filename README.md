# WASM version of flamewing's mdcomp

Portable version of mdcomp for use in various languages

Bindings for javascript are provided

# How to compile

Install emscripten sdk: https://emscripten.org/docs/getting_started/downloads.html
Get boost: https://www.boost.org/users/download/

```
git clone git@github.com:flamewing/mdcomp.git
make wasm
```

headers
O3

em++ mdcomp/src/lib/*.cc -s WASM=1 -Iinclude

em++  -Wall  -O3  -I boost/  -std=c++11  -s NO_EXIT_RUNTIME=1  -s DEMANGLE_SUPPORT=1 -s ALLOW_MEMORY_GROWTH=1  -s EXPORTED_FUNCTIONS="['_cmd','_main']"  src/*.cpp  -o build/harcs.js
