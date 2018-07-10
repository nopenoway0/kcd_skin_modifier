IDIR=source/headers
SDIR=source/source/*
MFILE=source/source/main.cpp

main:
	g++ -std=c++11 $(SDIR) -o kcdconverter.out -I$(IDIR)