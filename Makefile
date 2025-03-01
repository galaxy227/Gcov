# CCFLAGS = -Wall -Wextra -std=c++2a -O3 -D_GLIBCXX_DEBUG -fsanitize=undefined -fsanitize=address -g
CCFLAGS = -fprofile-arcs -ftest-coverage -fprofile-values -fPIC -O0 -g
OBJ_FILES = main.o rainfall.o

main: $(OBJ_FILES)
	g++ $(CCFLAGS) $(OBJ_FILES) -o main
	rm *.o

$(DIR_OBJ)main.o: main.cc
	g++ $(CCFLAGS) -c main.cc -o main.o

$(DIR_OBJ)rainfall.o: rainfall.cc
	g++ $(CCFLAGS) -c rainfall.cc -o rainfall.o

clean:
	rm -f main *.o
	rm *.gcno *.gcda *.gcov
