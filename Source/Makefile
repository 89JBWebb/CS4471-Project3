make:
	gcc host.c -o host
	gcc virus.c -o virus
	gcc clean.c -o clean
clean:
	rm host virus seed tmp clean
seed:
	cp virus seed
	printf ‘\xde\xad\xbe\xef’ >> seed
	cat host >> seed