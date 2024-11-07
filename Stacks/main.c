#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	
	int age;
	char name[50];
	char surname[50];
	struct Node* next;
	
};

struct Node* head = NULL;

void getValue(struct Node* temp){
	
	printf("\nPlease enter the age: ");
	scanf(" %d", &temp->age);
	printf("\nPlease enter the name: ");
	scanf(" %s", temp->name);
	printf("\nPlease enter the surname: ");
	scanf(" %s", temp->surname);
	printf("\n\n***Setting Values Is Done !***\n");
}

void pushStack(struct Node* temp){
	
	temp = (struct Node*)malloc(sizeof(struct Node));
	
	if(head){
		temp->next = head;
		head = temp;
	}else{
		head = temp;
		temp->next = NULL;
	}
	
	getValue(temp);
	
}

void stackTop(struct Node* temp){
	
	temp = head;
	printf("\nAge: %d", temp->age);
	printf("\nName: %s", temp->name);
	printf("\nSurname: %s\n", temp->surname);
	
}

void popStack(struct Node* temp){
	
	temp = head;
	stackTop(temp);
	head = temp->next;
	temp->next = NULL;
	free(temp);
	
}

void listStack(struct Node* temp){
	int count = 1;
	temp = head;
	while(temp != '\0'){
		
		printf("\n(%d) Age: %d",count, temp->age);
		printf("\n(%d) Name: %s",count, temp->name);
		printf("\n(%d) Surname: %s",count, temp->surname);
		printf("\n************************\n");
		
		temp = temp->next;
		count++;
		
	}
}

int main() {
	
	int num, count = 0;
	char answer[50] = "yes";
	struct Node* start;
	while(1){
		printf("(1) Add Value\n(2) List Value\n(3) Pop Stack\n(4) Stack Top\n(5) Exit\n");
		scanf(" %d", &num);
		if(num == 1){
			pushStack(start);
			count++;
		}
		else if(num == 2){
			if(count == 0){
				printf("\nNo values added yet\n");
			}
			if(count != 0){
				listStack(start);
				printf("\n");	
			}
		}
		else if(num == 3){
			if(count == 0){
				printf("\nNo values added yet\n");
			}
			if(count != 0){
				popStack(start);
				count--;
			}
		}
		else if(num == 4){
			if(count == 0){
				printf("\nNo values added yet\n");
			}
			if(count != 0){
				stackTop(start);
			}
		}
		else if(num == 5){
			break;
		}
		else{
			printf("Please enter from the numbers that are given");
		}
	}
	return 0;
}
