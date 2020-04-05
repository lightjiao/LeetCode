/**
请你为
最不经常使用（LFU）缓存算法设计并实现数据结构。它应该支持以下操作：get 和 put。

get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
put(key, value) -
如果键不存在，请设置或插入值。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。
在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除
最近 最少使用的键。 「项的使用次数」就是自插入该项以来对其调用 get 和 put
函数的次数之和。使用次数会在对应项被移除后置为 0 。


进阶：
你是否可以在 O(1) 时间复杂度内执行两项操作？
 

示例：

LFUCache cache = new LFUCache( 2  ); // / capacity (缓存容量)

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回 1
cache.put(3, 3);    // 去除 key 2
cache.get(2);       // 返回 -1 (未找到key 2)
cache.get(3);       // 返回 3
cache.put(4, 4);    // 去除 key 1
cache.get(1);       // 返回 -1 (未找到 key 1)
cache.get(3);       // 返回 3
cache.get(4);       // 返回 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lfu-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.cpp"
#include "../VV.cpp"
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LFUCache
{
public:
    LFUCache(int capacity)
    {
        _m_capacity = capacity;
    }

    int get(int key)
    {
        if (_m_data.empty()) {
            return -1;
        }

        auto pos = _m_data.find(key);
        if (pos == _m_data.end()) {
            return -1;
        }

        _m_count[key]++;
        _m_time[key] = _m_timeNum;
        _m_timeNum++;

        return _m_data[key];
    }

    void put(int key, int value)
    {
        if (_m_capacity == 0) {
            return;
        }

        // capacity == size
        // key 不存在
        if (_m_data.size() == _m_capacity &&
            _m_data.find(key) == _m_data.end()) {
            // 移除老旧的 key
            vector<int> minCount;
            for (auto&& n : _m_count) {
                if (minCount.size() == 0) {
                    minCount.push_back(n.first);
                    continue;
                }

                if (n.second < _m_count[minCount[0]]) {
                    minCount = {n.first};
                }
                if (n.second == _m_count[minCount[0]]) {
                    minCount.push_back(n.first);
                }
            }

            int removedKey = minCount[0];
            for (auto&& n : minCount) {
                if (_m_time[n] < _m_time[removedKey]) {
                    removedKey = n;
                }
            }

            _m_data.erase(removedKey);
            _m_count.erase(removedKey);
            _m_time.erase(removedKey);
        }

        // 插入新key
        _m_data[key] = value;
        _m_count[key]++;
        _m_time[key] = _m_timeNum;
        _m_timeNum++;

        return;
    }

private:
    int _weak_key;  // 待移除的key --> 保证O(1) 的实现

    int _m_capacity;     // 容量
    int _m_timeNum = 0;  // 记录时间, 每次 + 1

    unordered_map<int, int> _m_data;
    unordered_map<int, int> _m_count;
    unordered_map<int, int> _m_time;
};

TEST_CASE("test")
{
    LFUCache cache(2);  // capacity (缓存容量)

    cache.put(1, 1);
    cache.put(2, 2);
    REQUIRE(cache.get(1) == 1);   // 返回 1
    cache.put(3, 3);              // 去除 key 2
    REQUIRE(cache.get(2) == -1);  // 返回 -1 (未找到key 2)
    REQUIRE(cache.get(3) == 3);   // 返回 3
    cache.put(4, 4);              // 去除 key 1
    REQUIRE(cache.get(1) == -1);  // 返回 -1 (未找到 key 1)
    REQUIRE(cache.get(3) == 3);   // 返回 3
    REQUIRE(cache.get(4) == 4);   // 返回 4
}

TEST_CASE("test2")
{
    LFUCache cache(2);  // capacity (缓存容量)

    cache.put(3, 1);
    cache.put(2, 1);
    cache.put(2, 2);
    cache.put(4, 4);
    REQUIRE(cache.get(2) == 2);  // 返回 1
}