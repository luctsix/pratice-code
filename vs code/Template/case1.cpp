/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去
除评委中最低分，取平均分。
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分
打分存到deque容器中
//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最
低分
//4. deque容器遍历一遍，累加分数，累加分数/d.size()
//5. person.score = 平均分
*/
#include <iostream>
#include <string>
#include <vector>

class Parter{
public:
    Parter(int score){this->score = score;}
    int score;
};
