#include "ftxui/component/component.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/component/screen_interactive.hpp"

using namespace ftxui;
using namespace std;

int
main(void)
{
    int value = 233;
    Component button = Button("+1",[&]{value++;});
    Component result = Renderer(button, [&]{
        return vbox({
            text(to_string(value)),
            separator(),
            button->Render()
        });
    });
    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(result);
    return 0;
}