#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define UP 72
#define DOWN 80
#define select 13
#define PI 3.14159
int size = 1;
int *x = NULL;
int *y = NULL;
char padd[50] = "";
void graph()
{
	system("cls");
	int a, b;
	x = (int *)malloc(size * sizeof(int));
	y = (int *)malloc(size * sizeof(int));
	int i, j;
	char ch = 'A';
	int count = 0;
	char in;
	while (1)
	{
		printf("Point : %c\n", ch);
		for (i = 26; i >= -26; i--)
		{
			for (j = -26; j <= 26; j++)
			{
				if (i == 0 || j == 0)
				{
					printf("#");
				}
				else
				{
					if (i == b && j == a)
					{
						printf("#");
					}
					else
					{
						printf(".");
					}
				}
			}
			printf("\n");
		}
		i = 0;
		j = 0;
		printf("Enter 0 to add new point or enter any character to exit\n");
		in = _getch();
		if (in == '0')
		{
			x = realloc(x, (size) * sizeof(int));
			y = realloc(y, (size) * sizeof(int));
			printf("Enter Points: \n");
			printf("x : ");
			scanf("%d", &a);
			printf("y : ");
			scanf("%d", &b);
			x[count] = a;
			y[count] = b;
			system("cls");
			padd[count] = ch;
			ch++;
			count++;
			size++;
		}
		else
		{
			system("cls");
			break;
			return;
		}
	}
}
void distance()
{

	system("cls");
	char start, end;
	int a1 = 0;
	int b1 = 0;
	int a2 = 0;
	int b2 = 0;
	int i;
	int found = 0;
top:
	printf("Select start point (Enter O to measure from orign) : \n");
	start = _getch();
	if (start > 90)
	{
		start = start - 32;
	}
	for (i = 0; i <= strlen(padd) - 1; i++)
	{
		if (padd[i] == start)
		{
			a1 = x[i];
			b1 = y[i];
			found = 1;
		}
	}
	i = 0;
	if (start == 'O')
	{
		a1 = 0;
		b1 = 0;
		found = 1;
	}
	if (!found)
	{
		printf("Point not found!\n");
		goto top;
	}
	found = 0;
	printf("Select end point : \n");
	end = _getch();
	if (end > 90)
	{
		end = end - 32;
	}
	for (i = 0; i <= strlen(padd) - 1; i++)
	{
		if (padd[i] == end)
		{
			a2 = x[i];
			b2 = y[i];
			found = 1;
		}
	}
	if (!found)
	{
		printf("Point not found!\n");
		goto top;
	}
	system("cls");
	double dist = sqrt(pow(a2 - a1, 2) + pow(b2 - b1, 2));
	printf("Distance between %c and %c is : %lf\n Enter any character to return to menu", start, end, dist);
	_getch();
	system("cls");
	return;
}
void angle()
{
	system("cls");
	char point;
	int a = 0;
	int b = 0;
	int found = 0;
	int i;
begin:
	printf("Enter a point to find its angle from origin : \n");
	point = _getch();
	if (point > 90)
	{
		point = point - 32;
	}
	for (i = 0; i <= strlen(padd) - 1; i++)
	{
		if (padd[i] == point)
		{
			a = x[i];
			b = y[i];
			found = 1;
		}
	}
	if (!found)
	{
		printf("Point not found!\n");
		goto begin;
	}
	double ang = atan2(b, a) * 180 / PI;
	printf("Angle of %c from origin is : %lf degrees\n Enter any character to return to menu", point, ang);
	_getch();
	system("cls");
	return;
}
void slope()
{
	system("cls");
	char start, end;
	int a1 = 0;
	int b1 = 0;
	int a2 = 0;
	int b2 = 0;
	int i;
	int found = 0;
top:
	printf("Select start point : \n");
	start = _getch();
	if (start > 90)
	{
		start = start - 32;
	}
	for (i = 0; i <= strlen(padd) - 1; i++)
	{
		if (padd[i] == start)
		{
			a1 = x[i];
			b1 = y[i];
			found = 1;
		}
	}
	i = 0;
	if (!found)
	{
		printf("Point not found!\n");
		goto top;
	}
	found = 0;
	printf("Select end point : \n");
	end = _getch();
	if (end > 90)
	{
		end = end - 32;
	}
	for (i = 0; i <= strlen(padd) - 1; i++)
	{
		if (padd[i] == end)
		{
			a2 = x[i];
			b2 = y[i];
			found = 1;
		}
	}
	if (!found)
	{
		printf("Point not found!\n");
		goto top;
	}
	system("cls");
	double m = (b2 - b1) / (a2 - a1);
	printf("Slope of line between %c and %c is : %lf\n Enter any character to return to menu", start, end, m);
	_getch();
	system("cls");
	return;
}
void export()
{
	FILE *myFile = NULL;

	myFile = fopen("Export_result.html", "w");

	if (myFile == NULL)
	{
		printf("Cannot Open file due to some errors!\n");
		return;
	}
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	int prv_val = 0;
	fprintf(myFile, "<!DOCTYPE html>\n");
	fprintf(myFile, "<html>\n");
	fprintf(myFile, "<head>\n");
	fprintf(myFile, "    <title>Exporting Result</title>\n");
	fprintf(myFile, "</head>\n");
	fprintf(myFile, "<body>\n");
	fprintf(myFile, "    <h1>The points are </h1>\n");
	for (int i = 0; i <= strlen(padd) - 1; i++)
	{
		fprintf(myFile, "    <p> X : %d</p>\n", x[i]);
		fprintf(myFile, "    <p> Y : %d</p>\n", y[i]);
		fprintf(myFile, "<h1>-------------------------------</h1>\n");
		double angle = atan2(y[i], x[i]) * 180 / PI;
		fprintf(myFile, " <p> The Angle between these points from origin  is : </p> \n");
		fprintf(myFile, "    <p> %.2lf </p> ", angle);
		fprintf(myFile, "<h1>-------------------------------</h1>\n");
		x1 = x[i];
		x2 = x[i + 1];
		if (x2 > strlen(padd))
		{
			x2 = 0;
		}
		y1 = y[i];
		y2 = y[i + 1];
		if (y2 > strlen(padd))
		{
			y2 = 0;
		}
		double slope = (double)(y2 - y1) / (x2 - x1);
		if (slope < 0)
		{
			fprintf(myFile, "<h1> Slope of these points is : </h1>\n");
			fprintf(myFile, "<p> Slope is undefined\n</p>");
		}
		else
		{
			fprintf(myFile, "<p> m = %.2lf \n </p>", slope);
		}

		double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

		fprintf(myFile,"<h1>  Distance between Points </h1> \n");
		fprintf(myFile,"<p> d = %.2lf \n </p> ",distance);

		fprintf(myFile, "<h1>-------------------------------</h1>\n");
	}

	// fprintf(myFile, "    <p> X : %d</p>\n", *x);
	// fprintf(myFile, "    <p> Y : %d</p>\n", *y);

	fprintf(myFile, "</body>\n");
	fprintf(myFile, "</html>\n");

	fclose(myFile);
}

