#include "robotka.h"
// ahoj
// Funkce setup se zavolá vždy po startu robota.
void setup() {
    rkConfig cfg;

    cfg.motor_max_power_pct = 100;
    cfg.motor_max_acceleration = 1000000;
    // Upravte nastavení, například:
    // cfg.motor_max_power_pct = 30; // limit výkonu motorů na 30%
    rkSetup(cfg);

    int lBlack = 2911;
    int rBlack = 2765;

    int black = 2000;
    int white = 1000;

    int leftWhite = 71;
    int rightWhite = 66;

    int lastState = 0;

    int distanceFront;
    int distanceLeft;

    int lookLeft;
    int lookRight;
    // Sem patří váš kód
    rkUltraMeasureAsync(1, [&](uint32_t distance_mm) {
        distanceFront = distance_mm;
        return true;
    });
    rkUltraMeasureAsync(2, [&](uint32_t distance_mm) {
        distanceLeft = distance_mm;
        return true;
    });
    while(rkButtonOn(true) == false){
    }
    while (rkButtonOn() == false) {
        
        while(rkIrLeft() >= black && rkIrRight() < black){
            lastState = 0;
            rkMotorsSetSpeed(100, 75);
            //delay(10);
        }
        while(rkIrRight() >= black && rkIrLeft() < black){
            lastState = 1;
            rkMotorsSetSpeed(75, 100);
            //delay(10);
        }
        if(rkIrRight() < black && rkIrLeft() < black){
            rkMotorsSetSpeed(100,100);
        }
        if(rkIrRight() <= white && rkIrLeft() <= white){
            if (lastState == 0)
            {
                while (rkIrRight() <= white)
                {
                    lastState = 3;
                    rkMotorsSetSpeed(40, 100);
                } 
                while (rkIrLeft() <= white)
                {
                    lastState = 3;
                    rkMotorsSetSpeed(100, 40);
                } 
            }
        }

        /*if (distanceFront <= 150)
        {
            rkMotorsSetSpeed(-50, 50); //look left
            delay(200);
            rkMotorsSetSpeed(0, 0); //wait for sensor
            delay(100);
            lookLeft = distanceFront;

            rkMotorsSetSpeed(50, -50); //look right (twice the left distance)
            delay(400);
            rkMotorsSetSpeed(0, 0); //wait for sensor
            delay(100);
            lookRight = distanceFront;

            rkMotorsSetSpeed(-50, 50); //set back to middle
            delay(200);

            if (lookLeft >= lookRight)
            {
                rkMotorsSetSpeed(-50, 50); //otoci se doleva
                delay(440);
                rkMotorsSetSpeed(50, 50); //jede rovne
                delay(440);
                rkMotorsSetSpeed(50, -50); //otoci se doprava
                delay(440);
                rkMotorsSetSpeed(50, 50); //jede rovne
                delay(440);
                rkMotorsSetSpeed(50, -50); //otoci se doprava
                delay(440);
                while (rkIrLeft() <= white || rkIrRight() <= white)
                {
                    rkMotorsSetSpeed(50, 50); //jede rovne
                }
            }
            else{
                rkMotorsSetSpeed(50, -50); //otoci se doprava
                delay(440);
                rkMotorsSetSpeed(50, 50); //jede rovne
                delay(440);
                rkMotorsSetSpeed(-50, 50); //otoci se doleva
                delay(440);
                rkMotorsSetSpeed(50, 50); //jede rovne
                delay(440);
                rkMotorsSetSpeed(-50, 50); //otoci se doleva
                delay(440);
                while (rkIrLeft() <= white || rkIrRight() <= white)
                {
                    rkMotorsSetSpeed(50, 50); //jede rovne
                }
            }
            
        }*/
        
        
        /*if (rkIrLeft() >= leftBlack) {
            rkMotorsSetSpeed(50, 25);
            delay(10);
            rkMotorsSetSpeed(50, 50);
        } else if (rkIrLeft() >= rightBlack) {
            rkMotorsSetSpeed(25, 50);
            delay(10);
            rkMotorsSetSpeed(50, 50);
        } else {
            rkMotorsSetSpeed(50, 50);
        }*/

    }

    /*
    int i = 0;
    int averageRight = rkIrRight();
    int averageLeft = rkIrLeft();
    int Left;
    int Right;

    while (i < 400) {
        Left = rkIrLeft();
        Right = rkIrRight();

        fmt::print("Left InfraRed: {}\n", Left);
        fmt::print("Right InfraRed: {}\n", Right);
        delay(30);
        i++;
        averageLeft = (averageLeft + Left) / 2;
        averageRight = (averageRight + Right) / 2;
    }
    fmt::print("Left average: {}\n", averageLeft);
    fmt::print("Right average: {}\n", averageRight);*/
}
