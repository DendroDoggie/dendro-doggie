SRC=src/
INCLUDE=include/

all: device_ops.o $(SRC)main.c
	$(CC) device_ops.o $(SRC)main.c -o ftxcom -lftdi1

device_ops.o: $(INCLUDE)device_ops.h $(SRC)device_ops.c
	$(CC) $(SRC)device_ops.c -c

clean:
	rm -rf ftxcom *out* *.o
