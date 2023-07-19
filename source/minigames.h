#pragma once

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>

#include <filesystem.h>
#include <nds.h>
#include <nf_lib.h>

#include "enums.h"

void LoadBackground(const char name[]);
void DeleteBackground(const char name[]);

class Minigame
{
public:
    virtual void Load() = 0;
    virtual void Delete() = 0;
    virtual void Update(volatile int frame, uint32 keys) = 0;
    virtual bool IsComplete() = 0;
};

class ValveMinigame : public Minigame
{
private:
    const int MAX_VALVE_ROTATION = 512;
    const int VALVE_ROTATION_SPEED = 4;

    const u32 VALVE_SPRITE = 3;
    const char VALVE_SPRITE_NAME[13] = "sprite/valve";
    const char VALVE_BACKGROUND_NAME[18] = "bg/valve_minigame";

    uint32 lastStylusPos[2] = {0, 0};

    int rotation = 0;
    int targetRotation = 0;

    bool isComplete = false;
public:
    ValveMinigame();

    void Load();
    void Delete();
    void Update(volatile int frame, uint32 keys);
    bool IsComplete();
};