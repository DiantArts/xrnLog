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
    ::std::vector<int> array{
        1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,
        23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,
        46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,
        69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,
        92,93,94,95,96,97,98,99,100,
    };

    auto lambda{ [&](
        ::std::size_t threadIndex
        , ::std::size_t maxThreadNumber
    ){
        ::std::size_t beginIndex{ (threadIndex - 1) * array.size() / maxThreadNumber };
        ::std::size_t endIndex{ threadIndex * array.size() / maxThreadNumber };
        ::fmt::print("[{}, {}]\n", beginIndex, endIndex);
        for (::std::size_t i{ beginIndex }; i < endIndex; ++i) {
            ::fmt::print("{}\n", array[i]);
        }
    } };

    auto lambda1{ [&](
        ::std::size_t threadIndex
        , ::std::size_t maxThreadNumber
    ){
        ::std::size_t beginIndex{ (threadIndex - 1) * array.size() / maxThreadNumber };
        ::std::size_t endIndex{ threadIndex * array.size() / maxThreadNumber };

        endIndex -= (endIndex - beginIndex) / 2;

        ::fmt::print("[{}, {}]\n", beginIndex, endIndex);
        for (::std::size_t i{ beginIndex }; i < endIndex; ++i) {
            ::fmt::print("{}\n", array[i]);
        }
    } };

    auto lambda2{ [&](
        ::std::size_t threadIndex
        , ::std::size_t maxThreadNumber
    ){
        ::std::size_t beginIndex{ (threadIndex - 1) * array.size() / maxThreadNumber };
        ::std::size_t beginIndexSave{ beginIndex };
        ::std::size_t endIndex{ threadIndex * array.size() / maxThreadNumber };

        beginIndex += (endIndex - beginIndexSave) / 2;

        ::fmt::print("[{}, {}]\n", beginIndex, endIndex);
        for (::std::size_t i{ beginIndex }; i < endIndex; ++i) {
            ::fmt::print("{}\n", array[i]);
        }
    } };

    ::std::size_t numberOfThread{ 5 };
    for (::std::size_t i{ 0 }; i < numberOfThread; ++i) {
        lambda1(i + 1, numberOfThread);
    }
    for (::std::size_t i{ 0 }; i < numberOfThread; ++i) {
        lambda2(i + 1, numberOfThread);
    }

    return EXIT_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////
// auto main()
    // -> int
// {

    // XRN_LOG("not specified");
    // XRN_LOG(::xrn::Logger::Level::none, "none o");
    // XRN_LOG(::xrn::Logger::Level::success, "success");
    // XRN_LOG(::xrn::Logger::Level::note, "note");
    // XRN_LOG(::xrn::Logger::Level::info, "info");
    // XRN_LOG(::xrn::Logger::Level::trace, "trace");
    // XRN_LOG(::xrn::Logger::Level::debug, "debug");
    // XRN_LOG(::xrn::Logger::Level::debug);
    // XRN_DEBUG();
    // XRN_LOG(::xrn::Logger::Level::warning, "warning");
    // XRN_LOG(::xrn::Logger::Level::error, "error");
    // XRN_ASSERT(true, "true assert");
    // XRN_ASSERT(false, "false assert");
    // XRN_FATAL_SASSERT(true, "fatal sassert true");
    // XRN_LOG(::xrn::Logger::Level::fatalError, "fatalError");
    // XRN_FATAL_SASSERT(false, "false");
    // return EXIT_SUCCESS;
// }
