make:
	gcc -o diuna main.c libki/*.c libki/*.h -lallegro -lallegro_font -lallegro_image
run:
	./diuna
del:
	rm ./diuna
