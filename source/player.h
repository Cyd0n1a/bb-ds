#pragma once

#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <filesystem.h>
#include <nds.h>
#include <NEMain.h>
#include <nf_lib.h>

#include "map.h"
#include "enums.h"

class Player
{
private:
    const float SPEED = 0.125;
    const float TILE_SIZE = 0.05;

    NE_Model *model;
    NE_Material *material;

public:
    bool canMove = true;
    Direction facing = DOWN;
    bool walking = false;

    int tileX;
    int tileZ;
    int targetX;
    int targetZ;

    float x = 0;
    float y = 0.4;
    float z = 0;
    float rotation = (facing + 1) * (512 / 4);

    Player();

    int Load();
    void Move(Map& map);
    void Update(volatile int frame);
    void Translate(float x, float y, float z);
    Tile GetPlayerTile(Map& map);
    void PrintCoords(Map& map);
    void HandleInput(uint32 keys);
    void Draw();
    void Unload();
};