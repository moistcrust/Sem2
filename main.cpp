#include "menu.h"


int main() {
    menu Game;
    while (Game.window.isOpen()) {
        Game.eventhandle();
        Game.render();
    }
    return 0;
}
