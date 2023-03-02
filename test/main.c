#include <stdio.h>
#include "../lesson.h"

void dummy_fn(void) {
	printf("DummyFn called!");
}

int main(void) {
	Lesson lesson = lesson_new();
	lesson_add_exercise_with_title(&lesson, dummy_fn, "First exercise!");
	lesson_add_exercise(&lesson, dummy_fn);
	lesson_add_exercise(&lesson, dummy_fn);

	lesson_display(lesson);
	lesson_select_exercise(lesson);
}
