CC = gcc
CFLAGS = -Wall -Iinclude
SRCDIR = src
OBJDIR = build

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
EXEC = desafiomatriz

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

clean:
	rm -f $(OBJDIR)/*.o $(EXEC)