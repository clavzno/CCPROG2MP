# CHECKLIST
format: [clavano, de grano]

# Milestone 1: February 23
[-, ] design for the project implementation
[x, ] collection of data needed for the project
[x, ] menu options
[x, ] preliminary outline of functions to be created

# Milestone 2:
# Milestone 3:
# Milestone 4:
# Milestone 5:

## Requirements (add any comments if necessary)
[] Vaccination Registration Menu
	[] User Registration
	[] Vaccination Appointment
	[] Chatbot (FAQs)
	[] Exit

[] Data Management Menu
	[] User
 		[] Add new user
   		[] View all users
	 	[] Edit user details
   		[] Delete user
	 	[] Exit
   [] Appointment
   		[] Add new appointment
	 	[] View all appointments
   		[] Edit appointment
	 	[] Delete appointment
   		[] Exit
   [] Chatbot
   [] Export
   [] Import
   [] Exit

[] Bonus:
	[] generating of pertinent reports
	[] meaningful chatbot convo
 

### Users.txt
<user1 id><space><password><new line>
<name><new line>
<address><new line>
<contact number><new line>
<sex><new line>
<location1><space><date1><space><vaccine1><new line>
<location2><space><date2><space><vaccine2><new line>
<location3><space><date3><space><vaccine3><new line>
<new line>
<user2 id><space><password><new line>
<name><new line>
<address><new line>
<contact number><new line>
<sex><new line>
<location1><space><date1><space><vaccine1><new line>
<location2><space><date2><space><vaccine2><new line>
<location3><space>><date3><space><vaccine3><new line>
<new line>
...
<userN id><space><password><new line>
<name><new line>
<address><new line>
<contact number><new line>
<sex><new line>
<location1><space><date1><space><vaccine1><new line>
<location2><space><date2><space><vaccine2><new line>
<location3><space><date3><space><vaccine3><new line>
<new line>
<eof>

### Appointment.txt
<appointment1 id><space><user id><new line>
<name><new line>
<location><new line>
<vaccine><new line>
<date><space><new line>
<time><new line>
<dose><new line>
<new line>
<appointment2 id><space><user id><new line>
<name><new line>
<location><new line>
<vaccine><new line>
<date><space><new line>
<time><new line>
<dose><new line>
<new line>
...
<appointmentN id><space><user id><new line>
<name><new line>
<location><new line>
<vaccine><new line>
<date><space><new line>
<time><new line>
<dose><new line>
<new line>
<eof>

### Chatbot.txt
<question1><new line>
<answer1><new line>
<question2><new line>
<answer2><new line>
...
<questionN><new line>
<answerN><new line>
<eof>
