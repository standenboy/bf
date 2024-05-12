all:
	cc bf.c -o bf
install:
	cp bf /usr/local/bin/bf
uninstall:
	rm /usr/local/bin/bf
clean:
	rm bf
