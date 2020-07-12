#include <mdcomp/snkrle.hh>

#include <istream>
#include <ostream>
/* #include <sstream> */

using std::istream;
using std::ostream;

extern "C" {
    void snkrle_decode(void *Src, void *Dst) {
        snkrle::decode((istream&)Src, (ostream&)Dst);
    }

    void snkrle_encode(void *Dst, void *Src) {
        snkrle::encode((istream&)Dst, (ostream&)Src);
    }
}
