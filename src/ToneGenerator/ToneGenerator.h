#include <tuple>
#include "../Oscillator/Oscillator.h"

class ToneGenerator {
    public:
        std::tuple<float*, int> generateTone(double, double, int, Oscillator);
};
