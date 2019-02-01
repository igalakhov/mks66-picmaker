all:
	g++ -o main.out main.cpp
	./main.out

convert:
	convert out.ppm out.png

