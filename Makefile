DEBUG=no
CXX=g++
ifeq ($(DEBUG), yes)
	CXXFLAGS=-ansi -pedantic -Wall -std=c++11 -g -DMAP
else
	CXXFLAGS=-ansi -pedantic -Wall -std=c++11 -g
endif
EXEC=main
OBJECTS=mainAlexis.cpp Model/Capteur.o Model/SerieMesures.o Model/Mesure.o Controller/ActionCapteur.o

all: $(OBJECTS)
	$(CXX) -o $(EXEC) $(OBJECTS)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) 

clean:
	rm -rf *.o
	rm -rf $(EXEC)
	rm -rf bin/$(EXEC)
	rm Controller/*.o
	rm View/*.o
	rm Model/*.o