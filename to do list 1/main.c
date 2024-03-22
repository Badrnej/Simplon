#include "header.h"

int main() {
	int choice;
	do {
		printf("\n===== Gestionnaire de tâches =====\n");
		printf("1. Ajouter une tâche\n");
		printf("2. Modifier une tâche\n");
		printf("3. Supprimer une tâche\n");
		printf("4. Filtrer les tâches\n");
		printf("5. Afficher toutes les tâches\n");
		printf("6. Marquer une tâche comme terminée\n");
		printf("7. Quitter\n");

		printf("\nEntrez votre choix : ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				add_task();
				break;
			case 2:
				modify_task();
				break;
			case 3:
				delete_task();
				break;
			case 4:
				filter_tasks();
				break;
			case 5:
				display_tasks();
				break;
			case 6:
				mark_task_done();
				break;
			case 7:
				printf("Programme terminé.\n");
				break;
			default:
				printf("Choix invalide. Veuillez réessayer.\n");
		}
	} while (choice != 7);

	return 0;
}
