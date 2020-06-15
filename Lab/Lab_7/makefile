# Config, just variables
CC=gcc
CFLAGS=-Wall -g
LFLAGS=-lm
TARGET=driver
#Generate source and object lists, also just string variables
C_SRCS := driver.c src/ppm_info.c
HDRS := src/ppm_info.h
OBJS := driver.o src/ppm_info.o
# default target
all: build
	@echo "All Done!"
#Link all built objects
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)
# special build rule
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@