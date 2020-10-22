#pragma once

#include <list>
#include <memory>

#include "IEventHandler.hpp"
#include "SnakeInterface.hpp"
#include "EventT.hpp"

class Event;
class IPort;

namespace Snake
{
struct ConfigurationError : std::logic_error
{
    ConfigurationError();
};

struct UnexpectedEventException : std::runtime_error
{
    UnexpectedEventException();
};

class Controller : public IEventHandler
{
    struct Segment;
public:
    Controller(IPort& p_displayPort, IPort& p_foodPort, IPort& p_scorePort, std::string const& p_config);

    Controller(Controller const& p_rhs) = delete;
    Controller& operator=(Controller const& p_rhs) = delete;

    void isGameLost(Segment& head, bool& isLost);
    void isHeadOnFruit();
    void snakeOutOfMap(bool& isLost);
    void setFreeLastSegment();
    void nextMoveSnake(Segment& head);

    bool isReceivedFoodcolidedWithSnake(EventT<FoodInd> const& food);
    bool isRequestedFoodcolidedWithSnake(EventT<FoodResp> const& food);
    void placeNewFoodInd(EventT<FoodInd> const& food);
    void placeNewFoodResp(EventT<FoodResp> const& food);
    void clearOldFood();

    void receive(std::unique_ptr<Event> e) override;

private:
    struct Segment
    {
        int x;
        int y;
        int ttl;
    };

    IPort& m_displayPort;
    IPort& m_foodPort;
    IPort& m_scorePort;

    std::pair<int, int> m_mapDimension;
    std::pair<int, int> m_foodPosition;

    Direction m_currentDirection;
    std::list<Segment> m_segments;
};

} // namespace Snake
