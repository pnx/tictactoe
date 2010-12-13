#
# Tic-Tac-Toe Makefile
#

CXX 	 = g++
CXXFLAGS = -Wall -Werror

program = tic_tac

obj  = src/main.o
obj += src/game.o
obj += src/square.o
obj += src/board.o
obj += src/player/player.o
obj += src/player/human_player.o
obj += src/player/computer_player.o

.PHONY : clean distclean
all : $(program)

$(program) : $(obj)
	$(CXX) $^ -o $@

%.o : %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(obj)

distclean : clean
	$(RM) $(program)
