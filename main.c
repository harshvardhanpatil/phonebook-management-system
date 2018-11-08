#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int n,gn;
struct contact{
    char name[20];
    char gender[10];
    char gmail[30];
    char lastname[20];
    int phone;
    char group[20];
}s[100];
struct group{
    char gname[10];
}g[20];
void readgroup(){
    printf("Enter the no of groups:");
    scanf("%d",&gn);
    int i;
    for(i=0;i<gn;i++)
    {
        printf("ENTER THE GROUP %d NAME:",(i+1));
        scanf("%s",g[i].gname);
    }
}
void read(){
    int i,j,flag=0;
    printf("Enter the no of contacts:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("ENTER THE %d TH CONTACT------------------\n",(i+1));
        printf("Enter the first name:");
        scanf("%s",s[i].name);
        printf("Enter the last name:");
        scanf("%s",s[i].lastname);
        printf("Enter the gender:");
        scanf("%s",s[i].gender);
        printf("Enter the gmail id:");
        scanf("%s",s[i].gmail);
        printf("Enter the phone no:");
        scanf("%d",&s[i].phone);
        printf("Enter the group of contact:");
        scanf("%s",s[i].group);
        while(flag==0)
        {

            for(j=0;j<gn;j++)
            {
                if(strcmp(s[i].group,g[j].gname)==0){
                    flag=1;
                    break;
                }
                else{
                    flag=0;
                }

            }
            if(flag==0){
                printf("GROUP DOES NOT EXISTS ENTER AGAIN:");
                scanf("%s",s[i].group);
                }


            }
        }





}
void readnew()
{
        int flag=0,i,j;

        printf("ENTER THE %d TH CONTACT------------------\n",(n));
        printf("Enter the first name:");
        scanf("%s",s[n].name);
        printf("Enter the last name:");
        scanf("%s",s[n].lastname);
        printf("Enter the gender:");
        scanf("%s",s[n].gender);
        printf("Enter the gmail id:");
        scanf("%s",s[n].gmail);
        printf("Enter the phone no:");
        scanf("%d",&s[n].phone);
        printf("Enter the group of contact:");
        scanf("%s",s[n].group);
        while(flag==0)
        {

            for(j=0;j<gn;j++)
            {
                if(strcmp(s[n].group,g[j].gname)==0){
                    flag=1;
                    break;
                }
                else{
                    flag=0;
                }

            }
            if(flag==0){
                printf("GROUP DOES NOT EXISTS ENTER AGAIN:");
                scanf("%s",s[n].group);
                }


            }
            n++;


}
void deletecont()
{
    int key,pos=-1;
    int i,j,k;
    printf("Enter the phone no of the contact to be deleted:");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(s[i].phone==key)
        {
            pos=i;
        }
    }
    if(pos==-1)
    {
        printf("NO CONTACT FOUND TO HAVE THE NUMBER-PLEASE CHECK THE NO AGAIN\n");
        return;
    }
    else
    {

        for(i=pos;i<n;i++)
        {
            strcpy(s[i].name,s[i+1].name);
            strcpy(s[i].gender,s[i+1].gender);
            strcpy(s[i].gmail,s[i+1].gmail);
            strcpy(s[i].lastname,s[i+1].lastname);
            s[i].phone=s[i+1].phone;
            strcpy(s[i].group,s[i+1].group);
            n--;
            printf("CONTACT DELETED");
        }
    }

}
void sortbyg()
{
    int i,j,k;
    for(i=0;i<gn;i++)
    {
        printf("GROUP %s members--------------------\n",g[i].gname);
        for(j=0;j<n;j++)
        {
            if(strcmp(g[i].gname,s[j].group)==0)
            {
                printf("NAME:%s\nGENDER:%s\nGMAIL:%s\nLASTNAME:%s\nPHONE:%d\nGROUP:%s\n\n",s[j].name,s[j].gender,s[j].gmail,s[j].lastname,s[j].phone,s[j].group);
            }
        }
    }

}
void display()
{
    int j;
    printf("DISPLAYING CONTACTS-----------------------------------\n");
    for(j=0;j<n;j++)
    {
        printf("NAME:%s\nGENDER:%s\nGMAIL:%s\nLASTNAME:%s\nPHONE:%d\nGROUP:%s\n\n",s[j].name,s[j].gender,s[j].gmail,s[j].lastname,s[j].phone,s[j].group);
    }
}
void readgroupnew()
{
    printf("ENTER THE GROUP %d NAME:",(gn+1));
    scanf("%s",g[gn].gname);
    gn++;
}
void menu()
{
    int c;
    printf("\nEnter your choice---------\n1.to enter new contact\t2.to delete\t3.to sort by group\n4.display\t5.to enter new group\t0.to Exit\n-->");
    scanf("%d",&c);
    while(1)
    {


        switch(c)
        {
            case 1:readnew();
            break;
            case 2:deletecont();
            break;
            case 3:sortbyg();
            break;
            case 4:display();
            break;
            case 5:readgroupnew();
            break;
            case 0:return;
            default:printf("Invalid choice\nPLEASE RETRY\n");
        }
        printf("\n\nEnter your choice---------\n1.to enter new contact\t2.to delete\t3.to sort by group\n4.display\t5.to enter new group\t0.to Exit\n-->");
        scanf("%d",&c);
    }
}
int main()
{
    readgroup();
    read();
    menu();
    return 0;
}
