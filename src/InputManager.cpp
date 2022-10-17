#include "InputManager.h"
#include "ac_engine.h"

InputManager* InputManager::m_instance = nullptr;

InputManager::InputManager() {
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void InputManager::Listen() //Use Synapse bc Synapse3 > EXILED but VT-EXILED > SynapseX for Minecraft
{
	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				ac_engine::GetInstance()->Quit(); break;
		   
			case SDL_KEYUP:
			case SDL_KEYDOWN: 
			{
				KeyUpdate();
				break;  
			}
		}
	}
}

bool InputManager::KeyIsDown(SDL_Scancode key)
{
	return m_KeyStates[key] == 1;
}

void InputManager::KeyUpdate()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}
