#include "sprite.h"
#include "io.h"

BOOL readSprite(FILE *file, Sprite *sprite)
{
    return (readLong(file, &sprite->x)
        && readLong(file, &sprite->y)
        && readLong(file, &sprite->z)
        && readShort(file, &sprite->cstat)
        && readShort(file, &sprite->picNum)
        && readSChar(file, &sprite->shade)
        && readChar(file, &sprite->pal)
        && readChar(file, &sprite->clipDist)
        && readChar(file, &sprite->filler)
        && readChar(file, &sprite->xRepeat)
        && readChar(file, &sprite->yRepeat)
        && readSChar(file, &sprite->xOffset)
        && readSChar(file, &sprite->yOffset)
        && readShort(file, &sprite->sectNum)
        && readShort(file, &sprite->statNum)
        && readShort(file, &sprite->angle)
        && readShort(file, &sprite->owner)
        && readShort(file, &sprite->xVel)
        && readShort(file, &sprite->yVel)
        && readShort(file, &sprite->zVel)
        && readShort(file, &sprite->loTag)
        && readShort(file, &sprite->hiTag)
        && readShort(file, &sprite->extra));
}

BOOL writeSprite(FILE *file, const Sprite *sprite)
{
    return (writeLong(file, sprite->x)
        && writeLong(file, sprite->y)
        && writeLong(file, sprite->z)
        && writeShort(file, sprite->cstat)
        && writeShort(file, sprite->picNum)
        && writeSChar(file, sprite->shade)
        && writeChar(file, sprite->pal)
        && writeChar(file, sprite->clipDist)
        && writeChar(file, sprite->filler)
        && writeChar(file, sprite->xRepeat)
        && writeChar(file, sprite->yRepeat)
        && writeSChar(file, sprite->xOffset)
        && writeSChar(file, sprite->yOffset)
        && writeShort(file, sprite->sectNum)
        && writeShort(file, sprite->statNum)
        && writeShort(file, sprite->angle)
        && writeShort(file, sprite->owner)
        && writeShort(file, sprite->xVel)
        && writeShort(file, sprite->yVel)
        && writeShort(file, sprite->zVel)
        && writeShort(file, sprite->loTag)
        && writeShort(file, sprite->hiTag)
        && writeShort(file, sprite->extra));
}

void parseSpriteNode(xmlNodePtr sprite_node, Sprite *sprite)
{
    xmlNodePtr child_element = sprite_node->children;

    while(child_element != NULL)
    {
        if(child_element->type == XML_ELEMENT_NODE)
        {
            if(xmlStrcmp(child_element->name, (xmlChar*) "x") == 0)
                sprite->x = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "y") == 0)
                sprite->y = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "z") == 0)
                sprite->z = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "cstat") == 0)
                sprite->cstat = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "picNum") == 0)
                sprite->picNum = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "shade") == 0)
                sprite->shade = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "pal") == 0)
                sprite->pal = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "clipDist") == 0)
                sprite->clipDist = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "filler") == 0)
                sprite->filler = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "xRepeat") == 0)
                sprite->xRepeat = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "yRepeat") == 0)
                sprite->yRepeat = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "xOffset") == 0)
                sprite->xOffset = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "yOffset") == 0)
                sprite->yOffset = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "sectNum") == 0)
                sprite->sectNum = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "statNum") == 0)
                sprite->statNum = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "angle") == 0)
                sprite->angle = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "owner") == 0)
                sprite->owner = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "xVel") == 0)
                sprite->xVel = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "yVel") == 0)
                sprite->yVel = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "zVel") == 0)
                sprite->zVel = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "loTag") == 0)
                sprite->loTag = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "hiTag") == 0)
                sprite->hiTag = atoi((char*)child_element->children->content);
            else if(xmlStrcmp(child_element->name, (xmlChar*) "extra") == 0)
                sprite->extra = atoi((char*)child_element->children->content);
        }

        child_element = child_element->next;
    }
}

void printSprite(FILE *file, const Sprite *sprite)
{
    fprintf(file, "    <sprite>\n");
    fprintf(file, "      <x>%d</x>\n", sprite->x);
    fprintf(file, "      <y>%d</y>\n", sprite->y);
    fprintf(file, "      <z>%d</z>\n", sprite->z);
    fprintf(file, "      <cstat>%d</cstat>\n", sprite->cstat);
    fprintf(file, "      <picNum>%d</picNum>\n", sprite->picNum);
    fprintf(file, "      <shade>%d</shade>\n", sprite->shade);
    fprintf(file, "      <pal>%u</pal>\n", sprite->pal);
    fprintf(file, "      <clipDist>%u</clipDist>\n", sprite->clipDist);
    fprintf(file, "      <filler>%u</filler>\n", sprite->filler);
    fprintf(file, "      <xRepeat>%u</xRepeat>\n", sprite->xRepeat);
    fprintf(file, "      <yRepeat>%u</yRepeat>\n", sprite->yRepeat);
    fprintf(file, "      <xOffset>%d</xOffset>\n", sprite->xOffset);
    fprintf(file, "      <yOffset>%d</yOffset>\n", sprite->yOffset);
    fprintf(file, "      <sectNum>%d</sectNum>\n", sprite->sectNum);
    fprintf(file, "      <statNum>%d</statNum>\n", sprite->statNum);
    fprintf(file, "      <angle>%d</angle>\n", sprite->angle);
    fprintf(file, "      <owner>%d</owner>\n", sprite->owner);
    fprintf(file, "      <xVel>%d</xVel>\n", sprite->xVel);
    fprintf(file, "      <yVel>%d</yVel>\n", sprite->yVel);
    fprintf(file, "      <zVel>%d</zVel>\n", sprite->zVel);
    fprintf(file, "      <loTag>%d</loTag>\n", sprite->loTag);
    fprintf(file, "      <hiTag>%d</hiTag>\n", sprite->hiTag);
    fprintf(file, "      <extra>%d</extra>\n", sprite->extra);
    fprintf(file, "    </sprite>\n");
}
