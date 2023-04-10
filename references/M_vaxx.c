#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char string[100];

struct UserReg {
  int userID;
  string password;
  string name;
  string address;
  string contact;
  string sex;
  string  firstDoseDate;
  string firstDoseVaccine;
  string firstDoseLocation;
  string secondDoseDate;
  string secondDoseVaccine;
  string secondDoseLocation;
  string boosterDoseDate;
  string boosterDoseVaccine;
  string boosterDoseLocation;
};

struct AppReq {
  int appID;
  string name;
  string location;
  string vaccine;
  string date;
  string time;
  string dose;
};

void currentTime(){
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Current local time and date: %s", asctime (timeinfo) );
}
int displayPrimary(int num) {
  do {
    printf("\t\t\t(1) Vaccine Registration Menu\n");
    printf("\t\t\t(2) Data Management Menu\n");
    printf("\n\nChoose an option:");
    scanf("%d", &num);
    system("cls");
    getchar();
  } while (num != 1 && num != 2);

  return num;
}

int displayVRM(int num) {
  do {
    printf("\t\t\t(1) User Registration\n");
    printf("\t\t\t(2) Vaccination Appointment\n");
    printf("\t\t\t(3) Chatbot FAQs\n");
    printf("\t\t\t(4) Exit\n");
    printf("\n\nChoose an option: ");
    scanf("%d", &num);
    system("cls");
    getchar();
  } while (num != 1 && num != 2 && num != 3 && num != 4);

  return num;
}

int UserRegistration(FILE *fp, struct UserReg A[], int i, int a) {

  int option;

  if(a == 0)
  fp = fopen("Users.txt", "w");
  else
  fp = fopen("Users.txt", "a");

  printf("Kindly input all the necessary information about you\n");
  do 
  {
    printf("User ID: ");
    scanf("%d", &A[i].userID);
    if (A[i].userID < 1000 || A[i].userID > 9999)
      printf("Error, enter only 4 DIGITS\n");
  } while (A[i].userID < 1000 || A[i].userID > 9999);
    fprintf(fp, "%d ", A[i].userID);
  getchar();
  printf("Password: ");
  fgets(A[i].password, 10, stdin);
  fprintf(fp, "%s", A[i].password);
  A[i].password[strcspn(A[i].password, "\n")] = '\0';
  printf("Name: ");
  fgets(A[i].name, 20, stdin);
  fprintf(fp, "%s", A[i].name);
  printf("Address: ");
  fgets(A[i].address, 30, stdin);
  fprintf(fp, "%s", A[i].address);

do
{
  printf("Contact: ");
  scanf("%s", A[i].contact);
  if(strlen(A[i].contact) != 11)
  {
    printf("Invalid phone number size provided.\n"); 
  }
}while(strlen(A[i].contact) != 11);
  fprintf(fp, "%s\n", A[i].contact);
  printf("Sex: ");
  scanf("%s", A[i].sex);
  fprintf(fp,"%s\n", A[i].sex);

  getchar();

  printf("First Dose Location: ");
  scanf("%s", A[i].firstDoseLocation);
  fprintf(fp, "%s ", A[i].firstDoseLocation);

  getchar();

 do
{
  printf("Format must be YYYY-MM-DD\n");
  printf("Date of your First Dose Vaccine: ");
  scanf("%s", A[i].firstDoseDate);
  if(strlen(A[i].firstDoseDate) != 10)
  {
    printf("Invalid date format.\n"); 
  }
}while(strlen(A[i].firstDoseDate) != 10);
  fprintf(fp, "%s ", A[i].firstDoseDate);

  printf("First Dose Vaccine: ");
  scanf("%s", A[i].firstDoseVaccine);
  fprintf(fp, "%s\n", A[i].firstDoseVaccine);

  printf("Would you like to add a Second Dose?");
  printf("\nEnter 1 if yes and 2 if No: ");
  scanf("%d", &option);
  getchar();

  fclose(fp);
  return option;
}

