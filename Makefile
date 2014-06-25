CXX = g++
CXXFLAGS = -Wall -MMD
OBJECTS = pang.o Game.o MainMenu.o splashScreen.o stdafx.o VisibleGameObject.o PlayerPaddle.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = pang
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} ${LIBS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}