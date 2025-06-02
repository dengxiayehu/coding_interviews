#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>

#include "config.h"

int main(int argc, char* argv[]) {
    std::cout << "build_time: " << BUILD_TIME << ", commit_id: " << COMMIT_ID << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);

    int ret = RUN_ALL_TESTS();

    return ret;
}
