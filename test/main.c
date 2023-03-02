#include <stdio.h>
#include "../lesson.h"

void dummy_fn(void) {
	printf("DummyFn called!");
}

int main(void) {
	Lesson lesson = lesson_new();
	lesson_add_exercise(&lesson, dummy_fn, "First exercise!");
	lesson_add_exercise(&lesson, dummy_fn, "Second exercise!");

	lesson_display(lesson);
	lesson_select_exercise(lesson);
}
