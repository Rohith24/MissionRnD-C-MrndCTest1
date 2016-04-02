/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
31, 31, 30, 31, 30, 31 };
struct date{
	int d, m, y;
};
typedef struct date Date;
Date get_date(struct node* datehead){
	Date d1;
	struct node *tempdate1 = datehead;
	d1.d = tempdate1->data * 10 + tempdate1->next->data;
	tempdate1 = tempdate1->next->next;
	d1.m = tempdate1->data * 10 + tempdate1->next->data;
	tempdate1 = tempdate1->next->next;
	d1.y = tempdate1->data * 10 + tempdate1->next->data;
	tempdate1 = tempdate1->next->next;
	d1.y = d1.y * 100 + tempdate1->data * 10 + tempdate1->next->data;
	return d1;
}
int checkdate(Date dat){
	if (dat.d > 31 || dat.d < 0 || dat.m<0 || dat.m>12){
		return 0;
	}
	return 1;
}

int countLeapYears(Date d)
{
	int years = d.y;
	if (d.m <= 2)
		years--;
	return years / 4 - years / 100 + years / 400;
}

int getDifference(Date dt1, Date dt2)
{
	long int n1 = dt1.y * 365 + dt1.d;
	for (int i = 0; i<dt1.m - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(dt1);


	long int n2 = dt2.y * 365 + dt2.d;
	for (int i = 0; i<dt2.m - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);

	
	return (n2 - n1)-1;
}

int between_days(struct node *date1head, struct node *date2head){
	Date d1, d2;
	struct node *tempdate1 = date1head, *tempdate2 = date2head;
	if (date1head != NULL&&date2head != NULL){
		d1 = get_date(date1head);
		d2 = get_date(date2head);
		if (checkdate(d1) && checkdate(d2)){
			return getDifference(d1, d2);
		}
	}
	return -1;
}