OBJS = main.cpp ScreenPt.o
LIBS = -lGL -lGLU -lglut
CC = g++ 
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

Planets : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(LIBS) -o Planets

ScreenPt.o : ScreenPt.h ScreenPt.cpp
	$(CC) $(CFLAGS) ScreenPt.cpp $(LIBS)

clean:
	\rm *.o Planets
