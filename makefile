help:
	@echo "--------"
	@echo "build"
build:
	cc energy_info.c -o energy_info
debug:
	cc -g energy_info.c -o energy_info
