#ifndef __SPRITE_H
#define __SPRITE_H

typedef struct Sprite Sprite;

#include <stdio.h>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include "buildmaptypes.h"

struct Sprite
{
    LONG x;
    LONG y;
    LONG z;
    SHORT cstat;
    SHORT picNum;
    SCHAR shade;
    CHAR pal;
    CHAR clipDist;
    CHAR filler;
    CHAR xRepeat;
    CHAR yRepeat;
    SCHAR xOffset;
    SCHAR yOffset;
    SHORT sectNum;
    SHORT statNum;
    SHORT angle;
    SHORT owner;
    SHORT xVel;
    SHORT yVel;
    SHORT zVel;
    SHORT loTag;
    SHORT hiTag;
    SHORT extra;
};

BOOL readSprite(FILE *file, Sprite *sprite);

BOOL writeSprite(FILE *file, const Sprite *sprite);

void parseSpriteNode(xmlNodePtr sprite_node, Sprite *sprite);

void printSprite(FILE *file, const Sprite *sprite);

#endif
