#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Booking 1

typedef struct
{
    char from[20];
    char to[20];
    int km;
    char date[20];
    int num_adults;
    int num_children;
}Traveller;

typedef struct
{
    char name[20];
    float ticket_price_adult;
    float ticket_price_child;
    int seats_available;
}Transport;

typedef struct
{
    char name[20];
    float discount;
}BankCard;

void get_traveller_details(Traveller *passenger);
void select_transport(Transport *trans,Traveller *passenger);
void select_payment_method(char *payment_method);
void select_online_payment_mode(char *online_payment_mode);
void apply_discount(float *total_amount,float *discount,char *bank_card_name,float actual_bill);
void print_ticket_details(Traveller *passenger,Transport *trans,float *total_amount,float *discount,float *actual_bill);
void book_tickets();

int i;

FILE *tic;
void get_traveller_details(Traveller *passenger)
{
	tic=fopen("tic.txt","w+");
    printf("---------Welcome to our SVCD Transportation (booking system)---------\n");
    //fprintf(tic,"---------Welcome to our SVCD Transportation (booking system)---------\n");
    printf("Enter the details of passenger(s):\n");
	//fprintf(tic,"Enter the details of passenger(s):\n");
    printf("May I know from where to where you want to travel:\n");
	//fprintf(tic,"May I know from where to where you want to travel:\n");
    printf("From: ");
    scanf("%s", passenger->from);
    printf("To: ");
    scanf("%s", passenger->to);
    printf("Enter number of kilometers you want to journey: ");
    scanf("%d", &passenger->km);
    printf("Date of travelling{dd/mm/yyyy}: ");
    scanf("%s", passenger->date);
    printf("Number of adults: ");
    scanf("%d", &passenger->num_adults);
    printf("Number of children: ");
    scanf("%d", &passenger->num_children);
    fscanf(tic,"%s %s %d %s %d %d", passenger->from,passenger->to,&passenger->km,passenger->date,&passenger->num_adults,&passenger->num_children);
    fprintf(tic,"From:%s \nTo:%s \nno.of km's:%d \nDate:%s \nAdults:%d \nChildren:%d", passenger->from,passenger->to,passenger->km,passenger->date,passenger->num_adults,passenger->num_children);
}

void select_transport(Transport *trans,Traveller *passenger)
{
	if((passenger->num_adults+passenger->num_children)>25)
	{
        printf("\nSorry No mode of transport available");
        fprintf(tic,"\nSorry No mode of transport available");
        exit(0);
    }
    else
	{
	int choice;
    printf("\nSelect mode of transport:\n");
    printf("1. Bus\n");
    printf("2. Train\n");
    printf("3. Cab\n");
    printf("Enter your choice: ");
    fprintf(tic,"\nSelect mode of transport:\n");
    fprintf(tic,"1. Bus\n");
    fprintf(tic,"2. Train\n");
    fprintf(tic,"3. Cab\n");
    fprintf(tic,"Enter your choice: ");
    scanf("%d", &choice);
    fscanf(tic,"%d",&choice);
    fprintf(tic,"%d",choice);
		switch(choice)
	    {
        case 1:
            strcpy(trans->name,"Bus");
            trans->ticket_price_adult=20.0;
            trans->ticket_price_child=10.0;
            trans->seats_available=20;
            if(trans->seats_available>=(passenger->num_adults+passenger->num_children))
			{
                printf("Seats booked successfully!\n");
                fprintf(tic,"\nSeats booked successfully!\n");
            }
            else
			{
                printf("Sorry, the number of seats available is only 20.\n");
                fprintf(tic,"\nSorry, the number of seats available is only 20.\n");
                select_transport(trans,passenger);
            }
            break;
        case 2:
            strcpy(trans->name,"Train");
            trans->ticket_price_adult=10.0;
            trans->ticket_price_child=5.0;
            trans->seats_available=25;
            if(trans->seats_available>=(passenger->num_adults+passenger->num_children)){
                printf("Seats booked successfully!\n");
                fprintf(tic,"\nSeats booked successfully!\n");}
            else
			{
                printf("Sorry, the number of seats available is only 25.\n");
                fprintf(tic,"\nSorry, the number of seats available is only 25.\n");
                select_transport(trans,passenger);
            }
            break;
        case 3:
            strcpy(trans->name,"Cab");
            trans->ticket_price_adult=30.0;
            trans->ticket_price_child=15.0;
            trans->seats_available=5;
            if(trans->seats_available>=(passenger->num_adults+passenger->num_children)){
                printf("Seats booked successfully!\n");
                fprintf(tic,"\nSeats booked successfully!\n");}
            else
			{
                printf("Sorry, the number of seats available is only 5.\n");
                fprintf(tic,"\nSorry, the number of seats available is only 5.\n");
                select_transport(trans,passenger);
            }
            break;
        default:
            printf("Invalid choice. Please select an appropriate choice.\n");
            fprintf(tic,"\nInvalid choice. Please select an appropriate choice.\n");
            select_transport(trans,passenger);
            break;
        }
	}
}

