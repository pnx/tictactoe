
#ifndef ENGINE_INPUT_MOUSE_H
#define ENGINE_INPUT_MOUSE_H

namespace MouseButtons {
    enum MouseButtons {
        None, Right, Left, Middle
    };
}
typedef MouseButtons::MouseButtons MouseButtonsType;

namespace ButtonState {
    enum ButtonState {
        None, Up, Down
    };
}
typedef ButtonState::ButtonState ButtonStateType;

typedef struct {
    MouseButtonsType Button;
    ButtonStateType State;
    int x;
    int y;
} MouseState;

class Mouse {

private :
    static MouseState mState;
public :
    static MouseState* getState();

    // Update the mouse state.
    static void Update();
};

#endif /* ENGINE_INPUT_MOUSE_H */