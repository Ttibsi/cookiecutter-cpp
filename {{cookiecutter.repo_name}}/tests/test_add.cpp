#include "add.h"

{% if cookiecutter.test_framework == "gtest" -%}
#include "gtest/gtest.h"

TEST(AddTests, AddTwoNums) {
        EXPECT_EQ(add(35, 34), 0x45);
}
{% elif cookiecutter.test_framework == "catch2" -%}
#include <catch2/catch_test_macros.hpp>

TEST_CASE("add two nums", "[AddTests]") {
        REQUIRE(add(35, 34) == 0x45);
}
{% endif -%}
