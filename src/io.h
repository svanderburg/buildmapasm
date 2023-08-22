#ifndef __IO_H
#define __IO_H
#include <stdio.h>
#include "buildmaptypes.h"

BOOL writeChar(FILE *file, const CHAR value);

BOOL writeSChar(FILE *file, const SCHAR value);

BOOL readChar(FILE *file, CHAR *value);

BOOL readSChar(FILE *file, SCHAR *value);

BOOL readUShort(FILE *file, USHORT *value);

BOOL readShort(FILE *file, SHORT *value);

BOOL readULong(FILE* file, ULONG *value);

BOOL readLong(FILE* file, LONG *value);

BOOL writeUShort(FILE *file, const USHORT value);

BOOL writeShort(FILE *file, const SHORT value);

BOOL writeULong(FILE *file, const ULONG value);

BOOL writeLong(FILE *file, const LONG value);

#endif
