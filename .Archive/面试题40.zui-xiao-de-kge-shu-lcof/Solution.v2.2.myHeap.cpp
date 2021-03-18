/**
输入整数数组 arr ，找出其中最小的 k
个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]


限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
 */
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class MyHeap
{
public:
    void push(int n)
    {
        heap.push_back(n);
        _adjustInsertElement();
    }

    void pop()
    {
        // 将堆顶置换到尾部并移除
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();

        _adjustRemoveElement(0);
    }

    int top()
    {
        return heap[0];
    }

    bool empty()
    {
        return heap.size() == 0;
    }

private:
    vector<int> heap;

    void _adjustInsertElement()
    {
        for (int i = heap.size() - 1; i > 0;) {
            if (heap[i] > heap[(i - 1) / 2]) {
                swap(heap[i], heap[(i - 1) / 2]);
            }
            else {
                break;
            }

            i = (i - 1) / 2;
        }
    }

    void _adjustRemoveElement(int root)
    {
        int l = root * 2 + 1;
        int r = root * 2 + 2;

        if (l > heap.size() - 1) {
            return;
        }

        // 没有右节点
        if (r > heap.size() - 1) {
            if (heap[l] > heap[root]) {
                swap(heap[l], heap[root]);
                return _adjustRemoveElement(l);
            }
        }
        // 有双子节点
        else {
            if (heap[l] > heap[r] && heap[l] > heap[root]) {
                swap(heap[l], heap[root]);
                return _adjustRemoveElement(l);
            }
            else if (heap[r] > heap[l] && heap[r] > heap[root]) {
                swap(heap[r], heap[root]);
                return _adjustRemoveElement(r);
            }
        }
    }
};

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        vector<int> result;
        if (k == 0) {
            return result;
        }

        MyHeap heap;
        for (int i = 0; i < k && i < arr.size(); i++) {
            heap.push(arr[i]);
        }

        for (int i = k; i < arr.size(); i++) {
            if (arr[i] < heap.top()) {
                heap.pop();
                heap.push(arr[i]);
            }
        }

        while (heap.empty() == false) {
            result.push_back(heap.top());
            heap.pop();
        }

        return result;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<int> arr;

    arr = {3, 2, 1};
    REQUIRE_THAT(s.getLeastNumbers(arr, 2),
                 Catch::Matchers::UnorderedEquals(vector<int>({1, 2})));

    arr = {0, 1, 2, 1};
    REQUIRE_THAT(s.getLeastNumbers(arr, 1),
                 Catch::Matchers::UnorderedEquals(vector<int>({0})));

    arr = {0, 0, 1, 3, 4, 5, 0, 7, 6, 7};
    REQUIRE_THAT(s.getLeastNumbers(arr, 9),
                 Catch::Matchers::UnorderedEquals(
                     vector<int>({0, 0, 0, 1, 3, 4, 5, 6, 7})));

    arr = {0, 0, 0, 2, 0, 5};
    REQUIRE_THAT(s.getLeastNumbers(arr, 0),
                 Catch::Matchers::UnorderedEquals(vector<int>({})));
}