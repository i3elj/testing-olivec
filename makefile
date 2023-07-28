make: src/main.c lib/olive.c lib/stb_image_write.h
	gcc -c src/main.c -o build/obj/main.o
	gcc -c lib/olive.c -o build/obj/olive.o
	gcc build/obj/olive.o build/obj/main.o `pkg-config --libs x11` -o build/bin/main 

clean:
	rm -rf build/obj/*
	rm -rf build/bin/*

run: build/bin/main
	./build/bin/main

