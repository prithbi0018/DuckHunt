#include "../../Header/Time/TimeService.h"

namespace Time {
    void TimeService::updateDeltaTime()
    {
        deltaTime = calculateDeltaTime();
        updatePreviousTime();
    }
    float TimeService::calculateDeltaTime()
    {
        int delta = static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previousTime).count());

        return static_cast<float>(delta) / 1000000.f;
    }
    void TimeService::updatePreviousTime()
    {
        previousTime = std::chrono::steady_clock::now();
    }
    TimeService::TimeService()
    {
    }
    TimeService::~TimeService()
    {
    }
    void TimeService::initialize()
    {
        previousTime = std::chrono::steady_clock::now();
        deltaTime = 0;
    }
    void TimeService::update()
    {
        updateDeltaTime();
    }
    float TimeService::getDeltaTime()
    {
        return deltaTime;
    }
}