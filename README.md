# MP3.LIB

.LIB files are straight from the mp3 player

readbloc.c is designed to find patterns in files (I used this to find file disk locations)

occ is a sheel script wrapper for readbloc.c

literalLocations contains 64 bit representations of file disk locations. I intend to search for these locations in the .LIB files. These 64 bit integers are represented in reverse. If you want to read these integers, place the first byte into the lowest valued byte of the integer (see code in readbloc.c). These intergers are not large endian! Each byte is little endian, but the bytes are situated in reverse. No added spacing is put between integers. 
