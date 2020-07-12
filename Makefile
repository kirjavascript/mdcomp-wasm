wasm:
	    em++ mdcomp/src/lib/*.cc glue.cc \
	    -Imdcomp/include \
	    -Iboost_1_73_0 \
	    -s EXPORTED_FUNCTIONS="['_snkrle_decode', '_snkrle_encode']" \
	    -s DEMANGLE_SUPPORT=1 \
	    -o mdcomp_portable.html
