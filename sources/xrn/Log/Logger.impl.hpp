#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// No output
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

template <
    typename... Args
> void ::xrn::Logger::log(
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    const Logger::Level level
)
{
#if defined(NO_DEBUG)
    if (level == Logger::Level::debug) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            level,
            false
        );
    }
#endif // ifdef NO_DEBUG
    return this->logImpl(
        filepath,
        functionName,
        lineNumber,
        level,
        true
    );
}

template <
    typename... Args
> void ::xrn::Logger::log(
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber
)
{
    return this->logImpl(
        filepath,
        functionName,
        lineNumber,
        Logger::Level::none,
        true
    );
}

///////////////////////////////////////////////////////////////////////////
template <
    typename... Args
> void ::xrn::Logger::massert(
    const bool condition,
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    Logger::Level level
)
{
#if defined(PRINT_ASSERTS) && defined(NO_DEBUG)
    if (level == Logger::Level::debug) {
        if (condition) {
            return this->logImpl(
                filepath,
                functionName,
                lineNumber,
                Logger::Level::success,
                false
            );
        } else {
            return this->logImpl(
                filepath,
                functionName,
                lineNumber,
                level,
                false
            );
        }
    } else if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            true
        );
    } else {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            level,
            false
        );
    }
#elif defined(PRINT_ASSERTS)
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            true
        );
    }
#elif defined(NO_DEBUG)
    if (level == Logger::Level::debug) {
        if (condition) {
            return this->logImpl(
                filepath,
                functionName,
                lineNumber,
                Logger::Level::success,
                false
            );
        } else {
            return this->logImpl(
                filepath,
                functionName,
                lineNumber,
                level,
                false
            );
        }
    } else if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            false
        );
    } else {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            level,
            false
        );
    }
#else
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            false
        );
    }
#endif
    return this->logImpl(
        filepath,
        functionName,
        lineNumber,
        level,
        true
    );
}

template <
    typename... Args
> void ::xrn::Logger::massert(
    const bool condition,
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber
)
{
#if defined(PRINT_ASSERTS) && defined(NO_DEBUG)
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            true
        );
    } else {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::error,
            false
        );
    }
#elif defined(PRINT_ASSERTS)
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            true
        );
    }
#elif defined(NO_DEBUG)
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            false
        );
    } else {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::error,
            false
        );
    }
#else
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            false
        );
    }
#endif
    return this->logImpl(
        filepath,
        functionName,
        lineNumber,
        Logger::Level::error,
        true
    );
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Log
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

template <
    typename... Args
> void ::xrn::Logger::log(
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    const Logger::Level level,
    const ::fmt::format_string<Args...> subformat,
    Args&&... args
)
{
#if defined(NO_DEBUG)
    if (level == Logger::Level::debug) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            level,
            false,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    }
#endif // ifdef NO_DEBUG
    return this->logImpl(
        filepath,
        functionName,
        lineNumber,
        level,
        true,
        subformat,
        ::std::forward<decltype(args)>(args)...
    );
}

template <
    typename... Args
> void ::xrn::Logger::log(
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    const ::fmt::format_string<Args...> subformat,
    Args&&... args
)
{
    return this->logImpl(
        filepath,
        functionName,
        lineNumber,
        Logger::Level::none,
        true,
        subformat,
        ::std::forward<decltype(args)>(args)...
    );
}

///////////////////////////////////////////////////////////////////////////
template <
    typename... Args
> void ::xrn::Logger::massert(
    const bool condition,
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    Logger::Level level,
    const ::fmt::format_string<Args...> subformat,
    Args&&... args
)
{
#if defined(PRINT_ASSERTS) && defined(NO_DEBUG)
    if (level == Logger::Level::debug) {
        if (condition) {
            return this->logImpl(
                filepath,
                functionName,
                lineNumber,
                Logger::Level::success,
                false,
                subformat,
                ::std::forward<decltype(args)>(args)...
            );
        } else {
            return this->logImpl(
                filepath,
                functionName,
                lineNumber,
                level,
                false,
                subformat,
                ::std::forward<decltype(args)>(args)...
            );
        }
    } else if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            true,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    } else {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            level,
            false,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    }
