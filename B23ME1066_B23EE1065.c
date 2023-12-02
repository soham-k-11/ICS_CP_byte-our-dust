#include<stdio.h>
#include<conio.h>

void clrscr()
{
    printf("\033[2J\033[H");    // ANSI escape sequence to clear screen
}

int voter_id;

const int password=1920;        //key to access certain operations

typedef struct                  //structure to store candidate info
{
    char candidate_name[50];
    int numvotes;

}candidates;


void display_candidates()        //Displays Candidate names for voting
{
    printf("\n--> Candidate-A\n--> Candidate-B\n--> Candidate-C\n--> Candidate-D\n--> NOTA(n/N)\n");
    printf("\nEnter candidate alphabet:");
}


void store_voter_id_in_file(int voter_id)               //Stores voter IDs in file      
{
    FILE *fp;
    fp=fopen("B23ME1066_B23EE1065.txt","a");
    fprintf(fp,"id_%d\n",voter_id);
    fclose(fp);
}

int duplicate_voter_id_checker(int voter_id)            //Checks if entered voter ID is a duplicate 
{
    FILE *fp;
    char v_id[6],c;
    int cpy,i;
    fp=fopen("B23ME1066_B23EE1065.txt","r");
    if((c=fgetc(fp))==EOF)
    {
        fseek(fp,-1,SEEK_CUR);
        fclose(fp);
        return 0;
    }
    fseek(fp,-1,SEEK_CUR);
    while(fscanf(fp,"%s",v_id)!=EOF)
    {
        cpy=voter_id;
        for (i = 5; i > 2; i--)
        {
            int t=cpy%10;
            if((v_id[i]-'0')==t)
            {
                cpy/=10;
                continue;
            }
            else
            {
                break;
            }
        }
        if(i==2)
        {
            fclose(fp);
            return 1;
        }
        
    }
    fclose(fp);
    return 0;
}

int voter_id_checker()                                     //Checks if the voter ID is valid or not
{
    printf("\nEnter your 3-digit voter ID:");
    scanf("%d",&voter_id);
    if(voter_id<=200&&voter_id>=101)
    {
        if(duplicate_voter_id_checker(voter_id)==0)         //Valid if its not a duplicate
        {
            printf("\n=> You are Welcome!\n");
            display_candidates();
        }
        else
        {
            clrscr();
            printf("\n=> You have already voted\n");
            printf("\n=> Do you want to enter next voter ID(Y/N)?");
            if(getchar()=='Y'||getchar()=='y')
            {
                voter_id_checker();
            }      
            else
            {
                clrscr();
                return 1;
            }                       
        }
    }
    else
    {
        printf("\n=> Voter ID not valid\n");
        printf("\n=> Do you want to try again(Y/N)?");
        if(getchar()=='Y'||getchar()=='y')
        {
            voter_id_checker();
        }
        else
        {
            clrscr();
            return 1;
        }  
    }
    return 0;
}


void display_options()          //Displays initial options for user
{
    printf("\n1. Caste a Vote\n2. Show Current status of Votes\n3. Reset Votes to zero\n4. Exit\n");
}


void store_in_obj(char fname[],candidates obj[])        //Stores all the data from database in array of structures 
{
    FILE *fp;
    fp=fopen(fname,"r");
    for (int i = 0; i < 5; i++)
    {
        fscanf(fp,"%s\t%d",obj[i].candidate_name,&obj[i].numvotes);
    }
    fclose(fp);    
}


void store_in_file(char fname[],candidates obj[])       //Stores all the data in array of structures in database
{
    FILE *fp;
    fp=fopen(fname,"w");
    for (int i = 0; i < 5; i++)
    {
        if(i==4)
        {
            fprintf(fp,"%s\t\t%d\n",obj[i].candidate_name,obj[i].numvotes);
            break;
        }
        fprintf(fp,"%s\t%d\n",obj[i].candidate_name,obj[i].numvotes);
    }
    fclose(fp); 
}


