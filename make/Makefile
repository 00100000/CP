%: %.cpp
	g++ -std=c++17 -DLOCAL -O2 -g -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wcast-qual -Wcast-align -Wno-parentheses -Wno-unknown-pragmas -fsanitize=undefined -fsanitize=address -fno-sanitize-recover -fno-omit-frame-pointer $< -o $@.bin
	./$@.bin

clean up:
	rm -r *.dSYM *.bin *.in *.out *.txt
