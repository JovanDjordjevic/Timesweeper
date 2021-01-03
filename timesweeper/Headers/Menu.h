#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

namespace Ui
{
    class Menu;
}

class Help;
class Options;

class Menu : public QMainWindow
{
    Q_OBJECT
    public:
        explicit Menu(QWidget *parent = nullptr);

        static Help *help;
        static Options *options;

    private slots:
        void startButtonClicked();
        void quitButtonClicked();
        void optionsButtonClicked();
        void helpButtonClicked();

    private:
        Ui::Menu *ui;
};

#endif // MENU_H
