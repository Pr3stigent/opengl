# Compiler settings - Can be customized.
CC = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lglfw3 -lopengl32 -lglu32 -lgdi32 -lglew32

# Makefile settings - Can be customized.
APPNAME = myapp
EXT = .cpp
SRCDIR = src
OBJDIR = build
INCDIR = inc
APPDIR = bin
DEPDIR = dep

SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(DEPDIR)/%.d)
APP = $(APPDIR)/$(APPNAME)
INC = $(foreach file, $(wildcard $(INCDIR)/*/include), -I$(file))
LIB = $(foreach file, $(wildcard $(INCDIR)/*/lib), -L$(file))

RM = rm
DELOBJ = $(OBJ)

DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

all: $(APP)

$(APP): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LIB) $(LDFLAGS)

%.d: $(SRCDIR)/%$(EXT)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

-include $(DEP)

$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -c $< $(INC) $(LIB) $(LDFLAGS) -o $@ 

.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(APP)

.PHONY: cleandep
cleandep:
	$(RM) $(DEP)

.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(DEP) $(APP)$(EXE)

.PHONY: cleandepw
cleandepw:
	$(DEL) $(DEP)
