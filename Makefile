build:
	$(MAKE) format
	@mkdir -p build
	gcc main.c -o build/main

format:
	@find . \( -name "*.c" -o -name "*.h" \) -not -name ".*" -print0 \
	| xargs -0 clang-format -i