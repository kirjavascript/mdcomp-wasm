#include <mdcomp/snkrle.hh>
#include <mdcomp/kosinski.hh>
#include <mdcomp/nemesis.hh>

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

    bool nemesis_decode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::iostream &os) { return nemesis::decode(is, os); });
    }

    bool nemesis_encode(char *input, size_t input_size, char **output, size_t *output_size) {
        return perform(input, input_size, output, output_size, [] (std::istream &is, std::ostream &os) { return nemesis::encode(is, os); });
    }
}
