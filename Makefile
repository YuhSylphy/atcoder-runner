# Makefile

BUILDDIR = ./bin
OBJDIR = $(BUILDDIR)/obj
SRCDIR = ./src
INCDIRS =
LIBDIRS = # -L

# TARGET = $(BUILDDIR)/a.out

CXX = clang++-10
CXXFLAGS = -std=c++17 -stdlib=libc++ -Wall -O2 -DNDEBUG -DONLINE_JUDGE
LDFLAGS =

SRCS := $(shell find $(SRCDIR) -name *.cpp)
OBJS := $(SRCS:./src/%.cpp=$(OBJDIR)/%.o)
OUTS := $(SRCS:./src/%.cpp=$(BUILDDIR)/%.out)
DEPS := $(OBJS:.o=.d)
LIBS = # -l
# INCLUDE := $(shell find $(INCDIRS) -type d)
INCLUDE := $(addprefix -I,$(INCLUDE))

CPPFLAGS := $(INCLUDE) -MMD -MP
LDFLAGS += $(LIBDIRS) $(LIBS)

default:
	make all

# all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CXX) -o $@ $^ $(LDFLAGS)

# $(OUTS): $(OBJS)
# 	mkdir -p $(dir $@)
# 	$(CXX) $(CXXFLAGS) -o $@ $> $(LDFLAGS)

# $(OBJS): $(SRCS)
# 	mkdir -p $(dir $@)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# AtCoder課題のビルド(Clang C++ 10.0.0)
bin/contests/%.out: src/%.cpp
	echo $@ $^
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

.PHONY: all clean rebuild

clean:
	$(RM) -r $(BUILDDIR)

rebuild:
	make clean && make

# RUNNER = ./bin/runner/runner.o

# $(RUNNER): $(RUNNER:./bin/%.o=./src/%.cpp)
# 	echo $(OBJS)
# 	mkdir -p $(dir $@)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# runner: $(RUNNER)

-include $(DEPS)
