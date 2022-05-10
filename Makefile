DEBUG=no
CXX=g++
ifeq ($(DEBUG), yes)
	CXXFLAGS=-ansi -pedantic -Wall -std=c++11 -g -DMAP
else
	CXXFLAGS=-ansi -pedantic -Wall -std=c++11 -g
endif
EXEC=main
OBJECTS=Model/Attribut.o Model/SerieMesures.o Model/Mesure.o

all: $(OBJECTS)
	$(CXX) -o $(EXEC) $(OBJECTS)
	cp $(EXEC) bin/

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) 

clean:
	rm -rf *.o
	rm -rf $(EXEC)
	rm -rf bin/$(EXEC)
	rm Controller/*.o
	rm View/*.o
	rm Model/*.o