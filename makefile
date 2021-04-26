TARGET = main
CC = g++
CFLAGS = -lSDL2 -lSDL2_image `pkg-config --cflags --libs sdl2`

all: clean build run 

build:
	@echo "Building Project ... "
	$(CC) $(TARGET).cpp $(CFLAGS) -o $(TARGET)

run:
	./$(TARGET)

clean:
	$(RM) -r $(TARGET)