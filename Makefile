bf:
	gcc -o bf bf.c
install:
	cp bf /usr/local/bin/
clean:
	rm ./bf
uninstall:
	rm /usr/local/bin/bf