int SecDoseOptional(FILE *fp, struct UserReg A[], int i) {

  int option;
  fp = fopen("Users.txt", "a");
  
  printf("Second Dose Location: ");
  scanf("%s", A[i].secondDoseLocation);
  fprintf(fp, "%s ", A[i].secondDoseLocation);

do
{
  printf("Format must be YYYY-MM-DD\n");
  printf("Date of your Second Dose Vaccine: ");
  scanf("%s", A[i].secondDoseDate);
  if(strlen(A[i].secondDoseDate) != 10)
  {
    printf("Invalid date format.\n"); 
  }
}while(strlen(A[i].secondDoseDate) != 10);
  fprintf(fp, "%s ", A[i].secondDoseDate);

  printf("Second Dose Vaccine: ");
  scanf("%s", A[i].secondDoseVaccine);
  fprintf(fp, "%s\n", A[i].secondDoseVaccine);

  printf("Would you like to add a Booster Dose?");
  printf("\nEnter 1 if yes and 2 if No: ");
  scanf("%d", &option);
  getchar();

  fclose(fp);
  return option;
}

void Success() {
  printf("You have Successfully Registered");
  printf("\nPress Enter to Continue...");
  getchar();
  system("cls");
}

void BoosterDose(FILE *fp, struct UserReg A[], int i) {

  fp = fopen("Users.txt", "a");

  printf("Booster Dose Location: ");
  scanf("%s", A[i].boosterDoseLocation);
  fprintf(fp, "%s ", A[i].boosterDoseLocation);

do
{
  printf("Format must be YYYY-MM-DD\n");
  printf("Date of your Booster Dose Vaccine: ");
  scanf("%s", A[i].boosterDoseDate);
  if(strlen(A[i].boosterDoseDate) != 10)
  {
    printf("Invalid date format.\n"); 
  }
}while(strlen(A[i].boosterDoseDate) != 10);
  fprintf(fp, "%s ", A[i].boosterDoseDate);

  printf("Booster Dose Vaccine: ");
  scanf("%s", A[i].boosterDoseVaccine);
  fprintf(fp, "%s\n\n", A[i].boosterDoseVaccine);
  getchar();

  Success();
  
  fclose(fp);
}

int AskIfRegistered(int num) {      
  int terminateLoop = 0;
  do
  {
  printf("Are you already a Registered User?");
  printf("\nType 1 if Yes and 2 if No: ");
  scanf("%d", &num);
  if (num != 1 && num != 2)
  {
    printf("Invalid choice, only enter 1 or 2.\n");
  }
  if (num == 1 || num == 2)
  {
    terminateLoop = 1;
  }
  
  } while (terminateLoop != 1 && num != 1 && num != 2);
  return num;
}

int Attempts(struct UserReg A[]) {
  int attempts = 0, found = 0, j, found1 = 0, i;
  int user;
  string pass;
  do {
    printf("Type in your User ID and Password below:\n");
    printf("User ID: ");
    scanf("%d", &user);
    getchar();
    for (i = 0; i < 100; i++) {
      if (A[i].userID == user) {
        found = 1;
        j = i;
      }
    }

    if (found == 0) {
      printf("User ID entered does not exist. Try again.\n\n");
      attempts++;}

    if (found == 1){
    printf("Password: ");
    fgets(pass, 10, stdin);
    pass[strcspn(pass, "\n")] = '\0';
    if (strncmp(pass,A[j].password,10) == 0) {
      printf("Log in successful\n\n");
      printf("Press Enter to Continue...");
      getchar();
      found1 = 1;
      } else {
        printf("The password entered does not match\n");
        attempts++;
      }
    }
  } while (found1 == 0 && attempts < 3);

  if (found1 == 1)
  return j;
  else return -1;
}

int VaccinationAppMenu(int num) {    
int terminateLoop = 0;
do
{
  printf("(1) Appointment Request\n");
  printf("(2) Manage Appointment Menu\n");
  printf("(3) Exit\n\n");
  printf("Choose an option: ");
  scanf("%d", &num);
  if (num == 3)
    {
        terminateLoop = 1;
    }
  if (num != 1 && num != 2 && num != 3)
  {
    printf("Invalid choice, only type numbers 1, 2, and 3.\n");
  }
  
} while (num != 1 && num != 2 && terminateLoop != 1); 
  return num;
}

void 

//add function to ask if user already made an appointment, kinda like the same as AskIfReg function

