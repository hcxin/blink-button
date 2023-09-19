#include "home_window.h"

HomeWindow::HomeWindow() {
}

/**
 * @author xinhaichen
 * 初始化窗口及控件
 */
void HomeWindow::setupUi() {
    setWindowTitle("闪烁");
    m_button = new QPushButton("开始闪烁");
    m_blinkButton = new QPushButton("button");
    QVBoxLayout *baseLayout = new QVBoxLayout();
    setLayout(baseLayout);
    baseLayout->addWidget(m_blinkButton, 1);
    baseLayout->addWidget(m_button,1);
    resize(200,200);
    BlinkThread *blinkThread = new BlinkThread;
    connect(m_button, SIGNAL(clicked()),this,SLOT(buttonClick()));
    connect(blinkThread, SIGNAL(blinkSignal()), this, SLOT(doBlink()));
    QObject::connect(blinkThread, SIGNAL(finished()), blinkThread, SLOT(deleteLater()));

    blink = false;
    blinkThread->start();
}

/**
 * 闪烁
 */
void HomeWindow::buttonClick() {
    count = 0;
    blink = !blink;
    if (blink){
        m_button->setText("停止闪烁");
    } else {
        m_button->setText("开始闪烁");
    }
}

void HomeWindow::doBlink() {
    if (blink) {
        qInfo("--doBlink--");
        count++;
        QString stylesheet;
        if (count %3==0){
             stylesheet = "background-color:#00AEEC;";
        } else if (count %3==1){
            stylesheet = "background-color:#B03060;";
        } else {
            stylesheet = "background-color:#03A89E;";
        }
        m_blinkButton->setStyleSheet(stylesheet);
    }
}
