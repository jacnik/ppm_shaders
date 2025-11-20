target := shader

all: shader

shader: clean
	cc -o $(target) $(target).c

clean:
	rm -f $(target)

run: shader
	./shader

