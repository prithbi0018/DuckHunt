#pragma once
#include <SFML/Graphics.hpp>
#include "DuckConfig.h"
namespace Duck {
	class DuckModel;
	class DuckView;
	class DuckController {
	protected:
		DuckModel* duckModel;
		DuckView* duckView;
		float upDownMovementSpeed = 10.f;
		float leftRightMovementSpeed = 10.f;
		float deadMovementSpeed = 400.f;
		int score = 10;

		const float duckSoundTime = 1.5f;
		float duckSoundElapsedTime = 0.f;

		virtual void move();
		virtual void moveLeft();
		virtual void moveRight();
		virtual void moveDown();
		virtual void moveUp();
		void deadMove();
		sf::Vector2f getRandomPosition();
		void playDuckSound();
		void handleOutOfBounds();
		void destroy();

	public:
		DuckController(DuckType type);
		~DuckController();

		void initialize();
		void update();
		void render();
		sf::Vector2f getDuckPosition();
		DuckType getDuckType();
		MovementDirection getMovementDirection();
		DuckState getDuckState();

		virtual bool checkIfColliding(sf::FloatRect bounds);

		const sf::Sprite& getDuckSprite();

	};
}