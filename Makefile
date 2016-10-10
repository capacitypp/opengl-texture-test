OBJS=Main.o
OBJPATHS=$(addprefix $(BUILDPATH)/, $(OBJS))
CPPFLAGS=$(INCLUDE) -Wall -O2 -std=c++14 -MMD
LDFLAGS=-lglut -lGLU -lGL
BUILDPATH=./build
CXX=ccache clang++
TARGET=Main

all : makefolder $(OBJPATHS)
	$(CXX) -o $(TARGET) $(LDFLAGS) $(OBJPATHS)

$(BUILDPATH)/%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -o $@ -c $<

makefolder :
	@mkdir -p $(BUILDPATH)

clean :
	$(RM) $(TARGET)
	$(RM) -r -f $(BUILDPATH)

-include $(BUILDPATH)/*.d

