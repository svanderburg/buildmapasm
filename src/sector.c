#include "sector.h"
#include "io.h"

BOOL readSector(FILE *file, Sector *sector)
{
    return (readShort(file, &sector->wallPtr)
        && readShort(file, &sector->wallNum)
        && readLong(file, &sector->ceilingZ)
        && readLong(file, &sector->floorZ)
        && readShort(file, &sector->ceilingStat)
        && readShort(file, &sector->floorStat)
        && readShort(file, &sector->ceilingPicNum)
        && readShort(file, &sector->ceilingHeiNum)
        && readSChar(file, &sector->ceilingShade)
        && readChar(file, &sector->ceilingPal)
        && readChar(file, &sector->ceilingXPanning)
        && readChar(file, &sector->ceilingYPanning)
        && readShort(file, &sector->floorPicNum)
        && readShort(file, &sector->floorHeiNum)
        && readSChar(file, &sector->floorShade)
        && readChar(file, &sector->floorPal)
        && readChar(file, &sector->floorXPanning)
        && readChar(file, &sector->floorYPanning)
        && readChar(file, &sector->visibility)
        && readChar(file, &sector->filler)
        && readShort(file, &sector->loTag)
        && readShort(file, &sector->hiTag)
        && readShort(file, &sector->extra));
}

BOOL writeSector(FILE *file, const Sector *sector)
{
    return (writeShort(file, sector->wallPtr)
        && writeShort(file, sector->wallNum)
        && writeLong(file, sector->ceilingZ)
        && writeLong(file, sector->floorZ)
        && writeShort(file, sector->ceilingStat)
        && writeShort(file, sector->floorStat)
        && writeShort(file, sector->ceilingPicNum)
        && writeShort(file, sector->ceilingHeiNum)
        && writeSChar(file, sector->ceilingShade)
        && writeChar(file, sector->ceilingPal)
        && writeChar(file, sector->ceilingXPanning)
        && writeChar(file, sector->ceilingYPanning)
        && writeShort(file, sector->floorPicNum)
        && writeShort(file, sector->floorHeiNum)
        && writeSChar(file, sector->floorShade)
        && writeChar(file, sector->floorPal)
        && writeChar(file, sector->floorXPanning)
        && writeChar(file, sector->floorYPanning)
        && writeChar(file, sector->visibility)
        && writeChar(file, sector->filler)
        && writeShort(file, sector->loTag)
        && writeShort(file, sector->hiTag)
        && writeShort(file, sector->extra));
}

void parseSectorNode(xmlNodePtr sector_node, Sector *sector)
{
    xmlNodePtr child_element = sector_node->children;

    while(child_element != NULL)
    {
        if(child_element->type == XML_ELEMENT_NODE)
        {
            if(xmlStrcmp(child_element->name, (xmlChar*) "wallPtr") == 0)
                sector->wallPtr = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "wallNum") == 0)
                sector->wallNum = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "ceilingZ") == 0)
                sector->ceilingZ = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "floorZ") == 0)
                sector->floorZ = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "ceilingStat") == 0)
                sector->ceilingStat = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "floorStat") == 0)
                sector->floorStat = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "ceilingPicNum") == 0)
                sector->ceilingPicNum = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "ceilingHeiNum") == 0)
                sector->ceilingHeiNum = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "ceilingShade") == 0)
                sector->ceilingShade = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "ceilingPal") == 0)
                sector->ceilingPal = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "ceilingXPanning") == 0)
                sector->ceilingXPanning = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "ceilingYPanning") == 0)
                sector->ceilingYPanning = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "floorPicNum") == 0)
                sector->floorPicNum = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "floorHeiNum") == 0)
                sector->floorHeiNum = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "floorShade") == 0)
                sector->floorShade = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "floorPal") == 0)
                sector->floorPal = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "floorXPanning") == 0)
                sector->floorXPanning = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "floorYPanning") == 0)
                sector->floorYPanning = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "visibility") == 0)
                sector->visibility = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "filler") == 0)
                sector->filler = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "loTag") == 0)
                sector->loTag = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "hiTag") == 0)
                sector->hiTag = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "extra") == 0)
                sector->extra = atoi((char*)child_element->children->content);
        }

        child_element = child_element->next;
    }
}

void printSector(FILE *file, const Sector *sector)
{
    fprintf(file, "    <sector>\n");
    fprintf(file, "      <wallPtr>%d</wallPtr>\n", sector->wallPtr);
    fprintf(file, "      <wallNum>%d</wallNum>\n", sector->wallNum);
    fprintf(file, "      <ceilingZ>%d</ceilingZ>\n", sector->ceilingZ);
    fprintf(file, "      <floorZ>%d</floorZ>\n", sector->floorZ);
    fprintf(file, "      <ceilingStat>%d</ceilingStat>\n", sector->ceilingStat);
    fprintf(file, "      <floorStat>%d</floorStat>\n", sector->floorStat);
    fprintf(file, "      <ceilingPicNum>%d</ceilingPicNum>\n", sector->ceilingPicNum);
    fprintf(file, "      <ceilingHeiNum>%d</ceilingHeiNum>\n", sector->ceilingHeiNum);
    fprintf(file, "      <ceilingShade>%d</ceilingShade>\n", sector->ceilingShade);
    fprintf(file, "      <ceilingPal>%u</ceilingPal>\n", sector->ceilingPal);
    fprintf(file, "      <ceilingXPanning>%u</ceilingXPanning>\n", sector->ceilingXPanning);
    fprintf(file, "      <ceilingYPanning>%u</ceilingYPanning>\n", sector->ceilingYPanning);
    fprintf(file, "      <floorPicNum>%d</floorPicNum>\n", sector->floorPicNum);
    fprintf(file, "      <floorHeiNum>%d</floorHeiNum>\n", sector->floorHeiNum);
    fprintf(file, "      <floorShade>%d</floorShade>\n", sector->floorShade);
    fprintf(file, "      <floorPal>%u</floorPal>\n", sector->floorPal);
    fprintf(file, "      <floorXPanning>%u</floorXPanning>\n", sector->floorXPanning);
    fprintf(file, "      <floorYPanning>%u</floorYPanning>\n", sector->floorYPanning);
    fprintf(file, "      <visibility>%u</visibility>\n", sector->visibility);
    fprintf(file, "      <filler>%u</filler>\n", sector->filler);
    fprintf(file, "      <loTag>%d</loTag>\n", sector->loTag);
    fprintf(file, "      <hiTag>%d</hiTag>\n", sector->hiTag);
    fprintf(file, "      <extra>%d</extra>\n", sector->extra);
    fprintf(file, "    </sector>\n");
}
