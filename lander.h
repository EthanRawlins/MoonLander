#ifndef LANDER_H
#define LANDER_H

#include "uiDraw.h"
#include "point.h"
#include "velocity.h"
class Lander
{
private:
   bool alive;   
   bool landed;
   float fuel;
   Point lander;
   Velocity velocity;
   float grav;

public:
   Lander();
   Point getPoint() const;
   Velocity getVelocity() const;
   bool isAlive();
   bool isLanded();
   void applyGravity(float grav);
   void advance();
   void setAlive(bool ualive);
   void setLanded(bool ulanded);
   void applyThrustBottom();
   void applyThrustLeft();
   void applyThrustRight();
   void draw();
   bool canThrust();
   float getFuel();
   void setFuel(float ufuel);
};

#endif // LANDER_H
