#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
float time2[7];
char station[7][50];
char exp[9][20];
int top=-1;
int src;
int des;
int route;
int fl=0;
char pwd[]="DS_KKKFPC";
int call=0;
void addStationTime(){
switch(route)
{
case 1:
#include<C:\Users\Desktop\route1.c> //this location of the route file should be changed accordingly
break;
case 2:
#include<C:\Users\Desktop\route2.c> //this location of the route file should be changed accordingly
break;
default:
    printf("Enter Valid option");
}
}
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
void fullPrintStack(){
int top2;
top2=top;
int i;
for(i=top2;i>=0;i--)
{
    printf("\n%0.2f\t%s",time2[i],station[i]);
}
}
int counter=0,no;
int full=1;
typedef struct info
{
char name[50];
int age;
char gender[20];
long phone;
float fare;
int seat;
int source;
int destination;
struct info *next;
}info;
info *start=NULL;
typedef struct wlist{
    info *node;
    struct wlist *next;
}wlist;
wlist *front,*rear;
void enqueue(info * wl)
{   wlist *newnode;
    newnode=(wlist *)malloc(sizeof(wlist));
    newnode->next=NULL;
    if(newnode==NULL)
    {
        printf("\nQueue full\n");
    }
    else if (rear==NULL)
    {
        newnode->node=wl;
        newnode->node->seat=1;
        rear=newnode;
        front=rear;
    }
    else{
        newnode->node=wl;
        newnode->node->seat=rear->node->seat+1;
        rear->next=newnode;
        rear=newnode;
    }
    printf("\nAdded to waiting list \tWL%d\n",rear->node->seat);
}
void dequeue(){
    wlist *temp;
if (front==NULL)
    {
        printf("\nWaiting List is Empty\n");
    }
else if(front==rear)
{
front=NULL;
rear=NULL;
}
else{
        temp=front;
        front=front->next;
        free(temp);
}
}
void printTicket(info *temp)
{
printf("________________________________________________________________________________\n");
printf("___________________________________Ticket_______________________________________");
printf("\nCongaratulations! Your booking has been confirmed\n");
printf("Name=%s\n",temp->name);
printf("Age=%d\n",temp->age);
printf("Gender=%s\n",temp->gender);
printf("Phone=%ld\n",temp->phone);
printf("Source=%d\n",temp->source);
printf("Destination=%d\n",temp->destination);
printf("SeatNo=%d\n",temp->seat);
printf("Fare=%0.2f\n",temp->fare);
printf("Make sure you carry your ID proofs for verification\nEnjoy your journey!!!!\n");
printf("________________________________________________________________________________\n");
}
void CheckStatus();
void cancellation();
void displayWaitList();
void num();
void reservation();
int addToLinkedList(info *);
void displayLinkedList();
info *isfull(info *,info *);
void main(){ int n;
printf("\nRoute 1- CSMT->Dadar->Kalyan->Karjat->Lonavala->ShivajiNagar->Pune\n");
printf("\nRoute 2- Pune->ShivajiNagar->Lonavala->Karjat->Kalyan->Dadar->CSMT\n");
char str[9];
printf("Enter the admin password - ");
scanf("%s",str);
int res=strcmp(pwd,str);
if(res!=0)
{
printf("\nSorry,you don't have admin rights\n");
exit(0);}
printf("Enter route-");
scanf("%d",&route);
printf("\nEnter the number of seats-");
scanf("%d",&no);
addStationTime();
while(1)
{delay(3);
  printf("\n**************Railway Ticket Reservation**************\n");
printf("     o x o x o x o . . .\n");
printf("   o      _____            _______________ ___=====__T___\n");
printf(" .][__n_n_|DD[  ====_____  |    |.\/.|   | |   |_|     |_\n");
printf(">(________|__|_[_________]_|____|_/\_|___|_|___________|_|\n");
printf("_/oo OOOOO oo`  ooo   ooo   o^o       o^o   o^o     o^o\n\n\n") ;
printf("Train Path- 0.CSMT-1.Dadar-2.Kalyan-3.Karjat-4.Lonavala-5.ShivajiNagar-6.Pune\n\nArrival Time-");
fullPrintStack();
    printf("\n\n\nEnter your choice-\n1.Reservation\n2.Cancellation\n3.Display seat chart\n4.Display Waiting List\n5.Check the current status of your booking\n6.Exit\n");
       scanf("%d",&n);
    switch(n)
    {
    case 1:reservation();
        break;
    case 2:
     cancellation();
     num();
     break;
     case 3:
     displayLinkedList();
     break;
     case 4:
     displayWaitList();
     break;
     case 5:
     CheckStatus();
     break;
     case 6:
        exit(0);
    default:printf("\nError\n");
    }
}
}
info * isfull(info *currentnode,info *newnode)
{
int s=currentnode->source;;
int d=currentnode->destination;
int sn=currentnode->seat;
int s1,d1,sn1;
info *temp=currentnode->next;
if(s>=newnode->destination)
{
full=0;
src=s;
des=d;
fl=0;
return(currentnode);
}
while(temp!=NULL)
{
s1=currentnode->source;
d1=currentnode->destination;
sn1=currentnode->seat;
if(temp->seat==sn)
{
if(d1<=newnode->source&&temp->source>=newnode->destination)
{
full=0;
src=s1;
des=d1;
return(currentnode);
}
if(temp->destination>=d)
{
d=temp->destination;}
}
else
{
if((s==0)&&(d==6))
{
src=s;
des=d;
full=1;
}
else
{
full=0;
src=s;
des=d;
if(d<=newnode->source)
{
return(currentnode);}
}
s=temp->source;
d=temp->destination;
sn=temp->seat;
if(s!=0&&s>=newnode->destination)
{full=0;
src=s;
des=d;
fl=1;
return(currentnode);
}
}
currentnode=temp;
temp=temp->next;
}
if((s==0)&&(d==6))
{
full=1;
src=s;
des=d;
return(NULL);
}
else
{
full=0;
src=s;
des=d;
return(currentnode);
}
}
int addToLinkedList(info *newnode)
{   info *temp,*prev;
    if(start==NULL)
{
        counter++;
	start=newnode;
        newnode->seat=counter;
	return(newnode->seat);
}
else
{
    int x=0,ct=0;
    if(counter<no)
        {
        prev=NULL;
        temp=start;
	while(temp!=NULL)
	{ if(temp->seat-ct!=1)
        {break;}
	prev=temp;
        ct=prev->seat;
        temp=temp->next;
	}
        if(temp==NULL)
	{prev->next=newnode;
        newnode->seat=(prev->seat)+1;
        counter=newnode->seat;
        }
        else
        {
            if(prev==NULL)
            {
             newnode->next=temp;
             newnode->seat=1;
             start=newnode;
             counter++;
            }
            else
            {prev->next=newnode;
            newnode->next=temp;
            newnode->seat=(prev->seat)+1;
            counter++;}
        }
        return(newnode->seat);
        }
        else
        {
         int f=2;
        prev=start;
        temp=start;
        while(temp!=NULL)
	{full=1;
        while(full!=0)
        {
        full=1;
       if(temp->next!=NULL)
       temp=isfull(temp,newnode);
        if(temp==NULL)
        {x=1;
            break;}
        prev=temp;
        temp=temp->next;
        }
        if(temp==NULL&&x==1)
       {
       break;
       }
       temp=prev;
        if(des<=newnode->source)
        {
           f=0;
           break;
        }
        else if(src>=newnode->destination)
        {
           f=1;
           break;
        }
        else
        prev=temp;
	temp=temp->next;
	}
	if(temp==NULL)
        {if(call!=1)
        {enqueue(newnode);}
        return(-1);
        }
        else
        {
        switch(f)
        {
         case 0:
         newnode->next=temp->next;
         temp->next=newnode;
         newnode->seat=temp->seat;
         return(newnode->seat);
        break;
         case 1:
         if(temp==start&&fl==0)
         {
         newnode->next=temp;
         start=newnode;
         newnode->seat=newnode->next->seat;
         }
         else
         {
         newnode->next=prev->next;
         prev->next=newnode;
         newnode->seat=newnode->next->seat;
         }
         return(newnode->seat);
         break;
        }
        }
        }
}
}
void cancellation()
{   long pno;
    printf("\nEnter phone number\n");
    scanf("%ld",&pno);
    info * temp,*prev;
    temp=start;
    wlist *p1=front,*q1=NULL;
        while(p1!=NULL)
        {full=1;call=1;
         if(p1->node->phone==pno)
         {
             break;
         }
         q1=p1;
          p1=p1->next;
        }
        if(front!=NULL)
{
        if(p1!=NULL)
        {
            if(p1==front)
            {
                printf("The amount of Rs.%0.2f will be refunded",p1->node->fare*0.8);
                front=p1->next;
                return;
            }
            else
            {
                q1->next=p1->next;
                return;
            }
        }
        }
    if(start==NULL)
    {
        printf("\nNo seats booked\n");
        return;
    }
    while(temp!=NULL && temp->phone!=pno)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\nNo such phone number found\n");
    return;
    }
    else if(temp==start)
    {
         printf("The amount of Rs.%0.2f will be refunded",temp->fare*0.8);
        start=temp->next;
        temp=start;
        if (start==NULL)
        {
            return;
        }
        if(start->seat!=1)
        {
            counter--;
        }
    }
    else
    {
        printf("The amount of Rs.%0.2f will be refunded",temp->fare*0.8);
        prev->next=temp->next;
        if(temp->next==NULL)
        {
        if(temp->seat!=prev->seat)
        {
        counter--;
        }
        }
        else
        {if((temp->next->seat==temp->seat)||(prev->seat==temp->seat))
        {

        }
        else
        {counter--;}

        }
   }

        full=1;
       int te=-1;
       wlist *p=front,*q=NULL;
        while(p!=NULL)
        {full=1;call=1;
         src=0;des=0;
         te=addToLinkedList(p->node);
        if(te==-1)
       {
        q=p;
        p=p->next;
       }
       else
       {
       if(p==front)
       {
       dequeue();p=front;
       }
       else
       {
       q->next=p->next;
        if(p==rear)
        {
          rear=q;
        }
        p=p->next;
        }
       }
       }
}
void CheckStatus()
{
long pno;
    printf("\nEnter phone number\n");
    scanf("%ld",&pno);
    info * temp;
    temp=start;
    if(start==NULL)
    {
        printf("\nLinked List Empty\n");
        return;
    }
    while(temp!=NULL && temp->phone!=pno)
    {
        temp=temp->next;
    }
    if(temp!=NULL)
    {
      printf("\nYour booking is confirmed\n");
      printf("Your seat no is-%d\n",temp->seat);
      return;
    }
    else
    { wlist *tmp=front;
     while(tmp!=NULL && tmp->node->phone!=pno)
    {
        tmp=tmp->next;
    }
    if(tmp==NULL)
    {
       printf("\nNo such phone number found");
       return;
    }
    else
    {
       printf("\nYou are in the waiting list -WL%d\n",tmp->node->seat);
    }
    }
}
void num()
{
wlist *p;
p=front;int r=1;
while(p!=NULL)
{
p->node->seat=r++;
p=p->next;
}
}
void displayWaitList()
{
char str[9];
printf("Enter the admin password in order to view");
scanf("%s",str);
int res=strcmp(pwd,str);
if(res!=0)
{
printf("\nSorry,you don't have admin rights\n");
return;}
else
{
wlist *p=front;
if(p==NULL)
{
printf("Waiting list is empty");
return;
}
while(p!=NULL)
{
printf("Name=%s\n",p->node->name);
printf("Age=%d\n",p->node->age);
printf("Gender=%s\n",p->node->gender);
printf("Phone=%ld\n",p->node->phone);
printf("Source=%d\n",p->node->source);
printf("Destination=%d\n",p->node->destination);
printf("SeatNo=WL%d\n",p->node->seat);
printf("\n**********************************\n");
p=p->next;
}
}
}
void displayLinkedList(){
char str[9];
printf("Enter the admin password in order to view:");
scanf("%s",str);
int res=strcmp(pwd,str);
if(res!=0)
{
printf("\nSorry,you don't have admin rights\n");
return;}
else
{
info *temp=start;
if (start==NULL)
{
printf("Linked List Empty\n");
return ;
}
while(temp!=NULL)
{
printf("Name=%s\n",temp->name);
printf("Age=%d\n",temp->age);
printf("Gender=%s\n",temp->gender);
printf("Phone=%ld\n",temp->phone);
printf("Source=%d\n",temp->source);
printf("Destination=%d\n",temp->destination);
printf("SeatNo=%d\n",temp->seat);
printf("\n**********************************\n");
temp=temp->next;
}
printf("\n");
}
}

