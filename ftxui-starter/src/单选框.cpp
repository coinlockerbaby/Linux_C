#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include <vector>
using namespace ftxui;
using namespace std;

int
main(void)
{
    vector<string> options = {
        "红色",
        "绿色",
        "黄色"
    };
    int selected = 0;
    auto radiobox = Radiobox(&options, &selected);
    auto title = text("选择一个颜色");
    auto layout = Renderer(
        radiobox,
        [&]{
            return vbox(
                title,
                separator(),
                radiobox->Render()
            )|border;
        }
    );    
    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(layout);
    exit(0);
}