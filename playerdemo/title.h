﻿/*
 * @file 	title.h
 * @date 	2018/01/07 11:13
 *
 * @author 	itisyang
 * @Contact	itisyang@gmail.com
 *
 * @brief 	播放器标题栏
 * @note
 */
#ifndef MAINWIDTITLE_H
#define MAINWIDTITLE_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class Title;
}

class Title : public QWidget
{
    Q_OBJECT

public:
    explicit Title(QWidget *parent = 0);
    ~Title();
    bool InitUi();
private:
    void paintEvent(QPaintEvent *event);
    //双击
    void mouseDoubleClickEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void ChangeMovieNameShow();
public slots:
	/**
	 * @brief	改变最大化按钮显示图标
	 * 
	 * @param	bIfMax 主窗口是否是最大化状态
	 * @note 	
	 */
    void OnChangeMaxBtnStyle(bool bIfMax);
    void OnPlay(QString strMovieName);
    void OnStopFinished();
signals:
    void SigCloseBtnClicked();	//< 点击关闭按钮
    void SigMinBtnClicked();	//< 点击最小化按钮
    void SigMaxBtnClicked();	//< 点击最大化按钮
    void SigDoubleClicked();	//< 双击标题栏

    void SigFullScreenBtnClicked(); ///< 点击全屏按钮
private:
    Ui::Title *ui;

    QString m_strMovieName;
};

#endif // MAINWIDTITLE_H
