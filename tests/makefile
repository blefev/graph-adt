CXX=g++
CXX_FLAGS=-isystem ../src -pthread
OBJS=bfs_test_1 bfs_test_2 dfs_test_1 dfs_test_2 dijkstra_test_1 dijkstra_test_2 primm_test_1 primm_test_2

all: $(OBJS)

$(OBJS): %: %.cpp
	$(CXX)  $(CXX_FLAGS) $(LD_FLAGS) -o $@.out $< ../src/graph.cpp

clean:
	rm *.o
	rm *.out

rebuild: clean all
