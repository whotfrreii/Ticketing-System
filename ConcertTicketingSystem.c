#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

#define MAX_USERS 10
#define MAX_CONCERTS 20
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define NUM_TICKET_TYPES 10
#define MAX_CONCERT_NAME_LENGTH 50
#define MAX_ARTIST_NAME_LENGTH 50
#define TAX_RATE 0.12

struct User{ 
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct Concert{
    char name[MAX_CONCERT_NAME_LENGTH];
    char location[50];
    char artist[MAX_ARTIST_NAME_LENGTH];
    int month;
    int day;
    int year;
    int hours;
    int minutes;
    int vip_floora_tickets;
    int vip_floorb_tickets;
    int patron_tickets;
    int lowerbox_premium_tickets;
    int lowerbox_sides_tickets;
    int	lowerbox_center_tickets;
    int upperbox_sides_tickets;
    int upperbox_center_tickets;
    int genadm_A_tickets;
    int genadm_B_tickets;
};

//global variables
int num_users = 0;
int num_concerts = 0;
User users[MAX_USERS]; 
Concert concerts[MAX_CONCERTS]; 

int current_user_index = -1; 
int ticketamount; 
int concertchoice;
int concertIndex;
int adminchoice;
int choice;
int index;
const char *ticket_types[] = {"VIP FLOOR A", "VIP FLOOR B", "PATRON", "LOWER BOX PREMIUM", "LOWER BOX SIDES", "LOWER BOX CENTER", "UPPER BOX SIDES", "UPPER BOX CENTER", "GENERAL ADMISSIONS A", "GENERAL ADMISSIONS B"}; //eto yung lalabas sa type ng tickets
float ticket_prices[NUM_TICKET_TYPES] = {9750, 8500, 7500, 8000, 7000, 6000, 5000, 4000, 2500, 1975}; //eto naman is for the prices
int seatchoice;
float payment;
float receipttotal; 
float totalamount;
int confirmchoice;
char any;
float taxAmount;
float grandTotal;
int paymentMethod;
int onlinePaymentMethod;
char gcashNumber[20];
char gcashAccountName[100];

//maximum ticket amounts 
const int MAX_VIP_FLOOR_A_TICKETS = 800;
const int MAX_VIP_FLOOR_B_TICKETS = 800;
const int MAX_PATRON_TICKETS = 400;
const int MAX_LOWERBOX_PREMIUM_TICKETS = 800;
const int MAX_LOWERBOX_SIDES_TICKETS = 400;
const int MAX_LOWERBOX_CENTER_TICKETS = 400;
const int MAX_UPPERBOX_SIDES_TICKETS = 400;
const int MAX_UPPERBOX_CENTER_TICKETS = 400;
const int MAX_GENADM_A_TICKETS = 400;
const int MAX_GENADM_B_TICKETS = 400;

//function declarations
void startMenu();
void userMenu(); 
void userSignup();
void userLogin(); 
void adminLogin(); 
void adminMenu(); 
int adminAddConcert();
int adminAddTicket(); 
int adminDeleteTicket();
void displayMainMenu();
void userProfile();
void concertMenu();
void updateTicketCountDisplay();
void displayConcertDetails(int concertIndex, int index);
void chooseseat(int concertindex, int index);
void purchaseTicket(int concertIndex, int index, float taxAmount, float grandTotal);
float getPrice(int concertIndex, int seatchoice, int index);
void displayTotalAmount(int concertIndex, int index, float taxAmount, float grandTotal);
void displayReceipt(int concertIndex, int index, float taxAmount, float grandTotal, float payment, const char* paymentMethod);
void displayTicket(int concertIndex, int index);
void concertOne(); 
void concertTwo(); 
void concertThree();
void concertFour();
void concertFive();
void quatityTicket(int concertIndex, int index);
void ticketAvaildetails();
void ticketAvailability(int concertIndex, int index);
void forgotPassword();
void changePassword();
void changeUsername();
void updateTickets(int concertIndex);


int main() {
	strcpy(concerts[0].name, "The 1975 : At their very best.");
    strcpy(concerts[0].artist, "The 1975");
    concerts[0].month = 1;
    concerts[0].day = 23;
    concerts[0].year = 2025;
    concerts[0].hours = 18;
    concerts[0].minutes = 00;
    concerts[0].vip_floora_tickets = 800; 
    concerts[0].vip_floorb_tickets = 800; 
    concerts[0].patron_tickets = 400;
    concerts[0].lowerbox_premium_tickets = 800; 
    concerts[0].lowerbox_sides_tickets = 400;
    concerts[0].lowerbox_center_tickets = 400;
    concerts[0].upperbox_sides_tickets = 400;
    concerts[0].upperbox_center_tickets = 400;
    concerts[0].genadm_A_tickets = 400;
    concerts[0].genadm_B_tickets = 400;
    num_concerts++;

    strcpy(concerts[1].name, "The Eras Tour");
    strcpy(concerts[1].artist, "Taylor Swift");
    concerts[1].month = 3;
    concerts[1].day = 19;
    concerts[1].year = 2025;
    concerts[1].hours = 18;
    concerts[1].minutes = 00;
    concerts[1].vip_floora_tickets = 800;
    concerts[1].vip_floorb_tickets = 800;
    concerts[1].patron_tickets = 400;
    concerts[1].lowerbox_premium_tickets = 800;
    concerts[1].lowerbox_sides_tickets = 400;
    concerts[1].lowerbox_center_tickets = 400;
    concerts[1].upperbox_sides_tickets = 400;
    concerts[1].upperbox_center_tickets = 400;
    concerts[1].genadm_A_tickets = 400;
    concerts[1].genadm_B_tickets = 400;
    num_concerts++;

	strcpy(concerts[2].name, "Portals Tour");
    strcpy(concerts[2].artist, "Melanie Martinez");
    concerts[2].month = 6;
    concerts[2].day = 6;
    concerts[2].year = 2025;
    concerts[2].hours = 17;
    concerts[2].minutes = 00;
    concerts[2].vip_floora_tickets = 800; 
    concerts[num_concerts].vip_floorb_tickets = 800;
    concerts[num_concerts].patron_tickets = 400;
    concerts[num_concerts].lowerbox_premium_tickets = 800;
    concerts[num_concerts].lowerbox_sides_tickets = 400;
    concerts[num_concerts].lowerbox_center_tickets = 400;
    concerts[num_concerts].upperbox_sides_tickets = 400;
    concerts[num_concerts].upperbox_center_tickets = 400;
    concerts[num_concerts].genadm_A_tickets = 400;
    concerts[num_concerts].genadm_B_tickets = 400;
    num_concerts++;
    
    strcpy(concerts[3].name, "Renaissance Tour");
    strcpy(concerts[3].artist, "Beyonce");
    concerts[3].month = 8;
    concerts[3].day = 8;
    concerts[3].year = 2025;
    concerts[3].hours = 19;
    concerts[3].minutes = 00;
    concerts[3].vip_floora_tickets = 800;
    concerts[3].vip_floorb_tickets = 800;
    concerts[3].patron_tickets = 400;
    concerts[3].lowerbox_premium_tickets = 800;
    concerts[3].lowerbox_sides_tickets = 400;
    concerts[3].lowerbox_center_tickets = 400;
    concerts[3].upperbox_sides_tickets = 400;
    concerts[3].upperbox_center_tickets = 400;
    concerts[3].genadm_A_tickets = 400;
    concerts[3].genadm_B_tickets = 400;
    num_concerts++;
    
    strcpy(concerts[4].name, "Chromatica Ball");
    strcpy(concerts[4].artist, "Lady Gaga");
    concerts[4].month = 11;
    concerts[4].day = 17;
    concerts[4].year = 2025;
    concerts[4].hours = 17;
    concerts[4].minutes = 00;
    concerts[4].vip_floora_tickets = 800;
    concerts[4].vip_floorb_tickets = 800;
    concerts[4].patron_tickets = 400;
    concerts[4].lowerbox_premium_tickets = 800;
    concerts[4].lowerbox_sides_tickets = 400;
    concerts[4].lowerbox_center_tickets = 400;
    concerts[4].upperbox_sides_tickets = 400;
    concerts[4].upperbox_center_tickets = 400;
    concerts[4].genadm_A_tickets = 400;
    concerts[4].genadm_B_tickets = 400;
    num_concerts++;
	
	startMenu(); 

    return 0;
}

//function definition

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// for start menu
void startMenu() {
	int startchoice;
	int ifchar;
    do {
        system("cls");
        
        printf("\033[1;36m\nWelcome to Quan2um Concert Ticketing System\033[0m\n");
        printf("\nStart Menu\n");
        printf("[1] User Log In / Sign Up\n");
        printf("[2] Admin Log In\n");
        printf("[0] Exit\n");
        printf("\nEnter your choice: ");

        // Checking if the input is an integer	
        ifchar = scanf("%d", &startchoice);

        // Clearing input buffer
        while (getchar() != '\n');

        if (ifchar != 1) {
            printf("Invalid input! Please enter a number.\n");
            Sleep(1000);
            startMenu();
        }

        if (startchoice < 0 || startchoice > 2) {
            printf("Invalid choice! Please try again.\n");
            Sleep(1000);
            startMenu();
        }

        switch (startchoice) {
            case 1:
                userMenu();
                break;
            case 2:
                adminLogin();
                break;
            case 0:
                printf("Exiting...\n");
                Sleep(2000);
                exit(0);//exit program
        }
    } while (startchoice != 0);

}

//for user menu
void userMenu(){
    int userchoice;
    int ifchar;
    do {
    	system("cls");
        printf("\nUSER MENU\n");
        printf("[1] Sign Up\n");
        printf("[2] Log In\n");
        printf("[3] Back\n");
        printf("\nEnter your choice: ");
        
        // Checking if the input is an integer
        ifchar = scanf("%d", &userchoice);

        // Clearing input buffer
        while (getchar() != '\n');

        if (ifchar != 1) {
            printf("Invalid input! Please enter a number.\n");
            Sleep(1000);
            userMenu();
        }

        if (userchoice < 1 || userchoice > 3) {
            printf("Invalid choice! Please try again.\n");
            Sleep(1000);
            userMenu();
        }

        switch (userchoice) {
            case 1:
                userSignup();
                break;
            case 2:
                userLogin();
                break;
            case 3:
                startMenu();
                break;
            
        }
    } while (userchoice != 0);
}

//for admin login
void adminLogin() {
    char username[20];
    char password[20];
    char choice;

    do {
        system("cls");

        printf("\nPress any key to login or 1 to go back: ");
        choice = getchar(); 

        if (choice != '1') {
            printf("\nEnter admin username: ");
            scanf("%s", username);

            printf("Enter admin password: ");

            int i = 0;
            char ch;
            while ((ch = _getch()) != '\r' && i < sizeof(password) - 1) { 
                if (ch == 8) { 
                    if (i > 0) {
                        i--;
                        printf("\b \b"); 
                    }
                } else {
                    password[i++] = ch;
                    printf("*");
                }
            }
            password[i] = '\0';
            printf("\n");

            if (strcmp(username, "quan2um") == 0 && strcmp(password, "quan2um") == 0) {
                printf("\nAdmin login successful.\n");
                adminMenu();
                return;
            } else {
                printf("\nInvalid admin username or password.");
                Sleep(1000);
            }
            choice = getchar(); 

            if (choice == '1') {
                startMenu();
                return;
            }
        } else {
            startMenu();
            return;
        }
    } while (strcmp(username, "quan2um") != 0 || strcmp(password, "quan2um") != 0);
}

//for admin menu
void adminMenu(){
	int ifchar;
	do{
		system("cls");
		printf("\nAdmin Menu:\n");
	    printf("[1] Add Concert\n");
	    printf("[2] Add Tickets\n");
	    printf("[3] Delete Tickets\n");
	    printf("[4] Ticket Availability\n");
	    printf("[5] Back to Start Menu\n");
	
	    printf("\nEnter your choice: ");	    
	    // Checking if the input is an integer
        ifchar = scanf("%d", &adminchoice);

        // Clearing input buffer
        while (getchar() != '\n');

        if (ifchar != 1) {
            printf("Invalid input! Please enter a number.\n");
            Sleep(1000);
            adminMenu();
        }

        if (adminchoice < 1 || adminchoice > 5) {
            printf("Invalid choice! Please try again.\n");
            Sleep(1000);
            adminMenu();
        }
	
	    switch (adminchoice) {
	        case 1:
	            adminAddConcert();
	            break;
	        case 2:
	            adminAddTicket();
	            break;
	        case 3:
	            adminDeleteTicket();
	            break;
	        case 4:
	            ticketAvaildetails();
	            break;
	        case 5:
	        	printf("Logging Out...");
	        	Sleep(2000);
	        	startMenu();
	        	break;
	    }
        
	}while(adminchoice != 4 || adminchoice != 0);
}
void ticketAvaildetails(){
	int concertchoice;
	int ifchar;
    
    system("cls");
	printf("\nConcerts:\n");
    for (int i = 0; i < num_concerts; i++) {
        printf("[%d] %s\n", i + 1, concerts[i].name);
    }
    
    // If there are concerts added by the admin, display them too
    for (int i = MAX_CONCERTS; i < num_concerts; i++) {
        printf("[%d] %s\n", i + 1, concerts[i].name);
    }
    printf("[0] Back to Admin Menu\n");
    
    printf("Enter your choice: ");
    
    // Checking if the input is an integer
        ifchar = scanf("%d", &concertchoice);

        // Clearing input buffer
        clearInputBuffer();

        if (ifchar != 1) {
            printf("Invalid input! Please enter a number.\n");
            Sleep(1000);
           ticketAvaildetails();
        }

    if (concertchoice >= 1 && concertchoice <= num_concerts) {
        index = concertchoice - 1;
        concertIndex = concertchoice - 1;
        ticketAvailability(concertIndex, index);
    } else if (concertchoice == 0) {
        adminMenu();
    } else {
        printf("Invalid choice! Please try again.\n");
        Sleep(2000);
       ticketAvaildetails();
    }
}

void ticketAvailability(int concertIndex, int index) {
	int ifchar;
    system("cls"); // Clear screen
    printf("\nConcert Details\n");
    printf("Concert Name: %s\n", concerts[index].name);
    printf("Artist: %s\n", concerts[index].artist);
    printf("Date: %02d-%02d-%04d\n", concerts[concertIndex].month, concerts[concertIndex].day, concerts[concertIndex].year);
    printf("Time: %02d:%02d\n", concerts[concertIndex].hours, concerts[concertIndex].minutes);
    printf("Location: SM Mall of Asia Arena, Manila\n");
    printf("\nAvailable Tickets/Seats:\n");
    printf("VIP FLOOR A: %d\n",concerts[concertIndex].vip_floora_tickets);
	printf("VIP FLOOR B: %d\n",concerts[concertIndex].vip_floorb_tickets);
	printf("PATRON: %d\n",concerts[concertIndex].patron_tickets);
	printf("LOWER BOX PREMIUM: %d\n",concerts[concertIndex].lowerbox_premium_tickets);
	printf("LOWER BOX SIDES PREMIUM: %d\n",concerts[concertIndex].lowerbox_sides_tickets);
	printf("LOWER BOX CENTER: %d\n",concerts[concertIndex].lowerbox_center_tickets);
	printf("UPPER BOX SIDES: %d\n",concerts[concertIndex].upperbox_sides_tickets);
	printf("UPPER BOX CENTER: %d\n",concerts[concertIndex].upperbox_center_tickets);
	printf("GENERAL ADMISSIONS A: %d\n",concerts[concertIndex].genadm_A_tickets);
	printf("GENERAL ADMISSIONS B: %d\n",concerts[concertIndex].genadm_B_tickets);
    
    printf("\nPress any key to go back: ");
    getchar(); 
    ticketAvaildetails();
}

//for adding concert as an admin
int adminAddConcert() {
	system("cls");
	
	char choices;
	printf("\nPress any key to enter concert details or 0 to go back.\n");
	scanf(" %c", &choices);
	if (choices != '0') {
	    do {
        printf("Enter concert name (up to %d characters): ", MAX_CONCERT_NAME_LENGTH - 1);
        fflush(stdin); //clear input buffer
        fgets(concerts[num_concerts].name, sizeof(concerts[num_concerts].name), stdin);
        concerts[num_concerts].name[strcspn(concerts[num_concerts].name, "\n")] = '\0';
	        if (strlen(concerts[num_concerts].name) == 0 || strlen(concerts[num_concerts].name) >= MAX_CONCERT_NAME_LENGTH) {
	            printf("Invalid input. Please try again.\n");
	        	}
    	} while (strlen(concerts[num_concerts].name) == 0 || strlen(concerts[num_concerts].name) >= MAX_CONCERT_NAME_LENGTH);

	    do {
	        printf("Enter artist name (up to %d characters): ", MAX_ARTIST_NAME_LENGTH - 1);
	        fflush(stdin); //clear input buffer
	        fgets(concerts[num_concerts].artist, sizeof(concerts[num_concerts].artist), stdin);
	        concerts[num_concerts].artist[strcspn(concerts[num_concerts].artist, "\n")] = '\0';
		        if (strlen(concerts[num_concerts].artist) == 0 || strlen(concerts[num_concerts].artist) >= MAX_ARTIST_NAME_LENGTH) {
		            printf("Invalid input. Please try again.\n");
		        }
	    	} while (strlen(concerts[num_concerts].artist) == 0 || strlen(concerts[num_concerts].artist) >= MAX_ARTIST_NAME_LENGTH);
	    
	    do {
	        printf("Enter concert month [1-12]: ");
	        fflush(stdin); //clear input buffer
	        scanf("%d", &concerts[num_concerts].month);
		        if(concerts[num_concerts].month < 1 || concerts[num_concerts].month > 12){
		        	printf("Invalid input. Pleaase try again.\n");
				}
	    	} while (concerts[num_concerts].month < 1 || concerts[num_concerts].month > 12);
	
	    do {
	        printf("Enter concert day [1-31]: ");
	        fflush(stdin); //clear input buffer
	        scanf("%d", &concerts[num_concerts].day);
		        if(concerts[num_concerts].day < 1 || 
		             (concerts[num_concerts].month == 2 && concerts[num_concerts].day > 28) ||
		             (concerts[num_concerts].day > 31)){
		             	printf("Invalid input. Please try again.\n");
					 }
	    	} while (concerts[num_concerts].day < 1 || 
	             (concerts[num_concerts].month == 2 && concerts[num_concerts].day > 28) ||
	             (concerts[num_concerts].day > 31));
	
	    do {
	        printf("Enter concert year [2025-2026]: ");
	        fflush(stdin); //clear input buffer
	        scanf("%d", &concerts[num_concerts].year);
		        if(concerts[num_concerts].year < 2025 || concerts[num_concerts].year > 2026){
		        	printf("Invalid input. Please try again.\n");
				}
	    	} while (concerts[num_concerts].year < 2025 || concerts[num_concerts].year > 2026);
	
	    printf("Date: %d-%d-%d\n", concerts[num_concerts].month, concerts[num_concerts].day, concerts[num_concerts].year);
	
	    do {
	        printf("Enter concert hours [1-24]: ");
	        fflush(stdin); //clear input buffer
	        scanf("%d", &concerts[num_concerts].hours);
		        if(concerts[num_concerts].hours < 1 || concerts[num_concerts].hours > 24){
		        	printf("Invalid input. Please try again.\n");
				}
	    	} while (concerts[num_concerts].hours < 1 || concerts[num_concerts].hours > 24);
	
	    do {
	        printf("Enter concert minutes [00-59]: ");
	        fflush(stdin); //clear input buffer
	        scanf("%d", &concerts[num_concerts].minutes);
		        if(concerts[num_concerts].minutes < 0 || concerts[num_concerts].minutes > 59){
		        	printf("Invalid input. Please try again.\n");
				}
	    	} while (concerts[num_concerts].minutes < 0 || concerts[num_concerts].minutes > 59);
	
	    printf("Time: %02d:%02d\n", concerts[num_concerts].hours, concerts[num_concerts].minutes);
	    	Sleep(1000);
	    printf("Location: SM Mall of Asia Arena\n");
	    	Sleep(1000);
	    
		system("cls");
		printf("Enter amount of ticket to each seats\n");
		
	    printf("Enter VIP Floor A tickets: ");
	    scanf("%d", &concerts[num_concerts].vip_floora_tickets);
	    while (concerts[num_concerts].vip_floora_tickets > MAX_VIP_FLOOR_A_TICKETS) {
	        printf("Invalid input. Maximum allowed tickets for VIP Floor A is %d. Please enter again: ", MAX_VIP_FLOOR_A_TICKETS);
	        scanf("%d", &concerts[num_concerts].vip_floora_tickets);
	    }
	    
	    printf("Enter VIP Floor B tickets: ");
	    scanf("%d", &concerts[num_concerts].vip_floorb_tickets);
	    while (concerts[num_concerts].vip_floorb_tickets > MAX_VIP_FLOOR_B_TICKETS) {
	        printf("Invalid input. Maximum allowed tickets for VIP Floor B is %d. Please enter again: ", MAX_VIP_FLOOR_B_TICKETS);
	        scanf("%d", &concerts[num_concerts].vip_floorb_tickets);
	    }
	    
	    printf("Enter Patron tickets: ");
	    scanf("%d", &concerts[num_concerts].patron_tickets);
	    while (concerts[num_concerts].patron_tickets > MAX_PATRON_TICKETS) {
	        printf("Invalid input. Maximum allowed tickets for PATRON is %d. Please enter again: ", MAX_PATRON_TICKETS);
	        scanf("%d", &concerts[num_concerts].patron_tickets);
	    }
	    
	    printf("Enter Lowerbox Premium tickets: ");
	    scanf("%d", &concerts[num_concerts].lowerbox_premium_tickets);
	    while (concerts[num_concerts].lowerbox_premium_tickets > MAX_LOWERBOX_PREMIUM_TICKETS) {
	        printf("Invalid input. Maximum allowed tickets for LOWERBOX PREMIUM is %d. Please enter again: ", MAX_LOWERBOX_PREMIUM_TICKETS);
	        scanf("%d", &concerts[num_concerts].lowerbox_premium_tickets);
	    }
	    
	    printf("Enter Lowerbox Sides tickets: ");
	    scanf("%d", &concerts[num_concerts].lowerbox_sides_tickets);
	    while (concerts[num_concerts].lowerbox_sides_tickets > MAX_LOWERBOX_SIDES_TICKETS) {
	        printf("Invalid input. Maximum allowed tickets for LOWERBOX SIDES is %d. Please enter again: ", MAX_LOWERBOX_SIDES_TICKETS);
	        scanf("%d", &concerts[num_concerts].lowerbox_sides_tickets);
	    }
	    
	    printf("Enter Lowerbox Center tickets: ");
	    scanf("%d", &concerts[num_concerts].lowerbox_center_tickets);
	    while (concerts[num_concerts].lowerbox_center_tickets > MAX_LOWERBOX_CENTER_TICKETS) {
	        printf("Invalid input. Maximum allowed tickets for LOWERBOX CENTER is %d. Please enter again: ", MAX_LOWERBOX_CENTER_TICKETS);
	        scanf("%d", &concerts[num_concerts].lowerbox_center_tickets);
	    }
	    
	    printf("Enter Upperbox Sides tickets: ");
	    scanf("%d", &concerts[num_concerts].upperbox_sides_tickets);
	    while (concerts[num_concerts].upperbox_sides_tickets > MAX_UPPERBOX_SIDES_TICKETS) {
	        printf("Invalid input. Maximum allowed tickets for UPPERBOX SIDES is %d. Please enter again: ", MAX_UPPERBOX_SIDES_TICKETS);
	        scanf("%d", &concerts[num_concerts].upperbox_sides_tickets);
	    }
	    
	    printf("Enter Upperbox Center tickets: ");  
	    scanf("%d", &concerts[num_concerts].upperbox_center_tickets);
	    while (concerts[num_concerts].upperbox_center_tickets > MAX_UPPERBOX_CENTER_TICKETS) {
	        printf("Invalid input. Maximum allowed tickets for UPPERBOX CENTER is %d. Please enter again: ", MAX_UPPERBOX_CENTER_TICKETS);
	        scanf("%d", &concerts[num_concerts].upperbox_center_tickets);
	    }
	    
	    printf("Enter General Admission A tickets: ");
	    scanf("%d", &concerts[num_concerts].genadm_A_tickets);
	    while (concerts[num_concerts].genadm_A_tickets > MAX_GENADM_A_TICKETS) {
	        printf("Invalid input. Maximum allowed tickets for GENERAL ADMISSIONS B is %d. Please enter again: ", MAX_GENADM_A_TICKETS);
	        scanf("%d", &concerts[num_concerts].genadm_A_tickets);
	    }
	    
	    printf("Enter General Admission B tickets: ");
	    scanf("%d", &concerts[num_concerts].genadm_B_tickets);
	    while (concerts[num_concerts].genadm_B_tickets > MAX_GENADM_B_TICKETS) {
	        printf("Invalid input. Maximum allowed tickets for GENERAL ADMISSIONS A is %d. Please enter again: ", MAX_GENADM_B_TICKETS);
	        scanf("%d", &concerts[num_concerts].genadm_B_tickets);
	    }
		
		printf("Concert Added Successfully!\n");
	    
	    // Return the index of the newly added concert
		num_concerts++;
		
		Sleep(2000);
	    
	    adminMenu();
	} else {
	    adminMenu();
	}
}


//add ticket as an admin
int adminAddTicket(){
	system("cls");
	printf("Concerts:\n");
    for (int i = 0; i < num_concerts; i++) {
        printf("[%d] %s\n", i + 1, concerts[i].name);
    }
    
    char choices;
	printf("\nPress any key to add tickets or 1 to go back.\n");
	scanf(" %c", &choices);
	if (choices != '1') {
	    printf("Choose concert to add tickets: ");
	    scanf("%d", &concertchoice);
	
	    if (concertchoice < 1 || concertchoice > num_concerts) {
	        printf("Invalid concert choice!\n");
	        return -1;
	    }
	
	    printf("Concert: %s\n", concerts[concertchoice - 1].name);
	    printf("VIP FLOOR A: %d\n",concerts[concertchoice - 1].vip_floora_tickets);
		printf("VIP FLOOR B: %d\n",concerts[concertchoice - 1].vip_floorb_tickets);
		printf("PATRON: %d\n",concerts[concertchoice - 1].patron_tickets);
		printf("LOWER BOX PREMIUM: %d\n",concerts[concertchoice - 1].lowerbox_premium_tickets);
		printf("LOWER BOX SIDES PREMIUM: %d\n",concerts[concertchoice - 1].lowerbox_sides_tickets);
		printf("LOWER BOX CENTER: %d\n",concerts[concertchoice - 1].lowerbox_center_tickets);
		printf("UPPER BOX SIDES: %d\n",concerts[concertchoice - 1].upperbox_sides_tickets);
		printf("UPPER BOX CENTER: %d\n",concerts[concertchoice - 1].upperbox_center_tickets);
		printf("GENERAL ADMISSIONS A: %d\n",concerts[concertchoice - 1].genadm_A_tickets);
		printf("GENERAL ADMISSIONS B: %d\n",concerts[concertchoice - 1].genadm_B_tickets);
		
		//ADD TICKETS TO VVIP A
			int amounttoadd_vvip_a;
		    printf("Amount of tickets to be added to VIP FLOOR A: ");
		    scanf("%d", &amounttoadd_vvip_a);
		
		    if (amounttoadd_vvip_a < 0) {
		        printf("Invalid amount of tickets!\n");
		        return -1;
		    }
		
		    // Check if adding tickets exceeds the maximum allowed
		    if (concerts[concertchoice - 1].vip_floora_tickets + amounttoadd_vvip_a > MAX_VIP_FLOOR_A_TICKETS) {
		        printf("Adding %d tickets would exceed the maximum limit for VIP FLOOR A!\n", amounttoadd_vvip_a);
		        return -1;
		    }
		
		    printf("Amount of tickets to be added: ");
		    scanf("%d", &amounttoadd_vvip_a);
		
		    // Add tickets equally to each type
		    concerts[concertchoice - 1].vip_floora_tickets += amounttoadd_vvip_a; 
	    
	    //ADD TICKETS TO VVIP B
		    int amounttoadd_vvip_b;
		    printf("Amount of tickets to be added to VIP FLOOR B: ");
		    scanf("%d", &amounttoadd_vvip_b);
		
		    if (amounttoadd_vvip_b < 0) {
		        printf("Invalid amount of tickets!\n");
		        return -1;
		    }
		
		    // Check if adding tickets exceeds the maximum allowed
		    if (concerts[concertchoice - 1].vip_floorb_tickets + amounttoadd_vvip_b > MAX_VIP_FLOOR_B_TICKETS) {
		        printf("Adding %d tickets would exceed the maximum limit for VIP FLOOR B!\n", amounttoadd_vvip_b);
		        return -1;
		    }
		
		    printf("Amount of tickets to be added: ");
		    scanf("%d", &amounttoadd_vvip_b);
	    
	   		concerts[concertchoice - 1].vip_floorb_tickets += amounttoadd_vvip_b; 
	   		
	   	//ADD TICKETS TO PATRON
	   		int amounttoadd_patron;
		    printf("Amount of tickets to be added to PATRON: ");
		    scanf("%d", &amounttoadd_patron);
		
		    if (amounttoadd_patron < 0) {
		        printf("Invalid amount of tickets!\n");
		        return -1;
		    }
		
		    // Check if adding tickets exceeds the maximum allowed
		    if (concerts[concertchoice - 1].patron_tickets + amounttoadd_patron > MAX_PATRON_TICKETS) {
		        printf("Adding %d tickets would exceed the maximum limit for PATRON!\n", amounttoadd_patron);
		        return -1;
		    }
		
		    printf("Amount of tickets to be added: ");
		    scanf("%d", &amounttoadd_patron);
	   		
	    	concerts[concertchoice - 1].patron_tickets += amounttoadd_patron; 
	    
	    //ADD TICKETS TO LOWERBOX PREMIUM
	    	int amounttoadd_lowerbox_premium;
		    printf("Amount of tickets to be added to LOWERBOX PREMIUM: ");
		    scanf("%d", &amounttoadd_lowerbox_premium);
		
		    if (amounttoadd_lowerbox_premium < 0) {
		        printf("Invalid amount of tickets!\n");
		        return -1;
		    }
		
		    // Check if adding tickets exceeds the maximum allowed
		    if (concerts[concertchoice - 1].lowerbox_premium_tickets + amounttoadd_lowerbox_premium > MAX_LOWERBOX_PREMIUM_TICKETS) {
		        printf("Adding %d tickets would exceed the maximum limit for LOWERBOX PREMIUM!\n", amounttoadd_lowerbox_premium);
		        return -1;
		    }
		
		    printf("Amount of tickets to be added: ");
		    scanf("%d", &amounttoadd_lowerbox_premium);
		    
	    	concerts[concertchoice - 1].lowerbox_premium_tickets += amounttoadd_lowerbox_premium; 
	    	
	    //ADD TICKETS TO LOWERBOX SIDE
	    	int amounttoadd_lowerbox_sides;
		    printf("Amount of tickets to be added to LOWERBOX SIDES: ");
		    scanf("%d", &amounttoadd_lowerbox_sides);
		
		    if (amounttoadd_lowerbox_sides < 0) {
		        printf("Invalid amount of tickets!\n");
		        return -1;
		    }
		
		    // Check if adding tickets exceeds the maximum allowed
		    if (concerts[concertchoice - 1].lowerbox_sides_tickets + amounttoadd_lowerbox_sides > MAX_LOWERBOX_SIDES_TICKETS) {
		        printf("Adding %d tickets would exceed the maximum limit for LOWERBOX SIDES!\n", amounttoadd_lowerbox_sides);
		        return -1;
		    }
		
		    printf("Amount of tickets to be added: ");
		    scanf("%d", &amounttoadd_lowerbox_sides);
		    
	    	concerts[concertchoice - 1].lowerbox_sides_tickets += amounttoadd_lowerbox_sides; 
	    	
	    //ADD TICKETS TO LOWERBOX CENTER
	    	int amounttoadd_lowerbox_center;
		    printf("Amount of tickets to be added to LOWERBOX CENTER: ");
		    scanf("%d", &amounttoadd_lowerbox_center);
		
		    if (amounttoadd_lowerbox_premium < 0) {
		        printf("Invalid amount of tickets!\n");
		        return -1;
		    }
		
		    // Check if adding tickets exceeds the maximum allowed
		    if (concerts[concertchoice - 1].lowerbox_center_tickets + amounttoadd_lowerbox_center > MAX_LOWERBOX_CENTER_TICKETS) {
		        printf("Adding %d tickets would exceed the maximum limit for LOWERBOX CENTER!\n", amounttoadd_lowerbox_center);
		        return -1;
		    }
		
		    printf("Amount of tickets to be added: ");
		    scanf("%d", &amounttoadd_lowerbox_center);
		    
	   	 concerts[concertchoice - 1].lowerbox_center_tickets += amounttoadd_lowerbox_center; 
	   	 
	   	//ADD TICKETS TO UPPERBOX SIDES
	   		int amounttoadd_upperbox_sides;
		    printf("Amount of tickets to be added to UPPERBOX SIDES: ");
		    scanf("%d", &amounttoadd_upperbox_sides);
		
		    if (amounttoadd_upperbox_sides < 0) {
		        printf("Invalid amount of tickets!\n");
		        return -1;
		    }
		
		    // Check if adding tickets exceeds the maximum allowed
		    if (concerts[concertchoice - 1].upperbox_sides_tickets + amounttoadd_upperbox_sides > MAX_UPPERBOX_SIDES_TICKETS) {
		        printf("Adding %d tickets would exceed the maximum limit for UPPERBOX SIDES!\n", amounttoadd_upperbox_sides);
		        return -1;
		    }
		
		    printf("Amount of tickets to be added: ");
		    scanf("%d", &amounttoadd_upperbox_sides);
		    
	    	concerts[concertchoice - 1].upperbox_sides_tickets += amounttoadd_upperbox_sides; 
	    	
	    //ADD TICKETS TO UPPERBOX CENTER
	    	int amounttoadd_upperbox_center;
		    printf("Amount of tickets to be added to UPPERBOX CENTER: ");
		    scanf("%d", &amounttoadd_upperbox_center);
		
		    if (amounttoadd_upperbox_center < 0) {
		        printf("Invalid amount of tickets!\n");
		        return -1;
		    }
		
		    // Check if adding tickets exceeds the maximum allowed
		    if (concerts[concertchoice - 1].upperbox_center_tickets + amounttoadd_upperbox_center > MAX_UPPERBOX_CENTER_TICKETS) {
		        printf("Adding %d tickets would exceed the maximum limit for UPPERBOX CENTER!\n", amounttoadd_upperbox_center);
		        return -1;
		    }
		
		    printf("Amount of tickets to be added: ");
		    scanf("%d", &amounttoadd_upperbox_center);
		    
	    	concerts[concertchoice - 1].upperbox_center_tickets += amounttoadd_upperbox_center; 
	    	
	    //ADD TICKETS TO GEN ADMISSION A
	    	int amounttoadd_genadm_a;
		    printf("Amount of tickets to be added to GENERAL ADMISSIONS A: ");
		    scanf("%d", &amounttoadd_genadm_a);
		
		    if (amounttoadd_genadm_a < 0) {
		        printf("Invalid amount of tickets!\n");
		        return -1;
		    }
		
		    // Check if adding tickets exceeds the maximum allowed
		    if (concerts[concertchoice - 1].upperbox_center_tickets + amounttoadd_genadm_a > MAX_UPPERBOX_CENTER_TICKETS) {
		        printf("Adding %d tickets would exceed the maximum limit for GENERAL ADMISSION A!\n", amounttoadd_genadm_a);
		        return -1;
		    }
		
		    printf("Amount of tickets to be added: ");
		    scanf("%d", &amounttoadd_genadm_a);
		    
	    	concerts[concertchoice - 1].genadm_A_tickets += amounttoadd_genadm_a; 
	    	
	    //ADD TICKETS TO GEN ADMISSION B
	    int amounttoadd_genadm_b;
		    printf("Amount of tickets to be added to GENERAL ADMISSIONS B: ");
		    scanf("%d", &amounttoadd_genadm_b);
		
		    if (amounttoadd_genadm_b < 0) {
		        printf("Invalid amount of tickets!\n");
		        return -1;
		    }
		
		    // Check if adding tickets exceeds the maximum allowed
		    if (concerts[concertchoice - 1].upperbox_center_tickets + amounttoadd_genadm_b > MAX_UPPERBOX_CENTER_TICKETS) {
		        printf("Adding %d tickets would exceed the maximum limit for GENERAL ADMISSION B!\n", amounttoadd_genadm_b);
		        return -1;
		    }
		
		    printf("Amount of tickets to be added: ");
		    scanf("%d", &amounttoadd_genadm_b);
		    
	    	concerts[concertchoice - 1].genadm_B_tickets += amounttoadd_genadm_b;
	    	
	    	printf("\nProcessing...");
	    	Sleep(2000);
	
	    // Display updated total of tickets
	    printf("Updated total of tickets:\n");
	    printf("VIP FLOOR A: %d\n",concerts[concertchoice - 1].vip_floora_tickets);
		printf("VIP FLOOR B: %d\n",concerts[concertchoice - 1].vip_floorb_tickets);
		printf("PATRON: %d\n",concerts[concertchoice - 1].patron_tickets);
		printf("LOWER BOX PREMIUM: %d\n",concerts[concertchoice - 1].lowerbox_premium_tickets);
		printf("LOWER BOX SIDES PREMIUM: %d\n",concerts[concertchoice - 1].lowerbox_sides_tickets);
		printf("LOWER BOX CENTER: %d\n",concerts[concertchoice - 1].lowerbox_center_tickets);
		printf("UPPER BOX SIDES: %d\n",concerts[concertchoice - 1].upperbox_sides_tickets);
		printf("UPPER BOX CENTER: %d\n",concerts[concertchoice - 1].upperbox_center_tickets);
		printf("GENERAL ADMISSIONS A: %d\n",concerts[concertchoice - 1].genadm_A_tickets);
		printf("GENERAL ADMISSIONS B: %d\n",concerts[concertchoice - 1].genadm_B_tickets);
	
	    adminMenu();
	} else {
	    adminMenu();
	}
}

//DELETE TICKETS AS AN ADMIN
int adminDeleteTicket(){
	system("cls");
	printf("Concerts:\n");
    for (int i = 0; i < num_concerts; i++) {
        printf("%d. %s\n", i + 1, concerts[i].name);
    }
    
    char choices;
	printf("\nPress any key to enter concert details or 1 to go back.\n");
	scanf(" %c", &choices);
	if (choices != '1') {
	    printf("Choose concert to deduct tickets: ");
	    scanf("%d", &concertchoice);
	
	    if (concertchoice < 1 || concertchoice > num_concerts) {
	        printf("Invalid concert choice!\n");
	        return -1;
	    }
	
	    printf("Concert: %s\n", concerts[concertchoice - 1].name);
	    printf("VIP FLOOR A: %d\n",concerts[concertchoice - 1].vip_floora_tickets);
		printf("VIP FLOOR B: %d\n",concerts[concertchoice - 1].vip_floorb_tickets);
		printf("PATRON: %d\n",concerts[concertchoice - 1].patron_tickets);
		printf("LOWER BOX PREMIUM: %d\n",concerts[concertchoice - 1].lowerbox_premium_tickets);
		printf("LOWER BOX SIDES PREMIUM: %d\n",concerts[concertchoice - 1].lowerbox_sides_tickets);
		printf("LOWER BOX CENTER: %d\n",concerts[concertchoice - 1].lowerbox_center_tickets);
		printf("UPPER BOX SIDES: %d\n",concerts[concertchoice - 1].upperbox_sides_tickets);
		printf("UPPER BOX CENTER: %d\n",concerts[concertchoice - 1].upperbox_center_tickets);
		printf("GENERAL ADMISSIONS A: %d\n",concerts[concertchoice - 1].genadm_A_tickets);
		printf("GENERAL ADMISSIONS B: %d\n",concerts[concertchoice - 1].genadm_B_tickets);
		
	    //DEDUCT TICKETS TO VVIP A
			int amounttodeduct_vvip_a;
			printf("Amount of tickets to be deducted to VIP FLOOR A: ");
			scanf("%d", &amounttodeduct_vvip_a);
			
			if (amounttodeduct_vvip_a < 0) {
			    printf("Invalid amount of tickets!\n");
			    return -1;
			}
			
			// Check if deducting tickets exceeds the maximum allowed
			if (concerts[concertchoice - 1].vip_floora_tickets - amounttodeduct_vvip_a < 0) {
			    printf("Deducting %d tickets would exceed the maximum limit for VIP FLOOR A!\n", amounttodeduct_vvip_a);
			    return -1;
			}
			
			printf("Amount of tickets to be deducted: ");
			scanf("%d", &amounttodeduct_vvip_a);
			
			// Deduct tickets equally from each type
			concerts[concertchoice - 1].vip_floora_tickets -= amounttodeduct_vvip_a; 
	
		//DEDUCT TICKETS TO VVIP B
			int amounttodeduct_vvip_b;
			printf("Amount of tickets to be deducted to VIP FLOOR B: ");
			scanf("%d", &amounttodeduct_vvip_b);
			
			if (amounttodeduct_vvip_b < 0) {
			    printf("Invalid amount of tickets!\n");
			    return -1;
			}
			
			// Check if deducting tickets exceeds the maximum allowed
			if (concerts[concertchoice - 1].vip_floorb_tickets - amounttodeduct_vvip_b < 0) {
			    printf("Deducting %d tickets would exceed the maximum limit for VIP FLOOR B!\n", amounttodeduct_vvip_b);
			    return -1;
			}
			
			printf("Amount of tickets to be deducted: ");
			scanf("%d", &amounttodeduct_vvip_b);
			
			concerts[concertchoice - 1].vip_floorb_tickets -= amounttodeduct_vvip_b;
	
		//DEDUCT TICKETS TO PATRON
			int amounttodeduct_patron;
			printf("Amount of tickets to be deducted to PATRON: ");
			scanf("%d", &amounttodeduct_patron);
			
			if (amounttodeduct_patron < 0) {
			    printf("Invalid amount of tickets!\n");
			    return -1;
			}
			
			// Check if deducting tickets exceeds the maximum allowed
			if (concerts[concertchoice - 1].patron_tickets - amounttodeduct_patron < 0) {
			    printf("Deducting %d tickets would exceed the maximum limit for PATRON!\n", amounttodeduct_patron);
			    return -1;
			}
			
			printf("Amount of tickets to be deducted: ");
			scanf("%d", &amounttodeduct_patron);
			
			concerts[concertchoice - 1].patron_tickets -= amounttodeduct_patron; 
	
		//DEDUCT TICKETS TO LOWERBOX PREMIUM
			int amounttodeduct_lowerbox_premium;
			printf("Amount of tickets to be deducted to LOWERBOX PREMIUM: ");
			scanf("%d", &amounttodeduct_lowerbox_premium);
			
			if (amounttodeduct_lowerbox_premium < 0) {
			    printf("Invalid amount of tickets!\n");
			    return -1;
			}
			
			// Check if deducting tickets exceeds the maximum allowed
			if (concerts[concertchoice - 1].lowerbox_premium_tickets - amounttodeduct_lowerbox_premium < 0) {
			    printf("Deducting %d tickets would exceed the maximum limit for LOWERBOX PREMIUM!\n", amounttodeduct_lowerbox_premium);
			    return -1;
			}
			
			printf("Amount of tickets to be deducted: ");
			scanf("%d", &amounttodeduct_lowerbox_premium);
			
			concerts[concertchoice - 1].lowerbox_premium_tickets -= amounttodeduct_lowerbox_premium;
	
		//DEDUCT TICKETS TO LOWERBOX SIDES
			int amounttodeduct_lowerbox_sides;
			printf("Amount of tickets to be deducted to LOWERBOX SIDES: ");
			scanf("%d", &amounttodeduct_lowerbox_sides);
			
			if (amounttodeduct_lowerbox_sides < 0) {
			    printf("Invalid amount of tickets!\n");
			    return -1;
			}
			
			// Check if deducting tickets exceeds the maximum allowed
			if (concerts[concertchoice - 1].lowerbox_sides_tickets - amounttodeduct_lowerbox_sides < 0) {
			    printf("Deducting %d tickets would exceed the maximum limit for LOWERBOX SIDES!\n", amounttodeduct_lowerbox_sides);
			    return -1;
			}
			
			printf("Amount of tickets to be deducted: ");
			scanf("%d", &amounttodeduct_lowerbox_sides);
			
			concerts[concertchoice - 1].lowerbox_sides_tickets -= amounttodeduct_lowerbox_sides;
	
		//DEDUCT TICKETS TO LOWERBOX CENTER
			int amounttodeduct_lowerbox_center;
			printf("Amount of tickets to be deducted to LOWERBOX CENTER: ");
			scanf("%d", &amounttodeduct_lowerbox_center);
			
			if (amounttodeduct_lowerbox_center < 0) {
			    printf("Invalid amount of tickets!\n");
			    return -1;
			}
			
			// Check if deducting tickets exceeds the maximum allowed
			if (concerts[concertchoice - 1].lowerbox_center_tickets - amounttodeduct_lowerbox_center < 0) {
			    printf("Deducting %d tickets would exceed the maximum limit for LOWERBOX CENTER!\n", amounttodeduct_lowerbox_center);
			    return -1;
			}
			
			printf("Amount of tickets to be deducted: ");
			scanf("%d", &amounttodeduct_lowerbox_center);
			
			concerts[concertchoice - 1].lowerbox_center_tickets -= amounttodeduct_lowerbox_center;
	
		//DEDUCT TICKETS TO UPPERBOX SIDES
			int amounttodeduct_upperbox_sides;
			printf("Amount of tickets to be deducted to UPPERBOX SIDES: ");
			scanf("%d", &amounttodeduct_upperbox_sides);
			
			if (amounttodeduct_upperbox_sides < 0) {
			    printf("Invalid amount of tickets!\n");
			    return -1;
			}
			
			// Check if deducting tickets is valid
			if (concerts[concertchoice - 1].upperbox_sides_tickets - amounttodeduct_upperbox_sides < 0) {
			    printf("Deducting %d tickets for UPPERBOX SIDES is not valid\n", amounttodeduct_upperbox_sides);
			    return -1;
			}
			
			printf("Amount of tickets to be deducted: ");
			scanf("%d", &amounttodeduct_upperbox_sides);
			
			concerts[concertchoice - 1].upperbox_sides_tickets -= amounttodeduct_upperbox_sides;
	
		//DEDUCT TICKETS TO UPPERBOX CENTER
			int amounttodeduct_upperbox_center;
			printf("Amount of tickets to be deducted to UPPERBOX CENTER: ");
			scanf("%d", &amounttodeduct_upperbox_center);
			
			if (amounttodeduct_upperbox_center < 0) {
			    printf("Invalid amount of tickets!\n");
			    return -1;
			}
			
			// Check if deducting tickets is valid
			if (concerts[concertchoice - 1].upperbox_center_tickets - amounttodeduct_upperbox_center < 0) {
			    printf("Deducting %d tickets for UPPERBOX CENTER is not valid\n", amounttodeduct_upperbox_center);
			    return -1;
			}
			
			printf("Amount of tickets to be deducted: ");
			scanf("%d", &amounttodeduct_upperbox_center);
			
			concerts[concertchoice - 1].upperbox_center_tickets -= amounttodeduct_upperbox_center;
	    	
	    //DEDUCT TICKETS TO GEN ADMISSION A
	    	int amounttodeduct_genadm_a;
		    printf("Amount of tickets to be deducted to GENERAL ADMISSIONS A: ");
		    scanf("%d", &amounttodeduct_genadm_a);
		
		    if (amounttodeduct_genadm_a < 0) {
		        printf("Invalid amount of tickets!\n");
		        return -1;
		    }
		
		    // Check if deducting tickets is valid
		    if (concerts[concertchoice - 1].upperbox_center_tickets - amounttodeduct_genadm_a < 0) {
		        printf("Deducting %d tickets for GENERAL ADMISSION A is not valid!\n", amounttodeduct_genadm_a);
		        return -1;
		    }
		
		    printf("Amount of tickets to be deducted: ");
		    scanf("%d", &amounttodeduct_genadm_a);
		    
	    	concerts[concertchoice - 1].genadm_A_tickets -= amounttodeduct_genadm_a; 
	    	
	    //DEDUCT TICKETS TO GEN ADMISSION B
	    int amounttodeduct_genadm_b;
		    printf("Amount of tickets to be deducted to GENERAL ADMISSIONS B: ");
		    scanf("%d", &amounttodeduct_genadm_b);
		
		    if (amounttodeduct_genadm_b < 0) {
		        printf("Invalid amount of tickets!\n");
		        return -1;
		    }
		
		    // Check if deducting tickets is valid
		    if (concerts[concertchoice - 1].upperbox_center_tickets - amounttodeduct_genadm_b < 0) {
		        printf("Deducting %d tickets for GENERAL ADMISSION B is not valid!\n", amounttodeduct_genadm_b);
		        return -1;
		    }
		
		    printf("Amount of tickets to be deducted: ");
		    scanf("%d", &amounttodeduct_genadm_b);
		    
	    	concerts[concertchoice - 1].genadm_B_tickets -= amounttodeduct_genadm_b;
	    	
	    	printf("\nProcessing...");
	    	Sleep(2000);
	
	    // Display updated total of tickets
	    printf("Updated total of tickets:\n");
	    printf("VIP FLOOR A: %d\n",concerts[concertchoice - 1].vip_floora_tickets);
		printf("VIP FLOOR B: %d\n",concerts[concertchoice - 1].vip_floorb_tickets);
		printf("PATRON: %d\n",concerts[concertchoice - 1].patron_tickets);
		printf("LOWER BOX PREMIUM: %d\n",concerts[concertchoice - 1].lowerbox_premium_tickets);
		printf("LOWER BOX SIDES PREMIUM: %d\n",concerts[concertchoice - 1].lowerbox_sides_tickets);
		printf("LOWER BOX CENTER: %d\n",concerts[concertchoice - 1].lowerbox_center_tickets);
		printf("UPPER BOX SIDES: %d\n",concerts[concertchoice - 1].upperbox_sides_tickets);
		printf("UPPER BOX CENTER: %d\n",concerts[concertchoice - 1].upperbox_center_tickets);
		printf("GENERAL ADMISSIONS A: %d\n",concerts[concertchoice - 1].genadm_A_tickets);
		printf("GENERAL ADMISSIONS B: %d\n",concerts[concertchoice - 1].genadm_B_tickets);
		
		adminMenu();
	} else {
	    adminMenu();
	}
}


//for user sign up
void saveUsers() {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < num_users; i++) {
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }
    fclose(file);
}

