EXE = test_doubly_linked_list_Program

EXE: test_doubly_linked_list.o doubly_linked_list.o
	gcc test_doubly_linked_list.o doubly_linked_list.o -o EXE

test_doubly_linked_list.o: test_doubly_linked_list.c doubly_linked_list.h
	gcc -c test_doubly_linked_list.c -o test_doubly_linked_list.o

doubly_linked_list.o: doubly_linked_list.c
	gcc -c doubly_linked_list.c -o doubly_linked_list.o

clean:
	rm *.o
	rm $(EXE)

