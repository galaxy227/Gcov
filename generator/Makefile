CCFLAGS = -Wall -Wextra -std=c++2a -O3 -D_GLIBCXX_DEBUG -fsanitize=undefined -fsanitize=address -g
OBJ_FILES = generator.o

generator: $(OBJ_FILES)
	g++ $(CCFLAGS) $(OBJ_FILES) -o generator

$(DIR_OBJ)generator.o: generator.cc
	g++ $(CCFLAGS) -c generator.cc -o generator.o

clean:
	rm -f generator *.o *.txt