void loadUsers() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("No existing users found.\n");
        return;
    }
    while (fscanf(file, "%s %s", users[num_users].username, users[num_users].password) != EOF) {
        num_users++;
    }
    fclose(file);
}

int containsSpace(const char *str) {
    while (*str) {
        if (*str == ' ') {
            return 1;
        }
        str++;
    }
    return 0;
}


void userSignup() {
    system("cls");
    if (num_users >= MAX_USERS) {
        printf("Maximum number of users reached!\n");
        return;
    }
    
    char choices[2]; 
    printf("\nPress any key to sign up or 1 to go back: ");
    scanf(" %1[^\n]", choices); 
    clearInputBuffer(); 

    if (choices[0] != '1') {
    	system("cls");
        printf("\nSIGN UP\n");

        char username[MAX_USERNAME_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
        int valid = 0;
        do {
            printf("\nEnter a username (max %d characters): ", MAX_USERNAME_LENGTH - 1);
            scanf(" %[^\n]", username); 
            clearInputBuffer(); 

            printf("Enter a password (max %d characters): ", MAX_PASSWORD_LENGTH - 1);
            scanf(" %[^\n]", password); 
            clearInputBuffer(); 

            if (strlen(username) >= MAX_USERNAME_LENGTH || strlen(password) >= MAX_PASSWORD_LENGTH) {
                printf("Username or password too long. Please try again.\n");
                Sleep(1000);
                system("cls");
                printf("\nSIGN UP\n");
                
            } else {
                valid = 1;
            }
        } while (!valid);
        
        strcpy(users[num_users].username, username);
        strcpy(users[num_users].password, password);
        
        printf("User signed up successfully!\n");
        Sleep(1000);
        num_users++;
        saveUsers();
    } else {
        userMenu();
    }
}


void userLogin() {
    loadUsers();
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int found = 0;

    while (1) {
        system("cls");
        char choice;

        printf("\nLOG IN\n");

        printf("\nEnter your username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = '\0';

        printf("Enter your password: ");
        
        int i = 0;
        char ch;
        while ((ch = getch()) != '\r' && i < MAX_PASSWORD_LENGTH - 1) { 
            if (ch == 8) { 
                if (i > 0) {
                    i--;
                    printf("\b \b"); 
                }
            } else {
                password[i++] = ch;
                printf("*");
            }
        }
        password[i] = '\0';
        printf("\n");

        for (int i = 0; i < num_users; i++) {
            if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
                printf("User login successful!\n");
                found = 1;
                current_user_index = i;
                Sleep(1000);
                displayMainMenu();
                return;
            }
        }

        if (!found) {
            printf("Cannot find account. Try again\n");
            printf("\nPress any key to login again.\n\n[1] to go back to the menu\[2] for Forgot Password: ");
            choice = getchar();
            clearInputBuffer();
            if (choice == '1') {
                userMenu();
                return;
            } else if (choice == '2') {
                forgotPassword();
                return;
            }
            Sleep(1000);
        }
    }
}

void changePassword() {
    char newPassword[MAX_PASSWORD_LENGTH];
    
    system("cls");
    printf("\nChange Password\n");

    while (1) {
        printf("\nEnter new password: ");
        scanf(" %[^\n]", newPassword);
        clearInputBuffer();

        if (strlen(newPassword) >= MAX_PASSWORD_LENGTH) {
            printf("Password too long. Please try again.\n");
            Sleep(1000);
            continue;
        }

        if (strcmp(newPassword, users[current_user_index].password) == 0) {
            printf("New password cannot be similar to the old password. Please try again.\n");
            Sleep(1000);
            continue;
        }

        strcpy(users[current_user_index].password, newPassword);
        saveUsers();
        printf("Password changed successfully!\n");
        Sleep(1000);
        break;
    }
}

void changeUsername() {
    char newUsername[MAX_USERNAME_LENGTH];
    system("cls");
    printf("\nChange Username\n");

    while (1) {
        printf("\nEnter new username: ");
        scanf(" %[^\n]", newUsername);
        clearInputBuffer();

        if (strlen(newUsername) >= MAX_USERNAME_LENGTH) {
            printf("Username too long. Please try again.\n");
            Sleep(1000);
            continue;
        }

        if (strcmp(newUsername, users[current_user_index].username) == 0) {
            printf("Please enter a different username. This username is the same as the old one.\n");
            Sleep(1000);
            continue;
        }

        strcpy(users[current_user_index].username, newUsername);
        saveUsers();
        printf("Username changed successfully!\n");
        Sleep(1000);
        break;
    }
}

void forgotPassword() {
    char username[MAX_USERNAME_LENGTH];
    int userIndex = -1;

    system("cls");
    printf("\nForgot Password\n");
    printf("\nEnter your username: ");
    scanf(" %[^\n]", username);
    clearInputBuffer();

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            userIndex = i;
            break;
        }
    }

    if (userIndex != -1) {
        while (1) {
            printf("Enter new password: ");
            char newPassword[MAX_PASSWORD_LENGTH];
            scanf(" %[^\n]", newPassword);
            clearInputBuffer();

            if (strlen(newPassword) >= MAX_PASSWORD_LENGTH) {
                printf("Password too long. Please try again.\n");
                Sleep(1000);
                continue;
            }

            if (strcmp(newPassword, users[userIndex].password) == 0) {
                printf("New password cannot be similar to the old password. Please try again.\n");
                Sleep(1000);
                continue;
            }

            strcpy(users[userIndex].password, newPassword);
            saveUsers();
            printf("Password changed successfully!\n");
            Sleep(1000);
            break;
        }
    } else {
        printf("Username not found. Please try again.\n");
        Sleep(1000);
        forgotPassword();
    }
}


