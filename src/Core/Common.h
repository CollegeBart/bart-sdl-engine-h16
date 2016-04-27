#pragma once

#define GEngine		Engine::GetInstance()
#define GResources	GEngine->GetResources()
#define GRenderer	GEngine->GetRenderer()
#define GInput		GEngine->GetInput()
#define GTimer		GEngine->GetTimer()
#define GPhysics	GEngine->GetPhysics()

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
#include "SDL_ttf.h"
#include "SDL_mixer.h"

// Box2D Lib
#include "Box2D.h"

// GLM include
#include "glm.hpp"

// Custom includes
#include "Rekt.h"
#include "Input.h"
#include "Resources.h"
#include "Timer.h"
#include "Physics.h"



