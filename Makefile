.PHONY: implementations test $(FILES)

# Directory containing the source files
SRC_DIR := Codeforces

# Retrieve all .cpp files in the directory
FILES := $(notdir $(wildcard $(SRC_DIR)/*.cpp))
FILES := $(FILES:.cpp=)

implementations:
	@cmake -S . -B build && cmake --build build && (cd build && ctest --output-on-failure)

# General rule for normal mode compilation and execution
$(FILES):
	@./testcode.sh $@

# Test target to handle test mode
test:
ifeq ($(FILENAME),)
	@echo "Usage: make test FILENAME=<filename_without_extension>"
else
	@./testcode.sh $(FILENAME) test
endif
