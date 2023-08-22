BUILD map assembler/disassembler
================================
This project provides a simple utility: `buildmapasm` that can be used to
disassemble and assemble MAP files (version 7) created with the BUILD editor to
XML and vice-versa.

Using a human-readable XML format of a BUILD map makes it possible to easily
inspect its properties in a text editor, perform queries (e.g. with the XPath
language) and make modifications that are inconvenient to do with the BUILD
editor, such as bulk replacing textures.

The BUILD engine is used by a number of popular games from the mid 90s, such as
Duke Nukem 3D, Shadow Warrior, Blood and Redneck Rampage.

Prerequisites
=============
* [libxml2](http://xmlsoft.org)
* An ANSI C compiler and Make

Installing the project
======================
You can build and install the project from source as follows:

```bash
$ make
$ make install
```

To use the project on build big-endian systems, edit `src/Makefile` and
uncomment the big endian flag. Then the I/O operations will automatically byte
swap all numeric values.

If you have the [Nix package manager](http://nixos.org/nix) installed, then you
can install the project with:

```bash
$ nix-env -f default.nix -i buildmapasm
```

Usage
=====
To convert a MAP file (`MYMAP.MAP`) to a readable XML representation on the
standard output, you can run:

```bash
$ buildmapasm MYMAP.MAP
```

We can also store the XML output in a file (`MYMAP.XML`):

```bash
$ buildmapasm -o MYMAP.XML MYMAP.XML
```

We can also read an XML representation of a map (`MYMAP.XML`) and assemble it
back into a binary map file (`MYMAP.MAP`):

```bash
buildmapasm -o MYMAP.MAP --output-binary MYMAP.XML
```

Example use cases of the XML format
===================================
One of the uses cases of the XML format is to perform all kinds of interesting
queries.

For example, the following command queries all sprites in a Duke3D map that have
a red palette swap (palette 21):

```bash
$ xmllint --xpath 'map/sprites/sprite[pal=21]' MYMAP.XML
```

We can also query all lizman sprites (in range 2120-2197) that have palette 21:

```bash
$ xmllint --xpath 'map/sprites/sprite[pal=21 and picNum >= 2120 and picNum <= 2197]' MYMAP.XML
```

License
=======
This library is available under the MIT license
