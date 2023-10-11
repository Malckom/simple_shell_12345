#include "main.h"
/**
 *add_sep_node_end - adds a separator found at the end
 *of a new_sep_list.
 * @head: head of the linked list.
 *@sep: separator found (; | &).
 *Return: address of the head.
 **/
new_sep_list *add_sep_node_end(new_sep_list **head, char sep)
{
new_sep_list *new_node, *current;
new_node = malloc(sizeof(new_sep_list));
if (new_node == NULL)
return (NULL);
new_node->separator = sep;
new_node->next = NULL;
current = *head;
if (current == NULL)
{
*head = new_node;
}
else
{
while (current->next != NULL)
current = current->next;
current->next = new_node;
}
return (*head);
}
void handle_separator(new_sep_list **head, char sep)
{
switch (sep)
{
case ';':/* Handle semicolon */
add_sep_node_end(head, ';');
break;
case '|':/* Handle pipe */
add_sep_node_end(head, '|');
break;
case '&':/* Handle ampersand */
add_sep_node_end(head, '&');
break;
default:/* Handle other cases */
break;
}
}
/*
*add_line_node_end -adds command line at end of linked list
*@head- pointer to the head of the linked list
*@line - command line to be added to the linked list.
*return - pointer to head of linked list
*/
new_sep_list *add_line_node_end(new_sep_list **head)
{
new_sep_list *new_node, *current;
new_node = malloc(sizeof(new_sep_list));
if (new_node == NULL)
return (NULL);
new_node->separator = ' ';
new_node->next = NULL;
current = *head;
if (current == NULL)
{
*head = new_node;
}
else
{
while (current->next != NULL)
current = current->next;
current->next = new_node;
}
return (*head);
}

/**
 *free_new_sep_list - frees a new_sep_list
 *@head: address of the head pointer.
 *@ new_node is used to temporarily hold the current node.
 *@current is moved to the next node in the list.
 *return: no return.
 **/
void free_add_node_list(new_sep_list **head)
{
new_sep_list *new_node;
new_sep_list *current;
if (head != NULL)
{
current = *head;
while ((new_node = current) != NULL)
{
current = current->next;
free(new_node);
}
*head = NULL;
}
}

/**
 *free_new_sep_list - frees a linked list of new_sep_list
 *@head: address of the head pointer.
 *return: no return.
 */
void free_add_line_list(new_sep_list **head)
{
new_sep_list *new_node;
new_sep_list *current;
if (head != NULL)
{
current = *head;
while ((new_node = current) != NULL)
{
current = current->next;
free(new_node);
}
*head = NULL;
}
}