void select_payment_method(char *payment_method)
{
    int choice;
    printf("\nSelect mode of payment:\n");
    printf("1. Cash\n");
    printf("2. Online\n");
    printf("Enter your choice: ");
    fprintf(tic,"\nSelect mode of payment:\n");
    fprintf(tic,"1. Cash\n");
    fprintf(tic,"2. Online\n");
    fprintf(tic,"Enter your choice: ");
    scanf("%d",&choice);
    fscanf(tic,"%d",&choice);
    fprintf(tic,"%d",choice);
    switch(choice)
	{
        case 1:
            strcpy(payment_method,"Cash");
            break;
        case 2:
            strcpy(payment_method,"Online");
            break;
        default:
            printf("Invalid choice. Please select an appropriate choice.\n");
            fprintf(tic,"Invalid choice. Please select an appropriate choice.\n");
            select_payment_method(payment_method);
            break;
    }
}

void select_online_payment_mode(char *online_payment_mode)
{
    int choice;
    printf("\nSelect mode of online payment:\n");
    printf("1. Card\n");
    printf("2. UPI\n");
    printf("Enter your choice: ");
    fprintf(tic,"\nSelect mode of online payment:\n");
    fprintf(tic,"1. Card\n");
    fprintf(tic,"2. UPI\n");
    fprintf(tic,"Enter your choice: ");
    scanf("%d",&choice);
    fscanf(tic,"%d",&choice);
    fprintf(tic,"%d",choice);
    switch(choice)
	{
        case 1:
            strcpy(online_payment_mode,"Card");
            break;
        case 2:
            strcpy(online_payment_mode,"UPI");
            break;
        default:
            printf("Invalid choice.Please select an appropriate choice.\n");
            fprintf(tic,"\nInvalid choice.Please select an appropriate choice.\n");
            select_online_payment_mode(online_payment_mode);
            break;
    }
}

void apply_discount(float *total_amount,float *discount,char *bank_card_name,float actual_bill)
{
    BankCard cards[3]={{"SBI", 0.05},{"CANARA", 0.1},{"HDFC", 0.15}};
    for(i=0;i<3;i++)
	{
        if(strcmp(bank_card_name,cards[i].name)==0)
		{
            *discount=cards[i].discount * actual_bill;
            *total_amount=actual_bill - *discount;
            break;
        }
    }

    if(*discount==0.0)
	{
        printf("Sorry,we cant avail discount for this bank card.\n");
        fprintf(tic,"\nSorry,we cant avail discount for this bank card.\n");
    }

}

void print_ticket_details(Traveller *passenger,Transport *trans,float *total_amount,float *discount,float *actual_bill)
{
    printf("---------Ticket Details---------\n");
    printf("From: %s\n",passenger->from);
    printf("To: %s\n",passenger->to);
    printf("Number of kilometers: %d\n",passenger->km);
    printf("Date of travel: %s\n",passenger->date);
    printf("Number of adults: %d\n",passenger->num_adults);
    printf("Number of children: %d\n",passenger->num_children);
    printf("Mode of transport selected: %s\n",trans->name);
    printf("Total amount: %.2f\n",*total_amount+*discount);
    printf("Discount applied: %.2f\n",*discount);
    printf("Actual bill to be pay after discount applied: %.2f\n",*actual_bill);
    printf("Successfully, your tickets are booked.\n");
    printf("Hope you will enjoy the ride.\n");
    printf("Happy journey!\n");
    printf("-----------------------------\n");
    // Save ticket details to a file
    if(tic==NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    fprintf(tic,"\n---------Ticket Details---------\n");
    fprintf(tic,"From: %s\n",passenger->from);
    fprintf(tic,"To: %s\n",passenger->to);
    fprintf(tic,"Number of kilometers: %d\n",passenger->km);
    fprintf(tic,"Date of travel: %s\n",passenger->date);
    fprintf(tic,"Number of adults: %d\n",passenger->num_adults);
    fprintf(tic,"Number of children: %d\n",passenger->num_children);
    fprintf(tic,"Mode of transport selected: %s\n",trans->name);
    fprintf(tic,"Total amount: %.2f\n",*total_amount + *discount);
    fprintf(tic,"Discount applied: %.2f\n",*discount);
    fprintf(tic,"Actual bill to be paid after discount applied: %.2f\n",*actual_bill);
    fprintf(tic,"Successfully, your tickets are booked.\n");
    fprintf(tic,"Hope you will enjoy the ride.\n");
    fprintf(tic,"Happy journey!\n");
    fprintf(tic,"----------------------------------\n");
}

void book_tickets()
{
    Traveller passenger[Booking];
    Transport trans;

    get_traveller_details(&passenger[0]);
    select_transport(&trans,&passenger[0]);

    if(trans.seats_available>=(passenger[0].num_adults+passenger[0].num_children))
	{
        char payment_method[10];
        char online_payment_mode[10];
        float total_amount,discount=0,actual_bill;

        select_payment_method(payment_method);

        if(strcmp(payment_method,"Online")==0)
		{
            select_online_payment_mode(online_payment_mode);
        }

        total_amount=(passenger[0].num_adults*trans.ticket_price_adult*passenger[0].km)+(passenger[0].num_children*trans.ticket_price_child*passenger[0].km);
        actual_bill=total_amount;

        if(strcmp(payment_method,"Online")==0 && strcmp(online_payment_mode,"Card")==0)
		{
            char bank_card_name[20];
            printf("Enter the name of your bank card: ");
            fprintf(tic,"\nEnter the name of your bank card: ");
            scanf("%s",bank_card_name);
            apply_discount(&total_amount,&discount,bank_card_name,actual_bill);
            fprintf(tic,"%s",bank_card_name);
            actual_bill=total_amount;
        }
        print_ticket_details(&passenger[0],&trans,&total_amount,&discount,&actual_bill);
    }
}