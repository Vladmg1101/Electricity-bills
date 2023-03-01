#include <stdio.h>
#include <stdlib.h>

struct NOD {
    int data;
    struct NOD * next;
};

struct NOD * create(int data){
    struct NOD  * nod_nou = malloc(sizeof(struct NOD));
    nod_nou -> data = data;
    nod_nou-> next = NULL;
    return nod_nou;
}

struct NOD * add(struct NOD * head, int data){
    if(head == NULL){
        return create(data);
    }
    struct NOD * ptr = head;
    while(ptr -> next != NULL){
        ptr = ptr->next;
    }
    ptr->next = create(data);
    return head;
}

void show(struct NOD * head){
    while(head != NULL){
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main(){
    int command, bill, year, month;
    scanf("%d", &year);
    scanf("%d", &month);
    scanf("%d", &command);
    struct NOD * head = NULL;
    while(scanf("%d", &bill) != EOF){
        head = add(head, bill);
    }
    if(command == 1 ){
        show(head);
    }
    if(command == 2){
        while(head != NULL){
            printf("%d %d %d\n", year, month, head->data);
            month++;
            if(month == 13){
                year++;
                month = 1;
            }
            head = head->next;
        }
    }
    if(command == 3){
        while(head != NULL){
            printf("%d %d %d\n", year, month, head->data);
            month++;
            if(month == 13){
                break;
            }
            head = head->next;
        }
    }
        if (command == 4) {
        int start_month = month, max_bill = -1, max_year = -1;
        while (bill != 1) {
            scanf("%d", &bill);
            head = add(head, bill);
        }
        while (head != NULL) {
            if (head -> data > max_bill && month == start_month) {
                max_bill = head -> data;
                max_year = year;
            }
            month++;
            if (month == 13) {
                year++;
                month = 1;
            }
            head = head -> next;
        }
        printf("%d\n", year);
    }
}
