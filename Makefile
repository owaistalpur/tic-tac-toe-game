# C complier
CCOMP := clang

# C complier flags
CFLAGS := -Wall -Werror

# Variable to hold Src files
SRC := tic_tac_toe.c
# Variable to hold Header files
INC := *.h
# Variable to hold Object files 
OBJS    := tic_tac_toe.o

# Make all src files and main
all: files main 

# Make a debug version
debug: files main_debug 

files: $(SRC) $(INC) 
	$(CCOMP) $(CFLAGS) -c $(SRC)

main: main.c files
	$(CCOMP) $(CFLAGS) main.c $(OBJS) -o game 

main_debug: main.c files 
	$(CCOMP) $(CFLAGS) main.c $(OBJS) -g -o main_debug

clean:
	rm *.o main tic_tac_toe main_debug
