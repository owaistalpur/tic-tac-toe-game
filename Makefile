CCOMP := clang
CFLAGS := -Wall

SRC := tic_tac_toe.c
INC := *.h
OBJS    := tic_tac_toe.o
all: files main 
debug: files main_debug 


files: $(SRC) $(INC) 
	$(CCOMP) $(CFLAGS) -c $(SRC)

main: main.c files
	$(CCOMP) $(CFLAGS) main.c $(OBJS) -o game 

main_debug: main.c files 
	$(CCOMP) $(CFLAGS) main.c $(OBJS) -g -o main_debug

clean:
	rm *.o main tic_tac_toe main_debug