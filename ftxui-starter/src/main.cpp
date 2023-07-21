#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

#include <iostream>
#include <vector>

using namespace ftxui;
using namespace std;

Component Window(std::string title, Component component) {
  return Renderer(component, [component, title] {  //
    return window(text(title), component->Render()) | flex;
  });
}

int
main(void)
{
    auto left_box = vbox
    (
        {
            window(text("window1"),text("this is window1")),
            window(text("window2"),text("this is window2"))
        }
    );

    auto 
    exit(0);
}