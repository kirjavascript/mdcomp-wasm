# mdcomp-wasm - Sega MegaDrive compressors for WebAssembly

WASM build of [mdcomp](https://github.com/flamewing/mdcomp) by flamewing, using code from [kensc-js](https://github.com/FraGag/kensc-js) by FraGag

This is a portable version of the library for use in various languages

Bindings for javascript are provided

# generate

Install emscripten sdk: <https://emscripten.org/docs/getting_started/downloads.html>  
Get boost: <https://www.boost.org/users/download/>  
Clone mdcomp: `git@github.com:flamewing/mdcomp.git`

then

```
make wasm
```
