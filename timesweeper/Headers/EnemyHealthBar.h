#ifndef ENEMYHEALTHBAR_H
#define ENEMYHEALTHBAR_H

#include <QGraphicsRectItem>

class EnemyHealthBar : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    public:
        EnemyHealthBar(int width, int height);
        ~EnemyHealthBar();

        QGraphicsRectItem* barFrame;
        QGraphicsRectItem* bar;

    private:
        int m_width;
        int m_height;
};

#endif // ENEMYHEALTHBAR_H
