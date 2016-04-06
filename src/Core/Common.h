#pragma once

#define GEngine		Engine::GetInstance()
#define GResources	GEngine->GetResources()
#define GRenderer	GEngine->GetRenderer()

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

// Custom includes
#include "Component.h"