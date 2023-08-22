#include "map.h"
#include <stdlib.h>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include "io.h"

static BOOL readSectors(FILE *file, Map *map)
{
    USHORT i;

    map->sectors = (Sector*)malloc(map->numOfSectors * sizeof(Sector));

    for(i = 0; i < map->numOfSectors; i++)
    {
         Sector *sector = &map->sectors[i];
         if(!readSector(file, sector))
            return FALSE;
    }

    return TRUE;
}

static BOOL readWalls(FILE *file, Map *map)
{
    USHORT i;

    map->walls = (Wall*)malloc(map->numOfWalls * sizeof(Wall));

    for(i = 0; i < map->numOfWalls; i++)
    {
        Wall *wall = &map->walls[i];
        if(!readWall(file, wall))
            return FALSE;
    }

    return TRUE;
}

static BOOL readSprites(FILE *file, Map *map)
{
    USHORT i;

    map->sprites = (Sprite*)malloc(map->numOfSprites * sizeof(Sprite));

    for(i = 0; i < map->numOfSprites; i++)
    {
        Sprite *sprite = &map->sprites[i];
        if(!readSprite(file, sprite))
            return FALSE;
    }

    return TRUE;
}

static void makeEmptyMap(Map *map)
{
    map->numOfSectors = 0;
    map->sectors = NULL;
    map->numOfWalls = 0;
    map->walls = NULL;
    map->numOfSprites = 0;
    map->sprites = NULL;
}

BOOL readMapFd(FILE *file, Map *map)
{
    makeEmptyMap(map);

    return (readULong(file, &map->mapVersion)
        && readULong(file, &map->posx)
        && readULong(file, &map->posy)
        && readULong(file, &map->posz)
        && readUShort(file, &map->angle)
        && readUShort(file, &map->currentSectorNumber)
        && readUShort(file, &map->numOfSectors)
        && readSectors(file, map)
        && readUShort(file, &map->numOfWalls)
        && readWalls(file, map)
        && readUShort(file, &map->numOfSprites)
        && readSprites(file, map));
}

BOOL readMap(const char *filename, Map *map)
{
    FILE *file = fopen(filename, "rb");

    if(file == NULL)
        return FALSE;
    else
    {
        BOOL status = readMapFd(file, map);
        fclose(file);
        return status;
    }
}

static void parseSectorsNode(xmlNodePtr sectors_node, Map *map)
{
    if(sectors_node->type == XML_ELEMENT_NODE && xmlStrcmp(sectors_node->name, (xmlChar*) "sectors") == 0)
    {
        xmlNodePtr child_element = sectors_node->children;
        USHORT i = 0;

        map->sectors = (Sector*)malloc(map->numOfSectors * sizeof(Sector));

        while(child_element != NULL)
        {
            if(child_element->type == XML_ELEMENT_NODE)
            {
                if(xmlStrcmp(child_element->name, (xmlChar*) "sector") == 0)
                {
                    parseSectorNode(child_element, &map->sectors[i]);
                    i++;
                }
            }

            child_element = child_element->next;
        }
    }
}

static void parseWallsNode(xmlNodePtr walls_node, Map *map)
{
    if(walls_node->type == XML_ELEMENT_NODE && xmlStrcmp(walls_node->name, (xmlChar*) "walls") == 0)
    {
        xmlNodePtr child_element = walls_node->children;
        USHORT i = 0;

        map->walls = (Wall*)malloc(map->numOfWalls * sizeof(Wall));

        while(child_element != NULL)
        {
            if(child_element->type == XML_ELEMENT_NODE)
            {
                if(xmlStrcmp(child_element->name, (xmlChar*) "wall") == 0)
                {
                    parseWallNode(child_element, &map->walls[i]);
                    i++;
                }
            }

            child_element = child_element->next;
        }
    }
}

static void parseSpritesNode(xmlNodePtr sprites_node, Map *map)
{
    if(sprites_node->type == XML_ELEMENT_NODE && xmlStrcmp(sprites_node->name, (xmlChar*) "sprites") == 0)
    {
        xmlNodePtr child_element = sprites_node->children;
        USHORT i = 0;

        map->sprites = (Sprite*)malloc(map->numOfSprites * sizeof(Sprite));

        while(child_element != NULL)
        {
            if(child_element->type == XML_ELEMENT_NODE)
            {
                if(xmlStrcmp(child_element->name, (xmlChar*) "sprite") == 0)
                {
                    parseSpriteNode(child_element, &map->sprites[i]);
                    i++;
                }
            }

            child_element = child_element->next;
        }
    }
}

