#Bamphiane Annie Phongphouthai
#bp8qg
#Makefile
#10/13/2017

CXX = clang++
CXXFLAGS = -Wall -g

OFILES= huffmandec.o huffmanNode.o

.SUFFIXES: .o .cpp

main: 	$(OFILES)
	$(CXX) $(OFILES)

clean:
	/bin/rm -f *.o *~
	/bin/rm -f *.out

huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmanenc.o: huffmandec.cpp heap.h huffmanNode.h 

