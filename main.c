#include<stdio.h>
#include<string.h>

struct student 
{
    int roll;
    char name[50];
    float marks[3];
    float total;
    float avg;
    char grade;
};

void studentdetail(struct student s[],int n)
{
    int i,len;
    for(i=0;i<n;i++)
    {
        printf("\n-----------STUDENT DETAIL--------\n");

        printf("Roll No:");
        scanf("%d",&s[i].roll);
        getchar();

        printf("Name:");
        fgets(s[i].name,sizeof(s[i].name),stdin);
         len = strlen(s[i].name);
        if(len > 0 && s[i].name[len - 1] == '\n') s[i].name[len - 1] = '\0';

        printf("Marks for 3 subject:");
        scanf("%f %f %f",&s[i].marks[0], &s[i].marks[1], &s[i].marks[2]);
    }
}

void calculate(struct student s[],int n)
{
   int i, j;
    for(i = 0; i < n; i++)
    {
        s[i].total = 0;
        for(j = 0; j < 3; j++)
        {
            s[i].total += s[i].marks[j];
        }

        s[i].avg = s[i].total / 3;

        if(s[i].avg >= 90)
            s[i].grade = 'A';
        else if(s[i].avg >= 75)
            s[i].grade = 'B';
        else if(s[i].avg >= 50)
            s[i].grade = 'C';
        else
            s[i].grade = 'F';
    }  
  
}

void result(struct student s[],int n)
{
    int i;
    printf("\n--------------------------------------\n");
    printf(" Roll  | Name  | Total | Average | Grade  ");
    printf("\n--------------------------------------\n");
        for(i = 0; i < n; i++)
        {
              printf("%d\t%s\t%.2f\t%.2f\t%c\n", s[i].roll, s[i].name, s[i].total, s[i].avg, s[i].grade);
        }
}

void topper(struct student s[],int n)
{
    int i,t=0;
    float ht=s[0].total;
    
    for(i=1;i<n;i++)
    {
        if(s[i].total>ht)
        {
            ht=s[i].total;
            t=i;
        }
    }
    printf("\nTopper Details\n");
    printf("Name: %s\n", s[t].name);
    printf("Roll No: %d\n", s[t].roll);
    printf("Total Marks: %.2f\n", s[t].total);
    printf("Average: %.2f\n", s[t].avg);
    printf("Grade: %c\n", s[t].grade);
}

void saveToFile(struct student s[], int n)
{
    FILE *fp = fopen("students.txt", "w");
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for(int i = 0; i < n; i++)
    {
        fprintf(fp, "%d,%s,%.2f,%.2f,%.2f,%.2f,%c\n",
                s[i].roll,
                s[i].name,
                s[i].marks[0], s[i].marks[1], s[i].marks[2],
                s[i].avg,
                s[i].grade);
    }

    fclose(fp);
    printf("\nData saved to students.txt successfully!\n");
}


int main()
{
    int n;

   // struct student s[n];
    printf("Total number of student u want:");
    scanf("%d",&n);

    struct student s[n];

        studentdetail(s,n);
        calculate(s,n);
        result(s,n);
        topper(s,n);
        saveToFile(s, n);



        return 0;



}
