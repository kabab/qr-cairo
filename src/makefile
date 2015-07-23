
all: qr_image.o color.o

qr_image.o: qr_image.cc
	g++ qr_image.cc  -c `pkg-config --libs --cflags cairo`
color.o: color.cc
	g++ color.cc -c

