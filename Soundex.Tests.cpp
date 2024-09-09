#include <gtest/gtest.h>
#include "Soundex.h"

// Handled empty string
TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

// Handled Siggle string
TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

// Handled Duplicate string
TEST(SoundexTest, HandlesDuplicatesAndSkips) {
    EXPECT_EQ(generateSoundex("AABBBB"), "A100");
}

// Handled Mixed string
TEST(SoundexTest, HandlesMixedCase) {
    EXPECT_EQ(generateSoundex("McDonald"), "M235");
}

// Handled Non Alphabetic string
TEST(SoundexTest, HandlesNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("John123"), "J500");
}

// Handled Large string
TEST(SoundexTest, HandlesLongInput) {
    EXPECT_EQ(generateSoundex("Washington"), "W252");
}

// Handled Short string
TEST(SoundexTest, HandlesShortInput) {
    EXPECT_EQ(generateSoundex("Li"), "L000");
}
// Handled string
TEST(SoundexTest, ProducesExactlyFourCharacters) {
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
}

