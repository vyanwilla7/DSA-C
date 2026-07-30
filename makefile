CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=address -g
FOLDER = build

src_sorting = algorithms/Sorting
src_arrays = data_structures/Arrays

### ==========FOR SORTING ALGORITHMS==========

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

# merge_sort
merge:
	$(CC) $(CFLAGS) $(src_sorting)/merge_sort.c -o $(FOLDER)/merge

run_merge:
	./$(FOLDER)/merge

### ==========FOR ARRAYS DATA STRUCTURES==========
array_static:
	$(CC) $(CFLAGS) $(src_arrays)/array_static.c -o $(FOLDER)/array_static

run_arr_static:
	./$(FOLDER)/array_static

array_dynamic:
	$(CC) $(CFLAGS) $(src_arrays)/array_dynamic.c -o $(FOLDER)/array_dynamic

run_arr_dynamic:
	./$(FOLDER)/array_dynamic
