CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -pthread

SRC = src/ThreadPool.cpp
MAIN = src/main.cpp
TESTS = tests/test_threadpool.cpp
TARGET = scheduler
TEST_TARGET = test_scheduler

all: $(TARGET)

$(TARGET): $(MAIN) $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

test: $(TESTS) $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $^
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)
