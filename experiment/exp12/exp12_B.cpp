#include<stdio.h>
/*
void gets(char *p)
{
    p--;
    do
    {
	p++;
	scanf("%c", p);
    }while(*p != '\n' && *p != '\0');
    *p = '\0';
}
*/
typedef struct Student_struct{
    char stu_name[21];
    char stu_ID[21];
    int score[5];
    double avg;
    int total;
} Student;

void sort(int *p, int n);
void sortStuScore(Student *s);
void statisticStuScore(Student *s);

void inputStuInfo(Student *s);
void outputStuInfo(Student *s);

void process(Student *s);

int main()
{
    int n;
    Student s[100];
    scanf("%d", &n);
    getchar();
    
    for(int i = 0; i < n; i++)
	inputStuInfo(&s[i]);

    for(int i = 0; i < n; i++)
    {
	process(&s[i]);
	outputStuInfo(&s[i]);
	printf("\n");
    }
    return 0;
}

void sort(int *p, int n)
{
    int temp;
    int *tp;
    for(int i = n - 1; i > 0; i--)
    {
	tp = p;
	for(int j = 0; j < i; j++, tp++)
	    if(*tp < *(tp + 1))
	    {
		temp = *tp;
		*tp = *(tp + 1);
		*(tp + 1) = temp;
	    }
    }
}

void sortStuScore(Student *s)
{
    sort(s->score, 5);
}

void statisticStuScore(Student *s)
{
    s->total = 0;
    for(int i = 0; i < 5; i++)
	s->total = s->total + s->score[i];
    s->avg = (double)s->total / (double)5;
}

void outputStuInfo(Student *s)
{
    printf("Name:%s\nID:%s\n", s->stu_name, s->stu_ID);

    printf("Score:");
    for(int i = 0; i < 5 - 1; i++)
	printf("%d ", s->score[i]);
    printf("%d\n", s->score[4]);

    printf("average:%.2lf total:%d\n", s->avg, s->total);
}

void inputStuInfo(Student *s)
{
    gets(s->stu_name);
    
    gets(s->stu_ID);

    for(int i = 0; i < 5; i++)
	scanf("%d", &s->score[i]);
    getchar();//read the \n.
}

void process(Student *s)
{
    sortStuScore(s);
    statisticStuScore(s);
}
