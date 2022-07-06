#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Log
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename... Args
> constexpr void ::xrn::Logger::logImpl(
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    const ::fmt::format_string<Args...> subformat,
    Args&&... args
)
{
    Logger::outputLog(
        filepath,
        functionName,
        lineNumber,
        Logger::Level::none,
        subformat,
        ::std::forward<decltype(args)>(args)...
    );
}

///////////////////////////////////////////////////////////////////////////
/// \brief Logs using fmt
///////////////////////////////////////////////////////////////////////////
template <
    typename... Args
> constexpr void ::xrn::Logger::logImpl(
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    const Logger::Level level,
    const ::fmt::format_string<Args...> subformat,
    Args&&... args
)
{
    Logger::outputLog(
        filepath,
        functionName,
        lineNumber,
        level,
        subformat,
        ::std::forward<decltype(args)>(args)...
    );
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Test
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/// \brief Same as assert from <cassert>
///
/// Prints successful tests if PRINT_DEBUG is defined
///
///////////////////////////////////////////////////////////////////////////
template <
    typename... Args
> constexpr void ::xrn::Logger::testImpl(
    bool condition,
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    const ::fmt::format_string<Args...> subformat,
    Args&&... args
)
{
    Logger::outputTest(
        condition,
        filepath,
        functionName,
        lineNumber,
        Logger::Level::fatalError,
        subformat,
        ::std::forward<decltype(args)>(args)...
    );
}

///////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////
template <
    typename... Args
> constexpr void ::xrn::Logger::testImpl(
    bool condition,
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    const Logger::Level level,
    const ::fmt::format_string<Args...> subformat,
    Args&&... args
)
{
    Logger::outputTest(
        condition,
        filepath,
        functionName,
        lineNumber,
        level,
        subformat,
        ::std::forward<decltype(args)>(args)...
    );
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Helper
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename... Args
> constexpr void ::xrn::Logger::outputLog(
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    const Logger::Level level,
    const ::fmt::format_string<Args...> subformat,
    Args&&... args
)
{
#if defined(NDEBUG)
    if (level == Logger::Level::debug) {
        return;
    }
#endif // ifdef NDEBUG

    // call position
    auto relaviteFilepath{
        ::std::filesystem::relative(::std::filesystem::path{ filepath }, ".").generic_string()
    };
    if (relaviteFilepath.starts_with("sources/")) {
        relaviteFilepath = relaviteFilepath.substr(8);
    }
    auto callPosition{
        ::fmt::format(::fmt::emphasis::bold,"{}:{}({})", relaviteFilepath, lineNumber, functionName)
    };

    // use message
    auto userMessage{
        ::fmt::format(subformat, ::std::forward<decltype(args)>(args)...)
    };

    // log level
    ::std::string logSpecifier;
    switch (level) {
    case Logger::Level::success: // is successful
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::bg(fmt::color::chartreuse) | ::fmt::fg(fmt::color::black),
            "SUCCESS"
        );
        break;
    case Logger::Level::note: // user driven (configuration operations)
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::fg(fmt::color::aqua),
            "note"
        );
        break;
    case Logger::Level::info: // user driven (regularly scheduled operations)
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::fg(fmt::color::gold),
            "info"
        );
        break;
    case Logger::Level::trace: // tracks potential bugs
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::fg(fmt::color::tomato),
            "trace"
        );
        break;
    case Logger::Level::debug: // (disabled with NDEBUG)
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::fg(fmt::color::fuchsia),
            "debug"
        );
        break;
    case Logger::Level::warning: // can potential become an error
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::fg(fmt::color::red),
            "warning"
        );
        break;
    case Logger::Level::error: // error that cannot be recovered but does not throw
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::bg(fmt::color::red) | ::fmt::fg(fmt::color::black),
            "ERROR"
        );
        break;
    case Logger::Level::none: // no extra output. Should be avoided
        ::fmt::print("{}: {}\n", callPosition, userMessage);
        return;
    case Logger::Level::fatal: // error that cannot be recovered, throws an exception
    case Logger::Level::fatalError: // same as fatal
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::bg(fmt::color::red) | ::fmt::fg(fmt::color::black),
            "ERROR"
        );
        throw ::std::runtime_error{ ::fmt::format("{} {}: {}", callPosition, logSpecifier, userMessage) };
    };

    ::fmt::print("{}: {}: {}\n", callPosition, logSpecifier, userMessage);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename... Args
> constexpr void ::xrn::Logger::outputTest(
    const bool condition,
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    Logger::Level level,
    const ::fmt::format_string<Args...> subformat,
    Args&&... args
)
{
#if defined(PRINT_DEBUG) && defined(NDEBUG)
    if (condition) {
        level = Logger::Level::success;
    } else {
        return;
    }
#elif defined(PRINT_DEBUG)
    if (condition) {
        level = Logger::Level::success;
    }
#elif defined(NDEBUG)
    return;
#else
    if (condition) {
        return;
    }
#endif

    Logger::outputLog(
        filepath,
        functionName,
        lineNumber,
        level,
        subformat,
        ::std::forward<decltype(args)>(args)...
    );
}
