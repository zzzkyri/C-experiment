#include <memory>
#include<tuple>
#include "src\ExecutorImpl.cpp"

namespace adas
{
    bool operator==(const Pose& lhs, const Pose& rhs)
    {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }

int main(int argc, char** argv)
{
    // Given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, E}));

    // When
    executor->Execute("L");
    // Then

  
}
}