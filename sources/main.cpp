#define NDEBUG
#define PRINT_DEBUG
#include <pch.hpp>
#include <Logger.hpp>

struct K {
    void run()
    {
        // ::xrn::test(false, "lol");
        ::xrn::test(true, "Message");
        ::xrn::test(true, ::xrn::Logger::Level::none, "Message");
        ::xrn::test(true, ::xrn::Logger::Level::success, "Message");
        ::xrn::test(true, ::xrn::Logger::Level::note, "Message");
        ::xrn::test(true, ::xrn::Logger::Level::info, "Message");
        ::xrn::test(true, ::xrn::Logger::Level::trace, "Message");
        ::xrn::test(true, ::xrn::Logger::Level::debug, "Message");
        ::xrn::test(true, ::xrn::Logger::Level::warning, "Message");
        ::xrn::test(true, ::xrn::Logger::Level::error, "Message");
    }
};

int main()
{
    K{}.run();
    return 0;
}