#elif defined(PRINT_ASSERTS)
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            true,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    }
#elif defined(NO_DEBUG)
    if (level == Logger::Level::debug) {
        if (condition) {
            return this->logImpl(
                filepath,
                functionName,
                lineNumber,
                Logger::Level::success,
                false,
                subformat,
                ::std::forward<decltype(args)>(args)...
            );
        } else {
            return this->logImpl(
                filepath,
                functionName,
                lineNumber,
                level,
                false,
                subformat,
                ::std::forward<decltype(args)>(args)...
            );
        }
    } else if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            false,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    } else {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            level,
            false,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    }
#else
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            false,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    }
#endif
    return this->logImpl(
        filepath,
        functionName,
        lineNumber,
        level,
        true,
        subformat,
        ::std::forward<decltype(args)>(args)...
    );
}

template <
    typename... Args
> void ::xrn::Logger::massert(
    const bool condition,
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    const ::fmt::format_string<Args...> subformat,
    Args&&... args
)
{
#if defined(PRINT_ASSERTS) && defined(NO_DEBUG)
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            true,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    } else {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::error,
            false,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    }
#elif defined(PRINT_ASSERTS)
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            true,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    }
#elif defined(NO_DEBUG)
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            false,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    } else {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::error,
            false,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    }
#else
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            false,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    }
#endif
    return this->logImpl(
        filepath,
        functionName,
        lineNumber,
        Logger::Level::error,
        true,
        subformat,
        ::std::forward<decltype(args)>(args)...
    );
}

///////////////////////////////////////////////////////////////////////////
template <
    typename... Args
> void ::xrn::Logger::sassert(
    const bool condition,
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    Logger::Level level,
    const ::fmt::format_string<Args...> subformat,
    Args&&... args
)
{
#if defined(FORCE_PRINT)
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            true,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    } else {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            level,
            true,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    }
#else
    if (!condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            level,
            true,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    }
#endif
}

template <
    typename... Args
