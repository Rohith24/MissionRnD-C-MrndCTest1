/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int number_of_nodes(struct node *root,struct node *head)
{
	if (root->next == head)
		return 1;
	else
		return 1 + number_of_nodes(root->next,head);
}
int MergeLists(struct node **list1, struct node **list2) {
	if (!(*list1)){
		(*list1) = (*list2);
		return number_of_nodes((*list1), (*list1));
	}
	if (!(*list2))
		return number_of_nodes((*list1), (*list1));
	struct node *list1head = (*list1), *list2head=(*list2);
	struct node *head;
	if ((*list1)->data < (*list2)->data) {
		head = (*list1);
	}
	else {
		head = (*list2);
		(*list2) = (*list1);
		(*list1) = head;
	}
	while ((*list1)->next && (*list2)) {
		if ((*list1)->next->data >(*list2)->data) {
			struct node *tmp = (*list1)->next;
			(*list1)->next = (*list2);
			(*list2) = tmp;
		}
		if ((*list1)->next == list1head && (*list2)->next == list2head)
			break;
		(*list1) = (*list1)->next;
	}
	(*list1)->next = (*list2);
	(*list1)->next->next = head;
	(*list1)=head;
	int num= number_of_nodes((*list1), (*list1));
	return num;
}

int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	if (*head1 == NULL&&*head2 == NULL)
		return -1;
	return MergeLists(head1, head2);
}


