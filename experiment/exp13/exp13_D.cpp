#include<stdio.h>
#include<string.h>

#define GROUP_MEMBER_NUM 4
#define NAME_LEN 20

typedef struct TEAM{
    char name[NAME_LEN + 1];
    int goal;
    int lost;
    int score;
}team;

void inputTeam(team *t);
void inputTeamList(team *t, int n);

void outputName(team *t);
void outputNameList(team *t, int n);

void swapStr(char *str1, char *str2);
void swapInt(int *pi1, int *pi2);
void Swap(team *p1,team *p2);
int Comp(team *p1,team *p2);
void Sort(team *teams,int n);

int main()
{
    team t[GROUP_MEMBER_NUM];
    
    inputTeamList(t, GROUP_MEMBER_NUM);
    Sort(t, GROUP_MEMBER_NUM);
    outputNameList(t, GROUP_MEMBER_NUM);
    
    return 0;
}

void inputTeam(team *t)
{
    scanf("%s%d%d%d", t->name, &t->goal, &t->lost, &t->score);
    getchar();
}

void inputTeamList(team *t, int n)
{
    for(int i = 0; i < n; i++)
    {
	inputTeam(t);
	t++;
    }
}

void outputName(team *t)
{
    puts(t->name);
}

void outputNameList(team *t, int n)
{
    for(int i = 0; i < n; i++)
    {
	outputName(t);
	t++;
    }
}

int Comp(team *p1,team *p2)// True means need to swap.
{
    if(p2->score > p1->score ||
       (
	   p2->score == p1->score &&
	   p2->goal - p2->lost > p1->goal - p1->lost ||
	   (
	       p2->goal - p2->lost == p1->goal - p1->lost &&
	       p2->goal > p1->goal)))
	return 1;
    else
	return 0;
}

void swapStr(char *str1, char *str2)
{
    char ts[NAME_LEN + 1];
    strcpy(ts, str1);
    strcpy(str1, str2);
    strcpy(str2, ts);
}

void swapInt(int *pi1, int *pi2)
{
    int ti;
    ti = *pi1;
    *pi1 = *pi2;
    *pi2 = ti;
}

void Swap(team *p1, team *p2)
{
    swapStr(p1->name, p2->name);
    swapInt(&p1->goal, &p2->goal);
    swapInt(&p1->lost, &p2->lost);
    swapInt(&p1->score, &p2->score);
}

void Sort(team *teams, int n)
{
    team *tpt;
    for(int i = 0; i < n - 1; i++)
    {
	tpt = teams;
	for(int j = 0; j < n - 1 - i; j++)
	{
	    if(Comp(tpt, tpt + 1))
		Swap(tpt, tpt + 1);
	    tpt++;
	}
    }
}
