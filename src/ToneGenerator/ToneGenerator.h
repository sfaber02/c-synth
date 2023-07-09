#include <tuple>
#include "../Oscillator/Oscillator.h"

class ToneGenerator {
    public:
        std::tuple<int*, int> generateTone(double, double, int, Oscillator);
};
