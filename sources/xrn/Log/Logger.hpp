#pragma once

#ifndef SPDLOG_FMT_EXTERNAL
#define SPDLOG_FMT_EXTERNAL ON
#endif
#ifndef SPDLOG_ACTIVE_LEVEL
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif
#include <spdlog/spdlog.h>
#include <spdlog/pattern_formatter.h>
#include <spdlog/async.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <fmt/format.h>
#include <fmt/color.h>

namespace xrn {

///////////////////////////////////////////////////////////////////////////
/// \brief Contains a function
///
/// \include Logger.hpp <Logger.hpp>
///
/// Output varies if NO_DEBUG (no debug) that disable asserts and PRINT_DEBUG
/// that prints "success" if the assert succeeded.
/// If FORCE_PRINT overrides silent actions (like SASSERT) and print on
/// success.
/// The logger level is optional;
/// The print format is the same as fmt (::std::format) library
///
/// \code cpp
/// XRN_ASSERT(true, "Message");
/// XRN_ASSERT(true, ::xrn::Logger::Level::none, "Message");
/// XRN_ASSERT(true, ::xrn::Logger::Level::success, "Message");
/// XRN_ASSERT(true, ::xrn::Logger::Level::note, "Message");
/// XRN_ASSERT(true, ::xrn::Logger::Level::info, "Message");
/// XRN_ASSERT(true, ::xrn::Logger::Level::trace, "Message");
/// XRN_ASSERT(true, ::xrn::Logger::Level::debug, "Message");
/// XRN_ASSERT(true, ::xrn::Logger::Level::warning, "Message");
/// XRN_ASSERT(true, ::xrn::Logger::Level::error, "Message");
/// \endcode
///
///////////////////////////////////////////////////////////////////////////
class Logger {

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // ErrorLevel
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Level of error to format the output
    ///
    /// The level should be used as followed:
    ///     - none: no extra output. Should be avoided
    ///     - note: user driven, configuration operations
    ///     - info: user driven, regularly scheduled operations
    ///     - trace: tracks potential bugs (disabled with NO_DEBUG)
    ///     - debug: (disabled with NO_DEBUG)
    ///     - warning: can potential become an error
    ///     - error: error that cannot be recovered but does not throw
    ///     - fatal: error that cannot be recovered, throws an exception
    ///     - fatalError: same as fatal
    ///
    /// \throws ::xrn::Exception fatal error
    ///
    ///////////////////////////////////////////////////////////////////////////
    enum Level {
        none = 0, // no extra output. Should be avoided
        success, // is successful
        note, // user driven (configuration operations)
        info, // user driven (regularly scheduled operations)
        trace, // tracks potential bugs (disabled with NO_DEBUG)
        debug, // (disabled with NO_DEBUG)
        warning, // can potential become an error
        error, // error that cannot be recovered but does not throw
        fatal, // error that cannot be recovered, throws an exception
        fatalError // same as fatal
    };



public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Helper
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Outputs the message with the right format
    ///////////////////////////////////////////////////////////////////////////
    template <
        typename... Args
    > void log(
        ::std::string_view filepath,
        ::std::string_view functionName,
        ::std::size_t lineNumber,
        Logger::Level level,
        ::fmt::format_string<Args...> subformat,
        Args&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Outputs the message with the right format (level none)
    ///////////////////////////////////////////////////////////////////////////
    template <
        typename... Args
    > void log(
        ::std::string_view filepath,
        ::std::string_view functionName,
        ::std::size_t lineNumber,
        ::fmt::format_string<Args...> subformat,
        Args&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Assert and outputs the message with the right format if needed
    ///////////////////////////////////////////////////////////////////////////
    template <
        typename... Args
    > void massert(
        bool condition,
        ::std::string_view filepath,
        ::std::string_view functionName,
        ::std::size_t lineNumber,
        Logger::Level level,
        ::fmt::format_string<Args...> subformat,
        Args&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Assert and outputs the message with the right format if needed
    ///
    /// (level fatalError)
    ///////////////////////////////////////////////////////////////////////////
    template <
        typename... Args
    > void massert(
        bool condition,
        ::std::string_view filepath,
        ::std::string_view functionName,
        ::std::size_t lineNumber,
        ::fmt::format_string<Args...> subformat,
        Args&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] static auto get()
        -> Logger&;



private:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructor
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    explicit Logger();

    ~Logger();

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Helpers
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Outputs the message with the right format
    ///////////////////////////////////////////////////////////////////////////
    template <
        typename... Args
    > void logImpl(
        ::std::string_view filepath,
        ::std::string_view functionName,
        ::std::size_t lineNumber,
        Logger::Level level,
        bool outputToConsole,
        ::fmt::format_string<Args...> subformat,
        Args&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Format date
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] static inline auto getDate()
        -> ::std::string;



private:

    ::std::shared_ptr<::spdlog::sinks::stdout_color_sink_mt> m_consoleFile;
    ::std::shared_ptr<::spdlog::sinks::basic_file_sink_mt> m_outputFile;
    ::std::shared_ptr<::spdlog::sinks::basic_file_sink_mt> m_errorFile;

    ::spdlog::logger m_console;
    ::spdlog::logger m_output;
    ::spdlog::logger m_error;

};

} // namespace xrn



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Macros
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/// \brief Output logs
///////////////////////////////////////////////////////////////////////////
#define XRN_LOG(...) \
    ::xrn::Logger::get().log(__FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)

///////////////////////////////////////////////////////////////////////////
/// \brief Throws a runtime_error with the right output
///////////////////////////////////////////////////////////////////////////
#define XRN_THROW(...) \
    ::xrn::Logger::get().log(__FILE__, __FUNCTION__, __LINE__, ::xrn::Logger::Level::fatalError, __VA_ARGS__); \
    throw ::std::logic_error{ "exception shoulh have been already thrown. Issue with XRN_THROW" }

///////////////////////////////////////////////////////////////////////////
/// \brief Same as assert from <cassert>
///////////////////////////////////////////////////////////////////////////
#define XRN_ASSERT(condition, ...) \
    ::xrn::Logger::get().massert((condition), __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Header-implementation
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
#include <xrn/Log/Logger.impl.hpp>
