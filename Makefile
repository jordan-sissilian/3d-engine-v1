CC = g++

OBJS = ./game/src/*.cpp ./libs/glad/src/glad.c ./game/include/shader/*.cpp ./game/src/utils/*.cpp ./game/src/shape/*.cpp ./game/src/loadObjFile/loadObjFile.cpp

INCLUDE_PATHS = -I./libs/glfw-3.3.8/include/GLFW/glfw3.h

LIBRARY_PATHS = -L./libs/glfw-3.3.8/lib-arm64 -lglfw3 

# -w suppresses all warnings
COMPILER_FLAGS = -w

LINKER_FLAGS = -framework OpenGL -framework IOKit -framework Cocoa

OBJ_NAME = ./bin/3d

all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

t :
	clear && make && ./bin/3d && rm ./bin/3d