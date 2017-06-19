NAME = abstractVM

SRC =	main.cpp \
			./src/factory.cpp \
			./src/operand.cpp

HEADER =	-I./includes

LIB =

all : $(NAME)

$(NAME) :
	g++ -std=c++11 -ggdb3 -Wall -Wextra $(HEADER) -c $(SRC)
	g++ -o $(NAME)   *.o $(LIB)


clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
