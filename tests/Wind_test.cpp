#include <gtest/gtest.h>
#include "Wind_inf.h"

TEST(WindInfTest, HandlesConversion) {
    Wind_inf wind(100.0, 0);

    EXPECT_NEAR(wind.conv(), 60.0, 0.001);
    

    EXPECT_NEAR(wind.conv(), 96.0, 0.001);
}


TEST(WindInfTest, ReturnsCorrectDirection) {
    EXPECT_EQ(Wind_inf(10.0, 45).kat(), "NE");
    EXPECT_EQ(Wind_inf(10.0, 90).kat(), "E");
    EXPECT_EQ(Wind_inf(10.0, 180).kat(), "S");
    EXPECT_EQ(Wind_inf(10.0, 270).kat(), "W");
}

TEST(WindInfTest, HandlesBoundaryConditions) {
    EXPECT_EQ(Wind_inf(10.0, 0).kat(), "N");
    EXPECT_EQ(Wind_inf(10.0, 21).kat(), "N");
    EXPECT_EQ(Wind_inf(10.0, 350).kat(), "N"); 
    EXPECT_EQ(Wind_inf(10.0, 67).kat(), "NE");
}

struct WindDirParam {
    int degrees;
    std::string expected;
};

class WindDirectionTest : public ::testing::TestWithParam<WindDirParam> {};

TEST_P(WindDirectionTest, CheckAllDirections) {
    WindDirParam param = GetParam();
    Wind_inf wind(10.0, param.degrees);
    EXPECT_EQ(wind.kat(), param.expected);
}

INSTANTIATE_TEST_SUITE_P(
    DirectionTests,
    WindDirectionTest,
    ::testing::Values(
        WindDirParam{40, "N"},
        WindDirParam{80, "NE"},
        WindDirParam{120, "E"},
        WindDirParam{160, "SE"},
        WindDirParam{210, "S"},
        WindDirParam{250, "SW"},
        WindDirParam{300, "W"},
        WindDirParam{340, "NW"}
    )
);
