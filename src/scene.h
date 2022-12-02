#ifndef _SUDOKU_SCENE_H_
#define _SUDOKU_SCENE_H_

#include <iostream>
#include <vector>
#include "common.h"
#include "block.h"
#include "command.h"

//数独场景类
class CScene
{
  public:
    CScene(int index = 3);
    virtual ~CScene();

    void generate();  // 生成网格并填入随机值
    void show() const;  // 显示整个网格

    bool setCurValue(const int nCurValue, int& nLastValue); // 设置当前值,并保留旧值
    bool setPointValue(const point_t&, const int);  // 设置指定坐标的网格值
    point_t getCurPoint();  // 获取当前选中网格坐标

    void eraseRandomGrids(const int count); // 随机清除部分网格
    bool isComplete();  // 检查网格是否填满,且符合规则

    void play();
    void save(const char *filename);  // 保存
    void load(const char *filename);  // 加载

  private:
    void init(); // 将每个格子的指针放到block里面
    void setValue(const int); // 设置当前网格的值
    void setValue(const point_t &, const int);  // 设置网格的值(坐标, 值)
    void printUnderline(int line_no = -1) const;  // 打印下划线

private:
    int _max_column;  // 网格边长
    point_t _cur_point; // 当前选中网格坐标
    CBlock _column_block[9];  // 列块
    CBlock _row_block[9]; // 行块
    CBlock _xy_block[3][3]; // 3*3矩阵块
    point_value_t _map[81]; // 整个二维网格

    std::vector<CCommand> _vCommand;
};

#endif