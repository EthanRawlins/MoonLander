#include "point.h"
#include "velocity.h"
#include "lander.h"
#include "game.h"
#include "ground.h"
#include <iostream>
#include <sstream>
using namespace std;

Point Lander :: getPoint() const
{
   return lander;
}
Velocity Lander :: getVelocity() const
{
   return velocity;
}

bool Lander :: isAlive()
{
   /*if (alive)
   {
      return true;
   }
   else
   {
      return false;
   }*/
   return alive;
}

bool Lander :: isLanded()
{
   /*if(landed)
   {
      return true;
   }
   else
   {
      return false;
   }*/
   return landed;
}

void Lander :: applyGravity(float grav)
{
   if (alive && !landed)
   {
      velocity.setyvelocity(velocity.getDy() - grav);
   }
}

void Lander :: advance()
{
   lander.addY(velocity.getDy());
   lander.addX(velocity.getDx());
}
void Lander :: setAlive(bool ualive)
{
   alive = ualive;
}

void Lander :: setLanded(bool ulanded)
{
   landed = ulanded;
}

void Lander :: applyThrustBottom()
{
   if (canThrust() && fuel >= 3)
   {
      velocity.setyvelocity(velocity.getDy() + 0.3);
      fuel--;
      fuel--;
      fuel--;
   }
}

void Lander :: applyThrustLeft()
{
   if (canThrust())
   {
      velocity.setxvelocity(velocity.getDx() + 0.1);
      fuel--;
   }
}

void Lander :: applyThrustRight()
{
   if (canThrust())
   {
      
      velocity.setxvelocity(velocity.getDx() - 0.1);
      fuel--;
   }
}

void Lander :: draw()
{
   drawLander(lander);
}

bool Lander :: canThrust()
{
   if (fuel > 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

float Lander :: getFuel()
{
   return fuel;
}

void Lander :: setFuel(float ufuel)
{
   fuel = ufuel;
}

Lander :: Lander()
{
   grav = 0;
   alive = 1;
   landed = 0;
   fuel = 500;
}
