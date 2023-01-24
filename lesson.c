#include <stdio.h>
#include <string.h>

typedef void (*ExerciseFn)(void);

typedef struct {
	ExerciseFn fn;
	unsigned int number;
	char title[256];
} Exercise;

typedef struct {
	Exercise exercises[20];
	size_t size;
} Lesson;

Lesson lesson_new(void) {
	Lesson lesson = {
		.size = 0,
	};

	return lesson;
}

void lesson_add_exercise(Lesson *lesson, ExerciseFn fn, char title[256]) {
	Exercise exercise = {
		.fn = fn,
		.number = lesson->size + 1,
	};

	strcpy_s(exercise.title, 256, title);

	lesson->exercises[lesson->size] = exercise;
	lesson->size++;
}

void lesson_display(Lesson lesson) {
	for (size_t i = 0; i < lesson.size; i++) {
		const Exercise exercise = lesson.exercises[i];

		printf("[%u]: ", exercise.number);
		fputs(exercise.title, stdout);
		printf("\n");
	}

	printf("\n");
}

void lesson_select_exercise(Lesson lesson) {
	printf("Escolha um numero de exercicio: ");

	int selected_num;
	scanf_s("%i", &selected_num);

	printf("\n");

	for (size_t i = 0; i < lesson.size; i++) {
		const Exercise exercise = lesson.exercises[i];

		if (selected_num == exercise.number) {
			exercise.fn();
			return;
		}
	}

	printf("'%i' nao e um numero de exercicio valido.\n", selected_num);
}
