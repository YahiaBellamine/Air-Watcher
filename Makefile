DEBUG=no
CXX=g++
ifeq ($(DEBUG), yes)
	CXXFLAGS=-ansi -pedantic -Wall -std=c++17 -g -DMAP
else
	CXXFLAGS=-ansi -pedantic -Wall -std=c++17 -g
endif
EXEC=main
OBJECTS= Model/Capteur.o Model/SerieMesures.o Model/Mesure.o Controller/ActionCapteur.o Controller/ActionQualiteAir.o Model/AgenceGouvernementale.o Model/Attribut.o Model/Fournisseur.o Model/IndividuPrive.o Model/Nettoyeur.o Model/Utilisateur.o Controller/ServiceUtilisateur.o Controller/ActionNettoyeur.o
TEST =  Model/Capteur.o Model/SerieMesures.o Model/Mesure.o Controller/ActionCapteur.o

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

loading: Loading.cpp
	g++ -o loading Loading.cpp Model/SerieMesures.cpp Model/Capteur.cpp Model/Fournisseur.cpp Model/Attribut.cpp Model/Mesure.cpp Model/Temps.cpp Model/Nettoyeur.cpp Model/IndividuPrive.cpp

test: $(TEST)
	$(CXX) -o $(EXEC) $(TEST)
