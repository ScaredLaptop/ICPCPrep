.PHONY: implementations print-FILES test all $(FILENAMES)

# Directories containing the source files
SRC_DIRS := Codeforces Kattis Leetcode ProjectEuler OtherSite

# Retrieve all .cpp files in the directories and strip off directory and extension
FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
FILENAMES := $(foreach file,$(FILES),$(basename $(notdir $(file))))

implementations:
	@cmake -S . -B build && cmake --build build && (cd build && ctest --output-on-failure)

# General rule for normal mode compilation and execution
all: $(FILENAMES)

$(FILENAMES):
	@$(eval SRC_FILE := $(firstword $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/$@.cpp))))
	@echo "Compiling file: $(SRC_FILE)"
	@./testcode.sh $(SRC_FILE)

print-FILES:
	@echo "Files: $(FILENAMES)"

# Test target to handle test mode
test:
ifeq ($(FILENAME),)
	@echo "Usage: make test FILENAME=<filename_without_extension>"
else
	$(eval SRC_FILE := $(firstword $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/$(FILENAME).cpp))))
	@echo "Testing file: $(SRC_FILE)"
	@./testcode.sh $(SRC_FILE) test
endif
