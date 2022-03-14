binary: thread_exercise.c
	gcc $< -o $@ -lpthread

.PHONY: run clean

run:
	./binary

clean:
	rm binary
