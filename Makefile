OBJS = main.cpp ScreenPt.o Celestial.o Planet.o Sun.o
LIBS = -lGL -lGLU -lglut
CC = g++ 
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

Planets : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(LIBS) -o Planets

ScreenPt.o : ScreenPt.h ScreenPt.cpp
	$(CC) $(CFLAGS) ScreenPt.cpp $(LIBS)

Celestial.o : Celestial.h Celestial.cpp
	$(CC) $(CFLAGS) Celestial.cpp $(LIBS)

Planet.o : Planet.h Planet.cpp
	$(CC) $(CFLAGS) Planet.cpp $(LIBS)

Sun.o : Sun.h Sun.cpp
	$(CC) $(CFLAGS) Sun.cpp $(LIBS)

clean:
	\rm *.o Planets
