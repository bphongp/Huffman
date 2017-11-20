#Bamphiane Annie Phongphouthai
#bp8qg
#Makefile
#10/13/2017

CXX = clang++
CXXFLAGS = -Wall -g -o encoder
CXXFLAGS2= -Wall -g -o decoder

PRE= heap.o huffmanNode.o huffmanenc.o huffmanTree.o huffmandec.o
IN= huffmandec.o huffmanNode.o

.SUFFIXES: .o .cpp

main: PRE IN

PRE: 	$(PRE)
	$(CXX) $(PRE) $(CXXFLAGS)
IN: 	$(IN)
	$(CXX) $(IN) $(CXXFLAGS)

clean:
	/bin/rm -f *.o *~ encoder
	/bin/rm -f *.o *~ decoder

heap.o: heap.cpp heap.h huffmanNode.h
huffmanTree.o: huffmanTree.cpp huffmanTree.h huffmanNode.h heap.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmanenc.o: huffmanenc.cpp heap.h huffmanNode.h huffmanTree.h

huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmanenc.o: huffmandec.cpp heap.h huffmanNode.h 

