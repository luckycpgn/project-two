// GROUP3
//PROJECT NUMBER-2
// STORE MANAGEMENT SYSTEM

// This program represents a simple store management system for "Lamachaur Department Store".
// It allows users to log in, view available items, add new items, update existing items, delete items,
// calculate bills for purchases, and exit the system. The program utilizes file handling to store
// item information persistently.

// Header files included for various functionalities
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

// Preprocessor directives defining constants for default username and password
#define USER_NAME "CIVILCD"
#define PASS "GROUP3"
//to use goto function
COORD coord={0,0};
// Function prototypes
void gotoxy(int x,int y)// Function to move cursor to specified coordinates on the console
{
    coord.X=x; coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void title(); // Function to display an animated title with developer names
void home(); // Function representing the main menu of the system
void add(); // Function to add new items to the store
void update(); // Function to update existing item details
void deleterec(); // Function to delete items from the store
void view(); // Function to view all available items in the store
void bill(); // Function to calculate the bill for purchases

// Structure representing details of an item
struct details
{
    int id; // Unique ID of the item
    char name[20]; // Name of the item
    int price; // Price of the item
    int qty; // Quantity of the item
};

// Global variable to store item details
struct details item;

// Main function
int main()
{
    // Variables for username and password authentication
    int i;
    char username[10]=USER_NAME;
    char user[10];
    char pass[10]=PASS;
    char password[10];

    // Display animated title
    title();
    gotoxy(36,6);
    printf("::::::Please LogIn to continue:::::::");

    relogin:

    // Prompt user to log in
    printf("\n\n\nEnter username:");
    fflush(stdin);
    scanf("%s",&user);
    printf("\nEnter passcode:");
    scanf (" %s", &password);

    // Authentication process
    if((strcmp(user,username)==0)&&(strcmp(pass,password)==0))
    {
        printf("\nLogin Successful!!");
        getch(); // Wait for user input
        home(); // Proceed to main menu
    }
    else
    {
        printf("\nLogin Unsuccessful!!\nPlease try again:");
        goto relogin; // Retry login if authentication fails
    }

    return 0;
}


// Function to display the main menu
void home()
{
    // Clear the console screen
    system("cls");

    // Display main menu options
    printf ("\t\t\t:::::::::::::::::LAMACHAUR DEPARTMENT STORE:::::::::::::::::\n\n\n\t\t\t  :::::::::::::::::Welcome To Our System::::::::::::::::::\n\n\n\t\t\t");

    gotoxy(40,9);
    printf("You can do any one of the following:");
    gotoxy(40,11);
    printf("1. View available items");
    gotoxy(40,12);
    printf("2. Add items");
    gotoxy(40,13);
    printf("3. Update all the items");
    gotoxy(40,14);
    printf("4. Delete items in the store");
    gotoxy(40,15);
    printf("5. Calculate My Bill");
    gotoxy(40,16);
    printf("6. Exit");
	// Prompt user to choose an option
    rechoose:
    gotoxy(40,20);
    printf(" Choose any of the above options:");

    int x;
    scanf("%d",&x);

    // Switch case to perform actions based on user input
    switch(x)
    {

    case 1:
        view();
        break;

    case 2:
        add();
        break;

    case 3:
        update();
        break;

    case 4:
        deleterec();
        break;

    case 5:
        bill();
        break;

    case 6:
        exit(1);

    default:
        printf("Enter above choice only:");

        goto rechoose;

    }

}
// Function to add new items to the store
void add()
{
    // File pointer to handle file operations
    FILE *fp=fopen("items.dat","ab+");

    if(fp==NULL)
    {
        printf("Error opening file");
        return;
    }

    // Loop to continuously add items
    while(1)
    {
        system("cls"); // Clear the console screen

    printf ("\t\t\t:::::::::::::::::LAMACHAUR DEPARTMENT STORE:::::::::::::::::\n\n\n\t\t\t  :::::::::::::::::Welcome To Our System::::::::::::::::::");

    gotoxy(50,8);
    printf ("ADD ITEMS IN THE STORE");
		// Prompt user to input item details
        fflush(stdin);
        gotoxy(40,10);
        printf("Name of item: ");
        gets(item.name);

        gotoxy(40,11);
        printf ("Enter unique ID of the item: ");
        scanf ("%d",&item.id);

        gotoxy(40,12);
        printf("Quantity of item: ");
        scanf("%d",&item.qty);

        gotoxy(40,13);
        printf("Price of item: ");
        scanf("%d",&item.price);

		// Write item details to file
        fseek(fp,0,SEEK_END);
        fwrite(&item,sizeof(struct details),1,fp);
        fflush(stdin);
        gotoxy(40,16);
        printf("Continue? (Y/N)");
        char ch = getch();
        if(ch=='N'|| ch=='n')
            break;
    }

    fclose(fp); // close the file
    gotoxy(40,18);
    printf("Your items has been added successfully.");

    getch(); // wait for user input

    home(); //return to main menu
}

// This function updates the details of existing items in the store.
void update()
{
    // Open the file in write mode to update items.
    FILE *fp=fopen("items.dat","wb+");

    // Check if file opening is successful.
    if(fp==NULL)
    {
        printf("Error opening file");
        return;
    }

    // Loop to continuously update items.
    while(1)
    {
        system("cls"); // Clear the console screen.

        // Display update section title.
        printf ("\t\t\t:::::::::::::::::LAMACHAUR DEPARTMENT STORE:::::::::::::::::\n\n\n\t\t\t  :::::::::::::::::Welcome To Our System::::::::::::::::::");

        gotoxy(50,8);
        printf ("UPDATE ITEMS IN THE STORE");

        fflush(stdin);
        gotoxy(40,10);
        printf("Name of item: ");
        gets(item.name);

        gotoxy(40,11);
        printf ("Enter unique ID of the item: ");
        scanf (" %d",&item.id);

        gotoxy(40,12);
        printf("Quantity of item: ");
        scanf("%d",&item.qty);

        gotoxy(40,13);
        printf("Price of item: ");
        scanf("%d",&item.price);

        // Move file pointer to the end of the file.
        fseek(fp,0,SEEK_END);

        // Write the updated item details to the file.
        fwrite(&item,sizeof(struct details),1,fp);
        fflush(stdin);
        gotoxy(40,16);
        printf("Continue? (Y/N)");
        char ch = getch();
        if(ch=='N'|| ch=='n')
            break;
    }

    fclose(fp); // Close the file.
    gotoxy(40,18);
    printf("Your items have been updated successfully.");

    getch(); // Wait for user input.

    home(); // Return to the main menu.
}

// This function deletes items from the store based on item ID.
void deleterec()
{
    while (1)
    {
        system("cls"); // Clear the console screen.
        int itemid;
        int flag=0;
        char ch;
        printf ("\t\t\t:::::::::::::::::LAMACHAUR DEPARTMENT STORE:::::::::::::::::\n\n\n\t\t\t  :::::::::::::::::Welcome To Our System::::::::::::::::::");

        gotoxy(50,8);
        printf ("DELETE ITEMS IN THE STORE");

        gotoxy(40,10);
        printf ("Enter the Id of the item you want to delete:");
        scanf ("%d",&itemid);
        FILE *fp;
        FILE *ft;
        fp=fopen("items.dat","rb");
        ft=fopen("temp.dat","wb+");
        rewind(fp);
        while(fread(&item,sizeof(struct details),1,fp))
        {
            if (item.id==itemid)
            {
                // Item found, delete it from the file.
                flag=1;
                gotoxy(40,18);
                printf ("Record found and deleted successfully");
            }
            else
            {
                // Item not found, write it to the temporary file.
                fseek(ft,0,SEEK_END);
                fwrite(&item,sizeof(struct details),1,ft);
            }
        }
        if (flag==0)
        {
            gotoxy(40,18);
            printf ("Record not found");
        }
        fclose(fp);
        fclose(ft);
        remove("items.dat"); // Delete the original file.
        rename("temp.dat","items.dat"); // Rename the temporary file.

        getch(); // Wait for user input.

        home(); // Return to the main menu.
    }
}

// This function displays all available items in the store.
void view()
{
    system("cls"); // Clear the console screen.
    int x=0;
    printf ("\t\t\t:::::::::::::::::LAMACHAUR DEPARTMENT STORE:::::::::::::::::\n\n\n\t\t\t  :::::::::::::::::Welcome To Our System::::::::::::::::::");

    gotoxy(45,8);
    printf ("ITEMS AVAILABLE IN THE STORE");
    gotoxy(40,10);
    printf("ID\tName\t\t Quantity\tPrice");
    gotoxy(38,11);
    printf("----------------------------------------------------------");

    // Open the file in read mode.
    FILE *fp = fopen("items.dat", "rb");

    // Check if file opening is successful.
    if(fp==NULL)
    {
        printf("Error opening file");
    }

    // Move file pointer to the beginning of the file.
    fseek(fp,0,SEEK_SET);

    // Loop to read and display item details from the file.
    while(fread(&item,sizeof(struct details),1,fp))
    {
        gotoxy(40,13+x);
        printf("%d\t%s\t\t %d\t\t%d\t\t\n",item.id,item.name,item.qty,item.price);
        x++;
    }

    fclose(fp); // Close the file.

    getch(); // Wait for user input.

    home(); // Return to the main menu.
}

// This function calculates the bill for purchases.
void bill()
{
    int cur=0,x,y,i,sum=0,flag;
    system("cls"); // Clear the console screen.

    printf ("\t\t\t:::::::::::::::::LAMACHAUR DEPARTMENT STORE:::::::::::::::::\n\n\n\t\t\t  :::::::::::::::::Welcome To Our System::::::::::::::::::");
    FILE *fp = fopen("items.dat","rb"); // Open the file in read mode.
    struct details purchase[20]={0};
    gotoxy(50,8);
    printf ("BILLING SECTION");
    gotoxy(40,10);
    printf("How many items do you want to purchase?\t");
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        flag=0;
        system("cls"); // Clear the console screen.

        printf ("\t\t\t:::::::::::::::::LAMACHAUR DEPARTMENT STORE:::::::::::::::::\n\n\n\t\t\t  :::::::::::::::::Welcome To Our System::::::::::::::::::");

        fflush(stdin);
        gotoxy(50,8);
        printf("BILLING SECTION");
        gotoxy(40,11);
        printf ("Enter Id of item:\t");
        scanf ("%d",&purchase[i].id);
        rewind(fp);
        while(fread(&item,sizeof(struct details),1,fp))
        {
            if (item.id==purchase[i].id)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            fflush(stdin);
            gotoxy(40,12);
            printf("Name of item:\t");
            gets(purchase[i].name);

            gotoxy(40,13);
            printf("Quantity of item:\t");
            scanf("%d", &purchase[i].qty);

            gotoxy(40,14);
            printf("Price of item:\t");
            scanf("%d", &purchase[i].price);
        }
        if(flag==0)
        {
            gotoxy(40,12);
            printf("Record not found.");
            gotoxy(20,13);
            printf("Please view all the items first and use the item code,name,quantity available in the list.\n");
            break;
        }
    }
    if(flag==1)
    {
        getch(); // Wait for user input.
        fflush(stdin);
        system("cls"); // Clear the console screen.
        printf ("\t\t\t:::::::::::::::::LAMACHAUR DEPARTMENT STORE:::::::::::::::::\n\n\n\t\t\t  :::::::::::::::::Welcome To Our System::::::::::::::::::");

        gotoxy(50,6);
        printf("BILL");

        gotoxy(30,8);
        printf("Id\t Name\t Quantity\t Price\t   Total");

        // Calculate total cost and display bill details.
        for(i=0;i<x;i++)
        {
            gotoxy(30,12+cur);
            printf("%d\t %s\t %d\t\t %d\t    %d\t",purchase[i].id,purchase[i].name,purchase[i].qty,purchase[i].price,(purchase[i].qty*purchase[i].price));

            sum+=(purchase[i].qty*purchase[i].price);
            cur++;
        }

        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");


        printf("\nYour total cost is Rs. %d",sum);

        printf("\nEnter money received from customer:");
        fflush(stdin);
        scanf("%d",&y);

        printf("Please return Rs.%d",y-sum);
        getch(); // Wait for user input.
    }
}

// This function displays an animated title.
void title()
{
    int i,j,k,l;
    char title[]=("\t\t\t:::::::::::::::::LAMACHAUR DEPARTMENT STORE:::::::::::::::::\n\n\n\t\t\t  :::::::::::::::::Welcome To Our System::::::::::::::::::\n\n\n\t\t\t");
    char fn[]=("Developed By:");
    char fn1[]=("LUCKY SHARMA\t\tKRISHAL MALLA");
    char fn2[]=("KUSHAL ADHIKARI\t\tKRITAN POKHREL");

    // Display the animated title and developer names.
    for (i=0;i<strlen(title);i++)
    {
        putchar(title[i]);
        Sleep(25);
    }
    for (j=0;j<strlen(fn);j++)
    {
        gotoxy(75+j,21);
        putchar(fn[j]);
        Sleep(25);
    }
    for (k=0;k<strlen(fn1);k++)
    {
        gotoxy(85+k,22);
        putchar(fn1[k]);
        Sleep(25);
    }
    for (l=0;l<strlen(fn2);l++)
    {
        gotoxy(85+l,23);
        putchar(fn2[l]);
        Sleep(25);
    }
}

