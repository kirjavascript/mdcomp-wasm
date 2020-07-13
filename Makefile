wasm:
	    em++ mdcomp/src/lib/*.cc glue.cc \
	    -Wall \
	    -Imdcomp/include \
	    -Iboost_1_73_0 \
	    -s EXPORTED_FUNCTIONS="['_snkrle_decode', '_snkrle_encode', '_kosinski_encode', '_kosinski_decode', '_nemesis_encode', '_nemesis_decode']" \
	    -s ALLOW_MEMORY_GROWTH=1 \
	    -s DEMANGLE_SUPPORT=1 \
	    -o mdcomp_portable.js
