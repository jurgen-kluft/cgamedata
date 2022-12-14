#include "cbase/c_target.h"
#include "cbase/c_allocator.h"
#include "cbase/c_runes.h"
#include "cgamedata/c_object.h"
#include "cgamedata/metatest.h"
#include "cfile/c_file.h"

#include "cunittest/cunittest.h"

using namespace ncore;
extern ncore::alloc_t* gTestAllocator;

UNITTEST_SUITE_BEGIN(gamedata)
{
    UNITTEST_FIXTURE(main)
    {
        UNITTEST_FIXTURE_SETUP() {}
        UNITTEST_FIXTURE_TEARDOWN() {}

        UNITTEST_TEST(create)
        {
            crunes_t      filename("metatest.cdd");
            file_handle_t fh = file_open(filename, FILE_MODE_READ);
            s32 dataSize = (s32)file_size(fh);
            u8* data = (u8*)gTestAllocator->allocate(dataSize);
            file_read(fh, data, dataSize);

            ngd::TestRoot* root = (ngd::TestRoot*)data;
        }
    }
}
UNITTEST_SUITE_END