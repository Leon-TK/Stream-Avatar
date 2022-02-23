#pragma once

#include <thread>

#include "../../thirdparty/sfml/include/Graphics.hpp"

class GraphicThread
{
private:
	std::mutex m_mt;

public:
    GraphicThread() = default;
    GraphicThread(const GraphicThread&) = delete;
    GraphicThread& operator=(const GraphicThread&) = delete;

	Base::GraphManager gm;
	//Base::AnimationManager am;
	//Animations

	sf::Clock clock;
	sf::Clock clock2;

	Base::Timer timer;
	Base::Timer timer2;
	sf::RenderWindow window;
	
	void setUp();
	void update();
	Base::GraphManager* getGraphManager();

	std::thread getThread();
};