int main()
{
	int pointer = 0;
	char in;
	int selected = 0;
start:
	while (1)
	{
		printf("  ____  ____                _               \n");
		printf(" / ___|/ ___|_ __ __ _ _ __ | |__   ___ _ __ \n");
		printf("| |     |  _| '__/ _` | '_ \\| '_ \\ / _ \\ '__|\n");
		printf("| |___  |_| | | | (_| | |_) | | | |  __/ |   \n");
		printf(" \\____|\\____|_|  \\__,_| .__/|_| |_|\\___|_|   \n");
		printf("                      |_|                    \n");
		printf("\t Use arrow keys to navigate");
		printf("\n");
		printf("Points saved : %s\n", padd == "" ? "NO DATA" : padd);

		if (pointer == 0)
		{
			printf("[");
		}
		printf("- Graph (Set points)");
		if (pointer == 0)
		{
			printf("]");
		}
		printf("\n");
		if (pointer == 1)
		{
			printf("[");
		}
		printf("- Find distance between points");
		if (pointer == 1)
		{
			printf("]");
		}
		printf("\n");
		if (pointer == 2)
		{
			printf("[");
		}
		printf("- Find angle of a point from origin");
		if (pointer == 2)
		{
			printf("]");
		}
		printf("\n");
		if (pointer == 3)
		{
			printf("[");
		}
		printf("- Find slope of a line (between two points)");
		if (pointer == 3)
		{
			printf("]");
		}
		printf("\n");
		if (pointer == 4)
		{
			printf("[");
		}
		printf("- Export results");
		if (pointer == 4)
		{
			printf("]");
		}
		printf("\n");
		if (pointer == 5)
		{
			printf("[");
		}
		printf("- Exit");
		if (pointer == 5)
		{
			printf("]");
		}
		in = _getch();
		if (in == UP)
		{
			pointer--;
		}
		if (in == DOWN)
		{
			pointer++;
		}
		if (in == select)
		{
			selected = 1;
		}
		if (pointer == 6)
		{
			pointer = 0;
		}
		if (pointer == -1)
		{
			pointer = 5;
		}
		system("cls");
		if (selected)
		{
			if (pointer == 0)
			{
				goto o1;
			}
			else if (pointer == 1)
			{
				goto o2;
			}
			else if (pointer == 2)
			{
				goto o3;
			}
			else if (pointer == 3)
			{
				goto o4;
			}
			else if (pointer == 4)
			{
				goto o5;
			}
		}
	}
	if (0)
	{
	o1:
		graph();
		pointer = 0;
		selected = 0;
		goto start;

	o2:
		distance();
		pointer = 0;
		selected = 0;
		goto start;

	o3:
		angle();
		pointer = 0;
		selected = 0;
		goto start;

	o4:
		slope();
		pointer = 0;
		selected = 0;
		goto start;
	o5:
		export();
		printf("Result is exported you can now check the file by yourself, Thanks!\n");
		pointer = 0;
		selected = 0;
		goto start;
	}
	free(x);
	free(y);
}
