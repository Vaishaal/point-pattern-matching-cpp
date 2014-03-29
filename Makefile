CXX=g++ -g -gdwarf-2
CFLAGS=-c -Wall -g -Ieigen -Iann/include
LDFLAGS= -lboost_system -lboost_iostreams -lboost_program_options -Lann/lib -lANN
SOURCES=ppm.cpp
OBJECTS=$(SOURCES:.cpp=.o)
SOURCES_MAIN=tests.cpp main.cpp
OBJECTS_MAIN=$(SOURCES_MAIN:.cpp=.o)
EXECUTABLE=main tests
all: $(EXECUTABLE)
main:main.o $(OBJECTS)
	$(CXX) $< $(OBJECTS) $(LDFLAGS) -o $@

tests:tests.o $(OBJECTS)
	$(CXX) $< $(OBJECTS) $(LDFLAGS) -o $@

check: $(EXECUTABLE)
	./tests

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXECUTABLE)
	rm -rf $(OBJECTS)
	rm -rf $(OBJECTS_MAIN)
