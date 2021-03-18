#ifndef __2DVECTOR__
#define __2DVECTOR__

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "catch.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class VV
{
public:
    template <typename T>
    static void print(vector<vector<T>>& a)
    {
        for (auto&& n : a) {
            cout << " [ ";
            for (int i = 0; i < n.size(); i++) {
                cout << setw(6) << n[i];
                if (i != n.size() - 1) { cout << ", "; }
            }

            cout << " ] " << endl;
        }
    }

    /**
     * 对二级vector排序后再做比较
     */
    template <typename T>
    static bool equal(vector<vector<T>>& a, vector<vector<T>>& b)
    {
        for (auto&& n : a) {
            sort(n.begin(), n.end());
        }
        for (auto&& n : b) {
            sort(n.begin(), n.end());
        }

        return same(a, b);
    }

    /**
     * 对二级vector不做排序，比较是否相等
     * 用于比较生成的序列(premutations)
     */
    template <typename T>
    static bool same(vector<vector<T>>& a, vector<vector<T>>& b)
    {
        if (a.size() != b.size()) { return false; }

        for (auto&& m : a) {
            bool equalFlag = false;
            for (auto&& n : b) {
                if (m == n) {
                    equalFlag = true;
                    break;
                }
            }
            if (equalFlag == false) { return false; }
        }

        for (auto&& m : b) {
            bool equalFlag = false;
            for (auto&& n : a) {
                if (m == n) {
                    equalFlag = true;
                    break;
                }
            }
            if (equalFlag == false) { return false; }
        }

        return true;
    }
};

#endif