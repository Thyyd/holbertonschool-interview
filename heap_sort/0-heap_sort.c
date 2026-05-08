#include "sort.h"

/**
 * swap - Échange deux entiers dans un tableau
 * @a: Pointeur vers le premier entier
 * @b: Pointeur vers le deuxième entier
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Effectue le sift-down (tamisage vers le bas) sur un heap
 * @array: Le tableau à trier
 * @size: Taille totale du tableau
 * @root: Index de la racine du sous-arbre à tamiser
 * @heap_size: Taille actuelle du heap
 *
 * Description: Cette fonction maintient la propriété du max heap en déplaçant
 * un élément vers le bas jusqu'à ce qu'il soit à sa position correcte.
 * Le parent doit toujours être plus grand que ses enfants.
 */
void sift_down(int *array, size_t size, size_t root, size_t heap_size)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	/* Vérifier si l'enfant gauche existe et est plus grand que la racine */
	if (left < heap_size && array[left] > array[largest])
		largest = left;

	/* Vérifier si l'enfant droit existe et est plus grand que le plus grand actuel */
	if (right < heap_size && array[right] > array[largest])
		largest = right;

	/* Si le plus grand n'est pas la racine, échanger et continuer le sift-down */
	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		sift_down(array, size, largest, heap_size);
	}
}

/**
 * heap_sort - Trie un tableau d'entiers en ordre croissant
 *             en utilisant l'algorithme Heap Sort
 * @array: Le tableau à trier
 * @size: Taille du tableau
 *
 * Description: Implémente l'algorithme de tri par tas (Heap Sort).
 * Étape 1: Construire un max heap à partir du tableau
 * Étape 2: Extraire successivement le maximum et reconstruire le heap
 */
void heap_sort(int *array, size_t size)
{
	int i;

	/* Cas de base : un tableau de taille < 2 est déjà trié */
	if (array == NULL || size < 2)
		return;

	/* Étape 1: Construire le max heap (heapify) */
	/* On commence du dernier nœud non-feuille et on remonte */
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	/* Étape 2: Extraction un par un des éléments du heap */
	for (i = size - 1; i > 0; i--)
	{
		/* Déplacer la racine actuelle (max) à la fin */
		swap(&array[0], &array[i]);
		print_array(array, size);

		/* Appeler sift_down sur le heap réduit */
		sift_down(array, size, 0, i);
	}
}
