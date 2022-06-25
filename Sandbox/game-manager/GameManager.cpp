#include "GameManager.h"
#include <iostream>

void GameManager::run()
{
	initialize();

	_manager->lastTime = _manager->timeManager.GetCurrentTime();
	while (_manager->gameWindow->isOpen())
	{
		_manager->updateGameTime();
		std::cout << "FPS: " << _manager->getFPS() << std::endl;

		_manager->pollEvents();

		_manager->update(gameobjects);
		_manager->draw(gameobjects);

		if (_manager->isFpsLimited)
		{
			sf::sleep(sf::seconds(1.0f / _manager->maxFPS));
		}
	}
}

void GameManager::set_events()
{

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		_manager->set_input_func([this](sf::Event) { this->set_events_b(); }, this->evt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		printf("AAAAAAAAAAAAAAAAAAAAA\n");
	}*/
}

void GameManager::set_events_b()
{
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	//{
	//	_manager->set_input_func([this](sf::Event) { this->set_events(); }, this->evt);
	//}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	//{
	//	printf("BBBBBBBBBBBBBBBBBBBBB\n");
	//}
}

void GameManager::initialize()
{	
	_manager->set_input_func([this](sf::Event) { this->set_events(); }, evt);

	player = new WTGD::Character(new WTGD::KeyboardController(), "Player");
	player->renderer->set_texture("res\\pacman.png");
	player->transform->set_scale(100, 100);
	player->transform->set_position(640, 360);
	gameobjects.push_back(player);

	WTGD::WorldObject* square = new WTGD::WorldObject("Cube", true);
	square->transform->set_scale(100, 100);
	square->transform->set_position(500, 100);

	WTGD::Collider* coll = square->get_component<WTGD::Collider>();
	coll->get_body()->setSize(coll->get_body()->getSize());
	coll->get_body()->setOrigin(coll->get_body()->getSize() / 2.0f);
	coll->get_body()->setPosition(coll->get_body()->getPosition());
	coll->get_body()->setScale(coll->get_body()->getScale());

	gameobjects.push_back(square);

	_manager->add_colliders(gameobjects);

	_manager->createWindow(1280, 720, "Title");

	/* To be filled with
	
		add gameobjects to the game

	*/
}

