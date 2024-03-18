#define _CRT_SECURE_NO_WARNINGS
#include "task.h"
#include <stdio.h>
#include <string.h> //for strcpy and memcpy

TASK createTask(char name[MAXNAME], int priorityLevel, char content[MAXCONTENT]) {// , STATE state, time_t time) {
	TASK t;
	t.isEmpty = 0;
	strcpy(t.name, name);
	t.priorityLevel = priorityLevel;
	strcpy(t.content, content);
	//t.state = state;
	//t.time = time;
	return t;
}

void addTaskToList(TASK taskList[], char name[MAXNAME], int priorityLevel, char content[MAXCONTENT]) {// , STATE state, time_t time) {
	TASK newTask = createTask(name, priorityLevel, content);// , state, time);
	for (int index = 0; index < MAX_TASKS; index++) {
		if (taskList[index].isEmpty) {
			taskList[index] = newTask;
			printf("index:%d\ntask: %s\n", index, taskList[index].name);//for debugging
			return;
		}
	}	
}

void deleteTaskFromList(TASK taskList[], char taskToDelete[MAXNAME]) {
	for (int index = 0; index < MAX_TASKS; index++) {
		if (strcmp(taskList[index].name, taskToDelete)) { //finds the correct task to delete by comparing names
			taskList[index].isEmpty = 1; 
			strcpy(taskList[index].name, "");//set all values to empty
			taskList[index].priorityLevel = 0;
			strcpy(taskList[index].content, "");
		}
	}
}

void updateTaskFromList(TASK taskList[], char taskToUpdate[MAXNAME], char newName[MAXNAME], int newPriorityLevel, char newContent[MAXCONTENT]) {
	for (int index = 0; index < MAX_TASKS; index++) {
		if (strcmp(taskList[index].name, taskToUpdate) == 0) { //finds the correct task to update by comparing names
			strcpy(taskList[index].name, newName);//sets to new values as specified by user
			taskList[index].priorityLevel = newPriorityLevel;
			strcpy(taskList[index].content, newContent);
		}
	}
}