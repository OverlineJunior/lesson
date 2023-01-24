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

Lesson lesson_new(void);

void lesson_add_exercise(Lesson *lesson, ExerciseFn fn, char title[256]);

void lesson_display(Lesson lesson);

void lesson_select_exercise(Lesson lesson);
