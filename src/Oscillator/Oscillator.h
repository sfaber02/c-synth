class Oscillator {
    private:
        double phase;
        double phaseIncrement;
        WAVEFORM waveform;
    
        double frequencyToPhaseIncrement(int);

    public:
        Oscillator(int, WAVEFORM);
        double getSample();

};