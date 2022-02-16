#pragma once

#include "GraphicThread.h"

Base::GraphManager * const GraphicThread::getGraphManager()
{
	return &gm;
}

std::thread GraphicThread::getThread()
{
	return std::thread(&GraphicThread::update, this);
}

//bIdle1(&gm.getCamera()->character.body, &timer, 1.0f), 
//mInput1(&gm.getCamera()->character.mouth, rtath.getRtManager()->getInputBuffer())

void GraphicThread::setUp()
{
	window.create(sf::VideoMode(151, 151), "SFML works!", sf::Style::None);
	window.setActive(false);
	window.setFramerateLimit(25);
	window.setVerticalSyncEnabled(0);
	
}

void GraphicThread::update()
{
	
	while (window.isOpen())
	{

		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/*
		sf::Event msg;
		while (eventmanager.pollEvent(msg))
		{
			if (msg.type == EMessage)
				am.processevent(msg);
		}
		*/

		//BodyAnimations::Idle1* anim1 = new BodyAnimations::Idle1(&gm.getCamera()->character.body, &timer, 1.0f); // it should be not there
		//MouthAnimations::Input1* anim2 = new MouthAnimations::Input1(&gm.getCamera()->character.mouth, rtath.getRtManager()->getInputBuffer());// it should be not there

		//am.SetAnimation(&cameraAnim);
		//gm.getCamera()->getAnimation()->getCharAnim()->setBodyAnim(&bIdle1);

		//gm.getCamera()->getAnimation()->getCharAnim()->setMouthAnim(&mInput1);

		timer.update(&clock);

		gm.update();

		//if event == Donation then sequencer manager. current sequence == DonationSequence class

		window.clear();
		window.draw(*gm.getCamera()->bg.getBackground()->getSprite());
		window.draw(*gm.getCamera()->camText.getText());
		window.draw(*gm.getCamera()->character.body.getSprite());
		window.draw(*gm.getCamera()->character.mouth.getSprite());
		window.draw(*gm.getCamera()->fg.getGrid()->getSprite());
		window.display();

		//delete anim1;
		//delete anim2;

	}
	
}