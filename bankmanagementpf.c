#include<stdio.h> // input output
#include<stdlib.h> // for exit function 
#include<string.h> //  strcmp(string 1t, string2) for comparing two strings .. all sstrings functions included in this header file
#include<conio.h> // for getch()..System("cls")..
#include<windows.h> // sleep function
/// global declaration of functions and variables .. 
int list();
void deposit();
void withdraw();
void transferamount();
void checkdetails();
void end();
void createAccount();
//global variables..
int ch;
float totalamount=0,depoamo,withamo,transamo,totaldepo=0,totalwith=0,totaltrans=0;
char accPass[30];
char NIC[30],account[30];
char name[50];
char a[50];
char password[30], CNIC[30],mobile[30];
int main()
{
   system("cls"); // clears the screen
  createAccount();
 while(1)
 {
   system("cls");
   switch(list())
   {
     case 1:
        deposit();
       totaldepo+=depoamo; 
        printf("\n******Press any key to continue******");
        break;
     case 2:
        withdraw();
        if (withamo<=totalamount)
            totalwith+=withamo;
        printf("\n******Press any key to continue******");
        break;
     case 3:
        transferamount();
        if (transamo<=totalamount)
            totaltrans+=transamo;
            printf("\n******Press any key to continue******");

        break;
     case 4:
        checkdetails();
         printf("\n******Press any key to continue******");
        break;
     case 5:
        system("CLS");
        end();
        getch(); 
        exit(0);
     default:
        system("CLS");
        printf("\n******Invalid Choice******");
        printf("\nPress any key twice to choose again..");
        getch();
        break;
    }//end of switch
getch();
 }//end of while
}
int list()
{
  printf("************WELCOME TO ASD BANK*************");
  printf("\n\n1. Deposit Amount");
  printf("\n2. Withdraw Amount");
  printf("\n3. Transfer Amount");
  printf("\n4. Check details");
  printf("\n5. Exit");
  printf("\nEnter your choice <e.g- 1 to Deposit Amount>: ");
  scanf("%d", &ch);
  return(ch);
}
void deposit()
{
    printf("\nEnter the amount you want to Deposit: ");
    scanf("%f",&depoamo);
    totalamount+=depoamo;
    printf("\n%f Amount Deposit sucessfully!!",depoamo);
     checkdetails();
}
void withdraw()
{
    printf("\nEnter the amount you want to Withdraw: ");
    scanf("%f",&withamo);
      if (withamo<=totalamount)
       { totalamount-=withamo;
         printf("\n%f Amount Withdrawn sucessfully!!",withamo);
         checkdetails();
       }
      else
        {printf("\n******Invalid Amount to Withdraw!******");
        }
}
void transferamount()
{

   printf("\nEnter the amount you want to Transfer: ");
    scanf("%f",&transamo);
      if (transamo<=totalamount)
       { 
         totalamount-=transamo;
         printf("\n%f Amount transfered sucessfully!!!",transamo);
          checkdetails();
       }
      else
       {
          printf("\n******Invalid Amount to Transfer!******");
       }
}
void checkdetails()
{
  printf("\n\n*********************************Account Details*********************************");
    printf("\nYour remaining Total Amount=%f",totalamount); 
}
void end()
{
  int smiley = 1;
    printf("\n*****************ASD BANK********************\n");
    printf("\nYour Name=%s",name);
    printf("\nAccount Number=%s",account);
    printf("\nTotal Amount=%f",totalamount); 
    printf("\nTotal Deposited Amount=%f",totaldepo);
    printf("\nTotal Withdrawn Amount=%f",totalwith); 
    printf("\nTotal Transfered Amount=%f",totaltrans); 
    printf("\n\n**************Thank you for using ASD Bank services! %c ****************",smiley);
}
void createAccount()
{
printf("*****************Welcome to ASD bank******************\n");
printf("\n\n*****************Create your Account*************************\n");
printf("\n\nEnter your Name: ");
scanf("%s",name);
printf("\nEnter your CNIC: ");
scanf("%s",CNIC);
printf("\nEnter your Mobile: ");
scanf("%s",mobile);
printf("\nEnter your Password: ");
int p=0;
do{
    password[p]=getch();
    if(password[p]!='\r')//carriage return
    {
        printf("*");
    }
    p++;
}while(password[p-1]!='\r');
password[p-1]='\0';
printf("\n\nEnter your Account: ");
scanf("%s",account);
system("cls");
printf("************Your Entered Details************");
printf("\nName: %s",name);
printf("\nCNIC: %s",CNIC);
printf("\nMobile #: %s",mobile);
printf("\nAccount: %s",account);
  printf("\n\n***********Thank you for creating the account!*********");
  printf("\n\nYou are now being redirected to login page in 3 seconds!");
Sleep(3000); //1000mili sec=1 sec;
system("cls");
printf("\n\t\t\t -Login Page-");
int isMatched= 0;
while (isMatched!=1)
{
   printf("\nEnter your CNIC:");
 scanf("%s",NIC);
// gets(NIC);
 printf("\nEnter your password:");
//  scanf("%s",accPass);
 int t=0;
do{
    accPass[t]=getch();
    if(accPass[t]!='\r')
    {
        printf("*");
    }
    t++;
}while(accPass[t-1]!='\r');
accPass[t-1]='\0';
//  gets(accPass);
  int retCNIC = strcmp(NIC,CNIC); //0
  int retPass = strcmp(accPass,password);
   if(retPass == 0 && retCNIC == 0)
   {
    printf("\n\t\t\t *Login Success*");
    Sleep(2000); // sleeps for 2 seconds means it waits for two seconds and then execute other things
    isMatched=1;
  } 
   else
   {
    system("cls");
    printf("\nInvalid Login!");
    printf("\nTry again! \n");
    isMatched=0;
  }
}
}