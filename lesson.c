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

void lesson_add_exercise_with_title(Lesson *lesson, ExerciseFn fn, char title[256 - 32]) {
	Exercise exercise = {
		.fn = fn,
		.number = lesson->size + 1,
	};

	char title_mod[256] = ": ";
	strncat(title_mod, title, 256);

	strncpy(exercise.title, title_mod, 256);

	lesson->exercises[lesson->size] = exercise;
	lesson->size++;
}

void lesson_display(Lesson lesson) {
	for (int i = 0; i < lesson.size; i++) {
		const Exercise exercise = lesson.exercises[i];

		char out[256 + 32] = "[%u]";
		strncat(out, exercise.title, 256 + 32);
		strncat(out, "\n", 256 + 32);
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
