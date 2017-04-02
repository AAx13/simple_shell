#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char**environ;

typedef struct path_list
{
	char *path;
	struct path_list *next;
} p_list;

/* function builds a linked list of paths in $PATH var */
p_list **build_list(p_list **head)
{
	p_list *new_node;
	char *path;
	unsigned int i;

	for (i = 0; environ[i]; i++)
	{
		if (strcmp("PATH", strtok(environ[i], "=")) == 0)
		{
			path = strtok(NULL, ":");
			while (path != NULL)
			{
				new_node = malloc(sizeof(p_list));
				new_node->path = path;
				new_node->next = *head;
				*head = new_node;
				path = strtok(NULL, ":");
			}
		}
	}
	return (head);
}

int main(void)
{
	p_list *list;
	p_list *temp;

	list = NULL;
	build_list(&list);

	/* print list */
	while (list != NULL)
	{
		printf("%s\n", list->path);
		temp = list;
		list = list->next;
		free(temp);
	}
	return (0);
}
