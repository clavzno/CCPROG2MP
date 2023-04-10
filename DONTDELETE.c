      // iterate through each line in users.txt and find user through id in line
      char line[100];
      int userIDlen = (userProfilesptr[userIndex].userID);
      while (fgets(line, sizeof(line), userfile) != NULL)
      {
        // check if current line contains user id
        if (strcmp(line, userProfilesptr[userIndex].userID) == 0)
        {
          // found the line we are looking for, get the current position
          long pos = ftell(userfile);

          if (pos == -1)
          {
            printf("Error getting file position\n");
            fclose(userfile);
            return 1;
          }

          // move to position
          fseek(userfile, pos, SEEK_SET);

          // print new data starting on that line
          fprintf(userfile, "%d %s\n", userProfilesptr[userIndex].userID, userProfilesptr[userIndex].password);
          fprintf(userfile, "%s\n", userProfilesptr[userIndex].name);
          fprintf(userfile, "%s\n", userProfilesptr[userIndex].address);
          fprintf(userfile, "%s\n", userProfilesptr[userIndex].contact);
          fprintf(userfile, "%s\n", userProfilesptr[userIndex].sex);
          fprintf(userfile, "%s %s %s\n", userProfilesptr[userIndex].dose1_loc, userProfilesptr[userIndex].dose1_date, userProfilesptr[userIndex].dose1_type);
          fprintf(userfile, "%s %s %s\n", userProfilesptr[userIndex].dose2_loc, userProfilesptr[userIndex].dose2_date, userProfilesptr[userIndex].dose2_type);
          fprintf(userfile, "%s %s %s\n\n", userProfilesptr[userIndex].dose3_loc, userProfilesptr[userIndex].dose3_date, userProfilesptr[userIndex].dose3_type);
        }