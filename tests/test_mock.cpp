#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "app.hpp"
using json = nlohmann::json;
using namespace std;


class MockWeather : public Interface {
public:
    MOCK_METHOD(string, fetch, (string url), (override));
};

TEST(TestDanych,TestUzyskiwaniaDanych){
    MockWeather mock; 
    Extract_data testObj("Krakow", mock);

    string fake_json = R"({
        "coord": {"lat": 50.06, "lon": 19.94},
        "wind": {"speed": 5.5, "deg": 180},
        "name": "Krakow"
    })";

    EXPECT_CALL(mock, fetch(::testing::_))
    .Times(1)
    .WillOnce(::testing::Return(fake_json));

    testObj.get();
    EXPECT_DOUBLE_EQ(testObj.x, 50.06);
    EXPECT_DOUBLE_EQ(testObj.y, 19.94);
    EXPECT_DOUBLE_EQ(testObj.v, 5.5);
    EXPECT_EQ(testObj.deg, 180);
}