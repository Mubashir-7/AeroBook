#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct Flights{
	char FlightNo[8];
	char FlightName[50];
	char From[20];
	char Destination[20];
	char Departure[10];
	char Arrival[10];
	int Price;
};
struct Flights F[50];

struct Passenger{
	char FlightNo[8];
	int ID;
	char Name[30];
	int Seats;	
};
struct Passenger P[200];

int itr = 0;
int pitr = 0;

void FlightsTable(){
	int f;
	
	printf("\tFlight No#    \tFlight Name    \tDeparture Location    \tDestination    \tDeparture Time   \tArrival Time    \tSeat Price\n");
	
	for(f=0; f<50;f++){
		if(strcmp(F[f].FlightNo,"\0") !=0){
		break;
		}
		else{
		printf("%d    %s\t %s\t %s\t %s\t %s\t %s\t %d\t\n",f,F[f].FlightNo, F[f].FlightName, F[f].From, F[f].Destination, F[f].Departure, F[f].Arrival, F[f].Price);
		}
	}
}

int FlightNoSearch(char num[10]){
	int k, res;
	for (k =0; k < 50; k++){
		res = strcmp(num,F[k].FlightNo);
		if(res == 0){
			return k;
		}
	}
	return -1;
}

void SearchFlight(char dep[20], char des[20]){
	int i;
	for (i=0; i<50; i++){
		if ((strcmp(F[i].Destination,des)==0) && (strcmp(F[i].From,dep)==0)){
			printf("Flight No#: %s\nFlight Name: %s\nDeparture Location: %s\nDestination: %s\nDeparture Time: %s\nArrival Time: %s\nSeat Price: Rs%d\n",F[i].FlightNo, F[i].FlightName, F[i].From, F[i].Destination, F[i].Departure, F[i].Arrival, F[i].Price);		
		}
		else{
			break;
		}
	}
	if (i==0){
		printf("No Flights Available to You Destination");
	}	
}

void AddFlight(){
	char choice = 'y';
	int j = itr;
	int p, i;
	
	while (choice =='y' || choice == 'Y'){
		system("cls");
		FlightsTable();
		fflush(stdin);
		printf("\n\n");
		label:
			printf("Enter Flight No# : ");
			gets(F[j].FlightNo);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
		        if ((F[j].FlightNo[i] >= 'a' && F[j].FlightNo[i] <= 'z') || (F[j].FlightNo[i] >= 'A' && F[j].FlightNo[i] <= 'Z') || (F[j].FlightNo[i] >= '0' && F[j].FlightNo[i] <= '9') || (F[j].FlightNo[i] == '-')){
					continue;
	        	}
	        	else{
		       		goto label;
				}
		   	}
		label_2:
			printf("Enter Flight Name: ");
			gets(F[j].FlightName);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
	        if ((F[j].FlightName[i] >= 'a' && F[j].FlightName[i] <= 'z') || (F[j].FlightName[i] >= 'A' && F[j].FlightName[i] <= 'Z') || (F[j].FlightName[i] == ' ')){
	            continue;
	        }
	        else{
	        	goto label_2;
			}
	    	}
    	label_3:
			printf("Enter Boarding Location: ");
			gets(F[j].From);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
	    	    if ((F[j].From[i] >= 'a' && F[j].From[i] <= 'z') || (F[j].From[i] >= 'A' && F[j].From[i] <= 'Z') || (F[j].From[i] == ' ')){
	       	    	continue;
	        	}
	        	else{
	        		goto label_3;
				}
	    	}
	    label_4:
			printf("Enter Destination: ");
			gets(F[j].Destination);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
	        if ((F[j].Destination[i] >= 'a' && F[j].Destination[i] <= 'z') || (F[j].Destination[i] >= 'A' && F[j].Destination[i] <= 'Z') || (F[j].Destination[i] == ' ')){
	            continue;
	        }
	        else{
	        	goto label_4;
			}
	    	}
		label_5:
			printf("Enter Departure: ");
			gets(F[j].Departure);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
	        if ((F[j].Departure[i] >= 'a' && F[j].Departure[i] <= 'z') || (F[j].Departure[i] >= 'A' && F[j].Departure[i] <= 'Z') || (F[j].Departure[i] == ' ')){
	            continue;
	        }
	        else{
	        	goto label_5;
			}
	    	}
		label_6:
			printf("Enter Arrival: ");
			gets(F[j].Arrival);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
	        if ((F[j].Arrival[i] >= 'a' && F[j].Arrival[i] <= 'z') || (F[j].Arrival[i] >= 'A' && F[j].Arrival[i] <= 'Z') || (F[j].Arrival[i] == ' ')){
	            continue;
	        }
	        else{
	        	goto label_6;
			}
	    	}
			printf("Enter Seat Price: Rs");
			scanf("%d",&F[j].Price);
		
		printf("Do you want to add another Flight? (y/n): ");
		choice = getche();
		j++;
	}
	itr = j;
}