void AppointmentRequest(FILE *fptr, struct AppReq B[], int i, struct UserReg A[], int a) { 
  
  int terminateLoop = 0;
  char choice;
  if (a == 0)
  fptr = fopen("Appointment.txt", "w");
  else 
  fptr = fopen("Appointment.txt", "a");
  while (terminateLoop != 1)
  {
  printf("Registered already? Type 'Y' if yes, 'N' if not yet.");
  scanf(" %c", &choice);
  if (choice = 'N' || choice = 'n')
  {
    while(terminateLoop != 1)
    printf("To request for an appointment, kindly enter the following details\n");
  do{
    printf("App ID: ");
    scanf("%d", &B[i].appID);
    if(B[i].appID < 1000 || B[i].appID > 9999)
      printf("Error, enter only 4 DIGITS.\n");
  } while (B[i].appID < 1000 || B[i].appID > 9999);
    fprintf(fptr, "%d ", B[i].appID);
    fprintf(fptr, "%d\n", A[i].userID);
  getchar();
  printf("Name: ");
  fgets(B[i].name, 20, stdin);
  fprintf(fptr, "%s", B[i].name);
  printf("Location: ");
  scanf("%s", B[i].location);
  fprintf(fptr, "%s\n", B[i].location);
  printf("Vaccine: ");
  scanf("%s", B[i].vaccine);
  fprintf(fptr, "%s\n", B[i].vaccine);
  do{
    printf("Format must be YYYY-MM-DD\n");
    printf("Enter Date: ");
    scanf("%s", B[i].date);
    if(strlen(B[i].date) != 10)
      printf("Invalid date format. Try again.\n");
  }while (strlen(B[i].date) != 10);
  fprintf(fptr, "%s\n", B[i].date);
  do
  {
  printf("Time format must be '00:00' or 24-hour.\n");
  printf("Time: "); // Assuming that the user will enter betweeen 00:00 to 23:59. 
  scanf("%s", B[i].time);   
  if (strlen(B[i].time) != 5)
  {
    printf("Invalid time format. Try again.\n")
  }
  }while (strlen(B[i].time) != 5);
  fprintf(fptr, "%s\n", B[i].time);

  printf("Dose: ");
  scanf("%s", B[i].dose);
  fprintf(fptr, "%s\n\n", B[i].dose);

  printf("You have successfully booked your appointment\n\n");
  printf("Press Enter to continue...");
  getchar();
  getchar();

  fclose(fptr);
  printf("Done with register? type 'Y' if yes, type 'N' if no.\n");
  scanf(" %c", &choice);
  if (choice == 'Y' || choice == 'y')
  {
  terminateLoop = 1;
  }
  else if (choice == 'N' || choice == 'n')
  {
  terminateLoop = 0;
  }
  else
  {
  printf("Wrong, Y or N only.\n");
  }
  } 
  else if (choice = 'Y' || choice = 'y')
  {
  terminateLoop = 0;
  }
  else
  {
  printf("Wrong, Y or N only.\n");
  }
  }
}


int ManageAppointmentMenu (int n){
do
{
  printf("Manage Appointment\n");
  printf("(1)Cancel Appointment\n");
  printf("(2)Reschedule Date and Time\n");
  printf("(3)Change Vaccination Center Location and Vaccinatino Brand\n\n");
  printf("Choose an option: ");
  scanf("%d", &n);
  if (n != 1 && n != 2 && n != 3)
  {
    printf("Invalid choice, only type numbers 1, 2, and 3.\n");
  }
  
} while (n != 1 && n != 2 && n != 3);

return n;
}

void CancelAppointment (FILE *fptr, struct AppReq A[], struct UserReg B[], int i) {

  FILE *temp;
  int j = 0;

  fptr = fopen("Appointment.txt", "r");

  temp = fopen("Appointment.tmp", "w");

  printf("Your appointment will now be cancelled\n");
  printf("All appointment details will now be deleted\n");

  while (fscanf(fptr, "%d %d %s %s %s %s %s %s", &A[j].appID, &B[j].userID, A[j].name, A[j].location, A[j].vaccine, A[j].date, A[j].time, A[j].dose) == 8) {
    if (j != i){
      fprintf(temp, "%d %d\n%s\n%s\n%s\n%s\n%s\n%s\n\n", A[j].appID, B[j].userID, A[j].name, A[j].location, A[j].vaccine, A[j].date, A[j].time, A[j].dose);
    }
    j++;
  }

  fclose(fptr);
  fclose(temp);

  remove("Appointment.txt");
  rename("Appointment.tmp", "Appointment.txt");

  printf("Appointment Cancelled successfully\n");
  printf("Press Enter to Continue...");
  getchar();
  getchar();

  }

