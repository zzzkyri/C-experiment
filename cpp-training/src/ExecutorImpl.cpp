#include "ExecutorImpl.hpp"


namespace adas
{

Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept :
    pose(pose)
{
    
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
       for (const auto cmd : commands) {
        if (cmd == 'M') {
            if (pose.heading == E) {
                ++pose.x;
            }
            else if (pose.heading == W) {
                --pose.x;
            }
            else if (pose.heading == N) {
                ++pose.y;
            }
            else if (pose.heading == S) {
                --pose.y;   
            }
        }
        else if (cmd == 'L') {
            pose.heading = (Position)((pose.heading -1 + 4) % 4);
        }
        else if (cmd == 'R') {
            pose.heading = (Position)((pose.heading +1 ) % 4);
        }
       }



    
}

Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}













}