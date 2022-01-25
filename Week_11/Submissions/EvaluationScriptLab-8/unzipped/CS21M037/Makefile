# *****************************************************************************************
# Project:              CS6150 Lab
# Subtree:              /home/kausik/lab8
# Filename:             Makefile
# Programmer:           N Kausik, CS21M037
# Host System:          Linux
# Date Created:         11/Oct/2021
# Project:              Codebook Generator using Huffman Encoding
# *****************************************************************************************

SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INCDIR = ./include
CFLAGS = -g -c -I$(INCDIR)
CC = g++

all: $(BINDIR)/solution

$(BINDIR)/solution: $(OBJDIR)/CodeBookMain.o $(OBJDIR)/CodeBook.o $(OBJDIR)/HuffmanTree.o
	$(CC) -g -o $(BINDIR)/solution $(OBJDIR)/CodeBookMain.o $(OBJDIR)/CodeBook.o $(OBJDIR)/HuffmanTree.o

$(OBJDIR)/CodeBookMain.o: $(SRCDIR)/CodeBookMain.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/CodeBookMain.o $(SRCDIR)/CodeBookMain.C

$(OBJDIR)/CodeBook.o: $(SRCDIR)/CodeBook.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/CodeBook.o $(SRCDIR)/CodeBook.C

$(OBJDIR)/HuffmanTree.o: $(SRCDIR)/HuffmanTree.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/HuffmanTree.o $(SRCDIR)/HuffmanTree.C

clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*