void Reschedule (FILE *fptr, struct AppReq A[], int i){
  
  string updatedTime;
  string updatedDate;
  FILE *temp;
  char content[1000], *ptr, *ptr2;

  fptr = fopen("Appointment.txt", "r");

  temp = fopen("Appointment.tmp", "w");

  do{
    printf("Format must be YYYY-MM-DD\n");
    printf("Changing the Date from %s to: ", A[i].date);
    scanf("%s", updatedDate);
    if(strlen(updatedDate) != 10)
      printf("Invalid date format.\n");  
  } while (strlen(updatedDate) != 10);
  
  do
  {
    printf("Changing the Time from %s to: ", A[i].time);
    printf("Time format must be '00:00' or 24-hour.\n");   
    scanf("%s", updatedTime);
    if (strlen(updatedTime)!=5)
    {
      printf("Invalid time format. Try again.\n")
    }
  } while (strlen(updatedTime)!=5); // Assuming that the user will enter betweeen 00:00 to 23:59. 
    printf("Changing the Time from %s to: %s ", A[i].time, updatedTime); // nilagay ko lang ganyan gusto ko sanang gawin

  while (fgets(content, 1000, fptr) != NULL){
    ptr = strstr(content, A[i].date);
    ptr2 = strstr(content, A[i].time);
    if(ptr != NULL){
      strncpy(ptr, updatedDate, strlen(updatedDate));
    }
    if(ptr2 != NULL){
      strncpy(ptr2, updatedTime, strlen(updatedTime));
    }
    fputs(content, temp);
  }

  fclose(fptr);
  fclose(temp);

  remove("Appointment.txt");
  rename("Appointment.tmp", "Appointment.txt");

  printf("Date and Time changed successfully.\n");
  printf("Press Enter to continue...");
  getchar();
  getchar();
  
}

void ChangeVCLaVB (FILE *fptr, struct AppReq A[], int i){
  
  string updateLoc;
  string updateBrand;
  FILE *temp;
  char content[1000], *ptr, *ptr2;

  fptr = fopen("Appointment.txt", "r");

  temp = fopen("Appointment.tmp", "w");

  printf("Changing the Location from %s to: ", A[i].location);
  scanf("%s", updateLoc);
  printf("Changing the Vaccine Brand from %s to: ", A[i].vaccine);
  scanf("%s", updateBrand);

  while (fgets(content, 1000, fptr) != NULL){
    ptr = strstr(content, A[i].location);
    ptr2 = strstr(content, A[i].vaccine);
    if(ptr != NULL){
      strncpy(ptr, updateLoc, strlen(updateLoc));
    }
    if(ptr2 != NULL){  
      strncpy(ptr2, updateBrand, strlen(updateBrand));
    }
    fputs(content, temp);
  }

  fclose(fptr);
  fclose(temp);

  remove("Appointment.txt");
  rename("Appointment.tmp", "Appointment.txt");

  printf("Vaccine Center Location and Vaccine Brand changed successfully\n");
  printf("Press Enter to continue...");
  getchar();

}

int DMmenu (struct UserReg A[]){
  int i;

  i = Attempts(A);
  
  return i;
}


