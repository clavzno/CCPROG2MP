Milestone 1: Collection of Data needed for the project
last modified: 2023-02-22

# Module 1: Vaccination Registration Menu
## 1. User Registration
int userID
str[10] password
str[20] name
str[30] address
int contact
str[10] sex
str[10] first dose (YYYY-MM-DD)
str[10] first dose vaccine
str[10] first dose location 
str[10] second dose (Optional)
str[10] second dose vaccine (Optional)
str[10] second dose location (Optional)
str[10] booster dose (Optional)
str[10] booster dose vaccine (Optional)
str[10] booster dose location (Optional)

## 2. Vaccination Appointment
### 2.1 Appointment Request
int appID
str[20] name
str[10] location
str[10] vaccine
str[11] date 
//note: why is date saved with 10 char in user registration and 11 in appt request
str[6] time (24-hour format)
str[10] dose 
// note: pdf example does not match 

### 2.2 Chatbot FAQs
str[80] Question
str[80] Answer 


# Module 2: Data Management Menu
## 1. User
### 1.1 add new user
int userID
str[10] password
str[20] name
str[30] address
int contact
str[10] sex
str[10] first dose (YYYY-MM-DD)
str[10] first dose vaccine
str[10] first dose location 
str[10] second dose (Optional)
str[10] second dose vaccine (Optional)
str[10] second dose location (Optional)
str[10] booster dose (Optional)
str[10] booster dose vaccine (Optional)
str[10] booster dose location (Optional)
### 1.2 view all users
int userID (arranged by)
str[10] password
str[20] name
str[30] address
int contact
str[10] sex
str[10] first dose (YYYY-MM-DD)
str[10] first dose vaccine
str[10] first dose location 
str[10] second dose (Optional)
str[10] second dose vaccine (Optional)
str[10] second dose location (Optional)
str[10] booster dose (Optional)
str[10] booster dose vaccine (Optional)
str[10] booster dose location (Optional)
### 1.3 edit user details
int userID
str[10] password
str[20] name
str[30] address
int contact
str[10] sex
str[10] first dose (YYYY-MM-DD)
str[10] first dose vaccine
str[10] first dose location 
str[10] second dose (Optional)
str[10] second dose vaccine (Optional)
str[10] second dose location (Optional)
str[10] booster dose (Optional)
str[10] booster dose vaccine (Optional)
str[10] booster dose location (Optional)
### 1.4 delete user
### 1.5 exit

## 2. Appointment
## 3. Chatbot
## 4. Export
## 5. Import
