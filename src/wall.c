#include "wall.h"
#include "io.h"

BOOL readWall(FILE *file, Wall *wall)
{
    return (readLong(file, &wall->x)
        && readLong(file, &wall->y)
        && readShort(file, &wall->point2)
        && readShort(file, &wall->nextWall)
        && readShort(file, &wall->nextSector)
        && readShort(file, &wall->cstat)
        && readShort(file, &wall->picNum)
        && readShort(file, &wall->overPicNum)
        && readSChar(file, &wall->shade)
        && readChar(file, &wall->pal)
        && readChar(file, &wall->xRepeat)
        && readChar(file, &wall->yRepeat)
        && readChar(file, &wall->xPanning)
        && readChar(file, &wall->yPanning)
        && readShort(file, &wall->loTag)
        && readShort(file, &wall->hiTag)
        && readShort(file, &wall->extra));
}

BOOL writeWall(FILE *file, const Wall *wall)
{
    return (writeLong(file, wall->x)
        && writeLong(file, wall->y)
        && writeShort(file, wall->point2)
        && writeShort(file, wall->nextWall)
        && writeShort(file, wall->nextSector)
        && writeShort(file, wall->cstat)
        && writeShort(file, wall->picNum)
        && writeShort(file, wall->overPicNum)
        && writeSChar(file, wall->shade)
        && writeChar(file, wall->pal)
        && writeChar(file, wall->xRepeat)
        && writeChar(file, wall->yRepeat)
        && writeChar(file, wall->xPanning)
        && writeChar(file, wall->yPanning)
        && writeShort(file, wall->loTag)
        && writeShort(file, wall->hiTag)
        && writeShort(file, wall->extra));
}

void parseWallNode(xmlNodePtr wall_node, Wall *wall)
{
    xmlNodePtr child_element = wall_node->children;

    while(child_element != NULL)
    {
        if(child_element->type == XML_ELEMENT_NODE)
        {
            if(xmlStrcmp(child_element->name, (xmlChar*) "x") == 0)
                wall->x = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "y") == 0)
                wall->y = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "point2") == 0)
                wall->point2 = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "nextWall") == 0)
                wall->nextWall = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "nextSector") == 0)
                wall->nextSector = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "cstat") == 0)
                wall->cstat = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "picNum") == 0)
                wall->picNum = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "overPicNum") == 0)
                wall->overPicNum = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "shade") == 0)
                wall->shade = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "pal") == 0)
                wall->pal = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "xRepeat") == 0)
                wall->xRepeat = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "yRepeat") == 0)
                wall->yRepeat = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "xPanning") == 0)
                wall->xPanning = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "yPanning") == 0)
                wall->yPanning = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "loTag") == 0)
                wall->loTag = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "hiTag") == 0)
                wall->hiTag = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "extra") == 0)
                wall->extra = atoi((char*)child_element->children->content);
        }

        child_element = child_element->next;
    }
}

void printWall(FILE *file, const Wall *wall)
{
    fprintf(file, "    <wall>\n");
    fprintf(file, "      <x>%d</x>\n", wall->x);
    fprintf(file, "      <y>%d</y>\n", wall->y);
    fprintf(file, "      <point2>%d</point2>\n", wall->point2);
    fprintf(file, "      <nextWall>%d</nextWall>\n", wall->nextWall);
    fprintf(file, "      <nextSector>%d</nextSector>\n", wall->nextSector);
    fprintf(file, "      <cstat>%d</cstat>\n", wall->cstat);
    fprintf(file, "      <picNum>%d</picNum>\n", wall->picNum);
    fprintf(file, "      <overPicNum>%d</overPicNum>\n", wall->overPicNum);
    fprintf(file, "      <shade>%d</shade>\n", wall->shade);
    fprintf(file, "      <pal>%u</pal>\n", wall->pal);
    fprintf(file, "      <xRepeat>%u</xRepeat>\n", wall->xRepeat);
    fprintf(file, "      <yRepeat>%u</yRepeat>\n", wall->yRepeat);
    fprintf(file, "      <xPanning>%u</xPanning>\n", wall->xPanning);
    fprintf(file, "      <yPanning>%u</yPanning>\n", wall->yPanning);
    fprintf(file, "      <loTag>%d</loTag>\n", wall->loTag);
    fprintf(file, "      <hiTag>%d</hiTag>\n", wall->hiTag);
    fprintf(file, "      <extra>%d</extra>\n", wall->extra);
    fprintf(file, "    </wall>\n");
}
