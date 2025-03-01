# CCFLAGS = -Wall -Wextra -std=c++2a -O3 -D_GLIBCXX_DEBUG -fsanitize=undefined -fsanitize=address -g
CCFLAGS = -fprofile-arcs -ftest-coverage -fprofile-values -fPIC -O0 -g
OBJ_FILES = main.o

main: $(OBJ_FILES)
	g++ $(CCFLAGS) $(OBJ_FILES) -o main

$(DIR_OBJ)main.o: main.cc
	g++ $(CCFLAGS) -c main.cc -o main.o

clean:
	rm -f main *.o
	rm main.gcno main.gcda main.cc.gcov
