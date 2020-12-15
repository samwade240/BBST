MAIN   = src/main.cpp
SRCS   = $(filter-out $(MAIN),$(wildcard src/*.cpp))
OBJS   = $(SRCS:src/%.cpp=obj/%.o)
CFLAGS = -g -I src/
.PHONY: clean test all

all: $(SRCS) $(EXEC)

$(EXEC): $(OBJS) $(MAIN)
	g++ $(CFLAGS) $(OBJS) $(MAIN) -o $@

obj/%.o: src/%.cpp src/%.hpp obj
	g++ -c $(CFLAGS) $< -o $@

obj:
	mkdir -p obj

%test:
	cxxtestgen --runner=ErrorPrinter -o test/test-runner.cpp test/$@.cpp ${SRCS}
	g++ ${CFLAGS} test/test-runner.cpp $(SRCS) -o test-runner
	./test-runner

clean:
	rm -rf $(EXEC) obj test/test-runner.cpp test-runner
