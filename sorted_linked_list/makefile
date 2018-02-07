sorted_linked_list_program: test_sorted_linked_list.o sorted_linked_list.o
	gcc test_sorted_linked_list.o sorted_linked_list.o -o sorted_linked_list_Program -g

test_sorted_linked_list.o: test_sorted_linked_list.c sorted_linked_list.h
	gcc -c test_sorted_linked_list.c -o test_sorted_linked_list.o -g

sorted_linked_list.o: sorted_linked_list.c
	gcc -c sorted_linked_list.c -o sorted_linked_list.o -g

