#include "Localization.cpp"
#include <gtest/gtest.h>


TEST(LocationTest, CheckCoords){
	location loc(51.05,19.94);
	
	EXPECT_DOUBLE_EQ(loc.getX(), 51.05);
    EXPECT_DOUBLE_EQ(loc.getY(), 19.94);
}

TEST(LocationTest, CheckUrl){
	location loc(1.5, 2.5);
	
	std::string url = loc.genUrl;
	std::string exp = "https://www.google.com/maps/search/?api=1&query=1.500000,2.500000";
	
	EXPECT_EQ(url,exp);	
}

TEST(LocationTest, MapaPrintsCorrectCoordinates) {
    location loc(10.5, 20.25);

    testing::internal::CaptureStdout();
    
    loc.mapa(); 
    
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10.5 20.25");
}
