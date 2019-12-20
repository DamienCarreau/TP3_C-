YEARS = 2019
ECHO  = echo
RM = rm
COMP = g++
EDL = g++
RMFLAGS = -f
COMPFLAGS = -Wall -ansi -pedantic -std=c++11 -g
EDLFLAGS = -g
INT=
REAL =  Trajet.cpp TrajetSimple.cpp TrajetComp.cpp  Catalogue.cpp main.cpp
OBJ = $(REAL:.cpp=.o)
EXE = exec1


.PHONY : efface

$(EXE) : $(OBJ)
	$(EDL) -o $(EXE) $(OBJ)

%.o : %.c
	@echo "compilation de <hello.c>"
	$(COMP) $(COMPFLAGS) -c $<


efface :
	$(RM) $(RMFLAGS) $(OBJ) $(EXE) core