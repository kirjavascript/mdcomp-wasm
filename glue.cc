#include <mdcomp/artc42.hh>
#include <mdcomp/comper.hh>
#include <mdcomp/comperx.hh>
#include <mdcomp/kosinski.hh>
#include <mdcomp/kosplus.hh>
#include <mdcomp/enigma.hh>
#include <mdcomp/lzkn1.hh>
#include <mdcomp/nemesis.hh>
#include <mdcomp/rocket.hh>
#include <mdcomp/saxman.hh>
#include <mdcomp/snkrle.hh>

#include <limits>
#include <sstream>

// how many input bytes the operation read. A decoder handed the wrong format
// stops well short of the end or runs past it; eofbit is cleared first because
// reading the last byte of a valid stream sets it
static size_t bytes_consumed(std::istringstream &input_stream) {
    if (input_stream.eof()) {
        input_stream.clear();
    }

    auto const position = input_stream.tellg();
    return position < 0 ? std::numeric_limits<size_t>::max() : static_cast<size_t>(position);
}

template <typename Operation>
static bool perform(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed, Operation operation) {
    try {
        std::istringstream input_stream(std::string(input, input_size));
        std::stringstream output_stream;
        if (operation(input_stream, output_stream)) {
            std::string output_string(output_stream.str());
            *output_size = output_string.size();
            *output = static_cast<char *>(malloc(*output_size));
            memcpy(*output, output_string.data(), *output_size);
            if (consumed != nullptr) {
                *consumed = bytes_consumed(input_stream);
            }
            return true;
        }
    } catch (...) {
        // mdcomp throws on malformed input; without this the runtime aborts
    }

    return false;
}

extern "C" {
    bool snkrle_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [] (std::istream &is, std::iostream &os) { return snkrle::decode(is, os); });
    }

    bool snkrle_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, nullptr, [] (std::istream &is, std::ostream &os) { return snkrle::encode(is, os); });
    }

    bool kosinski_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [] (std::istream &is, std::iostream &os) { return kosinski::decode(is, os); });
    }

    bool kosinski_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, nullptr, [] (std::istream &is, std::ostream &os) { return kosinski::encode(is, os); });
    }

    bool moduled_kosinski_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [] (std::istream &is, std::iostream &os) { return kosinski::moduled_decode(is, os); });
    }

    bool moduled_kosinski_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, nullptr, [] (std::istream &is, std::ostream &os) { return kosinski::moduled_encode(is, os); });
    }

    bool nemesis_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [] (std::istream &is, std::iostream &os) { return nemesis::decode(is, os); });
    }

    bool nemesis_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, nullptr, [] (std::istream &is, std::ostream &os) { return nemesis::encode(is, os); });
    }

    bool artc42_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [] (std::istream &is, std::iostream &os) { return artc42::decode(is, os); });
    }

    bool artc42_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, nullptr, [] (std::istream &is, std::ostream &os) { return artc42::encode(is, os); });
    }

    bool saxman_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t compressed_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [compressed_size] (std::istream &is, std::iostream &os) { return saxman::decode(is, os, compressed_size); });
    }

    bool saxman_encode(char *input, size_t input_size, char **output, size_t *output_size, bool with_size) {
        return perform(input, input_size, output, output_size, nullptr, [with_size] (std::istream &is, std::ostream &os) { return saxman::encode(is, os, with_size); });
    }

    bool comper_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [] (std::istream &is, std::iostream &os) { return comper::decode(is, os); });
    }

    bool comper_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, nullptr, [] (std::istream &is, std::ostream &os) { return comper::encode(is, os); });
    }

    bool kosplus_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [] (std::istream &is, std::iostream &os) { return kosplus::decode(is, os); });
    }

    bool kosplus_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, nullptr, [] (std::istream &is, std::ostream &os) { return kosplus::encode(is, os); });
    }

    bool moduled_kosplus_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [] (std::istream &is, std::iostream &os) { return kosplus::moduled_decode(is, os); });
    }

    bool moduled_kosplus_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, nullptr, [] (std::istream &is, std::ostream &os) { return kosplus::moduled_encode(is, os); });
    }

    bool enigma_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [] (std::istream &is, std::iostream &os) { return enigma::decode(is, os); });
    }

    bool enigma_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, nullptr, [] (std::istream &is, std::ostream &os) { return enigma::encode(is, os); });
    }

    bool lzkn1_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [] (std::istream &is, std::iostream &os) { return lzkn1::decode(is, os); });
    }

    bool lzkn1_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, nullptr, [] (std::istream &is, std::ostream &os) { return lzkn1::encode(is, os); });
    }

    bool rocket_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [] (std::istream &is, std::iostream &os) { return rocket::decode(is, os); });
    }

    bool comperx_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [] (std::istream &is, std::iostream &os) { return comperx::decode(is, os); });
    }

    bool comperx_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, nullptr, [] (std::istream &is, std::ostream &os) { return comperx::encode(is, os); });
    }

    bool moduled_comperx_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t *consumed) {
        return perform(input, input_size, output, output_size, consumed, [] (std::istream &is, std::iostream &os) { return comperx::moduled_decode(is, os); });
    }

    bool moduled_comperx_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, nullptr, [] (std::istream &is, std::ostream &os) { return comperx::moduled_encode(is, os); });
    }

    bool rocket_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, nullptr, [] (std::istream &is, std::ostream &os) { return rocket::encode(is, os); });
    }
}
