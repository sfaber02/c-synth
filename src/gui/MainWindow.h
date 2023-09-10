#include <juce_core/juce_core.h>
#include <juce_gui_basics/juce_gui_basics.h>


class MainWindow    : public juce::DocumentWindow
{
public:
    explicit MainWindow (juce::String name) : DocumentWindow (name,
                            juce::Desktop::getInstance().getDefaultLookAndFeel()
                                                        .findColour (ResizableWindow::backgroundColourId),
                            DocumentWindow::allButtons)
    {
        setUsingNativeTitleBar (true);
        setContentOwned (new MainComponent(), true);

        #if JUCE_IOS || JUCE_ANDROID
        setFullScreen (true);
        #else
        setResizable (true, true);
        centreWithSize (getWidth(), getHeight());
        #endif

        setVisible (true);
    }

    void closeButtonPressed() override;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
};