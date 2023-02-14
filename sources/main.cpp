///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto main()
    -> int
{

    XRN_LOG("not specified");
    XRN_LOG(::xrn::Logger::Level::none, "none o");
    XRN_LOG(::xrn::Logger::Level::success, "success");
    XRN_LOG(::xrn::Logger::Level::note, "note");
    XRN_LOG(::xrn::Logger::Level::info, "info");
    XRN_LOG(::xrn::Logger::Level::trace, "trace");
    XRN_LOG(::xrn::Logger::Level::debug, "debug");
    XRN_LOG(::xrn::Logger::Level::debug);
    XRN_DEBUG();
    XRN_LOG(::xrn::Logger::Level::warning, "warning");
    XRN_LOG(::xrn::Logger::Level::error, "error");
    XRN_ASSERT(true, "true assert");
    XRN_ASSERT(false, "false assert");
    XRN_FATAL_SASSERT(true, "fatal sassert true");
    XRN_LOG(::xrn::Logger::Level::fatalError, "fatalError");
    XRN_FATAL_SASSERT(false, "false");
    return EXIT_SUCCESS;
}
