#ifndef __MAP_H
#define __MAP_H

typedef struct Map Map;

#include <stdio.h>
#include "buildmaptypes.h"
#include "sector.h"
#include "wall.h"
#include "sprite.h"

struct Map
{
    ULONG mapVersion;
    ULONG posx;
    ULONG posy;
    ULONG posz;
    USHORT angle;
    USHORT currentSectorNumber;
    USHORT numOfSectors;
    Sector *sectors;
    USHORT numOfWalls;
    Wall *walls;
    USHORT numOfSprites;
    Sprite *sprites;
};

BOOL readMapFd(FILE *file, Map *map);

BOOL readMap(const char *filename, Map *map);

BOOL readMapFromXML(const char *filename, Map *map);

BOOL writeMapFd(FILE *file, const Map *map);

BOOL writeMap(const char *filename, const Map *map);

void clearMap(Map *map);

void printMapFd(FILE *file, const Map *map);

BOOL printMap(const char *filename, const Map *map);

#endif
