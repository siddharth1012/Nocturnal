// The implementation of the userinterface class

#include "userinterface.h"

UserInterface::UserInterface()
{
	//background = LoadTexture();

	gameObjects.push_back(this); // Push back into the game object list
}

UserInterface::~UserInterface()
{
	//UnloadTexture();
}

void UserInterface::update() { gameTime += GetFrameTime(); } // Increment the game time by 1 second per second

void UserInterface::render()
{
	// Basic UserInterface elements
	DrawText(("TIME: " + formatTime(gameTime)).c_str(), windowWidth - 145, 0, 24, RED);
	DrawText(("SCORE: " + std::to_string(score)).c_str(), 10, 0, 24, RED);
	DrawText(("BULLETS: " + std::to_string(bullets)).c_str(), 10, 24, 24, RED);
}

std::string UserInterface::formatTime(float gameTime)
{
	std::ostringstream time; // Sting to store the formated time

	int minutes = static_cast<int>(gameTime) / 60; // Get seconds
	int seconds = static_cast<int>(gameTime) % 60; // Get minutes

	time << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << seconds;

	return time.str(); // return formated time
}