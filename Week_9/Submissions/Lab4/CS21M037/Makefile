# *****************************************************************************************
# Project:              CS6150 Lab
# Subtree:              /home/kausik/lab4
# Filename:             Makefile for Sorting Algorithms
# Programmer:           N Kausik
# Host System:          Linux
# Date Created:         27/Sept/2021
# Project:              Implementation of Sorting Algorithms (Bubbble Sort and Quick Sort)
# *****************************************************************************************

SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INCDIR = ./include
CFLAGS = -g -c -I$(INCDIR)
CC = gcc

all: $(BINDIR)/solution

$(BINDIR)/solution: $(OBJDIR)/SortingMain.o $(OBJDIR)/SortingAlgos.o
	$(CC) -g -o $(BINDIR)/solution $(OBJDIR)/SortingMain.o $(OBJDIR)/SortingAlgos.o

$(OBJDIR)/SortingMain.o: $(SRCDIR)/SortingMain.c
	$(CC) $(CFLAGS) -o $(OBJDIR)/SortingMain.o $(SRCDIR)/SortingMain.c

$(OBJDIR)/SortingAlgos.o: $(SRCDIR)/SortingAlgos.c
	$(CC) $(CFLAGS) -o $(OBJDIR)/SortingAlgos.o $(SRCDIR)/SortingAlgos.c

clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*