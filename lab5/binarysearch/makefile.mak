#  Makefile
#    a makefile for the stack example.
#

#            SHELL = 	/bin/sh

#              TOP = .
#      CURRENT_DIR = .

#              CPP = /lib/cpp $(STD_CPP_DEFINES)
              CXX  = g++

#        CCOPTIONS =
#           CFLAGS = $(CDEBUGFLAGS) $(CCOPTIONS) $(ALLDEFINES)
#           RM_CMD = $(RM) *.o core

SRCS=	TestTree.cpp	\
	BSTree.cpp	\

OBJS=	TestTree.o	\
	BSTree.o		\
	link.o

TestTree.o:	BSTree.h

BSTree.o:	BSTree.h

PROGRAMS = testStack

all::  $(PROGRAMS)


TestTree: $(OBJS)
	$(CXX) -o $@ $(OBJS)
#$(CXX) -o $@ $(OBJS) $(LDOPTIONS) $(LOCAL_LIBRARIES) $(LDLIBS)  $(EXTRA_LOAD_FLAGS)

clean::
	$(RM) testStack 

latex::
	latex stack.tex    

###########################################################################
# common rules for all Makefiles - do not edit

emptyrule::

clean::
	rm *.o

