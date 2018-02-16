DEBUG   = -g
OBJECTS = main.o linked_list.o
EXE     = linked_list_Program


all: $(EXE)



#Building the executable

$(EXE): $(OBJECTS)
	@#echo "ARGS: $@ # $< # $^"
	gcc $^ -o $@ $(DEBUG)


#Generating object files (.o)

main.o: main.c linked_list.h
	@#echo "ARGS: $@ # $< # $^"
	gcc -c $< -o $@ $(DEBUG)

linked_list.o : linked_list.c linked_list.h
	@#echo "ARGS: $@ # $< # $^"
	gcc -c $< -o $@ $(DEBUG)


#Clean up

clean:
	@rm -f *.o $(EXE)

# $@: target
# $<: le premier de la liste des dependances
# $^: Toute la liste des dependance


