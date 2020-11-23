#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char data;
    struct _node *next;
}node;

node *create_list(char data){
    node *head = (node *)malloc(sizeof(node));
    head->data = data;
    head->next = NULL;

    return head;
}

void push(node *head, char data){
    node *current = head;
    
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = new_node;
}

void bpush(node **head, char data){
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    
    *head = new_node;
}

void delete_list(node *head){
    node *tmp;

    while(head != NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int size_list(node *head){
    node *current = head;
    int i = 0;

    while(current->next != NULL){
        current = current->next;
        i++;
    }

    return i;
}

char *string_converter(node *head){
    int i = 0, size = size_list(head);
    char *string = (char *)malloc((sizeof(char) * size) + 1);
    node *current = head;

    while(current->next != NULL){
        string[i] = current->data;
        current = current->next;
        i++;
    }

    string[size] = '\0';
    
    return string;
}

void insert_at(node **head, int index, char data){
    node *current = *head;
    int size = size_list(*head);
    node *new_node;
    
    if(index == 0)
        bpush(&(*head), data);
    else if (index > 0 && index <= size){
        for(int i = 0; i < (index -1); i++)
            current = current->next;

        new_node = (node *)malloc(sizeof(node));

        new_node->data = data;
        new_node->next = current->next;
        current->next = new_node;
    }
    
}

int main(int argc, char **argv){
    node *head = create_list('>');
    char c = 'a';
    char *string;
    
    push(head, ' ');
    
    printf("Insert string: ");

    while(c != '\n'){
        scanf("%c", &c);
        push(head, c);
    }

    insert_at(&head, 0, 'B');

    string = string_converter(head);

    puts(string);

    free(string);
    
    delete_list(head);

    return 0;
}