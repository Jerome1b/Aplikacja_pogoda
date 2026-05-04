#include "Localization.cpp"
#include <gtest/gtest.h>

TEST(LocationTest, MapaPrintsCorrectCoordinates) {
    location loc(10.5, 20.25);

    testing::internal::CaptureStdout();
    
    loc.mapa(); 
    
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10.5 20.25");
}
