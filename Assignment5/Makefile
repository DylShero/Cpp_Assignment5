CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++23
LDFLAGS  := -lstdc++exp #For print in windows

TARGETS = assignment5a assignment5b assignment5c assignment5d
HDRS = unique_ptr.h shared_ptr.h

all: $(TARGETS)

assignment5a: assignment5a.cc $(HDRS)
	$(CXX) $(CXXFLAGS) assignment5a.cc -o assignment5a $(LDFLAGS)

assignment5b: assignment5b.cc $(HDRS)
	$(CXX) $(CXXFLAGS) assignment5b.cc -o assignment5b $(LDFLAGS)

assignment5c: assignment5c.cc $(HDRS)
	$(CXX) $(CXXFLAGS) assignment5c.cc -o assignment5c $(LDFLAGS)

assignment5d: assignment5d.cc $(HDRS)
	$(CXX) $(CXXFLAGS) assignment5d.cc -o assignment5d $(LDFLAGS)

clean:
	rm -f $(TARGETS) *.o