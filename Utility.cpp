#ifndef __UTILITY__
#define __UTILITY__

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "catch.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print2DVector(vector<vector<int>>& a)
{
    for (auto&& n : a) {
        for (auto&& m : n) {
            printf("%5d", m);
        }
        cout << endl;
    }
}

/**
 * test vector<vector<int>> is equal or not
 */
bool vectorOfVectorEqual(vector<vector<int>>& a, vector<vector<int>>& b)
{
    if (a.size() != b.size()) {
        return false;
    }

    for (auto&& n : a) {
        sort(n.begin(), n.end());
    }
    for (auto&& n : b) {
        sort(n.begin(), n.end());
    }

    for (auto&& m : a) {
        bool equalFlag = false;
        for (auto&& n : b) {
            if (m == n) {
                equalFlag = true;
                break;
            }
        }
        if (equalFlag == false) {
            return false;
        }
    }

    for (auto&& m : b) {
        bool equalFlag = false;
        for (auto&& n : a) {
            if (m == n) {
                equalFlag = true;
                break;
            }
        }
        if (equalFlag == false) {
            return false;
        }
    }

    return true;
}

// TEST_CASE("test Utility.h")
// {
//     vector<vector<int>> a, b;
//     a = {
//         {1, 2, 3},
//         {3, 2, 1},
//     };

//     b = {
//         {3, 2, 1},
//         {1, 2, 3},
//     };
//     REQUIRE(vectorOfVectorEqual(a, b) == true);

//     a = {
//         {1, 2, 3},
//         {1, 2, 3},
//     };

//     b = {
//         {1, 2, 3},
//         {3, 2, 1},
//     };
//     REQUIRE(vectorOfVectorEqual(a, b) == true);

//     a = {
//         {1, 2, 3},
//         {1, 2, 3},
//     };

//     b = {
//         {1, 2, 3},
//         {3, 2, 2},
//     };
//     REQUIRE(vectorOfVectorEqual(a, b) == false);
// }

#endif