CXX = clang++
# Update these paths to match your installation
# You may also need to update the linker option rpath, which sets where to look for
# the SDL2 libraries at runtime to match your install
SDL_LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib
SDL_INCLUDE = -I/usr/local/include
CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE)
SRCDIR = src
OBJDIR = obj
LDFLAGS = $(SDL_LIB)
PROG = vox

all: $(PROG)

$(PROG): $(OBJDIR)/main.o
	$(CXX) $(OBJDIR)/main.o $(LDFLAGS) -o $@

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o 
#	$(CXX) $(CXXFLAGS) $(SRCDIR)/$< -o $@


.PHONY:	clean
clean:
	rm $(PROG) && rm $(OBJDIR)/*
