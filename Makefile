SUFFIXES += .d

VERSION = 4.1
CC     		= /cluster/gcc/6.4.0/bin/g++
CFLAGS  	= $(shell root-config --cflags)
LIBS    	= $(shell root-config --libs) -lEG
RM      	= @-rm -rf 
LNK     	= @-ln -s

CLASSES 	= ConvertDoHIA GiBUUtrack PrepareGiBUU THParticle Utility
SOURCES = $(CLASSES:%=%.cpp)
HEADERS = $(CLASSES:%=%.hpp)
OBJECTS = $(CLASSES:%=%.o)

DICTSRC  = THParticle.hpp
DICTLDEF = MergeDataLinkDef.hpp
DICTHDR  = hparticleDict.hpp
DICTCXX  = hparticleDict.cpp
DICTOBJ  = hparticleDict.o

all: gibuuSoft analysis

gibuuSoft: GibuuSoft.o $(OBJECTS) $(DICTCXX)
	$(CC) -Wall $(CFLAGS) $< $(DICTOBJ) $(OBJECTS) $(LIBS) -o ${SIMDATADIR}/GiBuu/$@
	${RM} ./$@
	${LNK} ${SIMDATADIR}/GiBuu/$@ ./
	
test: test.o Utility.o 
	$(CC) -Wall $< Utility.o  -o $@
		
analysis: AnaGiBUUsim.o $(DICTCXX) $(OBJECTS)
	$(CC) -Wall $(CFLAGS) $< $(LIBS) $(DICTOBJ) $(OBJECTS) -o ${SIMDATADIR}/GiBuu/$@
	${RM} ./$@
	${LNK} ${SIMDATADIR}/GiBuu/$@ ./
	
-include $(OBJECTS:%.o=%.d)
	
%.o: %.cpp 
	$(CC) -c -MMD $(CFLAGS) $<  $(LIBS)

%.o: %.cc
	$(CC) -c -MMD $(CFLAGS) $<  $(LIBS)
	
%.o: %.C
	$(CC) -c -MMD $(CFLAGS) $<  $(LIBS)

$(DICTCXX): $(DICTSRC) $(DICTLDEF)
	rootcint -f $(DICTCXX) -c $(DICTSRC) $(DICTLDEF)
	$(CC) -c $(CFLAGS) $(DICTCXX) -o $(DICTOBJ)
	
	
.PHONY: clean remove

clean:
	$(RM) *.o
	$(RM) *.d
	$(RM) hparticleDict.*

remove:
	$(RM) *.o
	$(RM) *.d
	$(RM) hparticleDict.*
	$(RM) ${SIMDATADIR}/GiBuu/gibuuSoft 
	$(RM) ${SIMDATADIR}/GiBuu/analysis
	$(RM) gibuuSoft
	$(RM) analysis

