#include<stdio.h>

int main()
{
    int c;
    int i, j;
    int sum, diff;
    int count = 0;
    FILE *pf = fopen("generated.c", "w");
    if(pf == NULL)
	return 1;
    fputs("#include<stdio.h>\n\nint main()\n{\n\tint a, b, c;\n\tint count = 0;\n\tscanf(\"%d%d%d\", &a, &b, &c);\n", pf);
    
    for(i = 2; i <= 10000; i++)
    {
	sum = 1;
	for(j = 2; j < i; j++)
	    if((i % j) == 0)
		sum = sum + j;
	diff = sum - i;
	if(diff >= -100 && diff <= 100)
	{
	    fprintf(pf, "\tif(a <= %d && %d <= b && %d <= c && %d >= -c)\n\t{\n\t\tprintf(\"%%d\", %d);\n\t\tcount = count + 1;\n\t\tif((count %% 5) == 0)\n\t\t\tprintf(\"\\n\");\n\t\telse\n\t\t\tprintf(\"\\t\");\n\t}\n", i, i, diff, diff, i);
	    count = count + 1;
	}
    }
    fputs("\tif((count % 5) != 0)\n\t\tprintf(\"\\n\");\n\tif(count == 0)\n\t\tprintf(\"There is no proper number in the interval.\");\n\treturn 0;\n}", pf);
    printf("%d", count);
    fclose(pf);
    return 0;
}
