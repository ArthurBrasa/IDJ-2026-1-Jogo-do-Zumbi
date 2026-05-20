#include <InputManager.h>

InputManager::InputManager() : quitRequestedFlag(false), updateCounter(0), mouseX(0), mouseY(0) {
    for (int i = 0; i < 6; ++i) {
        mouseState[i]  = false;
        mouseUpdate[i] = 0;
    }
}

InputManager& InputManager::GetInstance() {
    static InputManager instance;
    return instance;
}

void InputManager::update() {
    SDL_GetMouseState(&mouseX, &mouseY);
    quitRequestedFlag = false;
    ++updateCounter;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                quitRequestedFlag = true;
                break;

            case SDL_MOUSEBUTTONDOWN:
                mouseState[event.button.button]  = true;
                mouseUpdate[event.button.button] = updateCounter;
                break;

            case SDL_MOUSEBUTTONUP:
                mouseState[event.button.button]  = false;
                mouseUpdate[event.button.button] = updateCounter;
                break;

            case SDL_KEYDOWN:
                if (!event.key.repeat) {
                    keyState[event.key.keysym.sym]  = true;
                    keyUpdate[event.key.keysym.sym] = updateCounter;
                }
                break;

            case SDL_KEYUP:
                keyState[event.key.keysym.sym]  = false;
                keyUpdate[event.key.keysym.sym] = updateCounter;
                break;

            default:
                break;
        }
    }
}

bool InputManager::keyPress(int key)   { return keyState[key] && keyUpdate[key] == updateCounter; }
bool InputManager::keyRelease(int key) { return !keyState[key] && keyUpdate[key] == updateCounter; }
bool InputManager::isKeyDown(int key)  { return keyState[key]; }

bool InputManager::mousePress(int btn)   { return mouseState[btn] && mouseUpdate[btn] == updateCounter; }
bool InputManager::mouseRelease(int btn) { return !mouseState[btn] && mouseUpdate[btn] == updateCounter; }
bool InputManager::isMouseDown(int btn)  { return mouseState[btn]; }

int  InputManager::getMouseX()       { return mouseX; }
int  InputManager::getMouseY()       { return mouseY; }
bool InputManager::quitRequested()   { return quitRequestedFlag; }
