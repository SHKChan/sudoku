#ifndef _SUDOKU_BLOCK_H_
#define _SUDOKU_BLOCK_H_

// 数独行政区域类
class CBlock  // 块
{
    static const int MAX_COUNT = 9; // 最大容量

  public:
    CBlock();
    bool isValid() const; // 是否仍有效
    bool isFull() const;  // 是否已填满
    void print() const; // 按行打印"| X |"
    void push_back(point_value_t *point); // 写入块中

  private:
    int _count; // 存入的网格指针数量
    point_value_t *_numbers[MAX_COUNT]; // 网格指针数组
};

#endif