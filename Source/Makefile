make:
	gcc host.c -o host
	gcc virus.c -o virus
	gcc test.c -o test
	gcc reader.c -o reader
clean:
	rm host virus seed tmp test
seed:
	cp virus seed
	printf ‘\xde\xad\xbe\xef’ >> seed
	cat host >> seed