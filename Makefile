.PHONY:
all: potential-spork

CFILES := $(wildcard *.c)
OFILES := $(CFILES:%.c=%.o)

%.o: %.c %.h
	@gcc $(CFLAGS) -c $< -o $@

potential-spork: $(OFILES)
	@ar rcs libpotentialSpork.a $(OFILES)

clean:
	@rm -rf *.o libpotentialSpork.a
