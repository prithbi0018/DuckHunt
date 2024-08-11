#include "../../Header/Duck/DuckModel.h"
#include "../../Header/Duck/DuckController.h"
#include <vector>

namespace Duck {
	DuckModel::DuckModel(DuckType type)
	{
		duckType = type;
	}
	DuckModel::~DuckModel()
	{
	}
	void DuckModel::initialize()
	{
		duckPosition = referencePosition;
		switch (std::rand() % 2) {
		case 0:
			setMovementDirection(MovementDirection::LeftUp);
			break;
		case 1:
			setMovementDirection(MovementDirection::RightUp);
			break;
		}

	}
	sf::Vector2f DuckModel::getDuckPosition()
	{
		return duckPosition;
	}
	void DuckModel::setDuckPosition(sf::Vector2f position)
	{
		duckPosition = position;
	}
	sf::Vector2f DuckModel::getReferencePosition()
	{
		return referencePosition;
	}
	void DuckModel::setReferencePosition(sf::Vector2f position)
	{
		referencePosition = position;
	}
	DuckType DuckModel::getDuckType()
	{
		return duckType;
	}
	void DuckModel::setDuckType(DuckType type)
	{
		duckType = type;
	}
	DuckState DuckModel::getDuckState()
	{
		return duckState;
	}
	void DuckModel::setDuckState(DuckState state)
	{
		duckState = state;
	}
	MovementDirection DuckModel::getMovementDirection()
	{
		return movementDirection;
	}
	void DuckModel::setMovementDirection(MovementDirection direction)
	{
		movementDirection = direction;
	}
}