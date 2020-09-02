# '_saxman_decode', '_saxman_encode',

define EXPORTED
[\
    '_artc42_decode', '_artc42_encode',\
    '_comper_decode', '_comper_encode',\
    '_kosinski_decode', '_kosinski_encode',\
    '_moduled_kosinski_decode', '_moduled_kosinski_encode',\
    '_kosplus_decode', '_kosplus_encode',\
    '_enigma_decode', '_enigma_encode',\
    '_lzkn1_decode', '_lzkn1_encode',\
    '_nemesis_decode', '_nemesis_encode',\
    '_rocket_decode', '_rocket_encode',\
    '_saxman_decode', '_saxman_encode',\
    '_snkrle_decode', '_snkrle_encode'\
]
endef

wasm:
	    em++ mdcomp/src/lib/*.cc glue.cc \
	    -O3 \
	    -Wall \
	    -Imdcomp/include \
	    -Iboost_1_73_0 \
	    -s EXPORTED_FUNCTIONS="$(EXPORTED)" \
	    -s ALLOW_MEMORY_GROWTH=1 \
	    -s DEMANGLE_SUPPORT=1 \
	    -o mdcomp_portable.js
