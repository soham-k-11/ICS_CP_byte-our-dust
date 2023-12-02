#include<math.h>
#include<string.h>  
#include<stdlib.h>
#include"B23ME1066_B23EE1065.c"

int main()
{
    char fname[]="B23ME1066_B23ME1047.txt";                                //database.txt will be the file where we store our vote data
    int d;
    while(1)
    {       
        display_options();                                      //Displays the tasks that can be performed
        printf("\nEnter option number:");
        scanf("%d",&d);
        switch(d)
        {
            case 1: if(voter_id_checker())                         //Checks the voter ID of voters
                    {
                        break;
                    }
                    char candidate_alphabet;
                    scanf(" %c", &candidate_alphabet);          //Takes candidate alphabet(unique identity) as input
                    vote_counter(fname,candidate_alphabet);     //Counts the vote given by the user
                    break;

            case 2: if(password_checker(fname)==1)              //Checks if the password entered by user is correct
                    {
                        display_votes(fname);                   //If correct password is entered, displays the votes
                    }
                    break;

            case 3: if(password_checker(fname))
                    {
                        reset_votes(fname);                     //If correct password is entered, resets the votes
                    }
                    break; 

            case 4: clrscr();
                    printf("\nYOU HAVE EXITED\n");              //If user enters 4, then exits the program
                    return 0;   
    
            default:printf("\nEnter Valid Option Number\n");    //If user enters anything other than 1,2,3,4 then prints error message
                    break;   
            
        }
    }

    return 0;
}