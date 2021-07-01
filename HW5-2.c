#include <stdio.h>
int myatoi(char);

void main()
{
	char str[81];
	printf("Enter string: ");
	gets(str);
	printf("%d", myatoi(str));
}

int myatoi(char newstr1[81])
{
	int j, k = 0;

	char newstr2[81];
	for (j = 0; newstr1[j] != '\0'; j++)
	{
		if (newstr1[j] == '-')
		{
			if (j == 0)
			{
				newstr2[j] = newstr1[j];
				continue;
			}
		}
		if (newstr1[j] >= '0' && newstr1[j] <= '9')
		{
			if (k != 0)
			{
				newstr2[j - k] = newstr1[j];
			}
			else
			{
				newstr2[j] = newstr1[j];
			}
		}
		else
		{
			k++;
		}
	}
	if (k != 0)
	{
		newstr2[j - k] = '\0';
	}
	else
	{
		newstr2[j] = '\0';
	}
	int n;
	int a = 0, b;
	for (n = 0; newstr2[n] != '\0'; n++)
	{
		if (newstr2[n] == '-')
		{
			continue;
		}
		b = (newstr2[n] - 48);
		if (n != 0)
		{
			a = a * 10 + b;
		}
		else
		{
			a = a + b;
		}
	}
	if (newstr2[0] == '-')
	{
		a = a * -1;
	}
	return a;
}

