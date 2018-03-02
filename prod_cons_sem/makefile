EXE = PRODCONS_PB
OBJ = -pthread

all: $(EXE)

$(EXE): main.o prod_cons.o
	gcc $(OBJ) $^ -o $@

main.o: main.c prod_cons.h
	gcc -c $< -o $@

prod_cons.o: prod_cons.c prod_cons.h
	gcc -c $< -o $@

clean:
	rm -f *.o $(EXE)

