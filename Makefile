CC = gcc
FLAGS = -Wall -Wextra -std=c99
TARGET = temp_stats
SRCS = $(wildcard ./src/*.c)
OBJ = $(SRCS:.c=.o)
INC_PATH = ./inc/

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c
	$(CC) $(FLAGS) -c -I$(INC_PATH) $< -o $@

clean:
	rm -rf $(TARGET) $(OBJ)