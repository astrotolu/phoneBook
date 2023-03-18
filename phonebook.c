#include <stdio.h>

int menu();

int main()
{

    int selection, numOfContact, i, choice;
    char name[50], addr[50];
    int age, phone, dob;

    selection = menu();

    if (selection == 1)
    {
        printf("Enter the number of contact to be added: ");
        scanf("%d", &numOfContact);

        for (i = 0; i < numOfContact; i++)
        {

            printf("Enter the name: ");
            scanf("%s", &name);
            printf("Enter the age: ");
            scanf("%d", &age);
            printf("Enter the phone number: ");
            scanf("%d", &phone);
            printf("Enter the date of birth: ");
            scanf("%d", &dob);
            printf("Enter the address: ");
            scanf("%s", &addr);
        }

        printf("\n\tPress 3 to see the entered contact\n");
        printf("\tPress 0 to exit the phone book\n");

        printf("\nEnter: ");
        scanf("%d", &choice);

        if (choice == 3)
        {

            for (i = 0; i < numOfContact; i++)
            {
                printf("\nThe number of contact you have entered is: %d\n", numOfContact);

                printf("\n--------------------\n");
                printf("Name: %s\n", name);
                printf("Age: %d\n", age);
                printf("Phone Number: %d\n", phone);
                printf("Date of Birth: %d\n", dob);
                printf("Address: %s\n", addr);
                printf("--------------------\n");
            }
        }
    }
    else
    {
        printf("You have selected 0\n");
    }

    return 0;
}

int menu()
{

    int selection;

    printf("\t\t\t\xB2\xB2\xB2 WELCOME TO PHONE BOO \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

    printf("\n\t MENU \t\t\n");

    printf("\nPress 1 to add the contact\n");

    printf("\nEnter: ");
    scanf("%d", &selection);

    return selection;
}