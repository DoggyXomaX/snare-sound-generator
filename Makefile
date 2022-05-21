all:
	gcc -DLANG_RU -o bin/snare_sound.exe main.c include/wav.c include/args.c

en:
	gcc -o bin/snare_sound.exe main.c include/wav.c include/args.c

run:
	./bin/snare_sound.exe