#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
  FILE *fp;
  char name[29],a[20];
  char Grade[]="A";
  int result;
 struct node
  {
     char name[29],G[2];
     int mm,em,sm,pm,cm;
     struct node *next;
  };
  struct student;
  int main()
  {
    int i,n,ch,ps,x,k;
    k=0;
    char filename[20];

  struct node *h,*t,*t1,*w,*q;
  h=NULL;

  printf("\n /*    THE TERMINAL   *\\ \n");


while(1)
 {
     
      printf("\n1.Enter the mark list information of students\n2:Save the information into data file\n3.Read from data file\n4.Search with Name\n5.Sorting according to marks list\n6.Assign grades to each student\n");
        printf("\nenter your choice=");
      scanf("%d",&ch);
      switch(ch)
     
{

case 1:    
 printf("\nenter the new record=\t");
   if(h==NULL)
 {
  h=t=(struct node *)malloc(sizeof(struct node));
  printf("\nName of a student:\t");
    scanf("%s",&t1->name);
    printf("Enter Maths Marks: ");
    scanf("%d", &t->mm);
    printf("Enter English Marks: ");
    scanf("%d", &t->em);
    printf("Enter Social Marks: ");
    scanf("%d", &t->sm);
    printf("Enter Physics Marks: ");
    scanf("%d", &t->pm);
    printf("Enter Chemistry Marks: ");
    scanf("%d", &t->cm);
   t->next=NULL;
break;
}
else
  {
    t1=(struct node *)malloc(sizeof(struct node));

    printf("\nName of a student:\t");
    scanf("%s",&t1->name);
    printf("Enter Maths Marks: ");
    scanf("%d", &t->mm);
    printf("Enter English Marks: ");
    scanf("%d", &t->em);
    printf("Enter Social Marks: ");
    scanf("%d", &t->sm);
    printf("Enter Physics Marks: ");
    scanf("%d", &t->pm);
    printf("Enter Chemistry Marks: ");
    scanf("%d", &t->cm);
    t1->next=t->next;
    t->next=t1;
    t=t1;
  }

break;
  
case 2:
   puts("Enter name of text file to write: \n");
    scanf("%s",filename);

    /* Open the file for reading. - fp is global */
    if ( (fp = fopen(filename, "w")) == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
    }
    else
    {
        printf("%s Write file opened\n",filename);
    }
    if(h==NULL)
    {
        printf("Nothing in file");
    }
    while(h!=NULL)
    {  
      
       fprintf(fp, "%s\n",h->name);
       fprintf(fp, "%d\n",h->mm);
       fprintf(fp, "%d\n",h->em);
       fprintf(fp, "%d\n",h->sm);
       fprintf(fp, "%d\n",h->pm);
       fprintf(fp, "%d\n",h->cm);
       
       
        h=h->next;
    }
    fprintf(fp, "\n");
  fclose(fp);
  break;

break;

case 3:
    puts("Enter name of text file to read: \n");
    scanf("%s",filename);

    w=h;
    if ( (fp = fopen("filename", "r")) == NULL)
    {
        //fprintf(stderr, "Error opening file.\n");
        while (fread(&h,sizeof(h),1,fp)==1)
        {
          printf("\nname of a student:%s\nmathsmarks:%d\nenglisjmarks:%d\nsocailmarks:%d\nphysimarks:%d\nchemismarks:%d\n",
  w->name,w->mm,w->em,w->sm,w->pm,w->cm);
  w=w->next;
        }
        
    }
    else
    {
        printf("%s Read file opened\n",filename);
    }
    fclose(fp);
  break;


case 4:
    printf("enter the Name you want to search\n");
   scanf("%s",&name);
   t=h;
 while (t!=NULL)
 {
   if(strcmp(name,t->name)==0){
   printf("Namre Found");
     printf("\nname of a student:%s\nmathsmarks:%d\nenglisjmarks:%d\nsocailmarks:%d\nphysimarks:%d\nchemismarks:%d\n",t->name,t->mm,t->em,t->sm,t->pm,t->cm);
    break;}
   else
   t=t->next;
 }
break; 

case 5:
    t=(struct node *)malloc(sizeof(struct node));
    t1=(struct node *)malloc(sizeof(struct node));
    t=h;
    t1=t->next;
    while(t!=NULL){
        if(strcmp(t->name,t1->name)>0){
            strcpy(a,t1->name);
            strcpy(t1->name,t->name);
            strcpy(t->name,a);        }
     t=t->next;
     printf("SORTED");
        }
    break;

case 6:
  w=h;
  while (w!=NULL)
  {
  result=((w->em+w->cm+w->mm+w->pm+w->sm)/500)*100;
  if(result>=80)
    strcpy(Grade,"A");
  if(result>=60 && result<=80) 
    strcpy(Grade,"B");
  if(result>=40 && result<=60) 
    strcpy(Grade,"P");
  else 
    strcpy(Grade,"F");
  strcpy(w->G,Grade);
  printf("Name=%s,Grade=%s",w->name,w->G);
  w=w->next;
  }        
 break;
    
}//case
}//while
}//main