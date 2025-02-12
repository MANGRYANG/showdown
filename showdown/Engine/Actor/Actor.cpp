#include "PCH.h"
#include "Actor.h"
#include "CoreMinimal.h"

// Constructor initializes the actor's position and sets the default state.
Actor::Actor(const Vector2& initPosition)
    : position(initPosition)
    , isActive(true)
    , isExpired(false)
{
}

// Use default destructor since no dynamic resources are managed.
Actor::~Actor() = default;

// Update the actor state.
// This method can be overridden by derived classes to provide custom behavior.
void Actor::Update(float deltaTime)
{
    // TODO: Implement update logic.
    // For example: update movement, check collisions, etc.
}

// Render the actor.
// This method can be overridden by derived classes to draw custom visuals.
void Actor::Draw()
{
    // TODO: Implement draw logic.
}

// Set a new position for the actor.
void Actor::SetPosition(const Vector2& newPosition)
{
    position = newPosition;
}

// Retrieve the current position of the actor.
Vector2 Actor::GetPosition() const
{
    return position;
}
