# Compiler settings - Can be customized.
CC = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = 

# Makefile settings - Can be customized.
ITAG = -I

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
INC = $(ITAG)$(wildcard $(INCDIR)/*)
#INC = $(wildcard $(ITAG)$(INCDIR)/*/include)

RM = rm
DELOBJ = $(OBJ)

DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

$(error $(SRC) || $(INC) || $(DEP))

all: $(APP)

$(APP): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.d: $(SRCDIR)/%$(EXT)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

-include $(DEP)

$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<

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