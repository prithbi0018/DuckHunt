#pragma once
#include <chrono>
namespace Time {
	class TimeService {
	private:

		std::chrono::time_point<std::chrono::steady_clock> previousTime;

		float deltaTime;
		void updateDeltaTime();
		float calculateDeltaTime();
		void updatePreviousTime();

	public:
		TimeService();
		~TimeService();

		void initialize();
		void update();

		float getDeltaTime();
		
	};
}