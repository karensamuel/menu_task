#include <iostream>
#include "TerminalUi.h"

#ifdef _WIN32
    #include <windows.h>
#endif

namespace TerminalUI {

    bool initialize() {

#ifdef _WIN32

        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

        if (hOut == INVALID_HANDLE_VALUE)
            return false;

        DWORD dwMode = 0;

        if (!GetConsoleMode(hOut, &dwMode))
            return false;

        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

        if (!SetConsoleMode(hOut, dwMode))
            return false;

#endif

        return true;
    }

    void setCursorPosition(int x, int y) {
        std::cout << "\033[" << y << ";" << x << "H"<< std::flush;
    }
    void hideCurser(){
        std::cout << "\033[?25l" << std::flush;
    }

    void setColor(Color color) {
        std::cout << "\033[" << static_cast<int>(color) << "m";
    }

    void resetColor() {
        std::cout << "\033[0m"<< std::flush;

    }
 void resetScreen() {
            std::cout << "\033[2J\033[H" << std::flush;

    }
    void drawText(const std::string& text, int x, int y, Color color) {
        setCursorPosition(x, y);
        setColor(color);
        std::cout << text;
        resetColor();
           std::cout << std::flush;
    }

}