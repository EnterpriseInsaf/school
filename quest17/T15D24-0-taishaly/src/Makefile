CC = gcc
CFLAGS = -Wall -Werror -Wextra
BUILD_DIR = .
TARGET = $(BUILD_DIR)/Quest

all : build

rebuild : clean all

build : master_modules.o master_levels.o master_status_events.o binary_work.o modules_db.o shared.o
	$(CC) $(BUILD_DIR)/master_modules.o $(BUILD_DIR)/master_levels.o $(BUILD_DIR)/master_status_events.o $(BUILD_DIR)/binary_work.o $(BUILD_DIR)/modules_db.o $(BUILD_DIR)/shared.o -o $(TARGET)

master_modules.o :
	$(CC) $(CFLAGS) -c master_modules.c -o $(BUILD_DIR)/master_modules.o

master_levels.o :
	$(CC) $(CFLAGS) -c master_levels.c -o $(BUILD_DIR)/master_levels.o

master_status_events.o :
	$(CC) $(CFLAGS) -c master_status_events.c -o $(BUILD_DIR)/master_status_events.o

modules_db.o :
	$(CC) $(CFLAGS) -c modules_db.c -o $(BUILD_DIR)/modules_db.o

binary_work.o :
	$(CC) $(CFLAGS) -c binary_work.c -o $(BUILD_DIR)/binary_work.o

shared.o :
	$(CC) $(CFLAGS) -c shared.c -o $(BUILD_DIR)/shared.o

clean :
	rm -rf $(BUILD_DIR)/*.o $(TARGET)
