CC = gcc
CFLAGS = -Wall -Wextra -Isrc

SRCDIR = src
DISTDIR = dist

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(DISTDIR)/%.o, $(SOURCES))
EXECUTABLE = $(DISTDIR)/shopMaked.exe

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(DISTDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	powershell Remove-Item -Recurse -Force .\$(DISTDIR)\*.o

run:
	./$(EXECUTABLE)

