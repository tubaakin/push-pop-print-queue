#include <stdio.h> 
#define SIZE 10
 
//Tuğba Akın 191180008
typedef struct
{
	int array[SIZE];
	int front;
	int rear;
}element;

element queue;


int push_queue();
void pop_queue();
void print_queue();
void Options();


int main()
{
	queue.front = -1;
	queue.rear = -1;
    Options();
}
void Options(){
	int choice;
    while (1)
    {
    	printf("****OPTIONS***\n");
        printf("0.Print all elements of queue \n");
        printf("1.Add an element into the queue \n");
        printf("2.Remove element from the queue \n");
        printf("3.Exit \n");
        printf("Select (0-3)?");
        scanf("%d", &choice);
        switch (choice)
        {
            case 0:
            print_queue();
            break;
            case 1:
            push_queue();
            break;
            case 2:
            pop_queue();
            break;
            case 3:
            exit(0);
            default:
            printf("Invalid choice \n");
        } 
    } 
}

void print_queue()
{
    int i;
    if (queue.front == - 1 || queue.front>queue.rear)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = queue.front; i <= queue.rear; i++)
            printf("%d ", queue.array[i]);
        printf("\n");
    }
}

int push_queue()
{
	int i;
	int temp;
	int ref;
    int new_element;
    if (queue.rear == SIZE - 1){
        printf("The element pushing is failed \n");
    	return 0;	
	}
    else
    {
    	
        printf("Insert the element in the queue : ");
        scanf("%d", &new_element);
 
        if (queue.front == - 1)
    	{
        	queue.front++;
       	    queue.rear = queue.rear + 1;
            queue.array[queue.rear] = new_element;
    	}
    	else{
    		for(ref = queue.front; ref < (queue.rear+1); ref++){
    			if(new_element < queue.array[ref]){
    				for(i = queue.rear; i >= ref; i--){
    					queue.array[i+1] = queue.array[i];
					}
					queue.rear++;
				
					temp = queue.rear;
					queue.rear = ref-1;
					queue.rear = queue.rear + 1;
                    queue.array[queue.rear] = new_element;
					queue.rear = temp;
					break;
    				
				}
				else if(ref == queue.rear){
					queue.rear = queue.rear + 1;
                    queue.array[queue.rear] = new_element;
					break;
				}
			}
		}
        printf("The element has been successfully pushed \n");
        return 1;
    }
} 

void pop_queue()
{
    if (queue.front == - 1 || queue.front > queue.rear)
    {
        printf("Empty queue \n");
        return ;
    }
    else
    {
        printf("Element deleted from the queue is : %d\n", queue.array[queue.front]);
        queue.front = queue.front + 1;
    }
} 
 