void chatBotFAQ(){

  int terminateChatbot = 0;
  char userStringInput[80];
    printf("Welcome to Chatbot, ask us the following FAQs.\n");
    printf("FAQs:\n");
    printf("Is it mandatory?\n");
    printf("Is there any side effects with the vaccine?\n");
    printf("What are the approved vaccines in the Philippines?\n");
    printf("Who is our DOH chair?\n");
    printf("Where is nearest vaccine location?\n");
    printf("Where can I find the DOH website?\n");
    printf("\n");
    printf("Type 'exit' to exit\n");
    printf("\n"); 
    do
    {
     fgets(userStringInput);
      if (strcmp(userStringInput,"exit")==0)
    {
      terminateChatbot = 1;
      system("cls");
      printf("Thank you for using our ChatBot!\n");
      
    }
    else if(strcmp(userStringInput,"Is it mandatory?")==0)
    {
      printf("Chatbot: No, but it is highly recommended by our government.\n");
    }
    else if(strcmp(userStringInput,"Is there any side effects with the vaccine?")==0)
    {
      printf("Chatbot: Side effects can include pain, fever, fatigue, and headache.\n");
    }
    else if(strcmp(userStringInput,"What are the approved vaccines in the Philippines?")==0)
    {
      printf("Chatbot:\n");
      printf("1. Pfizer-BioNTech\n");
      printf("2. Oxford-AstraZeneca\n");
      printf("3. Sinovac\n");
      printf("4. Sputnik V\n");
      printf("5. Johnson and Johnson's Janssen\n");
      printf("6. Bharat BioTech\n");
      printf("7. Moderna\n");
      printf("8. Sinopharm.\n");

    }
    else if(strcmp(userStringInput,"Who is our DOH chair?")==0)
    {
      printf("Chatbot: MARIA ROSARIO S. VERGEIRE, MPH, CESO II is the current Officer-in-Charge of DOH\n");
    }
    else if(strcmp(userStringInput,"Where is nearest vaccine location?")==0)
    {
      printf("Chatbot: You can find your nearest vaccine location in your barangay health centers.\n");
    }
    else if(strcmp(userStringInput,"Where can I find the DOH website?")==0)
    {
      printf("Chatbot: You can enter https://doh.gov.ph/\n");
    }
    else
    {
      printf("Sorry, I do not know the answer. Please type another question\n");
      printf("Want to exit the chatBot? Type exit.\n");
    }
    }while(terminateChatbot != 1);
}

void chatBotAddQandA(int num){
  FILE *fp;
  char filename[80];
  char adminInputQuestion[80];
  char adminInputAnswer[80];
  char terminateLoop = 'Y';
  printf("Enter filename: ");
  scanf("%s", filename);

  printf("Add question: ");
  scanf("%s", adminInputQuestion);
  printf("Add answer: ");
  scanf("%s", adminInputAnswer);
  fp = fopen(filename, "a");

  fprintf(fp, "%s\n", adminInputAnswer);
  fprintf(fp, "%s\n", adminInputQuestion);
  
  while (terminateLoop == 'Y' || terminateLoop =='y')
  {
    printf("Add more? Type 'y' if yes, type 'n' if no...\n");
    scanf(" %c", &terminateLoop);
      if (terminateLoop == 'Y' || terminateLoop == 'y')
      {
        printf("Add question: ");
        scanf("%s", adminInputQuestion);
        fputs(adminInputQuestion,fp);
        printf("Add answer: ");
        scanf("%s", adminInputAnswer);
        fputs(adminInputAnswer,fp);
        
        fp = fopen(filename, "a");
        fprintf(fp, "%s\n", adminInputAnswer);
        fprintf(fp, "%s\n", adminInputQuestion);
        fclose(fp);
      }
  }
}

void chatBotViewQandA(int num){

  FILE *fp;
  char terminateLoop = 'Y';
  char filename[80];
  printf("Enter filename: ");
  scanf("%s", filename);
  fp = fopen(filename, "r");
    while (terminateLoop == 'Y' || terminateLoop == 'y')
    {
      char inputTexts;
    while ( (inputTexts = fgetc(fp)) != EOF)
    {
      putchar(inputTexts);
    }
    fclose(fp);
    printf("Read more? Type 'y' if yes, 'n' if no...\n");
    scanf(" %c", &terminateLoop);
    }
}

