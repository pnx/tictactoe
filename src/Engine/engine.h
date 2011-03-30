
#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "Graphics/Graphics.h"

typedef struct {
    int button;
    int state;
    int x;
    int y;
} MouseState;

class Engine
{
private:
    void HandleInput();
    void DoRender();
    void DoUpdate();
protected:
    bool isActive;
    MouseState mouse;
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