static void parseMapNode(xmlNodePtr map_node, Map *map)
{
    xmlNodePtr child_element = map_node->children;

    while(child_element != NULL)
    {
        if(child_element->type == XML_ELEMENT_NODE)
        {
            if(xmlStrcmp(child_element->name, (xmlChar*) "mapVersion") == 0)
                map->mapVersion = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "posx") == 0)
                map->posx = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "posy") == 0)
                map->posy = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "posz") == 0)
                map->posz = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "angle") == 0)
                map->angle = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "currentSectorNumber") == 0)
                map->currentSectorNumber = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "numOfSectors") == 0)
                map->numOfSectors = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "sectors") == 0)
                parseSectorsNode(child_element, map);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "numOfWalls") == 0)
                map->numOfWalls = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "walls") == 0)
                parseWallsNode(child_element, map);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "numOfSprites") == 0)
                map->numOfSprites = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "sprites") == 0)
                parseSpritesNode(child_element, map);
        }

        child_element = child_element->next;
    }
}

BOOL readMapFromXML(const char *filename, Map *map)
{
    xmlDocPtr doc = xmlReadFile(filename, NULL, 0);
    xmlNodePtr map_node;

    if(doc == NULL)
    {
        xmlCleanupParser();
        return FALSE;
    }

    makeEmptyMap(map);
    map_node = doc->children;

    if(map_node->type == XML_ELEMENT_NODE && xmlStrcmp(map_node->name, (xmlChar*) "map") == 0)
        parseMapNode(map_node, map);

    xmlFreeDoc(doc);
    xmlCleanupParser();

    return TRUE;
}

static BOOL writeSectors(FILE *file, const Map *map)
{
    USHORT i;

    for(i = 0; i < map->numOfSectors; i++)
    {
         Sector *sector = &map->sectors[i];
         if(!writeSector(file, sector))
            return FALSE;
    }

    return TRUE;
}

static BOOL writeWalls(FILE *file, const Map *map)
{
    USHORT i;

    for(i = 0; i < map->numOfWalls; i++)
    {
        Wall *wall = &map->walls[i];
        if(!writeWall(file, wall))
            return FALSE;
    }

    return TRUE;
}

static BOOL writeSprites(FILE *file, const Map *map)
{
    USHORT i;

    for(i = 0; i < map->numOfSprites; i++)
    {
        Sprite *sprite = &map->sprites[i];
        if(!writeSprite(file, sprite))
            return FALSE;
    }

    return TRUE;
}

BOOL writeMapFd(FILE *file, const Map *map)
{
    return (writeULong(file, map->mapVersion)
        && writeULong(file, map->posx)
        && writeULong(file, map->posy)
        && writeULong(file, map->posz)
        && writeUShort(file, map->angle)
        && writeUShort(file, map->currentSectorNumber)
        && writeUShort(file, map->numOfSectors)
        && writeSectors(file, map)
        && writeUShort(file, map->numOfWalls)
        && writeWalls(file, map)
        && writeUShort(file, map->numOfSprites)
        && writeSprites(file, map));
}

BOOL writeMap(const char *filename, const Map *map)
{
    FILE *file = fopen(filename, "w");

    if(file == NULL)
        return FALSE;
    else
    {
        BOOL status = writeMapFd(file, map);
        fclose(file);
        return status;
    }
}

void clearMap(Map *map)
{
    free(map->sectors);
    free(map->walls);
    free(map->sprites);
}

static void printSectors(FILE *file, const Map *map)
{
    USHORT i;

    fprintf(file, "  <sectors>\n");

    for(i = 0; i < map->numOfSectors; i++)
        printSector(file, &map->sectors[i]);

    fprintf(file, "  </sectors>\n");
}

static void printWalls(FILE *file, const Map *map)
{
    USHORT i;

    fprintf(file, "  <walls>\n");

    for(i = 0; i < map->numOfWalls; i++)
        printWall(file, &map->walls[i]);

    fprintf(file, "  </walls>\n");
}

static void printSprites(FILE *file, const Map *map)
{
    USHORT i;

    fprintf(file, "  <sprites>\n");

    for(i = 0; i < map->numOfSprites; i++)
        printSprite(file, &map->sprites[i]);

    fprintf(file, "  </sprites>\n");
}

void printMapFd(FILE *file, const Map *map)
{
    fprintf(file, "<map>\n");
    fprintf(file, "  <mapVersion>%u</mapVersion>\n", map->mapVersion);
    fprintf(file, "  <posx>%u</posx>\n", map->posx);
    fprintf(file, "  <posy>%u</posy>\n", map->posy);
    fprintf(file, "  <posz>%u</posz>\n", map->posz);
    fprintf(file, "  <angle>%u</angle>\n", map->angle);
    fprintf(file, "  <currentSectorNumber>%u</currentSectorNumber>\n", map->currentSectorNumber);
    fprintf(file, "  <numOfSectors>%u</numOfSectors>\n", map->numOfSectors);
    printSectors(file, map);
    fprintf(file, "  <numOfWalls>%u</numOfWalls>\n", map->numOfWalls);
    printWalls(file, map);
    fprintf(file, "  <numOfSprites>%u</numOfSprites>\n", map->numOfSprites);
    printSprites(file, map);
    fprintf(file, "</map>\n");
}

BOOL printMap(const char *filename, const Map *map)
{
    FILE *file = fopen(filename, "w");

    if(file == NULL)
        return FALSE;
    else
    {
        printMapFd(file, map);
        fclose(file);
        return TRUE;
    }
}