> void ::xrn::Logger::sassert(
    const bool condition,
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    const ::fmt::format_string<Args...> subformat,
    Args&&... args
)
{
#if defined(FORCE_PRINT)
    if (condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::success,
            true,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    } else {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::error,
            true,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    }
#else
    if (!condition) {
        return this->logImpl(
            filepath,
            functionName,
            lineNumber,
            Logger::Level::error,
            true,
            subformat,
            ::std::forward<decltype(args)>(args)...
        );
    }
#endif
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::Logger::get()
    -> Logger&
{
    static ::xrn::Logger logger;
    return logger;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructor
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

::xrn::Logger::Logger()
    : m_consoleFile{ ::std::make_shared<::spdlog::sinks::stdout_color_sink_mt>() }
    , m_outputFile{ ::std::make_shared<::spdlog::sinks::basic_file_sink_mt>(".logs/output.txt") }
    , m_errorFile{ ::std::make_shared<::spdlog::sinks::basic_file_sink_mt>(".logs/error.txt") }
    , m_console{ "consoleSink", m_consoleFile }
    , m_output{ "outputSink", m_outputFile }
    , m_error{ "errorSink", m_errorFile }
{
    m_consoleFile->set_level(::spdlog::level::trace);
    m_consoleFile->set_pattern("%v");
    m_console.set_level(::spdlog::level::trace);
    m_console.flush_on(::spdlog::level::warn);

    m_outputFile->set_level(::spdlog::level::trace);
    m_outputFile->set_pattern("[%m-%d-%C %H:%M:%S.%F] [%t] %v");;
    m_output.set_level(::spdlog::level::trace);
    m_output.flush_on(::spdlog::level::warn);

    m_errorFile->set_level(::spdlog::level::warn);
    m_errorFile->set_pattern("[%m-%d-%C %H:%M:%S.%F] [%t] %v");;
    m_error.set_level(::spdlog::level::warn);
    m_error.flush_on(::spdlog::level::warn);
}

::xrn::Logger::~Logger()
{
    m_console.flush();
    m_output.flush();
    m_error.flush();
    ::spdlog::shutdown();
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename... Args
> void ::xrn::Logger::logImpl(
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    const Logger::Level level,
    const bool displayOnConsole
)
{
    // call position
    auto relaviteFilepath{
        ::std::filesystem::relative(::std::filesystem::path{ filepath }, ".").generic_string()
    };
    ::fmt::print("{}\n", "heo");
    if (relaviteFilepath.starts_with("sources/")) {
        relaviteFilepath = relaviteFilepath.substr(8);
    } else if (auto pos{ relaviteFilepath.find("/sources/") }; pos != ::std::string::npos) {
        if (auto pos2{ relaviteFilepath.find("/xrn") }; pos2 != ::std::string::npos) {
            auto name{ relaviteFilepath.substr(pos2 + 1, pos - (pos2 + 1)) };
            relaviteFilepath = name + ':' + relaviteFilepath.substr(pos + 9);
        } else {
            relaviteFilepath = relaviteFilepath.substr(pos + 9);
        }
    }
    auto callPosition{
        ::fmt::format(::fmt::emphasis::bold,"{}:{}({})", relaviteFilepath, lineNumber, functionName)
    };

    // log level
    ::std::string logSpecifier;
    switch (level) {
    case Logger::Level::none: // no extra output. Should be avoided
        m_output.trace("[{}]", callPosition);
        return;
    case Logger::Level::success: // is successful
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::bg(fmt::color::chartreuse) | ::fmt::fg(fmt::color::black),
            "SUCCESS"
        );
        break;
    case Logger::Level::note: // user driven (configuration operations)
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::fg(fmt::color::gold),
            "note"
        );
        break;
    case Logger::Level::info: // user driven (regularly scheduled operations)
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::fg(fmt::color::aqua),
            "info"
        );
        break;
    case Logger::Level::trace: // tracks potential bugs
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::fg(fmt::color::tomato),
            "trace"
        );
        break;
    case Logger::Level::debug: // (disabled with NO_DEBUG)
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
            "FAILURE"
        );
        break;
    case Logger::Level::fatal: // error that cannot be recovered, throws an exception
    case Logger::Level::fatalError: // same as fatal
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::bg(fmt::color::red) | ::fmt::fg(fmt::color::black),
            "FATAL"
        );
        m_output.error("[{}] [{}]", logSpecifier, callPosition);
        m_error.error("[{}] [{}]", logSpecifier, callPosition);
        throw ::std::runtime_error{
            ::fmt::format("\n[{}] [{}]", logSpecifier, callPosition)
        };
    };

    switch (level) {
    case Logger::Level::none: // no extra output. Should be avoided
    case Logger::Level::success: // is successful
    case Logger::Level::note: // user driven (configuration operations)
        if (displayOnConsole) {
            m_console.trace("[{}]", logSpecifier);
        }
        m_output.trace("[{}] [{}]", logSpecifier, callPosition);
        break;
    case Logger::Level::info: // user driven (regularly scheduled operations)
        if (displayOnConsole) {
            m_console.info("[{}]", logSpecifier);
        }
        m_output.trace("[{}] [{}]", logSpecifier, callPosition);
        break;
    case Logger::Level::trace: // tracks potential bugs
        if (displayOnConsole) {
            m_console.trace("[{}] [{}]", logSpecifier, callPosition);
        }
        m_output.trace("[{}] [{}]", logSpecifier, callPosition);
        break;
    case Logger::Level::debug: // (disabled with NO_DEBUG)
        if (displayOnConsole) {
            m_console.debug("[{}] [{}]", logSpecifier, callPosition);
        }
        m_output.debug("[{}] [{}]", logSpecifier, callPosition);
        break;
    case Logger::Level::warning: // can potential become an error
        if (displayOnConsole) {
            m_console.warn("[{}] [{}]", logSpecifier, callPosition);
        }
        m_output.warn("[{}] [{}]", logSpecifier, callPosition);
        m_error.warn("[{}] [{}]", logSpecifier, callPosition);
        break;
    case Logger::Level::error: // error that cannot be recovered but does not throw
        if (displayOnConsole) {
            m_console.error("[{}] [{}]", logSpecifier, callPosition);
        }
        m_output.error("[{}] [{}]", logSpecifier, callPosition);
        m_error.error("[{}] [{}]", logSpecifier, callPosition);
        break;
    default:
        throw ::std::runtime_error{ "This throw should never been used" };
    };
}

///////////////////////////////////////////////////////////////////////////
template <
    typename... Args
