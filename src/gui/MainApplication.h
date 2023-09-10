#include <juce_core/juce_core.h>
#include <juce_gui_basics/juce_gui_basics.h>


using namespace juce;

class mainApp : public juce::JUCEApplication {
    public:
        mainApp() {}

        const juce::String getApplicationName() override;       
        const juce::String getApplicationVersion() override;   
        bool moreThanOneInstanceAllowed() override;       

        void initialise (const juce::String& commandLine) override;

        void shutdown() override;
        void systemRequestedQuit() override;
        void anotherInstanceStarted (const juce::String& commandLine) override;
    private:
        std::unique_ptr<MainWindow> mainWindow;
}