#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <QTimer>
#include <QtMultimedia/QMediaPlayer>

#include "Headers/Character.h"
#include "Headers/GunArm.h"

class PlayerCharacter : public Character
{
    Q_OBJECT
    public:
        PlayerCharacter (Character *parent = nullptr);
        ~PlayerCharacter();
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);
        void shootProjectile();
        void aimAtPoint(QPoint point);
        QPointF targetPoint;
        GunArm *gunArm;
        enum AimDirection
        {
            aimingLeft,
            aimingRight
        };
        AimDirection aimDirection;
        QPointF projectileStartPoint;
        QPointF shoulderPosition;// = QPointF(50, 70);

        void updateShoudlerPosition();

        GunArm *getGunArm() const;
        int getHealth() const;
        void increaseHealth();
        void decreaseHealth();

        void advance(int step) override;

signals:
        void enteredPortal();
        void startDialogue();
        void healthChanged();
        void playerIsDead();

    public slots:

    private slots:
        void jump();
        void walk();
        void detectCollision();

    private:
        qreal velocityX, velocityY = 1;
        qreal gravity = 0.5;
        bool isOnGround;
        QMediaPlayer *projectilesound;
        QPolygonF playerRectPoints;
        int health = 8;
        QGraphicsPixmapItem *pauseScreen;
        bool isPaused = false;
        bool canMove = false;
};

#endif // PLAYERCHARACTER_H
