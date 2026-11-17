CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = aperture
SOURCES = $(wildcard src/*.cpp)

INSTALL_DIR = $(HOME)/.local/bin

.PHONY: all build install uninstall clean

all: build

build:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

install: build
	mkdir -p $(INSTALL_DIR)
	install -m 755 $(TARGET) $(INSTALL_DIR)/$(TARGET)

uninstall:
	rm -f $(INSTALL_DIR)/$(TARGET)

clean:
	rm -f $(TARGET)
