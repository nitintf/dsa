.DEFAULT_GOAL := create

.PHONY: create

# Define a template for the C++ code
define CPP_TEMPLATE
#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

int main() {}
endef
export CPP_TEMPLATE

create:
	@ABSOLUTE_PATH=$(filter-out $@,$(MAKECMDGOALS)); \
	mkdir -p $$ABSOLUTE_PATH; \
	echo "$$CPP_TEMPLATE" > $$ABSOLUTE_PATH/solution.cpp; \
	# touch $$ABSOLUTE_PATH/notes.excalidraw; \
	echo "$$ABSOLUTE_PATH" > $$ABSOLUTE_PATH/README.md; \
	echo "Folder and files created at $$ABSOLUTE_PATH."

%:
	@:
