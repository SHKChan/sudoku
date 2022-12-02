#ifndef _SUDOKU_COMMAND_H_
#define _SUDOKU_COMMAND_H_

#include <memory>
#include "common.h"

class CScene;
class CCommand  // 指令
{
public:
    CCommand(CScene* pOwner);
    CCommand(CScene *pOwner, const point_t &point, int preValue, int curValue);
    CCommand(const CCommand &);
    ~CCommand();

    bool execute(int nInputValue);  // 填入值
    void undo();    // 撤销上一步操作
    point_t getPoint() { return _stPoint; }
    int getPreValue() { return _nPreValue; }
    int getCurValue() { return _nCurValue; }
    void setPoint(const point_t &point) { _stPoint = point; }
    void setPreValue(int preValue) { _nPreValue = preValue; }
    void setCurValue(int curValue) { _nCurValue = curValue; }

private:
    CScene* _pOwner;    // 网格指针
    point_t _stPoint;   // 当前光标坐标
    int _nPreValue; // 旧值,用于undo
    int _nCurValue;  // actually the member is never used
};

#endif