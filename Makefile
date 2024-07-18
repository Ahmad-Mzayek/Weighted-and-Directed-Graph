# =============================================================

CC = g++
SRC := src
OUTPUT := bin
BUILD := build
INCLUDE := include
CFLAGS := -std=c++23 -Wall -Wextra -g
LFLAGS =

# =============================================================

ifeq ($(OS),Windows_NT)	# For Windows OS.
MAIN := main.exe
SOURCEDIRS := $(SRC)
BUILDDIRS := $(BUILD)
INCLUDEDIRS := $(INCLUDE)
FIXPATH = $(subst /,\,$1)
RM := del /q /f
MD := mkdir

else	# For UNIX OS.
MAIN := main
SOURCEDIRS := $(shell find $(SRC) -type d)
INCLUDEDIRS := $(shell find $(INCLUDE) -type d)
BUILDDIRS := $(BUILD)
FIXPATH = $1
RM = rm -f
MD := mkdir -p

endif	# OS.

# =============================================================

SOURCES := $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))
OBJECTS := $(patsubst $(SRC)/%.cpp,$(BUILD)/%.o,$(SOURCES))
DEPS := $(OBJECTS:.o=.d)
OUTPUTMAIN := $(call FIXPATH,$(OUTPUT)/$(MAIN))
LIBS := $(patsubst %,-L%, $(BUILDDIRS:%/=%))
INCLUDES := $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))

# =============================================================

all: $(OUTPUT) $(BUILD) $(MAIN) run clean

$(OUTPUT):
	$(MD) $(OUTPUT)

$(BUILD):
	$(MD) $(BUILD)

$(MAIN): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS) $(LIBS)

-include $(DEPS)

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -MMD $< -o $@

.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	$(RM) $(call FIXPATH,$(DEPS))

run: all
	./$(OUTPUTMAIN)

# =============================================================
