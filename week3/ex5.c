#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   struct node *next;
   struct node *previous;
};
struct node *head = NULL;

void print_list(){
	struct node *current = head;
  	printf("\n[ ");
	while(current->next != NULL) {
        	printf("%d, ",current->data);
	        current = current->next;
	}
	printf("%d",current->data);
	printf(" ]");
}

void insert_node(int data){
	if (head == NULL){
		head = (struct node *)malloc(sizeof(struct node));
		head->data = data;
		head->next = NULL;
		head->previous = NULL;
		return;
	}
	struct node *current = head;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = (struct node*)malloc(sizeof(struct node));
	current->next->data = data;
	current->next->next = NULL;
	current->next->previous = current;
}

void delete_node(int del_data){
	if (del_data == head->data){
		struct node *temp = head->next;
		free(head);
		head = temp;
		head->previous = NULL;
		return;
	}
	struct node *current = head->next;
	while((current->data != del_data) && (current != NULL)){
		current = current->next;
	}
	if (current == NULL) {return;}
	
	if (current->next != NULL){
	current->next->previous = current->previous;
	} 
	else 
	{
	current->previous->next = NULL; 
	free(current); 
	return;
	}
	
	current->previous->next = current->next;	
	free(current);
		 
}

int main(){
	insert_node(1);
	insert_node(5);
	insert_node(2);
	print_list();
	delete_node(2);
	print_list();
	
	return 0;
}


