CXX=g++

EXEC=run

all: buff.o killer.o card.o main.o fight.o skill.o player.o
	$(CXX)  -std=c++11  buff.o killer.o card.o main.o fight.o skill.o player.o -o $(EXEC)

player.o: ./src/player.cpp
	$(CXX) -std=c++11  -c ./src/player.cpp

skill.o: ./src/skill.cpp
	$(CXX) -std=c++11  -c ./src/skill.cpp

fight.o: ./src/fight.cpp
	$(CXX) -std=c++11  -c ./src/fight.cpp

buff.o: ./src/buff.cpp
	$(CXX) -std=c++11  -c ./src/buff.cpp

killer.o: ./src/killer.cpp
	$(CXX) -std=c++11  -c  ./src/killer.cpp

card.o: ./src/card.cpp
	$(CXX) -std=c++11  -c  ./src/card.cpp

main.o: ./src/main.cpp
	$(CXX) -std=c++11  -c ./src/main.cpp
clean:
	rm $(EXEC) *.o