#include "main.h"

/**
 *  * add_variable_node_recursive - Recursively adds a variable at the end of a variable list.
 *   * @head: Address of the head pointer.
 *    * @variableLength: Length of the variable.
 *     * @value: Value of the variable.
 *      * @valueLength: Length of the value.
 *       * Return: Address of the head.
 *        */
variable_node *add_variable_node_recursive(variable_node **head, int variableLength, char *value, int valueLength)
{
	    if (*head == NULL) {
		            variable_node *new = malloc(sizeof(variable_node));
			            if (new == NULL)
					                return NULL;

				            new->variableLength = variableLength;
					            new->value = value;
						            new->valueLength = valueLength;
							            new->next = NULL;
								            *head = new;
									            return *head;
										        } else {
												        return add_variable_node_recursive(&((*head)->next), variableLength, value, valueLength);
													    }
}

/**
 *  * free_variable_list_recursive - Recursively frees a variable list.
 *   * @head: Address of the head pointer.
 *    * Return: No return.
 *     */
void free_variable_list_recursive(variable_node **head)
{
	    if (*head == NULL)
		            return;

	        free_variable_list_recursive(&((*head)->next));
		    free((*head)->value);
		        free(*head);
			    *head = NULL;
}

