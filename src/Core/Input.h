#pragma once

#include "Common.h"

class Input
{
public:
	Input();
	~Input();

	void Poll(const SDL_Event& e);
	
	bool IsKeyHeld(const SDL_Scancode& key);
	bool IsKeyPressed(const SDL_Scancode& key);
	bool IsKeyReleased(const SDL_Scancode& key);

	bool IsMouseButtonHeld( int button );
	bool IsMouseButtonPressed(int button);
	bool IsMouseButtonReleased(int button);

	glm::vec2 GetMousePosition() { return mousePosition; }

private:
	static const int KEY_COUNT = 256;
	static const int MOUSE_BUTTON_COUNT = 5;

	bool keys[KEY_COUNT];
	bool lastKeys[KEY_COUNT];

	bool mouseButtons[MOUSE_BUTTON_COUNT];
	bool lastMouseButtons[MOUSE_BUTTON_COUNT];

	glm::vec2 mousePosition;

	bool ProcessKey(const SDL_Scancode& key, bool isReleased);
};