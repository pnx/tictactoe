
#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "Graphics/Graphics.h"
#include "Input/Mouse.h"

class Engine
{
private:
    long LastTick;

    void Tick();
    void HandleInput();
    void DoRender();
    void DoUpdate();
protected:
    bool isActive;
    /* If the engine is running in fixed time step mode */
    bool FixedStep;
    unsigned FixedStepInterval;
    Graphics *graphics;
public:
    Engine();
    ~Engine();

    void Start();
    /* Extended constructor */
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Exit() = 0;
};

#endif /* ENGINE_ENGINE_H */
