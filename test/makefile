all: app.exe run

app.exe: main.c ../lesson.c
	@clang -Wall -o app.exe main.c ../lesson.c

run:
	@./app.exe