> void ::xrn::Logger::logImpl(
    const ::std::string_view filepath,
    const ::std::string_view functionName,
    const ::std::size_t lineNumber,
    const Logger::Level level,
    const bool displayOnConsole,
    const ::fmt::format_string<Args...> subformat,
    Args&&... args
)
{
    // call position
    auto relaviteFilepath{
        ::std::filesystem::relative(::std::filesystem::path{ filepath }, ".").generic_string()
    };
    if (relaviteFilepath.starts_with("sources/")) {
        relaviteFilepath = relaviteFilepath.substr(8);
    } else if (auto pos{ relaviteFilepath.find("/sources/") }; pos != ::std::string::npos) {
        if (auto pos2{ relaviteFilepath.find("/xrn") }; pos2 != ::std::string::npos) {
            auto name{ relaviteFilepath.substr(pos2 + 1, pos - (pos2 + 1)) };
            relaviteFilepath = name + ':' + relaviteFilepath.substr(pos + 9);
        } else {
            relaviteFilepath = relaviteFilepath.substr(pos + 9);
        }
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
    case Logger::Level::none: // no extra output. Should be avoided
        ::fmt::print("{}\n", userMessage);
        m_output.trace("[{}] {}", callPosition, userMessage);
        return;
    case Logger::Level::success: // is successful
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::bg(fmt::color::chartreuse) | ::fmt::fg(fmt::color::black),
            "SUCCESS"
        );
        break;
    case Logger::Level::note: // user driven (configuration operations)
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::fg(fmt::color::gold),
            "note"
        );
        break;
    case Logger::Level::info: // user driven (regularly scheduled operations)
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::fg(fmt::color::aqua),
            "info"
        );
        break;
    case Logger::Level::trace: // tracks potential bugs
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::fg(fmt::color::tomato),
            "trace"
        );
        break;
    case Logger::Level::debug: // (disabled with NO_DEBUG)
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
            "FAILURE"
        );
        break;
    case Logger::Level::fatal: // error that cannot be recovered, throws an exception
    case Logger::Level::fatalError: // same as fatal
        logSpecifier = ::fmt::format(
            ::fmt::emphasis::bold | ::fmt::bg(fmt::color::red) | ::fmt::fg(fmt::color::black),
            "FATAL"
        );
        m_output.error("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        m_error.error("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        throw ::std::runtime_error{
            ::fmt::format("\n[{}] [{}] {}", logSpecifier, callPosition, userMessage)
        };
    };

    switch (level) {
    case Logger::Level::none: // no extra output. Should be avoided
    case Logger::Level::success: // is successful
    case Logger::Level::note: // user driven (configuration operations)
        if (displayOnConsole) {
            m_console.trace("[{}] {}", logSpecifier, userMessage);
        }
        m_output.trace("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        break;
    case Logger::Level::info: // user driven (regularly scheduled operations)
        if (displayOnConsole) {
            m_console.info("[{}] {}", logSpecifier, userMessage);
        }
        m_output.trace("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        break;
    case Logger::Level::trace: // tracks potential bugs
        if (displayOnConsole) {
            m_console.trace("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        }
        m_output.trace("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        break;
    case Logger::Level::debug: // (disabled with NO_DEBUG)
        if (displayOnConsole) {
            m_console.debug("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        }
        m_output.debug("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        break;
    case Logger::Level::warning: // can potential become an error
        if (displayOnConsole) {
            m_console.warn("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        }
        m_output.warn("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        m_error.warn("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        break;
    case Logger::Level::error: // error that cannot be recovered but does not throw
        if (displayOnConsole) {
            m_console.error("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        }
        m_output.error("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        m_error.error("[{}] [{}] {}", logSpecifier, callPosition, userMessage);
        break;
    default:
        throw ::std::runtime_error{ "This throw should never been used" };
    };
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::Logger::getDate()
    -> ::std::string
{
    std::time_t t = ::std::time(0);   // get time now
    std::tm* now = ::std::localtime(&t);
    ::std::string output;

    // month
    if (now->tm_mon < 10) {
        output += '0';
    }
    output += ::std::to_string(now->tm_mon + 1);
    output += '-';

    // day
    if (now->tm_mday < 10) {
        output += '0';
    }
    output += ::std::to_string(now->tm_mday);
    output += ' ';

    // hour
    if (now->tm_hour < 10) {
        output += '0';
    }
    output += ::std::to_string(now->tm_hour);
    output += ':';

    // min
    if (now->tm_min < 10) {
        output += '0';
    }
    output += ::std::to_string(now->tm_min);
    output += ':';

    // sec
    if (now->tm_sec < 10) {
        output += '0';
    }
    output += ::std::to_string(now->tm_sec);
    output += '.';

    // ms
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch());
    const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(ms);
    ms -= seconds;
    if (ms < 10ms) {
        output += "00";
    } else if (ms < 100ms) {
        output += '0';
    }
    output += ::std::to_string(ms.count());

    return output;
}