void ChatbotEditQandA(int num){

  FILE *fp, *temp;
  char textFileName[80];
  char temp_filename[80];
  char adminOriginalLineInput[80];
  char adminReplacedInput[80];
  int replace_line = 0;
  char terminateLoop = 'Y';
  while (terminateLoop == 'Y' || terminateLoop == 'y')
  {
  printf("File: ");
  scanf("%s", textFileName);
  strcpy(temp_filename, "temp");
  strcat(temp_filename, textFileName);
  printf("Replace Line Number: ");
  scanf("%d", &replace_line);
  fflush(stdin);
  printf("New Line: ");
  fgets(adminReplacedInput, 80, stdin);
  fp = fopen(textFileName, "r");
  temp = fopen(temp_filename, "w");
  int keep_reading = 0;
  int current_line = 1;
  while (keep_reading != 1)
  {
    
    fgets(adminOriginalLineInput, 80, fp);
    
    if (feof(fp)) {
        keep_reading = 1;
      }
    else if (current_line == replace_line){
      fputs(adminReplacedInput, temp);
      }
    else {
      fputs(adminOriginalLineInput, temp);
    }
    current_line++;
    
  }

  fclose(fp);
  fclose(temp);
  remove(textFileName);
  rename(temp_filename, textFileName);

  printf("Edit more? Type 'y' if yes, type 'n' if no...\n");
  scanf(" %c", &terminateLoop);
  }
}

void ChatbotDeleteQandA(int num){
  FILE *fp, *temp;
  char textFileName[80];
  char temp_filename[80];
  char adminLineInput[80];
  int delete_line = 0;
  char terminateLoop = 'Y';
  while (terminateLoop == 'Y' || terminateLoop == 'y')
  {
  printf("enter filename: ");
  scanf("%s", textFileName);
  strcpy(temp_filename, "temp");
  strcat(temp_filename, textFileName);
  printf("Delete Line: ");
  scanf("%d", &delete_line);
  fp = fopen(textFileName, "r");
  temp = fopen(temp_filename, "w");
  int keep_reading = 0;
  int current_line = 1;
  do 
  {
    fgets(adminLineInput, 80, fp);
    if (feof(fp)) 
    {
      keep_reading = 1;
    }
    else if (current_line != delete_line)
    {
      fputs(adminLineInput, temp);
    }
    current_line++;
  } while (keep_reading != 0);
  
  fclose(fp);
  fclose(temp);
  
  remove(textFileName);
  rename(temp_filename, textFileName);

  printf("Delete more? Type 'y' if yes, type 'n' if no...\n");
  scanf(" %c", &terminateLoop);  
  }

}

void adminDataLogin(){

}


int main() {

  int manage, c;
  int opt, num = 0, choice;
  struct UserReg User[100];
  struct AppReq Appointment[100];
  int attempts;
  int j = 0;
  int choice1;
  int exitt = 0;
  FILE *fp;
  FILE *fptr;
  int option;
  int r;
  int a = 0, b = 0;
  int cancel;

  printf("Welcome! Date and Time is ");
  currentTime();
  do {
    if (displayPrimary(opt) == 1) {
      do {
        choice = displayVRM(opt);
        if (choice == 1) {
          choice1 = UserRegistration(fp, User, j, a);
          if (choice1 == 1) {
            if (SecDoseOptional(fp, User, j) == 1) {
              BoosterDose(fp, User, j);
            } else
              Success();
          } else{
            Success();
            j++;
            a++;}
        } else if (choice == 2) {
          if (AskIfRegistered(num) == 1) {
            r = Attempts(User);
            if (r != -1){
              do{
              option = VaccinationAppMenu(opt);
              if (option == 1){
                AppointmentRequest(fptr, Appointment, r, User, b);
                b++;
              } else if (option == 2){
                ManageAppointmentMenu(c);
                if(manage == 1){
                  CancelAppointment(fptr, Appointment, User, r);
                  cancel = 1;
                  } else if (manage == 2){
                  Reschedule(fptr, Appointment, r);
                    } else if (manage == 3){
                  ChangeVCLaVB (fptr, Appointment, r);
                    }
                }
              } while (option != 3 && cancel != 1);
            }
          } else {
            printf("You need to register first in order to access this "
                   "option\n\n");
            printf("Press Enter to Continue...");
            getchar();
            system("cls");
          }

        
        
        
        
        } else if (choice == 3){
          chatBotFAQ();
        }
      } while (choice != 4);


    } else {
      attempts = DMmenu(User);

    }
  } while (attempts != -1);



}


