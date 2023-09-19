#include <QApplication>
#include "home_window.h"

/**
 * @author xinhaichen
 * 程序入口
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    //设置应用图标
    QIcon icon = QApplication::style()->standardIcon(QStyle::SP_TitleBarMenuButton);
    app.setWindowIcon(icon);
    //创建窗口并显示
    HomeWindow *homeWindow = new HomeWindow;
    homeWindow->setupUi();
    homeWindow->show();
    return QApplication::exec();
}
