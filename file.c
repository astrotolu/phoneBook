#include <stdio.h>

// Function prototypes
void readData(void);
int menu();
int contactStoring();

int main()
{

    int selection, numOfContact, i, choice, ans;
    char name[50], addr[50];
    int age, phone, dob;

    selection = menu();

    if (selection == 1)
    {

        contactStoring();
    }
    else if (selection == 2)
    {

        readData();
    }
    else
    {

        printf("\nInvalid\n");
    }
}

// Menu Function
int menu()
{

    int selection;

    printf("\t\t\t\xB2\xB2\xB2 WELCOME TO PHONE BOOK \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

    printf("\n\t MENU \t\t\n");

    printf("\nPress 1 to add the contact\n");
    printf("Press 2 to read existing data\n");

    printf("\nEnter: ");
    scanf("%d", &selection);

    return selection;
}

// ContactStoring Function
int contactStoring()
{

    FILE *pWrite;
    int selection, numOfContact, i, choice, ans;
    char name[50], addr[50];
    int age, phone, dob;

    printf("Enter the number of contact to be added: ");
    scanf("%d", &numOfContact);

    for (i = 0; i < numOfContact; i++)
    {

        pWrite = fopen("contact.dat", "a+");

        if (pWrite == NULL)
        {

            printf("File cannot be opened\n");
        }
        else
        {
            // while (fscanf(pWrite, "%s%d%d%d%s", name, age, phone, dob, addr))
            // {
            // }

            printf("Enter the name: ");
            scanf("%s", &name);
            printf("Enter the age: ");
            scanf("%d", &age);
            printf("Enter the phone number: ");
            scanf("%d", &phone);
            printf("Enter the date of birth(mmddyyyy): ");
            scanf("%d", &dob);
            printf("Enter the address: ");
            scanf("%s", &addr);

            // apphend record info to file
            fprintf(pWrite, "\n%s %d %d %d %s", name, age, phone, dob, addr);
            printf("\nAccount created successfully!\n");
            fclose(pWrite);

        } // enf if
    }     // enf loop

    readData();
}

// ReadData Function
void readData(void)
{

    FILE *pView;

    int selection, numOfContact, i, choice, ans;
    char name[50], addr[50];
    int age, phone, dob;

    // open file access to read
    pView = fopen("contact.dat", "r");

    if (pView == NULL)
    {

        printf("\nFile cannot be opened\n");
    }
    else
    {

        printf("\nName\tAge\tPhone\t\tDOB\tAddress\n");

        // printf("\nThe number of contact you have entered is: %d\n", numOfContact);

        // read record from data file until end o file is reached

        // while (fscanf(pView, "%s %d %d %s", &name, &age, &phone, &dob, &addr))
        // {

        //     printf("\n%s\t%d\t%d\t%s", &name, age, phone, dob, addr);
        //     test++;
        // }

        while (!feof(pView))
        {

            // printf("Name: %s\n", name);
            // printf("Age: %d\n", age);
            // printf("Phone Number: %d\n", phone);
            // printf("Date of Birth: %d\n", dob);
            // printf("Address: %s\n", addr);
            fscanf(pView, "%s %d %d %d %s", &name, &age, &phone, &dob, &addr);
            printf("%s\t%d\t%d\t%d\t%s\n", name, age, phone, dob, addr);
        } // end of loop
    }     // end if

    fclose(pView);

} // end readData