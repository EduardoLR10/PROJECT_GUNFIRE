CXX = g++
CXXFLAGS = -W -Wall -std=c++1z -lm -g -fno-aggressive-loop-optimizations -I$(IDIR)

SDIR = src
IDIR = include
ODIR = obj

NAME = test

DEPS = $(wildcard $(IDIR)/*.h)

_OBJ = $(patsubst %.cpp,%.o,$(wildcard $(SDIR)/*.cpp))
OBJ = $(patsubst $(SDIR)/%,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(NAME): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(NAME)