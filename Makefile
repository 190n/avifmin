CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -g
LDFLAGS=
OBJS=avifmin.o parser.o

all: avifmin

avifmin: $(OBJS)
	$(CC) $(LDFLAGS) -o avifmin $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f avifmin $(OBJS)

scan-build: clean
	scan-build --use-cc=clang make

format:
	clang-format -i -style=file *.[ch]
