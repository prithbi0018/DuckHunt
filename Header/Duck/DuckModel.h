#pragma once
#include <SFML/System/Vector2.hpp>
#include "DuckConfig.h"
namespace Duck {
	class DuckController;
	class DuckModel {
	private:
		sf::Vector2f duckPosition;
		sf::Vector2f referencePosition = sf::Vector2f(900.f, 1000.f);

		DuckType duckType;
		DuckState duckState = DuckState::Alive;
		MovementDirection movementDirection = MovementDirection::LeftUp;

	public:
		DuckModel(DuckType type);
		~DuckModel();

		void initialize();

		const float leftMostPosition = 0.f;
		const float rightMostPosition = 1840.f;
		const float topMostPosition = 100.f;
		const float bottomMostPosition = 900.f;
		const float deadMovmentSpeed = 600.f;


		sf::Vector2f getDuckPosition();
		void setDuckPosition(sf::Vector2f position);

		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f position);

		DuckType getDuckType();
		void setDuckType(DuckType type);

		DuckState getDuckState();
		void setDuckState(DuckState state);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);


		
	};
}