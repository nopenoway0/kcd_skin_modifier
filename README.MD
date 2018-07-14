This program takes a verts file and replaces the information in a skin with it. A verts file is a binary file with xyz coordinates. First the original axis point is placed, then the new one is placed right after it.

For example: (old x coordinate)(new x coordinate)(old y coordinate)(new y coordinate)
Each coordinate is a 4 byte float.

All chunk patterns e.g. reading of bytes from a file and reverse engineering are directly from: Markemp and his CryEngine model converter at https://github.com/Markemp/Cryengine-Converter.