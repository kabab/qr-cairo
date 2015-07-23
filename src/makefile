
all: qr_image.o color.o qr_cairo.o

qr_image.o: qr_image.cc
	g++ qr_image.cc  -c `pkg-config --cflags cairo` -o ../build/qr_image.o
color.o: color.cc
	g++ color.cc -c -o ../build/color.o
qr_cairo.o: qr_cairo.cc
	g++ qr_cairo.cc -c `pkg-config --cflags cairo` -o ../build/qr_cairo.o
