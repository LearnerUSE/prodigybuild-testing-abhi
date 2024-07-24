#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node *next;
};
struct node *head;

struct node *CreateNode() {
    struct node *new = (struct node*) malloc(sizeof(struct node));
    return new;
}

void InsertAtBegin(int value) {
    struct node *NewNode = CreateNode();
    if (head == NULL) {
        NewNode->data = value;
        head = NewNode;
        NewNode->next = NULL;
    } else {
        printf("\n\t**Element already exists at this position**\n");
    }
}

void InsertAtnthNode(int pos , int value) {
    struct node* temp = head;
    if(pos==1) {
        printf("\n\t**Use Insert at begining**\n");
    } else { 
        struct node *NewNode = CreateNode();
        NewNode->data = value;
        NewNode->next = NULL;
        for (int i=0; i<pos-2; i++) {
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
}

void InsertAtEnd(int value) {
    if (head == NULL) {
        printf("\n\t**Use Insert at begining**\n");
    } else {
        struct node *temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        struct node *NewNode = CreateNode();
        NewNode->data = value;
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
}

void DeleteAtBegin() {
    if (head == NULL) {
        printf("\n\t**No element exists**\n");
    } else {
        head = head->next;
        printf("\n\t**Element deleted successfully**\n");
    }
}

void DeleteAtEnd() {
    if (head == NULL) {
        printf("\n\t**No element exists**\n");
    } else if (head->next == NULL) {
        printf("\n\t**Use Delete at begining**\n");
    } else {
        struct node *temp = head;
        while(temp->next->next!=NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
        free(temp->next);
        printf("\n\t**Element deleted successfully**\n");
    }
}

void DeletenthNode(int pos) {
    struct node *temp = head;
    if (pos == 1) {
        printf("\n\t**Use Delete at begining**\n");
    } else {
        for (int i=0; i<pos-2; i++) {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
        printf("\n\t**Element deleted successfully**\n");
    }
}

void Display() {
    if (head == NULL) {
        printf("\n\t**No elements to display**\n\n");
    } else {
        struct node *temp = head;
        printf("\nCurrent List:\n");
        while(temp!=NULL) {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

void test() {
    head = NULL;
    InsertAtBegin(1);
    InsertAtBegin(2);
    InsertAtBegin(3);
    InsertAtBegin(4);
    InsertAtBegin(5);
    InsertAtBegin(6);
    InsertAtBegin(7);
    InsertAtBegin(8);
    InsertAtBegin(9);
    InsertAtBegin(10);
    InsertAtBegin(11);
    InsertAtBegin(12);
    InsertAtBegin(13);
    InsertAtBegin(14);
    InsertAtBegin(15);
    InsertAtBegin(16);
    InsertAtBegin(17);
    InsertAtBegin(18);
    InsertAtBegin(19);
    InsertAtBegin(20);
    InsertAtBegin(21);
    InsertAtBegin(22);
    InsertAtBegin(23);
    InsertAtBegin(24);
    InsertAtBegin(25);
    InsertAtBegin(26);
    InsertAtBegin(27);
    InsertAtBegin(28);
    InsertAtBegin(29);
    InsertAtBegin(30);
    InsertAtBegin(31);
    InsertAtBegin(32);
    InsertAtBegin(33);
    InsertAtBegin(34);
    InsertAtBegin(35);
    InsertAtBegin(36);
    InsertAtBegin(37);
    InsertAtBegin(38);
    InsertAtBegin(39);
    InsertAtBegin(40);
    InsertAtBegin(41);
    InsertAtBegin(42);
    InsertAtBegin(43);
    InsertAtBegin(44);
    InsertAtBegin(45);
    InsertAtBegin(46);
    InsertAtBegin(47);
    InsertAtBegin(48);
    InsertAtBegin(49);
    InsertAtBegin(50);
    InsertAtBegin(51);
    InsertAtBegin(52);
    InsertAtBegin(53);
    InsertAtBegin(54);
    InsertAtBegin(55);
    InsertAtBegin(56);
    InsertAtBegin(57);
    InsertAtBegin(58);
    InsertAtBegin(59);
    InsertAtBegin(60);
    InsertAtBegin(61);
    InsertAtBegin(62);
    InsertAtBegin(63);
    InsertAtBegin(64);
    InsertAtBegin(65);
    InsertAtBegin(66);
    InsertAtBegin(67);
    InsertAtBegin(68);
    InsertAtBegin(69);
    InsertAtBegin(70);
    InsertAtBegin(71);
    InsertAtBegin(72);
    InsertAtBegin(73);
    InsertAtBegin(74);
    InsertAtBegin(75);
    InsertAtBegin(76);
    InsertAtBegin(77);
    InsertAtBegin(78);
    InsertAtBegin(79);
    InsertAtBegin(80);
    InsertAtBegin(81);
    InsertAtBegin(82);
    InsertAtBegin(83);
    InsertAtBegin(84);
    InsertAtBegin(85);
    InsertAtBegin(86);
    InsertAtBegin(87);
    InsertAtBegin(88);
    InsertAtBegin(89);
    InsertAtBegin(90);
    InsertAtBegin(91);
    InsertAtBegin(92);
    InsertAtBegin(93);
    InsertAtBegin(94);
    InsertAtBegin(95);
    InsertAtBegin(96);
    InsertAtBegin(97);
    InsertAtBegin(98);
    InsertAtBegin(99);
    InsertAtBegin(100);
    Display();
    DeleteAtBegin();
    DeleteAtEnd();
    DeletenthNode(5);
    Display();
}

int main() {
    test();
    return 0;
}