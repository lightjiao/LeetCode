#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

/**
 * 重载大根堆模板类，实现remove方法
 */
template <typename _Ty, typename _Container = std::vector<_Ty>,
          typename _Pr = std::less<typename _Container::value_type>>
class MyPriorityQueue : public std::priority_queue<_Ty, _Container, _Pr>
{
public:
    bool remove(const _Ty& value)
    {
        auto it = std::find(this->c.begin(), this->c.end(), value);

        if (it != this->c.end())
        {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }

        return false;
    }
};

/*
int main()
{
    // MyPriorityQueue<int, std::vector<int>, std::less<int>> q;
    MyPriorityQueue<int, std::vector<int>, std::greater<int>> q;
    // std::priority_queue<int, std::vector<int>, std::less<int>> q;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << q.top() << std::endl;
}
*/

/*
template<typename T>
template <typename _Ty, typename _Container = std::vector<_Ty>, typename _Pr =
std::less<typename _Container::value_type>> class custom_priority_queue : public
std::priority_queue<_Ty,  class std::vector<_Ty>, std::less<typename
_Container::value_type>>
{
  public:

      bool remove(const _Ty& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
       }
       else {
        return false;
       }
 }
};
*/