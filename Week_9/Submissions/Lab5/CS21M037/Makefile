# *****************************************************************************************
# Project:              CS6150 Lab
# Subtree:              /home/kausik/lab5
# Filename:             Makefile for Big Integer Addition
# Programmer:           N Kausik
# Host System:          Linux
# Date Created:         27/Sept/2021
# Project:              Implementation of Big Integer Addition
# *****************************************************************************************

SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INCDIR = ./include
CFLAGS = -g -c -I$(INCDIR)
CC = g++

all: $(BINDIR)/solution

$(BINDIR)/solution: $(OBJDIR)/BigIntAddMain.o $(OBJDIR)/BigIntAdd.o $(OBJDIR)/ListADT.o $(OBJDIR)/ElementType.o
	$(CC) -g -o $(BINDIR)/solution $(OBJDIR)/BigIntAddMain.o $(OBJDIR)/BigIntAdd.o $(OBJDIR)/ListADT.o $(OBJDIR)/ElementType.o

$(OBJDIR)/BigIntAddMain.o: $(SRCDIR)/BigIntAddMain.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/BigIntAddMain.o $(SRCDIR)/BigIntAddMain.C

$(OBJDIR)/BigIntAdd.o: $(SRCDIR)/BigIntAdd.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/BigIntAdd.o $(SRCDIR)/BigIntAdd.C

$(OBJDIR)/ListADT.o: $(SRCDIR)/ListADT.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/ListADT.o $(SRCDIR)/ListADT.C

$(OBJDIR)/ElementType.o: $(SRCDIR)/ElementType.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/ElementType.o $(SRCDIR)/ElementType.C

clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*