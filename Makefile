# Compiler settings - Can be customized.
CC = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lglfw3 -lopengl32 -lglu32 -lgdi32

# Makefile settings - Can be customized.
APPNAME = myapp
EXT = .cpp
SRCDIR = src
OBJDIR = build
INCDIR = inc
APPDIR = bin
DEPDIR = dep

ITAG = -I
LTAG = -L

SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(DEPDIR)/%.d)
APP = $(APPDIR)/$(APPNAME)
INC = $(ITAG)$(wildcard $(INCDIR)/*/include)
LIB = $(LTAG)$(wildcard $(INCDIR)/*/lib)
#INC = $(wildcard $(ITAG)$(INCDIR)/*/include)

RM = rm
DELOBJ = $(OBJ)

DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

#$(error $(SRC) || $(INC) || $(LIB))

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