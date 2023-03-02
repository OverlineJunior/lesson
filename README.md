Library for dealing with my college lessons in a consistent way, while also abstracting away information I shouldn't have to deal with while doing the lesson.

# Building

At the time I'm writing this, I don't know of any package manager for C, so the building process should be manual:

1. Paste the "lesson" folder somewhere in your project
2. Add the "lesson.c" file to the compilation process, like this: ```<compiler> <your entry point c file> path_to_lesson_folder/lesson.c```
3. Remove the .git folder inside the library's folder: ```rm -rf .git```, otherwise git won't be able to see this library correctly when staging your project's changes

# Version

SemVer 2.0.2