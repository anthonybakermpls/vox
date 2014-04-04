CXX = clang++
# Update these paths to match your installation
# You may also need to update the linker option rpath, which sets where to look for
# the SDL2 libraries at runtime to match your install
SDL_LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib
SDL_INCLUDE = -I/usr/local/include
CXXFLAGS = -Wall -c -std=c++11 
SRCDIR = src
OBJDIR = obj
INCLUDEDIR = include
LDFLAGS = $(SDL_LIB)
PROG = vox

all: $(PROG)

$(PROG): $(OBJDIR)/main.o $(OBJDIR)/sample.o
	$(CXX) $(OBJDIR)/main.o $(OBJDIR)/sample.o $(LDFLAGS) -o $@

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) $(SDL_INCLUDE) -c $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o 
#	$(CXX) $(CXXFLAGS) $(SRCDIR)/$< -o $@

$(OBJDIR)/sample.o: $(SRCDIR)/sample.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -c $(SRCDIR)/sample.cpp -o $(OBJDIR)/sample.o 



.PHONY:	clean
clean:
	rm $(PROG) && rm $(OBJDIR)/*
