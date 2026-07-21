CC = gcc
CFLAGS = -Wall -Wextra
FOLDER = build

src_sorting = algorithms/Sorting
src_arrays = data_structures/Arrays

### FOR SORTING ALGORITHMS 

# bubble_sort
bubble:
	$(CC) $(CFLAGS) $(src_sorting)/bubble_sort.c -o $(FOLDER)/bubble

run_bubble:
	./$(FOLDER)/bubble

# selection_sort
selection:
	$(CC) $(CFLAGS) $(src_sorting)/selection_sort.c -o $(FOLDER)/selection

run_selection:
	./$(FOLDER)/selection

# insertion_sort
insertion:
	$(CC) $(CFLAGS) $(src_sorting)/insertion_sort.c -o $(FOLDER)/insertion

run_insertion:
	./$(FOLDER)/insertion

### FOR ARRAYS DATA STRUCTURES
array_static:
	$(CC) $(CFLAGS) $(src_arrays)/array_static.c -o $(FOLDER)/array_static

run_arr_static:
	./$(FOLDER)/array_static
