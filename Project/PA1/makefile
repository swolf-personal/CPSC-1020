# Config, just variables
PROJECT=PA1
CC=g++
CFLAGS=-Wall -g -std=c++11
LFLAGS=-lm
CARGS=testP3.ppm testP6.ppm
TARGET=driver


#Dynamically find all source files, even in nested dirs
C_SRCS := \
	$(wildcard *.cpp) \
	$(wildcard src/*.cpp) \
	$(wildcard src/**/*.cpp)
#Just like above, but header hunting this time
HDRS := \
	$(wildcard *.h) \
	$(wildcard src/*.h) \
	$(wildcard src/**/*.h) \
#Very scarry patsubt command that effectively
#Just generates object files for all the found sources
OBJS := $(patsubst %.cpp, bin/%.o, $(wildcard *.cpp))
OBJS += $(filter %.o, $(patsubst src/%.cpp, bin/%.o, $(C_SRCS)))


# Catch root directory src files
bin/%.o: %.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Catch all nested directory files
bin/%.o: src/%.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


# default target
all: build
	@echo "All Done!"

#Link all built objects
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

run: build
	./$(TARGET) $(CARGS)

tar: 
	tar -czvf wolf7_$(PROJECT).tar.gz *

which:
	@echo "FOUND SOURCES: ${C_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"

clean:
	rm -f $(TARGET)
	rm -rf bin
	clear
