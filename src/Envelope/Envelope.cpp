#include "./Envelope.h"
#include "../globals.cpp"
#include <iostream>

void Envelope::setAttackTime(float attackTime) {}
void Envelope::setDecayTime(float releaseTime) {}
void Envelope::setSustainLevel(float sustainLevel) {}
void Envelope::setReleaseTime(float releaseTime) {}
void Envelope::noteOn() {
    phaseIncrement = 1.0 / (attackTime * SAMPLE_RATE);
    state = State::ATTACK;
}
float Envelope::getSample() {
    switch (state) {
        case IDLE:
            value = 0.0;
            break;
        case ATTACK:
             value += phaseIncrement;
            if (value >= 1.0) {
                phaseIncrement = -((1 - sustainLevel) * phaseIncrement) / (decayTime * SAMPLE_RATE);
                state = State::DECAY;
                value = 1.0;
            }
            break;
        case DECAY:
            break;
        case SUSTAIN:
            break;
        case RELEASE:
            break;
        default:
            break;
    }
    return value;
}