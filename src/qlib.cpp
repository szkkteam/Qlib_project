//============================================================================
// Name        : qlib.cpp
// Author      : istvan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "qmatrix.h"
#include "list.h"
#include <iostream>
#include "test.h"

//using namespace QLib;
using namespace std;
using namespace Qlib;
using namespace Qlib::DL;
using namespace ECS;

void matrixTest(void)
{
    QMatrix<float> mat1(3, 3, 1.0);
    QMatrix<float> mat2(10, 10, 2.0);


    //QMatrix<float> mat3 = mat1 + mat2;

    float value = 0.0;

    for (unsigned int i=0; i<mat1.GetRows(); i++)
    {
      for (unsigned int j=0; j<mat1.GetCols(); j++)
      {
        mat1.Set(i,j, value++);
      }
    }
    for (unsigned int i=0; i<mat1.GetRows(); i++)
    {
      for (unsigned int j=0; j<mat1.GetCols(); j++)
      {
        cout << mat1(i,j) << ", ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
    QMatrix<float> mat3 = mat1.Transpose();

    for (unsigned int i=0; i<mat1.GetRows(); i++)
    {
      for (unsigned int j=0; j<mat1.GetCols(); j++)
      {
        cout << mat3(i,j) << ", ";
      }
      std::cout << std::endl;
    }
}

int valtozo1 = 0;
int valtozo2 = 10;
int valtozo3 = 20;
int valtozo4 = 30;
int valtozo5 = 40;

void listTest(void)
{

    List<int> list1;
    list1.PushFront(valtozo1);
    list1.PushFront(valtozo2);
    List<int>::Iterator item = list1.PushFront(valtozo3);
    list1.PushFront(valtozo4);
    list1.PushFront(valtozo5);

    for (List<int>::Iterator it = list1.Begin(); it != list1.End(); it++)
    {
    	cout << *it << endl;
    }

    cout << "size: " << list1.Size() << endl;

    valtozo1 = 0;
    valtozo2 = 100;
    valtozo3 = 200;
    valtozo4 = 300;
    valtozo5 = 400;

 //  list1.Erase(item);

    for (List<int>::Iterator it = list1.Begin(); it != list1.End(); it++)
    {
    	cout << *it << endl;
    }

}

struct Position
{
    Position(float x, float y) : x(x), y(y) {}
    Position() : x(0.f), y(0.f) {}

    float x;
    float y;
};

struct Rotation
{
    Rotation(float angle) : angle(angle) {}
    Rotation() : angle(0) {}
    float angle;
};

class GravitySystem : public EntitySystem
{
public:
    GravitySystem(float amount)
    {
        gravityAmount = amount;
    }

    virtual ~GravitySystem() {}

    virtual void tick(World* world, float deltaTime) override
    {
        world->each<Position>([&](Entity* ent, ComponentHandle<Position> position) {
            position->y += gravityAmount * deltaTime;
        });
    }

private:
    float gravityAmount;
};

int main() {

    World* world = World::createWorld();
    world->registerSystem(new GravitySystem(-9.8f));

    Entity* ent = world->create();
    ent->assign<Position>(10.f, 0.f); // assign() takes arguments and passes them to the constructor
    ent->assign<Position>(20.f, 10.f); // assign() takes arguments and passes them to the constructor
    ent->assign<Rotation>(35.f);

    ComponentHandle<Position> pos = ent->get<Position>();

    if (pos)
    {
        std::cout << "My position is " << pos->x << ", " << pos->y << std::endl;
    }
    else
    {
        std::cout << "Not valid" << endl;
    }


	// Test the matrix Class;
//	matrixTest();
	// Test the list class
	//listTest();

	return 0;
}
