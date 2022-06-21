#ifndef LOOP_MANAGER_H
#define LOOP_MANAGER_H

#ifdef DLL_EXPORT
#define LOOP_MANAGER_API __declspec(dllexport)
#else
#define LOOP_MANAGER_API __declspec(dllimport)
#endif

#include <vector>
#include <SFML/Graphics.hpp>
#include <Gameobject.cpp>
#include "../time-manager/TimeManager.h"

namespace WTGD
{
	class LOOP_MANAGER_API LoopManager
	{
	//Constructors / Destructor
	public:
		/// <summary>
		/// Default Loop Manager Contructor
		/// </summary>
		LoopManager() : gameWindow(nullptr) {};
		/// <summary>
		/// Default Loop Manager Destructor
		/// </summary>
		~LoopManager();

	//Public Functions
	public:

		/// <summary>
		/// Creates the game window
		/// </summary>
		void createWindow(const float width, const float height, const char* title);

		/// <summary>
		/// Change the amount of max FPS for the game window (standard is 60 FPS)
		/// </summary>
		/// <param name="newLimit">The new FPS limit</param>
		void setMaxFPS(unsigned newLimit);

		/// <summary>
		/// Returns the current frame's FPS
		/// </summary>
		/// <returns></returns>
		unsigned getFPS()const;

		/// <summary>
		/// Toggle the FPS limit ON or OFF depending on the current setting
		/// </summary>
		void fpsLimitToggler();

		/// <summary>
		/// Draws the registered GameObjects on the screen
		/// </summary>
		void draw();
		/// <summary>
		/// Updates the registered GameObjects on the screen
		/// </summary>
		/// <param name="gameobjects"></param>
		void update(std::vector<GameObject> gameobjects);
		/// <summary>
		/// Reacts to events
		/// </summary>
		void pollEvents();
		/// <summary>
		/// Updates the game time
		/// </summary>
		void updateGameTime();

	//Private Members
	public:
		sf::RenderWindow* gameWindow;

		unsigned maxFPS = 60;
		bool isFpsLimited = true;

		WTGD::TimeManager timeManager;
		float elapsedTime = 0.0f;
		sf::Time lastTime, currentTime;
	};
}

#endif LOOP_MANAGER_H
