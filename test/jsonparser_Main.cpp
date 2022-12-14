#include "Log.h"
#include "json.h"

#ifdef JSONPARSER_TEST
#include "catch2/catch_session.hpp"
int main(int argc, char* argv[]) {
    logger::InitializeLogging();

    logger_info("Start unit testing...");

    // There must be exactly one instance
    Catch::Session session;

    // writing to session.configData() here sets defaults
    // this is the preferred way to set them

    int returnCode = session.applyCommandLine(argc, argv);
    if (returnCode != 0)  // Indicates a command line error
        return returnCode;

    // writing to session.configData() or session.Config() here
    // overrides command line args
    // only do this if you know you need to

    int numFailed = session.run();

    // numFailed is clamped to 255 as some unices only use the lower 8 bits.
    // This clamping has already been applied, so just return it here
    // You can also do any post run clean-up here
    return numFailed;
}
#endif