void reservation(){
    char fname[50];
    char lname[50];
    int n=0;

    info *newnode;
    newnode=(info *)malloc(sizeof(info));
    newnode->next=NULL;
    newnode->seat=0;
   printf("Enter first name-");
    scanf ("%s",fname);
    printf("Enter last name-");
    scanf ("%s",lname);
    strcat(fname," ");
    strcat(fname,lname);
    strcpy(newnode->name,fname);
    printf("Enter age-");
    scanf("%d",&newnode->age);
    printf("Enter Gender-");
    scanf("%s",newnode->gender);
    printf("Enter phone number-");
    scanf("%ld",&newnode->phone);
    printf("Enter Source Index-");
    scanf("%d",&newnode->source);
    printf("Enter Destination Index-");
    scanf("%d",&newnode->destination);
    if(newnode->source==newnode->destination||newnode->source<0||newnode->destination>6)
{
    printf("\nPlease select a proper source and destination\n");
    printf("Enter Source Index-");
    scanf("%d",&newnode->source);
    printf("Enter Destination Index-");
    scanf("%d",&newnode->destination);
}
info* check=start;
while(check!=NULL)
{
    if(check->phone==newnode->phone)
    {
        printf("\nEnter a valid phone number\n");
        printf("Re-Enter your phone number\n");
        scanf("%ld",&(newnode->phone));
        check=start;
    }
    else
    {check=check->next;}
}
if(check==NULL)
{wlist *chc=front;
while(chc!=NULL)
{
    if(chc->node->phone==newnode->phone)
    {
        printf("\nEnter a valid phone number\n");
        printf("Re-Enter your phone number\n");
        scanf("%ld",&(newnode->phone));
        chc=front;
    }
    else
    {chc=chc->next;}
}

}


    if(newnode->age<60)
   {

    printf("\nTotal Fare- %d",(newnode->destination - newnode->source)*50);
    newnode->fare=(newnode->destination - newnode->source)*50;}
    else
    {
    printf("\nTotal Fare- %0.0f",((newnode->destination - newnode->source)*50*(0.7)));
    newnode->fare=((newnode->destination - newnode->source)*50*(0.7));
    newnode->next=NULL;
    }


    printf("\nPress 1 to confirm \nPress 2 to go back\n");
    scanf("%d",&n);
    if(n==2)
    {
        return;
    }
  full=1;
  src=0;des=0;call=0;
  int st=addToLinkedList(newnode);
  if(st!=-1)
{
printf("Booking Confirmed \nYour seat no is %d\n",st);
src=0;des=0;
printTicket(newnode);


}


}

