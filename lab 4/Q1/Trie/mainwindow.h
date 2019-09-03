#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trie.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_SearchButton_clicked();
    void loadData();

private:
    Ui::MainWindow *ui;
    Trie dictionary;
};

#endif
