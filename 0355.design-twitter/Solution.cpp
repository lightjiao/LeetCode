/**
设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：

postTweet(userId, tweetId): 创建一条新的推文
getNewsFeed(userId):
检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
follow(followerId, followeeId): 关注一个用户
unfollow(followerId, followeeId): 取消关注一个用户

示例:

Twitter twitter = new Twitter();

// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
twitter.postTweet(1, 5);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
twitter.getNewsFeed(1);

// 用户1关注了用户2.
twitter.follow(1, 2);

// 用户2发送了一个新推文 (推文id = 6).
twitter.postTweet(2, 6);

// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
// 推文id6应当在推文id5之前，因为它是在5之后发送的.
twitter.getNewsFeed(1);

// 用户1取消关注了用户2.
twitter.unfollow(1, 2);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
// 因为用户1已经不再关注用户2.
twitter.getNewsFeed(1);

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-twitter
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
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Twitter
{
private:
    vector<pair<int, int>> allPost;

    map<int, unordered_set<int>> follows;

public:
    /** Initialize your data structure here. */
    Twitter()
    {
        allPost = {};
        follows = {};
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        allPost.push_back({userId, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
     * in the news feed must be posted by users who the user followed or by the
     * user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        auto userFollow = follows[userId];
        userFollow.emplace(userId);

        vector<int> result;
        for (int i = allPost.size() - 1; i >= 0; i--) {
            auto n = allPost[i];
            if (userFollow.count(n.first) > 0) {
                result.push_back(n.second);
            }
            if (result.size() == 10) {
                break;
            }
        }

        return result;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a
     * no-op. */
    void follow(int followerId, int followeeId)
    {
        follows[followerId].emplace(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be
     * a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
TEST_CASE("contains sample")
{
    // sample of catch2 contains
    vector<int> a;
    vector<int> b{5};
    auto        contains = Catch::Contains(b);

    a = {5};
    REQUIRE_THAT(a, contains);
    a = {5, 6};
    REQUIRE_THAT(a, contains);
    a = {4, 5};
    REQUIRE_THAT(a, contains);
}

TEST_CASE("test")
{
    Twitter     twitter;
    vector<int> result;

    // 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
    twitter.postTweet(1, 5);

    // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
    REQUIRE(twitter.getNewsFeed(1) == vector<int>{5});

    // 用户1关注了用户2.
    twitter.follow(1, 2);

    // 用户2发送了一个新推文 (推文id = 6).
    twitter.postTweet(2, 6);

    // 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
    // 推文id6应当在推文id5之前，因为它是在5之后发送的.
    REQUIRE(twitter.getNewsFeed(1) == vector<int>{6, 5});

    // 用户1取消关注了用户2.
    twitter.unfollow(1, 2);

    // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
    // 因为用户1已经不再关注用户2.
    REQUIRE(twitter.getNewsFeed(1) == vector<int>{5});
}
