CC = cl.exe
LINK = link.exe
NAME = hxd
CFLAGS = /c /TC /I includes /utf-8
LINK_FLAGS = /MACHINE:x64

SRCS = src/main.c \
	   src/hex_tab.c \
	   src/hex.c \
	   src/utils.c \
	   src/hexdump.c

OBJ = main.obj hex_tab.obj hex.obj utils.obj hexdump.obj

all:
	$(CC) $(CFLAGS) $(SRCS)
	$(LINK) $(OBJ)

clean:
	del $(OBJ) /S /Q