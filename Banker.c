#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
bool finish[5],d[5],e[5];int seq[5],j;

int main()
{
    printf("\n\a\n\t\t\t\t\t\t\t\t\t Welcome\n\n");printf("\n\tAll process numbers and iterations start from 0\n");Sleep(3000);
    printf("\nLoading\n");
    for(int i=0;i<50;i++)Sleep(25);
 //Initialization of data structures
    int alloc[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
    int max[5][3]={{7,5,3},{3,2,2},{9,0,2,},{2,2,2},{4,3,3}};
    int avail[3]={3,3,2};
    int need[5][3];

    for(int i=0;i<5;i++) //Initialization of "need array"
        for(int j=0;j<3;j++)
            need[i][j]=max[i][j]-alloc[i][j];


    a:
    printf("\n\nEnter your chioce");
    printf("\n\n\t1. To view the allocation matrix\n\t2. To view the maximum matrix\n\t3. To view the available matrix\n\t");
    printf("4. To view the need matrix\n\t5. To check if the system is in the safe state\n\t");
    printf("6. To exit\n");
    int chioce; scanf("%d",&chioce);
    switch(chioce)
    {
        case 1: //View the allocation matrix

            printf("\n\n\nThe allocation matrix is:\n\n\t\t\t\t");
            printf("A\tB\tC\n\n");
            for(int x=0;x<5;x++)
            {
                printf("\n\t\tProcess %d\t",x);
                for(int y=0;y<3;y++)
                    printf("%d\t",alloc[x][y]);
                    printf("\n\t\t\t\t");
            }
            goto a;
        case 2: //View the maximum matrix

                printf("\n\n\nThe maximum matrix is:\n\n\t\t\t\t");
                printf("A\tB\tC\n\n");
                for(int x=0;x<5;x++)
                {
                    printf("\n\t\tProcess %d\t",x);
                    for(int y=0;y<3;y++)
                    printf("%d\t",max[x][y]);
                    printf("\n\t\t\t\t");
                }
            goto a;
        case 3: //View the available matrix

                printf("\n\n\nThe available matrix is:\n\n\t\t\t\t");
                printf("A\tB\tC\n\n\t\t\t\t");
                for(int x=0;x<3;x++)
                {
                    printf("%d\t",avail[x]);
                }
            goto a;
        case 4:
            goto b;
        case 5:

            for(int i=0;i<5;i++) //Checking every process for the necessary condition that "need<=available"
            {
                d[i]=(!finish[i]&&need[i][0]<=avail[0]&&need[i][1]<=avail[1]&&need[i][2]<=avail[2]); /*Response stored here*/
                if(d[i])
                { //allocation of resources to the process, completion and deallocation of memory
                    avail[0]+=alloc[i][0];
                    avail[1]+=alloc[i][1];
                    avail[2]+=alloc[i][2];
                    finish[i]=true; //Process[i] finished
                    seq[j]=i;j++;
                    printf("\nIn the iteration %d, process %d executed",i,i);
                }
            }
            printf("\n\nNow as 3 processes have already executed successfully so their allocated resources have been");
            printf(" deallocated creating more free instances of resources, so again running the loop for the");
            printf(" remaining processes\n\n");Sleep(10000);
            for(int i=0;i<5;i++)
/* Again looping and checking for the processes that have not been able to complete in the previous iteration due to lack of
resources */
                if(d[i]==0)
                { //allocation of resources to the process, completion and deallocation of memory
                    e[i]=(!finish[i]&&need[i][0]<=avail[0]&&need[i][1]<=avail[1]&&need[i][2]<=avail[2]);
                    if(e[i])
                    {
                        avail[0]+=alloc[i][0];
                        avail[1]+=alloc[i][1];
                        avail[2]+=alloc[i][2];
                        finish[i]=true;  //Process[i] finished
                        seq[j]=i;j++;
                        printf("\nIn the iteration %d, process %d executed",i,i);
                    }
                }
            printf("\n\n\n\t\t\t\t\tAs all the processes have executed successfully so the system is in SAFESTATE!");
            printf("\n\n\t\t\t\t\t\tPress 0 to see the safe state sequence or any other key to exit\n");
            int f;scanf("%d",&f);
            if(f==0)
            {   //Safe Sequence
                printf("\n\nThe safe sequence is :");
                for(int i=0;i<5;i++)
                    printf("\n\n\n\t\t\t\tProcess %d",seq[i]);
                printf("\n\n\n\n\t\t\t\t\t\t\t\t");Sleep(2000);
                char x[]="Thank You!";
                for(int i=0;i<sizeof(x);i++)
                {
                    printf("%c",x[i]);Sleep(100);
                }
                printf("\n\n\n\t\t\t\t\t");
            }
            else
            {
                printf("\n\n\n\n\t\t\t\t\t\t\t\t");Sleep(1000);
                char x[]="Thank You!";
                for(int i=0;i<sizeof(x);i++)
                {
                    printf("%c",x[i]);Sleep(100);
                }
                printf("\n\n\n\t\t");
            }

        case 6: exit(0);
        default:    fflush(stdin);  goto a;
    }
    b:
    //Initialization of "need array"
    printf("\n\n\nThe need matrix is:\n\n\t\t\t\t");
    printf("A\tB\tC\n\n");
    for(int x=0;x<5;x++)
    {
        printf("\n\t\tProcess %d\t",x);
        for(int y=0;y<3;y++)
            printf("%d\t",need[x][y]);
        printf("\n\t\t\t\t");
    }
    goto a;
    return 0;
}
