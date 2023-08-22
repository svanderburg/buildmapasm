#include "io.h"

BOOL readChar(FILE *file, CHAR *value)
{
    int byte = fgetc(file);

    if(byte == EOF)
        return FALSE;
    else
    {
        *value = byte;
        return TRUE;
    }
}

BOOL readSChar(FILE *file, SCHAR *value)
{
    int byte = fgetc(file);

    if(byte == EOF)
        return FALSE;
    else
    {
        *value = byte;
        return TRUE;
    }
}

BOOL readUShort(FILE *file, USHORT *value)
{
    USHORT readValue;

    if(fread(&readValue, sizeof(USHORT), 1, file) == 1)
    {
#if BUILD_BIG_ENDIAN == 1
	/* Byte swap it */
	*value = (readValue & 0xff) << 8 | (readValue & 0xff00) >> 8;
#else
	*value = readValue;
#endif
	return TRUE;
    }
    else
        return FALSE;
}

BOOL readShort(FILE *file, SHORT *value)
{
    SHORT readValue;

    if(fread(&readValue, sizeof(SHORT), 1, file) == 1)
    {
#if BUILD_BIG_ENDIAN == 1
	*value = (readValue & 0xff) << 8 | (readValue & 0xff00) >> 8;
#else
	/* Byte swap it */
	*value = readValue;
#endif
	return TRUE;
    }
    else
        return FALSE;
}

BOOL readULong(FILE* file, ULONG *value)
{
    ULONG readValue;

    if(fread(&readValue, sizeof(ULONG), 1, file) == 1)
    {
#if BUILD_BIG_ENDIAN == 1
        /* Byte swap it */
        *value = (readValue & 0xff) << 24 | (readValue & 0xff00) << 8 | (readValue & 0xff0000) >> 8 | (readValue & 0xff000000) >> 24;
#else
        *value = readValue;
#endif
        return TRUE;
    }
    else
        return FALSE;
}

BOOL readLong(FILE* file, LONG *value)
{
    LONG readValue;

    if(fread(&readValue, sizeof(LONG), 1, file) == 1)
    {
#if BUILD_BIG_ENDIAN == 1
        /* Byte swap it */
        *value = (readValue & 0xff) << 24 | (readValue & 0xff00) << 8 | (readValue & 0xff0000) >> 8 | (readValue & 0xff000000) >> 24;
#else
        *value = readValue;
#endif
        return TRUE;
    }
    else
        return FALSE;
}

BOOL writeChar(FILE *file, const CHAR value)
{
    return (fputc(value, file) != EOF);
}

BOOL writeSChar(FILE *file, const SCHAR value)
{
    return (fputc(value, file) != EOF);
}

BOOL writeUShort(FILE *file, const USHORT value)
{
#if BUILD_BIG_ENDIAN == 1
    /* Byte swap it */
    USHORT writeValue = (value & 0xff) << 8 | (value & 0xff00) >> 8;
#else
    USHORT writeValue = value;
#endif

    return (fwrite(&writeValue, sizeof(USHORT), 1, file) == 1);
}

BOOL writeShort(FILE *file, const SHORT value)
{
#if BUILD_BIG_ENDIAN == 1
    /* Byte swap it */
    SHORT writeValue = (value & 0xff) << 8 | (value & 0xff00) >> 8;
#else
    SHORT writeValue = value;
#endif

    return (fwrite(&writeValue, sizeof(SHORT), 1, file) == 1);
}

BOOL writeULong(FILE *file, const ULONG value)
{
#if BUILD_BIG_ENDIAN == 1
    /* Byte swap it */
    ULONG writeValue = (value & 0xff) << 24 | (value & 0xff00) << 8 | (value & 0xff0000) >> 8 | (value & 0xff000000) >> 24;
#else
    ULONG writeValue = value;
#endif

    return (fwrite(&writeValue, sizeof(ULONG), 1, file) == 1);
}

BOOL writeLong(FILE *file, const LONG value)
{
#if BUILD_BIG_ENDIAN == 1
    /* Byte swap it */
    LONG writeValue = (value & 0xff) << 24 | (value & 0xff00) << 8 | (value & 0xff0000) >> 8 | (value & 0xff000000) >> 24;
#else
    LONG writeValue = value;
#endif

    return (fwrite(&writeValue, sizeof(LONG), 1, file) == 1);
}
