#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <unordered_map>
#include <SDL2/SDL.h>

#define LEFT_ARROW_KEY   SDLK_LEFT
#define RIGHT_ARROW_KEY  SDLK_RIGHT
#define UP_ARROW_KEY     SDLK_UP
#define DOWN_ARROW_KEY   SDLK_DOWN
#define ESCAPE_KEY       SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

class InputManager {
    public:
        static InputManager& GetInstance();

        void update();

        bool keyPress(int key);
        bool keyRelease(int key);
        bool isKeyDown(int key);

        bool mousePress(int button);
        bool mouseRelease(int button);
        bool isMouseDown(int button);

        int  getMouseX();
        int  getMouseY();
        bool quitRequested();

    private:
        InputManager();
        ~InputManager() = default;

        bool mouseState[6];
        int  mouseUpdate[6];

        std::unordered_map<int, bool> keyState;
        std::unordered_map<int, int>  keyUpdate;

        bool quitRequestedFlag;
        int  updateCounter;
        int  mouseX;
        int  mouseY;
};

#endif
