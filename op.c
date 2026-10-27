#include <stdio.h>
int main()
{
    // Displaying the hospital name and the name of the system
    printf("==================================================\n");
    printf("\t\tMEDICARE HOSPITAL\n");
    printf("\t     OP REGISTRATION SYSTEM\n");
    printf("==================================================\n");
    
    // Displaying instructions and the list of available departments

    printf("\n\n\t\t  INSTRUCTIONS\n\n");
    printf("Please enter the department number: \n");
    printf("\n1. Cardiology\n");
    printf("2. Orthopaedics\n");
    printf("3. Gynaecology\n");
    printf("4. Paediatrics\n");
    printf("5. General Medicine\n");
    printf("6. Casualty / Emergency\n");
    printf("\n\nEnter the appropriate number when asked.\n\n");
    printf("\n\nPress ctrl+c to exit from the program.\n\n");
    printf("==================================================\n\n");

    // The program runs continuously until the user stops it using Ctrl+C

    // Initialising the current token number for each department to 0
    int current_token[6]={0,0,0,0,0,0};

    // Storing the maximum number of tokens allowed for each department
    int max_token[6]={8,10,9,15,1};

     // Storing the names of the departments as an array of strings
    char department[5][20]={"Cardiology","Orthopaedics","Gynaecology","Paediatrics","General Medicine"};
    
    // Used to access the appropriate department name from the array
    int index;

    // Infinite loop for registering multiple patients

    while(1)
    {  
       // Variables for storing the details of the current patient
       int age,dept;
       char name[50],sex[10];

       // Taking patient details as input
       printf("Enter The Patients Name : ");
       fgets(name, 50, stdin);
       printf("\nEnter Patients Sex : ");
       fgets(sex,10, stdin);
       printf("\nEnter Patients Age : ");
       scanf("%d",&age);

       // Taking the department number selected by the patient
       printf("\nPlease select the department you need to visit: ");
       scanf("%d",&dept);

        // Clearing the newline character left in the input buffer
       getchar();

       //Selecting the department using the department number

       switch(dept)
       {
            //cardiology
            case 1:
                index = 0;
                current_token[0]++;
                // Checking whether a token is still available
                if(current_token[0]<=max_token[0])
                {
                    goto ticket;
                }
                else
                {   
                    // Informing the patient when the token limit is reached
                    printf("Sorry, the token limit for this department has been reached.\nNo more tokens are available for today.");
                    
                    // Skipping the rest of the current loop and registering the next patient
                    continue;
                } 
            
            // Orthopaedics
            case 2:
                index = 1;
                current_token[1]++;
                if(current_token[1]<=max_token[1])
                {
                    goto ticket;
                }
                else
                {
                    printf("Sorry, the token limit for this department has been reached.\nNo more tokens are available for today.");
                    continue;
                } 
                
            // Gynaecology
            case 3:
                index = 2;
                current_token[2]++;
                if(current_token[2]<=max_token[2])
                {
                    goto ticket;
                }
                else
                {
                    printf("Sorry, the token limit for this department has been reached.\nNo more tokens are available for today.");
                    continue;
                } 

            // Paediatrics
            case 4:
                index = 3;
                current_token[3]++;
                if(current_token[3]<=max_token[3])
                {
                    goto ticket;
                }
                else
                {
                    printf("Sorry, the token limit for this department has been reached.\nNo more tokens are available for today.");
                    continue;
                } 

            // General Medicine
            case 5:
                index = 4;
                current_token[4]++;
                if(current_token[4]<=max_token[4])
                {
                    goto ticket;
                }
                else
                {
                    printf("Sorry, the token limit for this department has been reached.\nNo more tokens are available for today.");
                    continue;
                }
                
            // Casualty / Emergency does not use the normal token system
            case 6:
                printf("\n==================================================\n");
                printf("\t\tMEDICARE HOSPITAL\n");
                printf("\tEMERGENCY OP TICKET \n\n");
                printf("==================================================\n\n");
                printf("Patient Name : %s",name);
                printf("Age          : %d",age);     
                printf("\nSex          : %s\n\n",sex);
                printf("Department   : Casualty / Emergency");
                printf("\nStatus       : EMERGENCY\n");
                printf("\n\n--------------------------------------------------\n");
                printf("Please wait for your token number to be called.\n");
                printf("==================================================\n\n");
                continue;
        // Common OP ticket section for departments 1 to 5         
       ticket:
        printf("\n==================================================\n");
        printf("\t\tMEDICARE HOSPITAL\n");
        printf("\t\t    OP TICKET \n\n");
        printf("==================================================\n\n");
        printf("Patient Name : %s",name);
        printf("Age          : %d",age);     
        printf("\nSex          : %s\n\n",sex);
        printf("Department   : %s",department[index]);
        printf("\nToken No.    : %d",current_token[dept - 1]);
        printf("\nTime         : 4:00 PM - 8:00 PM");
        printf("\n\n--------------------------------------------------\n");
        printf("Please wait for your token number to be called.\n");
        printf("==================================================\n\n");
        }
    }
    return 0;
}