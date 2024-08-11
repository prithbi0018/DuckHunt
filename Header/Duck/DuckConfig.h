#pragma once

namespace Duck {
	enum class DuckType {
		GreenDuck,
		BlueDuck
	};

	enum class DuckState {
		Alive,
		Dead
	};

	enum class MovementDirection {
		LeftUp,
		LeftDown,
		RightUp,
		RigthDown
	};
}