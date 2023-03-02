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

Lesson lesson_new(void);

void lesson_add_exercise(Lesson *lesson, ExerciseFn fn);

void lesson_add_exercise_with_title(Lesson *lesson, ExerciseFn fn, char title[256 - 32]);

void lesson_display(Lesson lesson);

void lesson_select_exercise(Lesson lesson);
