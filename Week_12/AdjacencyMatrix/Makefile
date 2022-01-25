# *****************************************************************************************
# Project:              CS6150 Lab
# Subtree:              /home/kausik/lab9
# Filename:             Makefile
# Programmer:           N Kausik, CS21M037
# Host System:          Linux
# Date Created:         11/Oct/2021
# Project:              Graph Algorithms using Adjacency Matrix
# *****************************************************************************************

SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INCDIR = ./include
CFLAGS = -g -c -I$(INCDIR)
CC = g++

all: $(BINDIR)/solution

$(BINDIR)/solution: $(OBJDIR)/AdjacencyMatrixMain.o $(OBJDIR)/AdjacencyMatrix.o $(OBJDIR)/ElementType.o
	$(CC) -g -o $(BINDIR)/solution $(OBJDIR)/AdjacencyMatrixMain.o $(OBJDIR)/AdjacencyMatrix.o $(OBJDIR)/ElementType.o

$(OBJDIR)/AdjacencyMatrixMain.o: $(SRCDIR)/AdjacencyMatrixMain.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/AdjacencyMatrixMain.o $(SRCDIR)/AdjacencyMatrixMain.C

$(OBJDIR)/AdjacencyMatrix.o: $(SRCDIR)/AdjacencyMatrix.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/AdjacencyMatrix.o $(SRCDIR)/AdjacencyMatrix.C

$(OBJDIR)/ElementType.o: $(SRCDIR)/ElementType.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/ElementType.o $(SRCDIR)/ElementType.C

clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*