#ifndef ENVELOPE_H
#define ENVELOPE_H

class Envelope {
    private:
        enum State {
            IDLE,
            ATTACK,
            DECAY,
            SUSTAIN,
            RELEASE
        };
         float attackTime = 10.0;
         float decayTime = 0.2;
         float sustainLevel = 0.2;
         float releaseTime = 0.5;
         State state = State::IDLE;
         float phase = 0.0;
         float phaseIncrement = 0.0;
         float value = 0.0;
    public:
        void setAttackTime(float);
        void setDecayTime(float);
        void setSustainLevel(float);
        void setReleaseTime(float);
        void noteOn();
        float getSample();
};

#endif