void reset_votes(char fname[])             //Resets the number of votes to zero
{
    FILE *fp;
    candidates obj[5];
    store_in_obj(fname,obj);
    for (int i = 0; i < 5; i++)
    {
        obj[i].numvotes=0;
    }
    store_in_file(fname,obj);
    fp=fopen("B23ME1066_B23EE1065.txt","w");
    fclose(fp);
    printf("\n=> Votes have been Reset\n");
}


void vote_counter(char fname[],char candidate_alphabet)        //Is called whenever user enters a candidate alphabet to vote for in order to count votes
{
    candidates obj[5];
    store_in_obj(fname,obj);
    switch (candidate_alphabet) 
    {
        case 'a':
        case 'A':
                obj[0].numvotes++;
                store_voter_id_in_file(voter_id);
                clrscr();
                printf("\n=> Your Vote has been Saved\n");
                break;
        case 'b':
        case 'B':
                obj[1].numvotes++;
                store_voter_id_in_file(voter_id);
                clrscr();
                printf("\n=> Your Vote has been Saved\n");
                break;

        case 'c':
        case 'C':
                obj[2].numvotes++;
                store_voter_id_in_file(voter_id);
                clrscr();
                printf("\n=> Your Vote has been Saved\n");
                break;
        case 'd':
        case 'D':
                obj[3].numvotes++;
                store_voter_id_in_file(voter_id);
                clrscr();
                printf("\n=> Your Vote has been Saved\n");
                break;
        case 'n':
        case 'N':
                obj[4].numvotes++;
                store_voter_id_in_file(voter_id);
                clrscr();
                printf("\n=> Your Vote has been Saved\n");
                break;
        default:clrscr();
                printf("\n=> The entered character is not a candidate alphabet.\n");
                break;
    }
    store_in_file(fname,obj);    
    
}


void display_votes(char fname[])            //Displays the current status of votes
{
    candidates obj[5];
    float sum=0;
    store_in_obj(fname,obj);
    for (int i = 0; i < 5; i++)             //Calculating the total number of votes
    {
        sum+=obj[i].numvotes;
    }

    if(sum==0)
    {
        printf("\nCANDIDATE NAME\t\tNUMBER OF VOTES SECURED\t\t   VOTE PERCENTAGE\n\n");
        for (int i = 0; i < 5; i++)
        {
            if(i==4)
            {
                printf("%s\t\t\t\t%d\t\t\t\t0\n",obj[i].candidate_name,obj[i].numvotes);
                break;
            }
            printf("%s\t\t\t%d\t\t\t\t0\n",obj[i].candidate_name,obj[i].numvotes);
        }
        
    }

    else
    {
        printf("\nCANDIDATE NAME\t\tNUMBER OF VOTES SECURED\t\t   VOTE PERCENTAGE\n\n");
        for (int i = 0; i < 5; i++)
        {
            if(i==4)
            {
                printf("%s\t\t\t\t%d\t\t\t\t%.2f\n",obj[i].candidate_name,obj[i].numvotes,(obj[i].numvotes*100)/sum);
                break;
            }
            printf("%s\t\t\t%d\t\t\t\t%.2f\n",obj[i].candidate_name,obj[i].numvotes,(obj[i].numvotes*100)/sum);
        }
    }    
    printf("\n=> Press any key to exit vote display panel");
    getch();
    clrscr();
}


int password_checker(char fname[])              //Checks whether the user is authorized or not
{
    fflush(stdout);
    printf("\n=> Enter 4-Digit security pin and press ENTER to validate yourself:");
    int pass;
    scanf("%d",&pass);
    if(pass==password)
    {
        clrscr();
        printf("\nAccess Granted!\n");
        return 1;
    }
    else
    {
        printf("\nAccess Denied\n");
        printf("\n=> Do you want to try again?(Y/N):");
        char decider;
        scanf(" %c",&decider);
        if(decider=='Y'||decider=='y')
        {
            password_checker(fname);
        }        
        else
        {
            clrscr();
            return 0;
        }
    }
    return 1;
}


