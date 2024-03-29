DEBUG=no
CXX=g++
ifeq ($(DEBUG), yes)
	CXXFLAGS=-ansi -pedantic -Wall -std=c++17 -g -DMAP
else
	CXXFLAGS=-ansi -pedantic -Wall -std=c++17 -g
endif
EXEC=main
OBJECTS= Loading.o TestUnit/TestUnit.o Model/Capteur.o Model/SerieMesures.o Model/Mesure.o Controller/ActionCapteur.o Controller/ActionQualiteAir.o Model/AgenceGouvernementale.o Model/Attribut.o Model/Fournisseur.o Model/IndividuPrive.o Model/Nettoyeur.o Model/Utilisateur.o Controller/ServiceUtilisateur.o Controller/ActionNettoyeur.o Model/Temps.o

all: $(OBJECTS)
	$(CXX) -o $(EXEC) $(OBJECTS)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) 

clean:
	rm -rf *.o
	rm -rf $(EXEC)
	rm -rf bin/$(EXEC)
	rm Controller/*.o
	rm TestUnit/*.o
	rm Model/*.o

test: $(TEST)
	$(CXX) -o $(EXEC) $(TEST)
