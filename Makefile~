#Bamphiane Annie Phongphouthai
#bp8qg
#Makefile
#10/13/2017

CXX = clang++
CXXFLAGS = -Wall -g

OFILES= heap.o huffmanNode.o huffmanenc.o huffmanTree.o

.SUFFIXES: .o .cpp

main: 	$(OFILES)
	$(CXX) $(OFILES)

clean:
	/bin/rm -f *.o *~
	/bin/rm -f *.out

heap.o: heap.cpp heap.h huffmanNode.h
huffmanTree.o: huffmanTree.cpp huffmanTree.h huffmanNode.h heap.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmanenc.o: huffmanenc.cpp heap.h huffmanNode.h huffmanTree.h

