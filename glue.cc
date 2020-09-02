#include <mdcomp/artc42.hh>
#include <mdcomp/comper.hh>
#include <mdcomp/kosinski.hh>
#include <mdcomp/kosplus.hh>
#include <mdcomp/enigma.hh>
#include <mdcomp/lzkn1.hh>
#include <mdcomp/nemesis.hh>
#include <mdcomp/rocket.hh>
#include <mdcomp/saxman.hh>
#include <mdcomp/snkrle.hh>

#include <sstream>

template <typename Operation>
static bool perform(char *input, size_t input_size, char **output, size_t *output_size, Operation operation) {
    std::istringstream input_stream(std::string(input, input_size));
    std::stringstream output_stream;
    if (operation(input_stream, output_stream)) {
        std::string output_string(output_stream.str());
        *output_size = output_string.size();
        *output = static_cast<char *>(malloc(*output_size));
        memcpy(*output, output_string.data(), *output_size);
        return true;
    }

    return false;
}

extern "C" {
    bool snkrle_decode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::iostream &os) { return snkrle::decode(is, os); });
    }

    bool snkrle_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::ostream &os) { return snkrle::encode(is, os); });
    }

    bool kosinski_decode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::iostream &os) { return kosinski::decode(is, os); });
    }

    bool kosinski_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::ostream &os) { return kosinski::encode(is, os); });
    }

    bool moduled_kosinski_decode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::iostream &os) { return kosinski::moduled_decode(is, os); });
    }

    bool moduled_kosinski_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::ostream &os) { return kosinski::moduled_encode(is, os); });
    }

    bool nemesis_decode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::iostream &os) { return nemesis::decode(is, os); });
    }

    bool nemesis_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::ostream &os) { return nemesis::encode(is, os); });
    }

    bool artc42_decode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::iostream &os) { return artc42::decode(is, os); });
    }

    bool artc42_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::ostream &os) { return artc42::encode(is, os); });
    }

    bool saxman_decode(char *input, size_t input_size, char **output, size_t *output_size, size_t compressed_size) {
        return perform(input, input_size, output, output_size, [compressed_size] (std::istream &is, std::iostream &os) { return saxman::decode(is, os, compressed_size); });
    }

    bool saxman_encode(char *input, size_t input_size, char **output, size_t *output_size, bool with_size) {
        return perform(input, input_size, output, output_size, [with_size] (std::istream &is, std::ostream &os) { return saxman::encode(is, os, with_size); });
    }

    bool comper_decode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::iostream &os) { return comper::decode(is, os); });
    }

    bool comper_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::ostream &os) { return comper::encode(is, os); });
    }

    bool kosplus_decode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::iostream &os) { return kosplus::decode(is, os); });
    }

    bool kosplus_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::ostream &os) { return kosplus::encode(is, os); });
    }

    bool enigma_decode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::iostream &os) { return enigma::decode(is, os); });
    }

    bool enigma_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::ostream &os) { return enigma::encode(is, os); });
    }

    bool lzkn1_decode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::iostream &os) { return lzkn1::decode(is, os); });
    }

    bool lzkn1_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::ostream &os) { return lzkn1::encode(is, os); });
    }

    bool rocket_decode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::iostream &os) { return rocket::decode(is, os); });
    }

    bool rocket_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::ostream &os) { return rocket::encode(is, os); });
    }
}
