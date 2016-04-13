#pragma once

#define GEngine		Engine::GetInstance()
#define GResources	GEngine->GetResources()
#define GRenderer	GEngine->GetRenderer()
#define GInput		GEngine->GetInput()
#define GTimer		GEngine->GetTimer()


#define TITLE_DEFAULT "BartEngine::"
#define SCREEN_WIDTH_DEFAULT 1280
#define SCREEN_HEIGHT_DEFAULT 720

// STL - Standard Template Library
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

// SDL Libs
#include "SDL.h"
#include "SDL_image.h"
//#include "SDL/SDL_ttf.h"

// Custom includes
#include "Vector2.h"
#include "Input.h"
#include "Resources.h"
#include "Component.h"
#include "Timer.h"
//#include "Transform.h"
//#include "Vector3.h"