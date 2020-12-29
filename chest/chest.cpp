#include <stdio.h>
#include <stdlib.h>

int chest[10][10] = { 0 };
int x = 0, y = 0; /*绘图，连子检测坐标*/
int black_x = 0, black_y = 0;/*收集落子坐标*/
int white_x = 0, white_y = 0;/*收集落子坐标*/
int pb = 0, pw = 0;/*判断落子是否合理*/
int i = 0; /*判断赢家*/



void show_chest()
{
	x = 0;
	y = 0;
	printf("┏ ○①②③④⑤⑥⑦⑧⑨┓\n");
	do
	{
		y = 0; 
		if (x == 0)
			printf("○");
		if (x == 1)
			printf("①");
		if (x == 2)
			printf("②");
		if (x == 3)
			printf("③");
		if (x == 4)
			printf("④");
		if (x == 5)
			printf("⑤");
		if (x == 6)
			printf("⑥");
		if (x == 7)
			printf("⑦");
		if (x == 8)
			printf("⑧");
		if (x == 9)
			printf("⑨");
		do
		{

			if (x != 0 && x != 9 && y != 0 && y != 9)
			{
				if (chest[x][y] == 0)
					printf("╋ ");
				else if (chest[x][y] == 1)
					printf("○");
				else printf("●");
			}
			else
			{
				if (chest[x][y] == 0)
				{
					if (x == 0 && y == 0)
						printf("┏ ");
					if (x == 0 && y == 9)
						printf("┓ ");
					if (x == 9 && y == 0)
						printf("┗ ");
					if (x == 9 && y == 9)
						printf("┛ ");
					if (x == 0 && y != 0 && y != 9)
						printf("┳ ");
					if (x == 9 && y != 0 && y != 9)
						printf("┻ ");
					if (y == 0 && x != 0 && x != 9)
						printf("┣ ");
					if (y == 9 && x != 0 && x != 9)
						printf("┫ ");

				}
				else
				{
					if (chest[x][y] == 1)
						printf("○");
					else printf("●");
				}


			}

			y++;
		} while (y != 10);
		y = 0; printf("┃ ");

		printf("\n");
		x++;
	} while (x != 10);
	printf("┗ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┛ \n");
	
}

int compare(int n1, int n2, int n3, int n4, int n5)
{
	int index = 0;
	index = index + (n1 == n2);
	index = index + (n2 == n3);
	index = index + (n3 == n4);
	index = index + (n4 == n5);
	if (index == 4)
		return 1;
	else return 0;
}

void judge()
{
	x = 0;
	y = 0;

	do
	{
		do
		{
			if (chest[x][y] != 0)
			{
				//printf("%d %d %d\n", chest[x][y], x, y);
				if ((y - 4) > 0)
				{
					if (compare((chest[x][y]), (chest[x][y - 1]), (chest[x][y - 2]), (chest[x][y - 3]), (chest[x][y - 4])))
					{
						if (chest[x][y] == 1)
							i = 1;
						else i = 2;
					}
				}

				if ((y + 4) < 9)
				{
					if (compare((chest[x][y]), (chest[x][y + 1]), (chest[x][y + 2]), (chest[x][y + 3]), (chest[x][y + 4])))
					{
						if (chest[x][y] == 1)
							i = 1;
						else i = 2;
					}
				}

				if ((x - 4) > 0)
				{
					if (compare((chest[x][y]), (chest[x - 1][y]), (chest[x - 2][y]), (chest[x - 3][y]), (chest[x - 4][y])))
					{
						if (chest[x][y] == 1)
							i = 1;
						else i = 2;
					}
				}

				if ((x + 4) < 9)
				{
					if (compare((chest[x][y]), (chest[x + 1][y]), (chest[x + 2][y]), (chest[x + 3][y]), (chest[x + 4][y])))
					{
						if (chest[x][y] == 1)
							i = 1;
						else i = 2;
					}
				}

				if (((y - 4) > 0) && ((x - 4) > 0))
				{
					if (compare((chest[x][y]), (chest[x - 1][y - 1]), (chest[x - 2][y - 2]), (chest[x - 3][y - 3]), (chest[x - 4][y - 4])))
					{
						if (chest[x][y] == 1)
							i = 1;
						else i = 2;
					}
				}
					
				if (((y - 4) > 0) && ((x + 4) < 9))
				{
					if (compare((chest[x][y]), (chest[x + 1][y - 1]), (chest[x + 2][y - 2]), (chest[x + 3][y - 3]), (chest[x + 4][y - 4])))
					{
						if (chest[x][y] == 1)
							i = 1;
						else i = 2;
					}
				}

				if (((y + 4) < 9) && ((x - 4) > 0))
				{
					if (compare((chest[x][y]), (chest[x - 1][y + 1]), (chest[x - 2][y + 2]), (chest[x - 3][y + 3]), (chest[x - 4][y + 4])))
					{
						if (chest[x][y] == 1)
							i = 1;
						else i = 2;
					}
				}

				if (((y + 4) < 9) && ((x + 4) < 9))
				{
					if (compare((chest[x][y]), (chest[x + 1][y + 1]), (chest[x + 2][y + 2]), (chest[x + 3][y + 3]), (chest[x + 4][y + 4])))
					{
						if (chest[x][y] == 1)
							i = 1;
						else i = 2;
					}
				}

			}
			x++;
		} while (x != 10);
		x = 0;
		y++;
	} while (y != 10);															/*检测连子*/

}

int main()
{
	printf("   欢迎来到C语言五子棋\n");
	printf("ps：本五子棋暂无禁手规则\n");

	do
	{
		show_chest();
		printf("请黑方落子\n");															/*黑方落子*/
		do																								
		{
			pb = 0;
			printf("请输入落子横坐标(0-9)：\n");
			scanf_s("%d", &black_y);
			rewind(stdin);
			printf("请输入落子纵坐标(0-9)：\n");
			scanf_s("%d", &black_x);
			rewind(stdin);
			system("cls");

			if (black_x < 0 || black_x > 9 || black_y < 0 || black_y > 9 || chest[black_x][black_y] != 0)
			{
				printf("你不能在这里落子\n");
				show_chest();
			}
			else
			{
				chest[black_x][black_y] = 1;
				printf("落子成功！\n");
				show_chest();
				pb = 1;
			}
		} while (pb != 1);

		judge();

		if (i == 1)
		{
			printf("黑方胜");
			break;
		}
		else if (i == 2)
		{
			printf("白方胜");
			break;
		}

		printf("请白方落子\n");															/*白方落子*/
		do																
		{
			pw = 0;
			printf("请输入落子横坐标(0-9)：\n");
			scanf_s("%d", &white_y);
			rewind(stdin);
			printf("请输入落子纵坐标(0-9)：\n");
			scanf_s("%d", &white_x);
			rewind(stdin);
			system("cls");

			if (white_x < 0 || white_x > 9 || white_y < 0 || white_y > 9 || chest[white_x][white_y] != 0)
			{
				printf("你不能在这里落子\n");
				show_chest();
			}
			else
			{
				chest[white_x][white_y] = 2;
				printf("落子成功！\n");
				pw = 1;
			}
		} while (pw != 1);


		judge();

		if (i == 1)
		{
			system("cls");
			show_chest();
			printf("黑方胜");
			break;
		}
		else if (i == 2)
		{
			system("cls");
			show_chest();
			printf("白方胜");
			break;
		}







	} while (true);


	return 0;
}