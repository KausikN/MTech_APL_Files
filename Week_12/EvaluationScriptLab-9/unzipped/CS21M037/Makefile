# *****************************************************************************************
# Project:              CS6150 Lab
# Subtree:              /home/kausik/lab9
# Filename:             Makefile for Dijkstra's Algorithm
# Programmer:           N Kausik
# Host System:          Linux
# Date Created:         01/Oct/2021
# Project:              Implementation of Dijkstra's Algorithm
# *****************************************************************************************

SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INCDIR = ./include
CFLAGS = -g -c -I$(INCDIR)
CC = g++

all: $(BINDIR)/solution

$(BINDIR)/solution: $(OBJDIR)/DijkstraAlgorithmMain.o $(OBJDIR)/DijkstraAlgorithm.o $(OBJDIR)/GraphADT.o $(OBJDIR)/MinHeap.o $(OBJDIR)/NodeType.o $(OBJDIR)/WeightType.o
	$(CC) -g -o $(BINDIR)/solution $(OBJDIR)/DijkstraAlgorithmMain.o $(OBJDIR)/DijkstraAlgorithm.o $(OBJDIR)/GraphADT.o $(OBJDIR)/MinHeap.o $(OBJDIR)/NodeType.o $(OBJDIR)/WeightType.o

$(OBJDIR)/DijkstraAlgorithmMain.o: $(SRCDIR)/DijkstraAlgorithmMain.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/DijkstraAlgorithmMain.o $(SRCDIR)/DijkstraAlgorithmMain.C

$(OBJDIR)/DijkstraAlgorithm.o: $(SRCDIR)/DijkstraAlgorithm.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/DijkstraAlgorithm.o $(SRCDIR)/DijkstraAlgorithm.C

$(OBJDIR)/GraphADT.o: $(SRCDIR)/GraphADT.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/GraphADT.o $(SRCDIR)/GraphADT.C

$(OBJDIR)/MinHeap.o: $(SRCDIR)/MinHeap.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/MinHeap.o $(SRCDIR)/MinHeap.C

$(OBJDIR)/NodeType.o: $(SRCDIR)/NodeType.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/NodeType.o $(SRCDIR)/NodeType.C

$(OBJDIR)/WeightType.o: $(SRCDIR)/WeightType.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/WeightType.o $(SRCDIR)/WeightType.C

clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*