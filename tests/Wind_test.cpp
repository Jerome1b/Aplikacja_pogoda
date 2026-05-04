#include <gtest/gtest.h>
#include "Wind_inf.h" // Załóżmy, że kod klasy jest w tym pliku

// Testowanie konwersji jednostek
TEST(WindInfTest, HandlesConversion) {
    // Inicjalizacja: v = 100.0
    Wind_inf wind(100.0, 0);

    // Pierwsza konwersja: km -> nm (100 * 0.6 = 60.0)
    EXPECT_NEAR(wind.conv(), 60.0, 0.001);
    
    // Druga konwersja: nm -> km (60 * 1.6 = 96.0)
    // Zauważ, że 0.6 * 1.6 = 0.96, więc wartość nie wraca idealnie do 100
    EXPECT_NEAR(wind.conv(), 96.0, 0.001);
}

// Testowanie kierunków świata (metoda kat)
TEST(WindInfTest, ReturnsCorrectDirection) {
    // Testowanie środka przedziałów
    EXPECT_EQ(Wind_inf(10.0, 45).kat(), "NE");
    EXPECT_EQ(Wind_inf(10.0, 90).kat(), "E");
    EXPECT_EQ(Wind_inf(10.0, 180).kat(), "S");
    EXPECT_EQ(Wind_inf(10.0, 270).kat(), "W");
}

TEST(WindInfTest, HandlesBoundaryConditions) {
    // Północ (N) - zakres od ok. 338 do 22 stopni
    EXPECT_EQ(Wind_inf(10.0, 0).kat(), "N");
    EXPECT_EQ(Wind_inf(10.0, 21).kat(), "N");
    EXPECT_EQ(Wind_inf(10.0, 350).kat(), "N"); // switch default/ostatni return

    // Przejście na NE (22 stopnie to granica: (22-22)/45 = 0 -> N, 23-22/45 = 0 -> N)
    // Dopiero przy deg = 67 zacznie się NE w Twoim switchu: (67-22)/45 = 1
    EXPECT_EQ(Wind_inf(10.0, 67).kat(), "NE");
}

// Test parametrzyowany dla wielu kierunków (opcjonalnie, dla czystości kodu)
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
