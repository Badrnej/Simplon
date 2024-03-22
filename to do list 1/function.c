#include "header.h"

Task tasks[MAX_TASKS];
int numTasks = 0;

void add_task() {
	if (numTasks >= MAX_TASKS) {
		printf("Nombre maximal de tâches atteint.\n");
		return;
	}

	char priority_choice;
	printf("Titre de la tâche : ");
	scanf(" %[^\n]s", tasks[numTasks].title);

	printf("Choisissez la priorité:\n");
	printf("1. tres important\n");
	printf("2. important\n");
	printf("3. pas important\n");
	printf("Votre choix : ");
	scanf(" %c", &priority_choice);

	switch (priority_choice) {
		case '1':
			strcpy(tasks[numTasks].priority, "tres important");
			break;
		case '2':
			strcpy(tasks[numTasks].priority, "important");
			break;
		case '3':
			strcpy(tasks[numTasks].priority, "pas important");
			break;
		default:
			printf("Choix de priorité invalide. La priorité sera définie sur 'Non spécifié'.\n");
			strcpy(tasks[numTasks].priority, "Non spécifié");
			break;
	}

	printf("Date d'échéance (JJ/MM/AAAA) : ");
	scanf(" %[^\n]s", tasks[numTasks].deadline);
	tasks[numTasks].done = 0;

	numTasks++;
	printf("Tâche ajoutée avec succès.\n");
}

void modify_task() {
	int index;
	printf("Numéro de la tâche à modifier : ");
	scanf("%d", &index);
	index--;

	if (index < 0 || index >= numTasks) {
		printf("Numéro de tâche invalide.\n");
		return;
	}

	printf("Nouveau titre de la tâche : ");
	scanf(" %[^\n]s", tasks[index].title);
	printf("Nouvelle priorité (tres important, important, pas important) : ");
	scanf(" %[^\n]s", tasks[index].priority);
	printf("Nouvelle date d'échéance (JJ/MM/AAAA) : ");
	scanf(" %[^\n]s", tasks[index].deadline);

	printf("Tâche modifiée avec succès.\n");
}

void delete_task() {
	int index;
	printf("Numéro de la tâche à supprimer : ");
	scanf("%d", &index);
	index--;

	if (index < 0 || index >= numTasks) {
		printf("Numéro de tâche invalide.\n");
		return;
	}

	for (int i = index; i < numTasks - 1; i++) {
		tasks[i] = tasks[i + 1];
	}

	numTasks--;
	printf("Tâche supprimée avec succès.\n");
}

void filter_tasks() {
	char filter[20];
	printf("Filtrer par priorité (tres important, important, pas important) ou par date d'échéance (JJ/MM/AAAA) : ");
	scanf(" %[^\n]s", filter);

	printf("Tâches filtrées :\n");
	for (int i = 0; i < numTasks; i++) {
		if (strcmp(tasks[i].priority, filter) == 0 || strcmp(tasks[i].deadline, filter) == 0) {
			printf("%d. %s - Priorité: %s - Échéance: %s - Terminée: %s\n", i + 1, tasks[i].title, tasks[i].priority, tasks[i].deadline, tasks[i].done ? "Oui" : "Non");
		}
	}
}

void display_tasks() {
	printf("Toutes les tâches :\n");
	for (int i = 0; i < numTasks; i++) {
		printf("%d. %s - Priorité: %s - Échéance: %s - Terminée: %s\n", i + 1, tasks[i].title, tasks[i].priority, tasks[i].deadline, tasks[i].done ? "Oui" : "Non");
	}
}

void mark_task_done() {
	int index;
	printf("Numéro de la tâche à marquer comme terminée : ");
	scanf("%d", &index);
	index--;

	if (index < 0 || index >= numTasks) {
		printf("Numéro de tâche invalide.\n");
		return;
	}

	tasks[index].done = 1;
	printf("Tâche marquée comme terminée.\n");
}
