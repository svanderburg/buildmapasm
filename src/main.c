#include "buildmaptypes.h"
#include <stdio.h>
#include <getopt.h>
#include "map.h"

#define PACKAGE_NAME "buildmapinspector"
#define PACKAGE_VERSION "0.1"

#define OPTION_OUTPUT_BINARY 0x1
#define OPTION_INPUT_XML     0x2

static void printUsage(const char *command)
{
    printf("Usage: %s [OPTION] [file]\n\n", command);

    puts(
    "This command is a BUILD map assembler/disassembler.\n"
    "It can read a BUILD engine maps (version 7) from a binary or a somewhat\n"
    "human-readable XML representation and converts it to a binary or XML\n"
    "representation.\n"
    );

    puts(
    "Options:\n"
    "      --input-xml      Specifies that the input file is in XML format. By\n"
    "                       default, it expects a binary file.\n"
    "      --output-binary  Specifies that the output file is in binary format. By\n"
    "                       default, it will output in XML format.\n"
    "  -o, --output-file    Specifies the file name where the output should be\n"
    "                       written to. If no output file is given the tool will use\n"
    "                       the standard output"
    );

    puts(
    "  -h, --help           Shows the usage of this command to the user\n"
    "  -v, --version        Shows the version of this command to the user"
    );
}

static void printVersion(const char *command)
{
    printf(
    "%s (" PACKAGE_NAME ") " PACKAGE_VERSION "\n\n"
    "Copyright (C) 2023 Sander van der Burg\n"
    , command);
}

static BOOL readMapFromBinaryOrXML(const char *filename, Map *map, const unsigned int options)
{
    if(options & OPTION_INPUT_XML)
        return readMapFromXML(filename, map);
    else
        return readMap(filename, map);
}

static BOOL writeMapToStdoutInBinaryOrXML(const Map *map, const unsigned int options)
{
    if(options & OPTION_OUTPUT_BINARY)
        return writeMapFd(stdout, map);
    else
    {
        printMapFd(stdout, map);
        return TRUE;
    }
}

static BOOL writeMapToFileInBinaryOrXML(const char *outputFile, const Map *map, const unsigned int options)
{
    if(options & OPTION_OUTPUT_BINARY)
        return writeMap(outputFile, map);
    else
        return printMap(outputFile, map);
}

static BOOL executeOperation(const char *filename, const char *outputFile, const unsigned int options)
{
    Map map;
    int exit_status = 0;

    if(readMapFromBinaryOrXML(filename, &map, options))
    {
        if(outputFile == NULL)
        {
            if(!writeMapToStdoutInBinaryOrXML(&map, options))
            {
                fprintf(stderr, "Cannot write MAP representation to the stdout!\n");
                exit_status = 1;
            }
        }
        else
        {
            if(!writeMapToFileInBinaryOrXML(outputFile, &map, options))
            {
                fprintf(stderr, "Cannot write MAP representation to the given file!\n");
                exit_status = 1;
            }
        }
    }
    else
    {
        fprintf(stderr, "Error while opening MAP file!\n");
        exit_status = 1;
    }

    clearMap(&map);

    return exit_status;
}

int main(int argc, char *argv[])
{
    char *filename;
    char *outputFile = NULL;
    unsigned int options = 0;

    int c;
    int option_index = 0;
    struct option long_options[] =
    {
        {"output-file", required_argument, 0, 'o'},
        {"output-binary", no_argument, 0, 'O'},
        {"input-xml", no_argument, 0, 'I'},
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {0, 0, 0, 0}
    };

    while((c = getopt_long(argc, argv, "o:hv", long_options, &option_index)) != -1)
    {
        switch(c)
        {
            case 'o':
                outputFile = optarg;
                break;
            case 'O':
                options |= OPTION_OUTPUT_BINARY;
                break;
            case 'I':
                options |= OPTION_INPUT_XML;
                break;
            case 'h':
                printUsage(argv[0]);
                return 0;
            case 'v':
                printVersion(argv[0]);
                return 0;
            case '?':
                printUsage(argv[0]);
                return 1;
        }
    }

    /* Validate non options */

    if(optind >= argc)
        filename = NULL;
    else
        filename = argv[optind];


    if(filename == NULL)
    {
        fprintf(stderr, "ERROR: No filename was provided!\n");
        return 1;
    }

    /* Execute operation */
    return executeOperation(filename, outputFile, options);
}
