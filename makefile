CC = gcc
CFLAGS = -Wall -Wextra
FOLDER = build

src_sorting = algorithms/Sorting

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