void EditFlight(){
	char choice = 'y';
	char num[10];
	int j,i,p;

	while (choice =='y'){
		system("cls");
		FlightsTable();
		fflush(stdin); 
		printf("Enter Flight No: ");
		gets(num);
		
		j = FlightNoSearch(num);
		if (j==-1){
			printf("No Flight exists for with No: %s",num);
		}
		else{
			printf("Flight No#: %s\nFlight Name: %s\nDeparture Location: %s\nDestination: %s\nDeparture Time: %s\nArrival Time: %s\nSeat Price: Rs%d\n",F[j].FlightNo, F[j].FlightName, F[j].From, F[j].Destination, F[j].Departure, F[j].Arrival, F[j].Price);
			fflush(stdin);
			printf("\n\n");
		label_g:
			printf("Enter Flight No# : ");
			gets(F[j].FlightNo);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
		        if ((F[j].FlightNo[i] >= 'a' && F[j].FlightNo[i] <= 'z') || (F[j].FlightNo[i] >= 'A' && F[j].FlightNo[i] <= 'Z') || (F[j].FlightNo[i] >= '0' && F[j].FlightNo[i] <= '9') || (F[j].FlightNo[i] == '-')){
					continue;
	        	}
	        	else{
		       		goto label_g;
				}
		   	}
		label_e:
			printf("Enter Flight Name: ");
			gets(F[j].FlightName);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
	        if ((F[j].FlightName[i] >= 'a' && F[j].FlightName[i] <= 'z') || (F[j].FlightName[i] >= 'A' && F[j].FlightName[i] <= 'Z') || (F[j].FlightName[i] == ' ')){
	            continue;
	        }
	        else{
	        	goto label_e;
			}
	    	}
    	label_o:
			printf("Enter Boarding Location: ");
			gets(F[j].From);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
	    	    if ((F[j].From[i] >= 'a' && F[j].From[i] <= 'z') || (F[j].From[i] >= 'A' && F[j].From[i] <= 'Z') || (F[j].From[i] == ' ')){
	       	    	continue;
	        	}
	        	else{
	        		goto label_o;
				}
	    	}
	    label_d:
			printf("Enter Destination: ");
			gets(F[j].Destination);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
	        if ((F[j].Destination[i] >= 'a' && F[j].Destination[i] <= 'z') || (F[j].Destination[i] >= 'A' && F[j].Destination[i] <= 'Z') || (F[j].Destination[i] == ' ')){
	            continue;
	        }
	        else{
	        	goto label_d;
			}
	    	}
		label_c:
			printf("Enter Departure: ");
			gets(F[j].Departure);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
	        if ((F[j].Departure[i] >= 'a' && F[j].Departure[i] <= 'z') || (F[j].Departure[i] >= 'A' && F[j].Departure[i] <= 'Z') || (F[j].Departure[i] == ' ')){
	            continue;
	        }
	        else{
	        	goto label_c;
			}
	    	}
		label_b:
			printf("Enter Arrival: ");
			gets(F[j].Arrival);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
	        if ((F[j].Arrival[i] >= 'a' && F[j].Arrival[i] <= 'z') || (F[j].Arrival[i] >= 'A' && F[j].Arrival[i] <= 'Z') || (F[j].Arrival[i] == ' ')){
	            continue;
	        }
	        else{
	        	goto label_b;
			}
	    	}
			printf("Enter Seat Price: Rs");
			scanf("%d",&F[j].Price);

			printf("Do you want to edit another Flight? (y/n): ");
			choice = getche();
		}
	}
}

void ArrivalDeparture(){
	char id[10], choice = 'y';
	int i,j,p;

	while (choice == 'y'){
		system("cls");
		FlightsTable();
		printf("\n\nEnter Flight No.");
		scanf("%s",id);
		
		j = FlightNoSearch(id);
		if (j == -1){
			printf("No Flight exists for with No: %s",id);
			break;
		}
		else{
			printf("\n\n");
		label_f:
			printf("Enter Departure: ");
			gets(F[j].Departure);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
		        if ((F[j].Departure[i] >= 'a' && F[j].Departure[i] <= 'z') || (F[j].Departure[i] >= 'A' && F[j].Departure[i] <= 'Z') || (F[j].Departure[i] == ' ')){
		            continue;
		        }
		        else{
			        	goto label_f;
					}
			    	}
		label_a:
			printf("Enter Arrival: ");
			gets(F[j].Arrival);
			p = strlen(F[j].FlightName);
			for (i = 0; i < p ; i++){
		        if ((F[j].Arrival[i] >= 'a' && F[j].Arrival[i] <= 'z') || (F[j].Arrival[i] >= 'A' && F[j].Arrival[i] <= 'Z') || (F[j].Arrival[i] == ' ')){
		            continue;
		        }
		        else{
		        	goto label_a;
				}
		    	}
			
			printf("Do you want to edit another Flight? (y/n): ");
			choice = getche();
		}
	}
}

