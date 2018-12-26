#include<stdio.h>
#include<stdlib.h>

#define MAX_NAME 20

typedef struct{
    char name[MAX_NAME + 1];
    int total;
}Stu;

void outputStuArray(Stu *s, int n)
{
    for(int i = 0; i < n; i++, s++)
    {
	printf("Name:%s\ntotal:%d\n\n", s->name, s->total);
    }
}

int compareString(char *str1, char *str2);
int compareStu(Stu *s1, Stu *s2);
int swapStuInfo(Stu *s1, Stu *s2);

void merge(Stu s[], int low, int mid, int high);
void sortStu(Stu *p, int low, int high);

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    Stu s[100];
    
    for(int i = 0; i < n; i++)
    {
	scanf("%s%d",s[i].name, &s[i].total);
	getchar();
    }
    
    sortStu(s, 0, n - 1);
    
    outputStuArray(s, n);
    
    return 0;
}

int compareString(char *str1, char *str2)
{
    while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0')
    {
	str1++;
	str2++;
    }
    if(*str1 == *str2)
	return 0;
    else if(*str1 > *str2)
	return 1;
    else
	return -1;
}

int compareStu(Stu *s1, Stu *s2)//if position right, return 1
{
    if(s1->total < s2->total || (s1->total == s2->total && compareString(s1->name, s2->name) == 1))
	return 0;
    else
	return 1;
}

void merge(Stu s[], int low, int mid, int high)
{
    int r1 = low, r2 = mid + 1, tp = 0;
    
    Stu *temp = (Stu*)malloc(sizeof(Stu) * (high - low + 1));

    if(temp != nullptr)
    {
	while(r1 <= mid && r2 <= high)
	{
	    if(compareStu(&s[r1], &s[r2]) == 1)
	    {
		temp[tp] = s[r1];
		r1++;
	    }
	    else
	    {
		temp[tp] = s[r2];
		r2++;
	    }
	    tp++;
	}
	
	while(r1 <= mid)
	{
	    temp[tp] = s[r1];
	    tp++;
	    r1++;
	}
	
	while(r2 <= high)
	{
	    temp[tp] = s[r2];
	    tp++;
	    r2++;
	}
	
	for(int i = 0; i < high - low + 1; i++)
	{
	    s[low + i] = temp[i];
	}
	
	free(temp);
    }
    else
    {
	printf("\n\nMemory overflow.\n\n\n");
    }
}

void sortStu(Stu s[], int low, int high)
{
    if(low < high)
    {
	int mid = (low + high) / 2;
	sortStu(s, low, mid);
	sortStu(s, mid + 1, high);
	merge(s, low, mid, high);
    }
}
