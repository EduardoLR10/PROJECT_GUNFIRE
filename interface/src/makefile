IDIR =../include
CC=g++ -std=c++17
CFLAGS=-I$(IDIR) -Wpedantic -g -lSDL2 -lSDL2_image

ODIR=obj

LIBS=-lm

_DEPS = CardBuilder.hpp Card.hpp interface.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = CardBuilder.o Card.o interface.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: builder

$(ODIR)/%.o: %.cpp 
	$(CC) -c -o $@ $< $(CFLAGS)

builder: $(ODIR)/main.o $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~ builder *.o