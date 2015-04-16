/**
  * uva_00101 in progress
  */

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

enum class Commands
{
    move_onto,pile_onto,pile_over,move_over,quit
};

Commands identifyCommand(char cmd1[4],char cmd2[4])
{
    if(strcmp(cmd1,"quit")==0)
    {
        return Commands::quit;
    }

    if (strcmp(cmd1,"move") == 0 && strcmp(cmd2,"onto") == 0)
    {
        return Commands::move_onto;
    }

    if (strcmp(cmd1,"move") == 0 && strcmp(cmd2,"over") == 0)
    {
        return Commands::move_over;
    }

    if(strcmp(cmd1,"pile") == 0 && strcmp(cmd2,"over") == 0)
    {
        return Commands::pile_over;
    }

    if (strcmp(cmd1,"pile") == 0 && strcmp(cmd2,"onto") == 0)
    {
        return Commands::pile_onto;
    }
}

void move_onto(int (*stacks)[25], int stack_tops[25],int size,int a,int b)
{   
        
    if (stack_tops[a] > 1)
    {
        for (int i = 1; i < stack_tops[a]; ++i)
        {
            int replace = stack_tops[i];
            int top = stack_tops[replace];
            *(*(stacks+replace)+stack_tops[top]) = replace;
            stack_tops[top] = stack_tops[top]+1;
        }
    }

    if (stack_tops[b] > 1)
    {
        for (int i = 1; i < stack_tops[b]; ++i)
        {
            int replace = stack_tops[i];
            int top = stack_tops[replace];
            *(*(stacks+replace)+stack_tops[top]) = replace;
            stack_tops[top] = stack_tops[top]+1;
        }
    }

           
    cout << "Moving " << a << " onto " << b << endl;        
    *(*(stacks+b)+stack_tops[b]) = a;
    stack_tops[b] = stack_tops[b]+1;
    stack_tops[a] = stack_tops[a]-1;
}

void move_over(int (*stacks)[25], int stack_tops[25],int size,int a,int b)
{
 
 if (stack_tops[a] > 1)
    {
        for (int i = 1; i < stack_tops[a]; ++i)
        {
            int replace = stack_tops[i];
            int top = stack_tops[replace];
            *(*(stacks+replace)+stack_tops[top]) = replace;
            stack_tops[top] = stack_tops[top]+1;
        }
    }

            
    cout << "Moving " << a << " onto " << b << endl;        
    *(*(stacks+b)+stack_tops[b]) = a;
    stack_tops[b] = stack_tops[b]+1;
    stack_tops[a] = stack_tops[a]-1;
}

int main(int argc, char **argv)
{
    int num_blocks;
    int stacks[25][25] = {0};
    int stack_tops[25] = {0};

    scanf("%d",&num_blocks);

    for (int i = 0; i < num_blocks; ++i)
    {
        stacks[i][0] = i;
        stack_tops[i] = 1;
    }

    /*stacks[1][0] = 8;
    stack_tops[1]++;
    stacks[1][1] = 5;
    stack_tops[1]++;
    stacks[1][2] = 4;
    stack_tops[1]++;*/
 
    while(1)
    {
	 
     int a, b;
     char c1[4];
	 char c2[4];
	 scanf("%s %d %s %d",c1,&a,c2,&b);
	 Commands cmd1 = identifyCommand(c1,c2);

     if(cmd1 == Commands::quit)
     {
        break;
     }

     switch(cmd1)
     {
        
        case Commands::move_onto:
            cout << "Moving onto" << endl;
            move_onto(stacks,stack_tops,num_blocks,a,b);
            break;
        case Commands::move_over:
            cout << "Moving over" << endl;
            move_over(stacks,stack_tops,num_blocks,a,b);
            break;
        case Commands::pile_over:
            //cout << "Piling" << endl;
            break;
        case Commands::pile_onto:
            //cout << "Piling" << endl;
            break;
            

        default:
            break;
     }


    }
   

    for (int i = 0; i < num_blocks; ++i)
    {
        cout << " " << stack_tops[i];
    }

   cout << endl;
 //  cout << "Quitting" << endl;
     for(int i = 0; i < num_blocks; i++)
     {
        cout << i << ": ";
        if (stack_tops[i] >= 0)
        {
            for (int j = 0; j < stack_tops[i]; ++j)
            {
                cout << " " << stacks[i][j];
            }
        }

        cout << endl;
     } 

    return 0;
}
