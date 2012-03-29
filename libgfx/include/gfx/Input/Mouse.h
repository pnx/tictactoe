
#ifndef ENGINE_INPUT_MOUSE_H
#define ENGINE_INPUT_MOUSE_H

#include "../Math/MathTypes.h"

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
	cord2f point;
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