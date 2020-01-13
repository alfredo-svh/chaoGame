CXX		= g++ -std=c++11
CXXFLAGS	= -g -Wall
OBJS		= Chao.o chaoGame.o
PROG		= playChao

all:		$(PROG)

$(PROG):	$(OBJS)
			$(CXX) -o $(PROG) $(OBJS)
					
clean:;		$(RM) $(PROG) core *.o
