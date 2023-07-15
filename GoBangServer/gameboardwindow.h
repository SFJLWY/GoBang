﻿#ifndef GAMEBOARDWINDOW_H
#define GAMEBOARDWINDOW_H


#include "gameboard.h"
namespace Ui {
class GameBoardWindow;
}

class GameBoardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameBoardWindow(QWidget *parent = 0);
    ~GameBoardWindow();
    virtual void paintEvent(QPaintEvent*);//包括光标移动在内的绘制函数
    void mouseReleaseEvent(QMouseEvent* event);//鼠标释放事件处理
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动函数，用于实时返回鼠标位置

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_changeChessSkin_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::GameBoardWindow *ui;
    GameBoard gameBoard;
    int currentX;//释放光标对应的十字位置
    int currentY;//释放光标对应的十字位置
    int moveX;//移动光标对应的十字位置
    int moveY;//移动光标对应的十字位置
    int chessSkin;//棋子皮肤
    int backgroundSkin;//背景皮肤
    const int chessSize=30;//棋子贴图尺寸，用于调节棋子贴图大小
    bool mouseflag;//鼠标锁，用于隔离游戏中和未开始游戏的状态，避免未开始游戏显示光标
    QPixmap *whiteChess;//用于切换自定义光标
    QPixmap *blackChess;

};

#endif // GAMEWINDOW_H
