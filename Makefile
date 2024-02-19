.DEFAULT_GOAL := create

.PHONY: create

create:
	$(eval FOLDER_NAME := $(filter-out $@,$(MAKECMDGOALS)))
	@mkdir -p $(FOLDER_NAME)
	@echo "#include<vector>\n#include<iostream>\n#include<string>\n\nusing namespace std;\n\n/**\nNotes\n*/\n\nint main() {}" > $(FOLDER_NAME)/solution.cpp
	@touch $(FOLDER_NAME)/notes.excalidraw
	@echo "$(FOLDER_NAME)" > $(FOLDER_NAME)/README.md
	@echo "Folder and files created."

%:
	@:
