// Copyright (c) 2023 Sri Lakshmi Kanthan P
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

// Google test header files
#include <gtest/gtest.h>

// Local header files
#include "tests/network/packets/DiscoveryPacket.hpp"
#include "tests/network/packets/InvalidRequest.hpp"
#include "tests/network/packets/SyncingPacket.hpp"

/**
 * @brief Testing the clipbirdesk Application
 */
auto main(int argc, char **argv) -> int {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
