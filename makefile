CXX=g++
CXXFLAGS=-std=c++11

main: main.o token_stream.o cal.o
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -c $<
clean:
	rm -rf *.o main
