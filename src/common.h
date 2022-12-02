#ifndef _SUDOKU_COMMON_H_
#define _SUDOKU_COMMON_H_

static const unsigned int UNSELECTED = 0;

enum class Difficulty : int
{
    EASY = 1,
    NORMAL,
    HARD
};

enum class State : int
{
    INITED = 0, // 是否初始化
    ERASED, // 抹除
};

using point_t = struct point_t {    // 坐标
    int x;
    int y;
};

using point_value_t = struct point_value_t {    // 网格
    int value;  // 值
    State state;    // 网格状态
};

class CPointSort
{
  public:
    bool operator()(const point_t &lhs, const point_t &rhs) const
    {
        if ((lhs.x == rhs.x) && (lhs.y == rhs.y))
            return false;
        else
            return true;
    }
};

#endif