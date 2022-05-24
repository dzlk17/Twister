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
    /**
     * @brief players Vector containing players
     */
    std::vector<Player> players;
    /**
     * @brief colours Array containing colors of places on the board
     */
    std::array<Color,C> colours = {"Red", "Green", "Yellow", "Blue"};

private slots:
    /**
     * @brief AddPlayer Function adding new player to game
     */
    void AddPlayer();
    /**
     * @brief RemovePlayer Function removing player from game if he failes.
     */
    void RemovePlayer();
    /**
     * @brief PlayPressed Start one round of game(for one player).
     */
    void PlayPressed();
    /**
     * @brief PlayersList Function printing list of current players.
     */
    void PlayersList();

};

