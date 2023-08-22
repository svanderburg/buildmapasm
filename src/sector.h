#ifndef __SECTOR_H
#define __SECTOR_H

typedef struct Sector Sector;

#include <stdio.h>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include "buildmaptypes.h"

struct Sector
{
    SHORT wallPtr;
    SHORT wallNum;
    LONG ceilingZ;
    LONG floorZ;
    SHORT ceilingStat;
    SHORT floorStat;
    SHORT ceilingPicNum;
    SHORT ceilingHeiNum;
    SCHAR ceilingShade;
    CHAR ceilingPal;
    CHAR ceilingXPanning;
    CHAR ceilingYPanning;
    SHORT floorPicNum;
    SHORT floorHeiNum;
    SCHAR floorShade;
    CHAR floorPal;
    CHAR floorXPanning;
    CHAR floorYPanning;
    CHAR visibility;
    CHAR filler;
    SHORT loTag;
    SHORT hiTag;
    SHORT extra;
};

BOOL readSector(FILE *file, Sector *sector);

BOOL writeSector(FILE *file, const Sector *sector);

void parseSectorNode(xmlNodePtr sector_node, Sector *sector);

void printSector(FILE *file, const Sector *sector);

#endif
