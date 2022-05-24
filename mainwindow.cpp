#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->add_button->setStyleSheet("background-color: green");
    ui->remove_button->setStyleSheet("background-color: red");
    connect(ui->add_button, SIGNAL(released()), this, SLOT(AddPlayer()));
    connect(ui->add_button, SIGNAL(released()), this, SLOT(PlayersList()));
    connect(ui->remove_button, SIGNAL(released()), this, SLOT(RemovePlayer()));
    connect(ui->remove_button, SIGNAL(released()), this, SLOT(PlayersList()));

    connect(ui->pushButton_play, SIGNAL(released()), this, SLOT(PlayPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddPlayer()
{
    players.push_back(ui->player_change->toPlainText());
}

void MainWindow::RemovePlayer()
{
    QString name = ui->player_change->toPlainText();
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i].GetName() == name)
        {
            players.erase(players.begin()+i);
            return;
        }
    }
}

void MainWindow::PlayersList()
{
    QString list;
    for(auto i: players)
    {
        list += i.GetName();
        list += ", ";
    }
    ui->players_list->setText(list);
}

void MainWindow::PlayPressed()
{
    static int i = 0;
    ui->player_name->setText(players[i].GetName());
    Color c = RandomColor(colours);
    ui->pushButton_play->setStyleSheet(QString::fromStdString("background-color: ") += c.GetName());
    ui->limb->setText(RandomPlace(c, players[i]));
    i = (i+1)%players.size();

}
