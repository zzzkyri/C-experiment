#pragma once

#include <string>

namespace adas{

enum Position{N, E, S, W};

struct Pose
{
    int x;
    int y;
    Position heading;
};

class Executor {
  
public:
    static Executor* NewExecutor(const Pose& pose = {0, 0, N}) noexcept;

public:
    Executor(void) = default;				
    virtual ~Executor(void) = default;
    Executor(const Executor&) = delete;				
    Executor& operator=(const Executor&) = delete;

public:
virtual void Execute(const std::string& command)noexcept   = 0; 
virtual Pose Query(void) const noexcept = 0;


};

} // namespace adas