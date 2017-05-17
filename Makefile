all:
	gcc -Wall -Werror -pedantic -Wextra *.c -o simple_shell && cp man_1_simple_shell simple_shell.1 && gzip simple_shell.1 && sudo cp simple_shell.1.gz /usr/share/man/man1 && mandb
gdb:
	gcc -Wall -Werror -pedantic -Wextra *.c -ggdb -g -o simple_shell
run:
	./simple_shell
run-v:
	valgrind -v ./simple_shell
run-m:
	valgrind --leak-check=full --show-leak-kinds=all ./simple_shell
run-e:
	valgrind --track-origins=yes ./simple_shell
clean:
	sudo rm simple_shell *~ /usr/share/man/man1/simple_shell.1.gz simple_shell.1.gz simple_shell.1 && mandb
