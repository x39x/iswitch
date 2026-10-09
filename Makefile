CC = clang
CFLAGS = -O2 -arch arm64 -Wall -Wextra
LDFLAGS = -framework Carbon

TARGET = iswitch
BINDIR =$(HOME)/.local/bin

.PHONY: all install show

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

install: $(TARGET)
	mkdir -p $(BINDIR)
	install -m 755 $(TARGET) $(BINDIR)/$(TARGET)
show:
	swift available_input_method.swift
