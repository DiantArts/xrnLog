#define NDEBUG
#define PRINT_DEBUG
#include <pch.hpp>
#include <Logger.hpp>

struct K {
    void run()
    {
        ::xrn::test(false, "lol");
        // ::xrn::log("Message");
        // ::xrn::log(::xrn::Logger::Level::none, "Message");
        // ::xrn::log(::xrn::Logger::Level::success, "Message");
        // ::xrn::log(::xrn::Logger::Level::note, "Message");
        // ::xrn::log(::xrn::Logger::Level::info, "Message");
        // ::xrn::log(::xrn::Logger::Level::trace, "Message");
        // ::xrn::log(::xrn::Logger::Level::debug, "Message");
        // ::xrn::log(::xrn::Logger::Level::warning, "Message");
        // ::xrn::log(::xrn::Logger::Level::error, "Message");
    }
};

int main()
{
    K{}.run();
    return 0;
}
