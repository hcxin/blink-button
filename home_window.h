#pragma once

#include <windows.h>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QStyle>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QMainWindow>
#include "blink_thread.h"


/**
 * @author xinhaichen
 */
class HomeWindow : public QWidget {
Q_OBJECT
public:
    HomeWindow();
    void setupUi();

public slots:
    void buttonClick();
    void doBlink();

private:
    QPushButton *m_button;
    QPushButton *m_blinkButton;
    bool blink;
    long count;
};