//for user mainmenu
void displayMainMenu() {
	loadUsers();
    int mainchoice;
    int ifchar;
    do {
    	system("cls");
        printf("\nConcert Menu\n");
        printf("[1] Profile\n");
        printf("[2] Available Concerts\n");
        printf("[3] Log Out\n");
        printf("\nEnter your choice: ");
		        
        // Checking if the input is an integer
        ifchar = scanf("%d", &mainchoice);

        // Clearing input buffer
        while (getchar() != '\n');

        if (ifchar != 1) {
            printf("Invalid input! Please enter a number.\n");
            Sleep(1000);
            displayMainMenu();
        }

        if (mainchoice < 1 || mainchoice > 3) {
            printf("Invalid choice! Please try again.\n");
            Sleep(1000);
            displayMainMenu();
        }
        
        switch (mainchoice) {
            case 1:
                userProfile();
                break;
            case 2:
                concertMenu();
                break;
            case 3:
            	printf("Logging out...\n");
            	Sleep(2000);
                userMenu();
                break;
          
        }
    } while (mainchoice != 0);
}

//for user profile
void userProfile() {
    system("cls");
    printf("\nUser Profile\n");
    printf("\nUsername: %s\n", users[current_user_index].username);
    printf("\nPassword: %s\n", users[current_user_index].password);

    printf("\n1. Change Username\n");
    printf("2. Change Password\n");
    printf("3. Back\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    clearInputBuffer();

    switch (choice) {
        case 1:
            changeUsername();
            break;
        case 2:
            changePassword();
            break;
        case 3:
            displayMainMenu();
            break;
        default:
            printf("Invalid choice. Try again.\n");
            Sleep(1000);
            userProfile();
    }
    displayMainMenu();
}


//for concert menu
void concertMenu(){
	int concertchoice;
	int ifchar;
    
    system("cls");
	printf("\nConcerts:\n");
    for (int i = 0; i < num_concerts; i++) {
        printf("[%d] %s\n", i + 1, concerts[i].name);
    }
    
    // If there are concerts added by the admin, display them too
    for (int i = MAX_CONCERTS; i < num_concerts; i++) {
        printf("[%d] %s\n", i + 1, concerts[i].name);
    }
    printf("[0] Back to Main Menu\n");
    
    printf("Enter your choice: ");
    
    // Checking if the input is an integer
        ifchar = scanf("%d", &concertchoice);

        // Clearing input buffer
        clearInputBuffer();

        if (ifchar != 1) {
            printf("Invalid input! Please enter a number.\n");
            Sleep(1000);
            concertMenu();
        }

    if (concertchoice >= 1 && concertchoice <= num_concerts) {
        index = concertchoice - 1;
        concertIndex = concertchoice - 1;
        displayConcertDetails(concertIndex, index);
    } else if (concertchoice == 0) {
        displayMainMenu();
    } else {
        printf("Invalid choice! Please try again.\n");
        Sleep(2000);
        concertMenu();
    }
}


//DISPLAY CONCERT DETAILS
void displayConcertDetails(int concertIndex, int index) {
	int ifchar;
    system("cls"); // Clear screen
    printf("\nConcert Details\n");
    printf("Concert Name: %s\n", concerts[index].name);
    printf("Artist: %s\n", concerts[index].artist);
    printf("Date: %02d-%02d-%04d\n", concerts[concertIndex].month, concerts[concertIndex].day, concerts[concertIndex].year);
    printf("Time: %02d:%02d\n", concerts[concertIndex].hours, concerts[concertIndex].minutes);
    printf("Venue: SM Mall of Asia Arena, Manila\n");
    
    printf("\nAvailable Seats:\n");
    printf("VIP FLOOR A: %d\n",concerts[concertIndex].vip_floora_tickets);
	printf("VIP FLOOR B: %d\n",concerts[concertIndex].vip_floorb_tickets);
	printf("PATRON: %d\n",concerts[concertIndex].patron_tickets);
	printf("LOWER BOX PREMIUM: %d\n",concerts[concertIndex].lowerbox_premium_tickets);
	printf("LOWER BOX SIDES PREMIUM: %d\n",concerts[concertIndex].lowerbox_sides_tickets);
	printf("LOWER BOX CENTER: %d\n",concerts[concertIndex].lowerbox_center_tickets);
	printf("UPPER BOX SIDES: %d\n",concerts[concertIndex].upperbox_sides_tickets);
	printf("UPPER BOX CENTER: %d\n",concerts[concertIndex].upperbox_center_tickets);
	printf("GENERAL ADMISSIONS A: %d\n",concerts[concertIndex].genadm_A_tickets);
	printf("GENERAL ADMISSIONS B: %d\n",concerts[concertIndex].genadm_B_tickets);
    
    printf("\nDo you want to purchase ticket/s? [1] YES | [2] NO\n");
    // Checking if the input is an integer
        ifchar = scanf("%d", &confirmchoice);

        // Clearing input buffer
        clearInputBuffer();

        if (ifchar != 1) {
            printf("Invalid input! Please enter a number.\n");
            Sleep(1000);
            displayConcertDetails(concertIndex, index);
        }

    if(confirmchoice == 1){
    	chooseseat(concertIndex, index);
	}
	else if(confirmchoice == 2){
		concertMenu();
	}
	else{
		printf("\nInvalid choice. Please try again\n");
		Sleep(2000);
		system("cls");
		displayConcertDetails(concertIndex, index);
	}
}

void concertOne(){ 
	displayConcertDetails(concertIndex, index);
}


void concertTwo(){ 
	displayConcertDetails(concertIndex, index);
}

void concertThree(){
	displayConcertDetails(concertIndex, index);
}

void concertFour(){ 
	displayConcertDetails(concertIndex, index);
}

void concertFive(){ 
	displayConcertDetails(concertIndex, index);
}

void chooseseat(int concertIndex, int index){
	int ifchar;
	system("cls");
	
	printf("Ticket Prices:\n");
    for (int i = 0; i < NUM_TICKET_TYPES; i++) {
        printf("[%d.] %s: %.2f\n", i + 1, ticket_types[i], ticket_prices[i]);
    }
    
	printf("\nEnter your choice: ");    
    	// Checking if the input is an integer
        ifchar = scanf("%d", &seatchoice);

        // Clearing input buffer
        clearInputBuffer();

        if (ifchar != 1) {
            printf("Invalid choice.\n");
            Sleep(1000);
            chooseseat(concertIndex, index);
        }

    if (seatchoice >= 1 && seatchoice <= NUM_TICKET_TYPES) {
        concertIndex = seatchoice - 1; 
        quatityTicket(concertIndex, index);
    } else {
        printf("Invalid! Try Again.\n");
        Sleep(2000);
        chooseseat(concertIndex, index);
    }
}
    
void quatityTicket(int concertIndex, int index)	{
    char input[100]; 
    while (1) {
        printf("\n\nHow many tickets do you want to buy?: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Check if input is a valid integer
            if (sscanf(input, "%d", &ticketamount) == 1) {
                break;
            } else {
                printf("\nInvalid input. Try again in choosing seat and \nPlease input how many tickets you want to buy.\n");
                 Sleep(3000);
               	
				chooseseat(concertIndex, index);
            }
   		}
	}
    

    printf("\nProcessing...\n");
    Sleep(2000); 
    
    purchaseTicket(concertIndex, index, taxAmount, grandTotal);
}

float getPrice(int concertIndex, int seatchoice, int index) {
    if (seatchoice >= 1 && seatchoice <= NUM_TICKET_TYPES) {
        concertIndex = seatchoice - 1;
        return ticket_prices[seatchoice - 1]; // Adjusting for zero-based indexing
    } else {
        return 0; // Invalid seat type
    }
}

void purchaseTicket(int concertIndex, int index, float taxAmount, float grandTotal){
    int ifchar;
    system("cls");
    
    float ticketPrice = getPrice(concertIndex, seatchoice, index);
    totalamount = ticketPrice * ticketamount;
    taxAmount = totalamount * TAX_RATE;
    grandTotal = totalamount + taxAmount;

    printf("Summary of Order:\n");
    printf("Concert Name: %s\n", concerts[index].name); // concert name
    printf("Type of Seat: %s\n", ticket_types[seatchoice - 1]); // chosen seat
    printf("Price: %.2f\n", ticketPrice); // chosen seat's price
    printf("Total: %.2f\n", totalamount); // total amount
    printf("Tax: %.2f\n", taxAmount); // tax amount
    printf("Grand Total: %.2f\n", grandTotal); // grand total

    do {
        printf("\nDo you want to continue? [1] YES | [2] GO BACK TO CONCERT MENU");
        printf("\nChoice: ");
        
        // Checking if the input is an integer
        ifchar = scanf("%d", &confirmchoice);

        // Clearing input buffer
        clearInputBuffer();

        if (ifchar != 1) {
            printf("Invalid input! Please enter a number.\n");
            Sleep(1000);
            purchaseTicket(concertIndex, index, taxAmount, grandTotal);
        }

        if (confirmchoice == 1) {
            switch (seatchoice) {
                case 1:
                    concerts[concertIndex].vip_floora_tickets -= ticketamount;
                    break;
                case 2:
                    concerts[concertIndex].vip_floorb_tickets -= ticketamount;
                    break;
                case 3:
                    concerts[concertIndex].patron_tickets -= ticketamount;
                    break;
                case 4:
                    concerts[concertIndex].lowerbox_premium_tickets -= ticketamount;
                    break;
                case 5:
                    concerts[concertIndex].lowerbox_sides_tickets -= ticketamount;
                    break;
                case 6:
                    concerts[concertIndex].lowerbox_center_tickets -= ticketamount;
                    break;
                case 7:
                    concerts[concertIndex].upperbox_sides_tickets -= ticketamount;
                    break;
                case 8:
                    concerts[concertIndex].upperbox_center_tickets -= ticketamount;
                    break;
                case 9:
                    concerts[concertIndex].genadm_A_tickets -= ticketamount;
                    break;
                case 10:
                    concerts[concertIndex].genadm_B_tickets -= ticketamount;
                    break;
                default:
                    printf("\nInvalid\n");
                    Sleep(1100);
            }
            printf("\nProcessing...\n");
            Sleep(2000);
            system("cls");
            displayTotalAmount(concertIndex, index, taxAmount, grandTotal);
        } else if (confirmchoice == 2) {
            concertMenu();
        } else {
            printf("Invalid choice. Please try again.\n");
            Sleep(2000);
            system("cls");
            purchaseTicket(concertIndex, index, taxAmount, grandTotal);
        }

    } while (confirmchoice != 1 && confirmchoice != 2);
}
void displayTotalAmount(int concertIndex, int index, float taxAmount, float grandTotal){
    float payment;
    int validInput;
    
    // Payment method selection
    while (1) {
        printf("\nSelect payment method:\n[1] Cash\n[2] Online Payment\n");
        printf("Choice: ");
        validInput = scanf("%d", &paymentMethod);

        // Clear the input buffer
        clearInputBuffer();

        if (validInput == 1 && (paymentMethod == 1 || paymentMethod == 2)) {
            break;
        } else {
            printf("Invalid choice!\n");
            Sleep(1000);
            system("cls");
            printf("Summary of Order:\n");
            printf("Concert Name: %s\n", concerts[index].name); // concert name
            printf("Type of Seat: %s\n", ticket_types[seatchoice - 1]); // chosen seat
            printf("Price: %.2f\n", getPrice(concertIndex, seatchoice, index)); // chosen seat's price
            printf("Total: %.2f\n", totalamount);
            printf("Tax: %.2f\n", taxAmount);
            printf("Grand Total: %.2f\n", grandTotal);
        }
    }

    if (paymentMethod == 1) { // Cash payment
        while (1) {
            printf("\nGrand Total: %.2f\n", grandTotal);
            printf("\nInput your payment: ");
            validInput = scanf("%f", &payment);

            // Clear the input buffer
            clearInputBuffer();

            if (validInput == 1) {
                // Checks if the payment is enough for the total amount of the purchase
                if (payment >= grandTotal) {
                    receipttotal = payment - grandTotal;
                    printf("\nProcessing...\n");
                    updateTickets(concertIndex);
                    Sleep(2000);
                    printf("Payment Successful! Thank you for purchasing. Enjoy the concert!\n");
                    Sleep(2000);
                    displayReceipt(concertIndex, index, taxAmount, grandTotal, payment, "Cash");
                    break;
                } else {
                    printf("\nInsufficient payment. Please enter a valid amount.\n");
                    Sleep(2000);
                    system("cls");
                    displayTotalAmount(concertIndex, index, taxAmount, grandTotal);
                }
            } else {
                printf("Invalid input. Please enter a valid number.\n");
                Sleep(2000);
                system("cls");
                displayTotalAmount(concertIndex, index, taxAmount, grandTotal);
            }
        }
    } else if (paymentMethod == 2) { // Online payment
        printf("\nSelect online payment method:\n[1] GCash\n[2] PayPal\n");
        printf("Choice: ");
        validInput = scanf("%d", &onlinePaymentMethod);

        // Clear the input buffer
        clearInputBuffer();

        if (validInput == 1 && (onlinePaymentMethod == 1 || onlinePaymentMethod == 2)) {
            if (onlinePaymentMethod == 1) { // GCash payment
                printf("\nEnter your GCash number: ");
                scanf("%s", gcashNumber);
                printf("Enter your GCash account name: ");
                scanf("%s", gcashAccountName);

                printf("\nGrand Total: %.2f\n", grandTotal);
                printf("\nInput your payment: ");
                validInput = scanf("%f", &payment);

                // Clear the input buffer
                clearInputBuffer();

                if (validInput == 1 && payment >= grandTotal) {
                    receipttotal = payment - grandTotal;
                    printf("\nProcessing...\n");
                    updateTickets(concertIndex);
                    Sleep(2000);
                    printf("Payment Successful! Thank you for purchasing. Enjoy the concert!\n");
                    Sleep(2000);
                    displayReceipt(concertIndex, index, taxAmount, grandTotal, payment, "GCash");
                } else {
                    printf("\nInsufficient payment or invalid input. Please enter a valid amount.\n");
                    Sleep(2000);
                    system("cls");
                    displayTotalAmount(concertIndex, index, taxAmount, grandTotal);
                }
            } else if (onlinePaymentMethod == 2) { // PayPal payment
                char paypalEmail[100];
                printf("\nEnter your PayPal email: ");
                scanf("%s", paypalEmail);

                printf("\nGrand Total: %.2f\n", grandTotal);
                printf("\nInput your payment: ");
                validInput = scanf("%f", &payment);

                // Clear the input buffer
                clearInputBuffer();

                if (validInput == 1 && payment >= grandTotal) {
                    receipttotal = payment - grandTotal;
                    printf("\nProcessing...\n");
                    updateTickets(concertIndex);
                    Sleep(2000);
                    printf("Payment Successful! Thank you for purchasing. Enjoy the concert!\n");
                    Sleep(2000);
                    displayReceipt(concertIndex, index, taxAmount, grandTotal, payment, "PayPal");
                } else {
                    printf("\nInsufficient payment or invalid input. Please enter a valid amount.\n");
                    Sleep(2000);
                    system("cls");
                    displayTotalAmount(concertIndex, index, taxAmount, grandTotal);
                }
            }
        } else {
            printf("Invalid choice!\n");
            Sleep(1000);
            system("cls");
            displayTotalAmount(concertIndex, index, taxAmount, grandTotal);
        }
    }
}


void updateTickets(int concertIndex) {
    switch (seatchoice) {
        case 1:
            concerts[concertIndex].vip_floora_tickets -= ticketamount;
            break;
        case 2:
            concerts[concertIndex].vip_floorb_tickets -= ticketamount;
            break;
        case 3:
            concerts[concertIndex].patron_tickets -= ticketamount;
            break;
        case 4:
            concerts[concertIndex].lowerbox_premium_tickets -= ticketamount;
            break;
        case 5:
            concerts[concertIndex].lowerbox_sides_tickets -= ticketamount;
            break;
        case 6:
            concerts[concertIndex].lowerbox_center_tickets -= ticketamount;
            break;
        case 7:
            concerts[concertIndex].upperbox_sides_tickets -= ticketamount;
            break;
        case 8:
            concerts[concertIndex].upperbox_center_tickets -= ticketamount;
            break;
        case 9:
            concerts[concertIndex].genadm_A_tickets -= ticketamount;
            break;
        case 10:
            concerts[concertIndex].genadm_B_tickets -= ticketamount;
            break;
        default:
            printf("Invalid seat choice.\n");
            break;
    }
}

void displayReceipt(int concertIndex, int index, float taxAmount, float grandTotal, float payment, const char* paymentMethod){
	int ifchar;
	system("cls");
	
	//receipt display
	printf("\t\t\t\t\t\t\033[0;36m.__ .___ __ .___._..__ .___.\033[0m\n");
    printf("\t\t\t\t\t\t\033[0;36m[__)[__ /  `[__  | [__)  |  \033[0m\n");
    printf("\t\t\t\t\t\t\033[0;36m|  |[___\\__.[__ _|_|     |  \033[0m\n\n");
    printf("\t\t\t\033[0;34m___  ______  ______  ______  ______  ______  ______  ______  ______  ___\033[0m\n\n");
    printf("\t\t\t\t\t\033[0;36mConcert: %s\033[0m\n", concerts[index].name); // User's chosen concert name
    printf("\t\t\t\t\t\033[0;36mType of Seat: %s\033[0m\n", ticket_types[seatchoice - 1]); // User's chosen seat
    printf("\t\t\t\t\t\033[0;36mPrice: %.2f\033[0m\n", getPrice(concertIndex, seatchoice, index)); // User's chosen seat's price
    printf("\t\t\t\t\t\033[0;36mPayment Method: %s\033[0m\n", paymentMethod);
    printf("\t\t\t\t\t\033[0;36mGrand Total: %.2f\033[0m\n", totalamount); // User's total amount of the ticket/s
    printf("\t\t\t\t\t\033[0;36mPayment: %.2f\033[0m\n", payment); // User's payment amount
    printf("\t\t\t\t\t\033[0;36mChange: %.2f\033[0m\n", receipttotal); // User's change
	printf("\t\t\t\033[0;34m___  ______  ______  ______  ______  ______  ______  ______  ______  ___\033[0m\n\n");
	
	do{
		printf("\nDo you want to continue? [1] YES | [2] GO BACK TO USER MENU");
		printf("\nChoice: ");		
		// Checking if the input is an integer
        ifchar = scanf("%d", &confirmchoice);

        // Clearing input buffer
        clearInputBuffer();

        if (ifchar != 1) {
            printf("Invalid input! Please enter a number.\n");
            Sleep(1000);
			displayReceipt( concertIndex, index, taxAmount, grandTotal, payment, paymentMethod);
        }

        if (confirmchoice < 0 || confirmchoice > 2) {
            printf("Invalid choice! Please try again.\n");
            Sleep(1000);
            displayReceipt( concertIndex, index, taxAmount, grandTotal, payment, paymentMethod);
        }
		
		if(confirmchoice == 1){
			printf("\nProcessing...\n");
			Sleep(2000);
			displayTicket(concertIndex, index);
		}
		else if(confirmchoice == 2){
			printf("\nPlease wait.\n");
			Sleep(2000);
			userMenu();
		}
		else {
			printf("Invalid choice. Please try again.\n");
			Sleep(1000);
			displayReceipt(concertIndex, index, taxAmount, grandTotal, payment, paymentMethod);
		}
	}while((confirmchoice != 1 && confirmchoice != 2) || ifchar != 1);
}

void displayTicket(int concertIndex, int index) {
	int ifchar;
	
    system("cls");
    
    printf("Concert: %s\n", concerts[index].name);
    printf("Artist: %s\n", concerts[index].artist);
    printf("Location: SM Mall of Asia Arena\n");  
    printf("Type of Seat: %s\n", ticket_types[seatchoice - 1]);
    printf("Price per Ticket: %.2f\n", getPrice(concertIndex, seatchoice,index));
    printf("Number of Tickets Bought: %i\n", ticketamount);
    
    printf("Grand Total: %.2f\n", totalamount);
    
    do{
    	printf("\nDo you want to buy again? [1] YES | [2] Concert Menu\n");
	    printf("Choice: ");	    
	    // Checking if the input is an integer
        ifchar = scanf("%d", &confirmchoice);

        // Clearing input buffer
        clearInputBuffer();

        if (ifchar != 1) {
            printf("Invalid input! Please enter a number.\n");
            Sleep(1000);
            displayTicket(concertIndex, index);
        }

        if (confirmchoice < 0 || confirmchoice > 2) {
            printf("Invalid choice! Please try again.\n");
            Sleep(1000);
            displayTicket(concertIndex, index);
        }
	    
	    if (confirmchoice == 1) {
	        concertMenu();
	        printf("Please wait.\n");
            Sleep(1000);
	    } else if(confirmchoice == 2){
	    	printf("Please wait.\n");
            Sleep(1000);
	        displayMainMenu();
	    } else {
	    	printf("Invalid choice. Please try again\n");
	    	Sleep(1500);
	    	displayTicket(concertIndex, index);
	    	
		}
	}while((confirmchoice != 1 && confirmchoice != 2) || ifchar != 1);
}

