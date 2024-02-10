#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRIPTION_LENGTH 100
#define MAX_DATE_LENGTH 11
#define MAX_PRIORITY_LENGTH 10
#define MAX_TASKS 100

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    char due_date[MAX_DATE_LENGTH];
    char priority[MAX_PRIORITY_LENGTH];
} Task;

void add_task(Task tasks[], int *task_count) {
    if (*task_count >= MAX_TASKS) {
        printf("Cannot add more tasks. Maximum limit reached.\n");
        return;
    }

    Task new_task;
    printf("Enter task description: ");
    scanf(" %[^\n]", new_task.description);
    printf("Enter due date (YYYY-MM-DD): ");
    scanf(" %s", new_task.due_date);
    printf("Enter priority (high/medium/low): ");
    scanf(" %s", new_task.priority);

    tasks[*task_count] = new_task;
    (*task_count)++;

    printf("Task added successfully!\n");
}

void delete_task(Task tasks[], int *task_count) {
    char description[MAX_DESCRIPTION_LENGTH];
    printf("Enter task description to delete: ");
    scanf(" %[^\n]", description);

    int found = 0;
    for (int i = 0; i < *task_count; i++) {
        if (strcmp(tasks[i].description, description) == 0) {
            found = 1;
            for (int j = i; j < (*task_count) - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            (*task_count)--;
            printf("Task deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Task not found.\n");
    }
}

void update_task(Task tasks[], int task_count) {
    char description[MAX_DESCRIPTION_LENGTH];
    printf("Enter task description to update: ");
    scanf(" %[^\n]", description);

    int found = 0;
    for (int i = 0; i < task_count; i++) {
        if (strcmp(tasks[i].description, description) == 0) {
            found = 1;
            printf("Enter updated description: ");
            scanf(" %[^\n]", tasks[i].description);
            printf("Enter updated due date (YYYY-MM-DD): ");
            scanf(" %s", tasks[i].due_date);
            printf("Enter updated priority (high/medium/low): ");
            scanf(" %s", tasks[i].priority);
            printf("Task updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Task not found.\n");
    }
}

void view_tasks(Task tasks[], int task_count) {
    if (task_count == 0) {
        printf("No tasks found.\n");
    } else {
        printf("Tasks:\n");
        for (int i = 0; i < task_count; i++) {
            printf("%d. Description: %s, Due Date: %s, Priority: %s\n", i + 1,
                tasks[i].description, tasks[i].due_date, tasks[i].priority);
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int task_count = 0;
    int choice;

    while (1) {
        printf("\nTo-Do List Manager:\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Update Task\n");
        printf("4. View Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task(tasks, &task_count);
                break;
            case 2:
                delete_task(tasks, &task_count);
                break;
            case 3:
                update_task(tasks, task_count);
                break;
            case 4:
                view_tasks(tasks, task_count);
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}