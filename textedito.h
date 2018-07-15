#ifndef TEXTEDITO_H
#define TEXTEDITO_H

#include <QMainWindow>
#include <qtextedit.h>
#include <qmenubar.h>
#include <qmenu.h>
#include <qaction.h>
#include <qpushbutton.h>
#include <qdialog.h>
#include <qlineedit.h>

namespace Ui {
class TextEdito;
}

class TextEdito : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextEdito(QWidget *parent = 0);
    ~TextEdito();

private slots:
    void aboutText();
    void findText();
    void resultShow();
    void setFont();

private:
    void CreateUI();
    QTextEdit *textedit;//富文本编辑

    QMenuBar *menubar;//菜单栏
    QMenu *filemenu;//文件菜单
    QMenu *editmenu;//编辑菜单
    QMenu *formatmenu;//格式菜单
    QMenu *selectmenu;//查找菜单
    QMenu *helpmenu;//帮助菜单

    //文件菜单动作
    QAction *newfile;//新建文件
    QAction *openfile;//打开文件
    QAction *savefile;
    QAction *saveAsfile;
    QAction *quit;

    //编辑菜单动作
    QAction *cut;
    QAction *copy;
    QAction *paste;

    //格式菜单
    QAction *autoChage;//自动换行
    QAction *font;//字体

    //查找菜单
    QAction *select;
    QDialog *finddlg;
    QPushButton *findBtn;
    QLineEdit *findedit;


    //帮助菜单
    QAction *about;


};

#endif // TEXTEDITO_H
