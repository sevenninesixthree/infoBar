help:
	@echo "--------"
	@echo "build"
build:
	gcc energy_info.c -o energy_info
debug:
	gcc -g energy_info.c -o energy_info
