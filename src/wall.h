#ifndef __WALL_H
#define __WALL_H

typedef struct Wall Wall;

#include <stdio.h>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include "buildmaptypes.h"

struct Wall
{
    LONG x;
    LONG y;
    SHORT point2;
    SHORT nextWall;
    SHORT nextSector;
    SHORT cstat;
    SHORT picNum;
    SHORT overPicNum;
    SCHAR shade;
    CHAR pal;
    CHAR xRepeat;
    CHAR yRepeat;
    CHAR xPanning;
    CHAR yPanning;
    SHORT loTag;
    SHORT hiTag;
    SHORT extra;
};

BOOL readWall(FILE *file, Wall *wall);

BOOL writeWall(FILE *file, const Wall *wall);

void parseWallNode(xmlNodePtr wall_node, Wall *wall);

void printWall(FILE *file, const Wall *wall);

#endif
