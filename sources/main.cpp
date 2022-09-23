///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#define PRINT_DEBUG
#include <xrn/Log.hpp>

///////////////////////////////////////////////////////////////////////////
auto main()
    -> int
{
    XRN_ASSERT(true, ::xrn::Logger::Level::none, "Message");
    XRN_ASSERT(true, ::xrn::Logger::Level::success, "Message");
    XRN_ASSERT(true, ::xrn::Logger::Level::note, "Message");
    XRN_ASSERT(true, ::xrn::Logger::Level::info, "Message");
    XRN_ASSERT(true, ::xrn::Logger::Level::trace, "Message");
    XRN_ASSERT(true, ::xrn::Logger::Level::debug, "Message");
    XRN_ASSERT(true, ::xrn::Logger::Level::warning, "Message");
    XRN_ASSERT(true, ::xrn::Logger::Level::error, "Message");
    XRN_ASSERT(true, ::xrn::Logger::Level::fatalError, "Message");
    return EXIT_SUCCESS;
}
