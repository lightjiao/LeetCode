#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file

#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Program
{
public:
    int Invoke()
    {
        return 0;
    }
};

TEST_CASE("test")
{
    Program s;

    REQUIRE(s.Invoke() == 1);
    // REQUIRE(s.lengthOfLongestSubstring("abcabcbb") == 3);
    // REQUIRE(s.lengthOfLongestSubstring("pwwkew") == 3);
}