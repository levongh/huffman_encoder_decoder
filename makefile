CC = g++
SUBDIRS  = src
OBJ_DIR   = obj
BIN_DIR   = bin
CPPFLAGS = -O3 -std=c++14 -Wall -Werror

.PHONY: all clean

all:
	$(foreach subdir, $(SUBDIRS), cd $(subdir); make all; cd ../;)

clean:
		rm -rf $(OBJ_DIR) $(BIN_DIR)

