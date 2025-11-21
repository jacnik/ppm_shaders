target := shader

shader: shader.cpp
	cc -O3 -o $(target) $(target).cpp -lm

clean:
	rm -f $(target) *.ppm *.mp4

run: clean shader
	./shader

