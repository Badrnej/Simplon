#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

typedef struct {
	    char title[100];
	        char priority[20];
		    char deadline[20];
		        int done;
} Task;

extern Task tasks[MAX_TASKS];
extern int numTasks;

void add_task();
void modify_task();
void delete_task();
void filter_tasks();
void display_tasks();
void mark_task_done();

#endif /* HEADER_H */
