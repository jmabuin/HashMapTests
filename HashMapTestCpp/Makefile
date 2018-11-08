include Makefile.in
PROG=			HashMapTest

SOURCES  = $(wildcard $(SRCDIR)/*.cpp)

OBJECTS  = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

LIBS = 
INCLUDES =

.PHONY: all

.SUFFIXES: .cpp .o .cc

all: $(PROG)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

CreateDir:
	if [ ! -d "$(OBJDIR)" ]; then mkdir build; fi

HashMapTest: CreateDir $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(DFLAGS) $(AOBJS) $(OBJECTS) -o $@ $(LIBS)

clean: $(SUBCLEAN)
	rm $(PROG) build/*.o
