#include "textedito.h"
#include "ui_textedito.h"
#include <qmessagebox.h>
#include <QHBoxLayout>
#include <qlabel.h>
#include <qpalette.h>

TextEdito::TextEdito(QWidget *parent) :
    QMainWindow(parent)
{
    CreateUI();
}

TextEdito::~TextEdito()
{

}

//创建界面
void TextEdito::CreateUI()
{
    setWindowTitle("TextEditor");
    textedit = new QTextEdit;
    setCentralWidget(textedit);

    menubar = new QMenuBar;//菜单栏

    filemenu = new QMenu("file(&F)");//文件菜单
    newfile = new QAction("newfile(&N)");//新建文件
    openfile = new QAction("openfile(&O)");//打开文件
    savefile = new QAction("savefile(&S)");//保存文件
    saveAsfile = new QAction("saveAsfile(&A)");//另存为文件
    quit = new QAction("quit(&Q)");//退出
    filemenu->addAction(newfile);
    filemenu->addAction(openfile);
    filemenu->addAction(savefile);
    filemenu->addAction(saveAsfile);
    filemenu->addAction(quit);

    editmenu = new QMenu("edit(&E)");//编辑菜单
    cut = new QAction("cut(&X)");
    copy = new QAction("copy(&C)");
    paste = new QAction("paste(&V)");
    editmenu->addAction(cut);
    editmenu->addAction(copy);
    editmenu->addAction(paste);

    formatmenu = new QMenu("format(&O)");//格式菜单
    autoChage = new QAction("auto(&A)");//自动换行
    font = new QAction("font(&F)");//字体
    formatmenu->addAction(autoChage);
    formatmenu->addAction(font);

    selectmenu = new QMenu("view(&V)");//查找菜单
    select = new QAction("select(&S)");
    selectmenu->addAction(select);
    connect(select,&QAction::triggered,this,&TextEdito::findText);


    helpmenu =new QMenu("help(&H)");//帮助菜单
    about = new QAction("about(&B)");
    helpmenu->addAction(about);
    connect(about,&QAction::triggered,this,&TextEdito::aboutText);


    menubar->addMenu(filemenu);
    menubar->addMenu(editmenu);
    menubar->addMenu(formatmenu);
    menubar->addMenu(selectmenu);
    menubar->addMenu(helpmenu);

    setMenuBar(menubar);
    resize(600,400);

    QHBoxLayout *hl = new QHBoxLayout;

    finddlg = new QDialog(this);
    finddlg->setWindowTitle("findbox");
    findBtn = new QPushButton("search");
    connect(findBtn,&QPushButton::clicked,this,&TextEdito::resultShow);

    findedit = new QLineEdit;
    QLabel *findlabel = new QLabel("word");
    hl->addWidget(findlabel);
    hl->addWidget(findedit);
    hl->addWidget(findBtn);
    finddlg->setLayout(hl);
    finddlg->hide();



}

void TextEdito::aboutText(){
    QMessageBox::about(this,"about","text editor of qt");
}

void TextEdito::findText(){
    finddlg->show();
}

void TextEdito::resultShow(){
    QString string = findedit->text();
    //使用查找函数查找指定字符串,查找方式为向后查找
    bool isfind = textedit->find(string,QTextDocument::FindBackward);
    if(isfind){
        //查找后高亮显示
        QPalette palette = textedit->palette();
        palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
        textedit->setPalette(palette);
    }
    else
        QMessageBox::information(this,"Atention","Didn't find anything.",QMessageBox::Ok);
}
//100分钟

