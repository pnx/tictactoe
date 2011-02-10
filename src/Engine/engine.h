
#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include <SDL.h>

typedef struct {
    int button;
    int state;
    int x;
    int y;
} MouseState;

class Engine
{
private:
    unsigned height;
    unsigned width;
    SDL_Surface* screen;

    void HandleInput();
    void DoRender();
    void DoUpdate();
protected:
    bool isActive;
    MouseState mouse;
public:
    Engine();
    ~Engine();
    void SetSize(int height, int width);
    void Start();
    /* Extended constructor */
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render(SDL_Surface *screen) = 0;
    virtual void Exit() = 0;
};

#endif /* ENGINE_ENGINE_H */
