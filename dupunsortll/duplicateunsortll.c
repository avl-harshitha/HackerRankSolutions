#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;

void append(int data){
    struct node* ptr = head;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
	    head = temp;
	    return;
	  }
    while(ptr->next != NULL)
    {
         ptr = ptr->next;
    }
    ptr->next = temp;
}

void removeDuplicates(int max) {
    int* hashmap = (int*)calloc(max + 1, sizeof(int));
    struct node* ptr = head;
    struct node* prev = head;
    while(ptr->next != NULL){
    	if(hashmap[ptr->data] == 0)
		hashmap[ptr->data] = 1;
	else{
		prev->next = ptr->next;
	}
	prev = ptr;
    	ptr = ptr->next;
    }
    if(hashmap[ptr->data] == 1)
	prev->next = NULL;
}


void printList() {
   struct node* ptr = head;
   while(ptr->next != NULL) {
   	printf("%d",ptr->data);
	ptr = ptr->next;
   }
   printf("%d\n",ptr->data);
}

int main() {
	int n, val, max = 0;
	scanf("%d", &n);
	for(int i = 0;i < n;i ++)
	    {
		 scanf("%d",&val);
		 if(max < val)
			 max = val;
		 append(val);
	    }
	printList();
	removeDuplicates(max);
	printList();
	return 0;
}

