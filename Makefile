OBJS= libsort.c test.c

sort:
	gcc $(OBJS) -o $@ -DDEBUG -g
clean:
	rm sort;