void DeleteFlight(){
	char choice='y', num[8];
	int j;
	
	while (choice =='y'){
		system("cls");
		FlightsTable();
		fflush(stdin); 
		printf("Enter Flight No: ");
		gets(num);
		
		j = FlightNoSearch(num);
		if (j==-1){
			printf("No Flight exists for with No: %s",num);
			break;
		}
		else{
			for (j; j<50; j++){
				if (F[j+1].FlightNo == NULL){
					break;
				}
				else{
					strcpy(F[j].FlightNo,F[j+1].FlightNo);
					strcpy(F[j].FlightName,F[j+1].FlightName);
					strcpy(F[j].From,F[j+1].From);
					strcpy(F[j].Destination,F[j+1].Destination);
					strcpy(F[j].Departure,F[j+1].Departure);
					strcpy(F[j].Arrival,F[j+1].Arrival);
					F[j].Price = F[j+1].Price;
				}
			}
		}
	}
}

int FlightDetails(){
	char choice; 
	int temp = 1;
	
	int pin = 9078;
	
	system("cls");
	
	printf("Enter Pin Code for Authorization: ");
	scanf("%d",&temp);
	
	system("cls");
	
	if (temp != pin){
		printf("\nYou are not Authorized to change Flight Details.");
		return 0;
	}
	while (temp){
		system("cls");	
		printf("*****************************************************************");
		printf("*******************************************************\n\t\t\tWelcome To the Airline Rservation Program\n*******************************************************");
		printf("*****************************************************************\n");
		printf("\n\n1. Add New Flight\n2. Edit Flight Record\n3. Flight Arrival and Departure\n4. Delete Flight\n5. Back to Main Menu\nYour Choice: ");
		scanf(" %c",&choice);		
		switch(choice){
			case '1':
				AddFlight();
				break;
			case '2':
				EditFlight();
				break;
			case '3':
				ArrivalDeparture();
				break;
			case '4':
				DeleteFlight();
				break;
			case '5':
				return 0;
		}
	}
	
	return 0;
}

void FlightSchedule(){
	char id[10];
	char choice = 'y';
	int j;
		
	while(choice == 'y'){
		system("cls");
		
		printf("Enter Flight No: ");
		gets(id);
		j = FlightNoSearch(id);
		
		printf("FlightNo# %s\nFlight Name: %s\nBoarding Location: %s\nDestination: %s\nDeparture: %s\nArrival: %s\n", F[j].FlightNo, F[j].FlightName, F[j].From, F[j].Destination, F[j].Departure, F[j].Arrival);		
		
		printf("Do you want to check another Flight Schedule? (y/n): ");
		choice = getche();
	}
	
	
}

void ReserveSeats(){
	char choice='y', des[20], dep[20];
	int j=pitr,p,i;
	
	while (choice =='y'){
		system("cls");
		FlightsTable();
		fflush(stdin); 
		
		printf("\n\nEnter Departure Location: ");
		gets(dep);
		printf("Enter Destination: ");
		gets(des);
		
		SearchFlight(dep,des);
		
		label_8:
			printf("Enter Flight No# : ");
			gets(P[j].FlightNo);
			p = strlen(F[j].FlightNo);
			for (i = 0; i < p ; i++){
		        if ((P[j].FlightNo[i] >= 'a' && P[j].FlightNo[i] <= 'z') || (P[j].FlightNo[i] >= 'A' && P[j].FlightNo[i] <= 'Z') || (P[j].FlightNo[i] >= '0' && P[j].FlightNo[i] <= '9') || (P[j].FlightNo[i] == '-')){
					continue;
	        	}
	        	else{
		       		goto label_8;
				}
			}
			label_11:
			printf("Enter Passenger ID: ");
			scanf("%d",&P[j].ID);
			if (P[j].ID <1000000000 || P[j].ID>9999999999999){
				goto label_11;
			}
		
		
		printf("Do you want Reserve Seats for snother Flight(y/n): ");
		choice = getche();
	}
	pitr=j;
}

int main(){
	int j=1;
	char choice;
	
	while (j){
		system("cls");
		printf("*****************************************************************");
		printf("*******************************************************\n\t\t\tWelcome To the Airline Rservation Program\n*******************************************************");
		printf("*****************************************************************\n");
		printf("\n1. Reserve Seats\n2. Flights Schedule\n3. Passenger Records\n4. Quit\nYour Choice: ");
		scanf(" %c",&choice);

		switch(choice){
			case '1':
				ReserveSeats();
				break;
			case '2':
				FlightSchedule();
				break;
			case '3':
				FlightDetails();
				break;
			case '4':
				exit(1);
		}
		printf("\n\n");
	}
	return 0;
}
