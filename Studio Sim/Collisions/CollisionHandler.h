#pragma once
#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "Collider.h"

//Monitors collisions between colliders and resolve them
class CollisionHandler
{
public:
    CollisionHandler() = default;

private:
    std::vector<Collider*> m_colliders;
public:
    //Specify which colliders to monitor

    void AddCollider(std::shared_ptr<Collider> collider);
    void AddCollider(std::vector<std::shared_ptr<Collider>>& colliders);

private:
    bool BoxToBox(BoxCollider* box1, BoxCollider* box2);
    bool CircleToBox(CircleCollider* circle, BoxCollider* box);
    bool CircleToCircle(CircleCollider* circle1, CircleCollider* circle2);
    bool PointToBox(Vector2f point, BoxCollider* box);
    bool PointToCircle(Vector2f point, CircleCollider* circle);
    //Check for collisions between any type of collider
    bool CollisionCheck(Collider* collider1, Collider* collider2);

private:
    void CollisionCheckAll();

    void Resolution(Collider* collider1, Collider* collider2);

public:
    void Update();
};

#endif