#include <stdio.h>
#include <string.h>

#define TITLE_SIZE 256

typedef void (*ExerciseFn)(void);

typedef struct {
	ExerciseFn fn;
	unsigned int number;
	char title[TITLE_SIZE];
} Exercise;

typedef struct {
	Exercise exercises[20];
	int size;
} Lesson;

Lesson lesson_new(void) {
	Lesson lesson = {
		.size = 0,
	};

	return lesson;
}

void lesson_add_exercise(Lesson *lesson, ExerciseFn fn) {
	Exercise exercise = {
		.fn = fn,
		.number = lesson->size + 1,
	};

	lesson->exercises[lesson->size] = exercise;
	lesson->size++;
}

void lesson_add_exercise_with_title(Lesson *lesson, ExerciseFn fn, char title[TITLE_SIZE - 32]) {
	Exercise exercise = {
		.fn = fn,
		.number = lesson->size + 1,
	};

	char title_mod[TITLE_SIZE] = ": ";
	strncat(title_mod, title, TITLE_SIZE);

	strncpy(exercise.title, title_mod, TITLE_SIZE);

	lesson->exercises[lesson->size] = exercise;
	lesson->size++;
}

void lesson_display(Lesson lesson) {
	for (int i = 0; i < lesson.size; i++) {
		const Exercise exercise = lesson.exercises[i];

		char out[TITLE_SIZE + 32] = "[%u]";
		strncat(out, exercise.title, TITLE_SIZE + 32);
		strncat(out, "\n", TITLE_SIZE + 32);
		printf(out, exercise.number);
	}

	printf("\n");
}

void lesson_select_exercise(Lesson lesson) {
	printf("Escolha um numero de exercicio: ");

	int selected_num;
	scanf("%i", &selected_num);

	printf("\n");

	for (int i = 0; i < lesson.size; i++) {
		const Exercise exercise = lesson.exercises[i];

		if (selected_num == exercise.number) {
			exercise.fn();
			return;
		}
	}

	printf("'%i' nao e um numero de exercicio valido.\n", selected_num);
}
