CC=gcc

enigma: codebook.txt enigma.c
	$(CC) enigma.c -o enigma

codebook.txt: codebook_maker
	./codebook_maker

codebook_maker: codebook_maker.c
	$(CC) codebook_maker.c -o codebook_maker

clean:
	rm -f enigma codebook_maker codebook.txt
