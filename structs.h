#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_USERS 100

struct userFile {
    //REQUIRED UPON REGISTRY
    int userID; //maximum number of 10, all are initialized as 0
    char fullName[21];
    char password[11];
    char address[50];
    char contactNumber[12]; //philippine numbers start with 0-xxx-xxx-xxxx
    char sex; //M or F
    char firstDoseDate[10]; //format: YYYY-MM-DD
    char firstDoseVaccine[11];
    char firstDoseLocation[11];
    //OPTIONAL
    char secondDoseDate[10]; //format: YYYY-MM-DD
    char secondDoseVaccine[11];
    char secondDoseLocation[11];
    char firstBoosterDate[10]; //format: YYYY-MM-DD
    char firstBoosterVaccine[11];
    char firstBoosterLocation[12];
    char secondBoosterDate[10]; //format: YYYY-MM-DD
    char secondBoosterVaccine[11];
    char secondBoosterLocation[11];
};

struct vaccineAppointment {
    int applicationID; //maximum number of 10
    char fullName[21];
    char location[50];
    char vaccine[11];
    char date[10]; //format: YYYY-MM-DD
    char time[6]; //format: HH:MM (24-hour format)
    char dose[14]; //second, first booster, second booster
};

struct chatbot {
    char question[600];
    char answer[600];
};

#endif