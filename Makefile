EXEC = sistema
CXX = g++
CXXFLAGS = -Wall -std=c++11

SRCS = main.cpp \
       servico/servico.cpp \
       dados/dados.cpp

OBJS = $(SRCS:.cpp=.o)

INCLUDES = -Ientidades -Idados -Iservico

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

clean:
	rm -f $(OBJS) $(EXEC)
