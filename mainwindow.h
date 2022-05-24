#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <array>
#include <vector>
#include "player.h"
#include "color.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<Player> players;
    std::array<Color,C> colours = {"Red", "Green", "Yellow", "Blue"};

private slots:
    void AddPlayer();
    void RemovePlayer();
    void PlayPressed();
    void PlayersList();

};

