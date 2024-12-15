/******************
Name:
ID:
Assignment:
*******************/
#include <stdio.h>
#include <string.h>

void task1RobotPaths();
int robot_path(int x, int y);

void task2HumanPyramid();
void task3ParenthesisValidator();
void task4QueensBattle();
void task5CrosswordGenerator();

int main()
{
    int task = -1;
    do
    {
        printf("Choose an option:\n"
               "1. Robot Paths\n"
               "2. The Human Pyramid\n"
               "3. Parenthesis Validation\n"
               "4. Queens Battle\n"
               "5. Crossword Generator\n"
               "6. Exit\n");

        if (scanf("%d", &task))
        {
            switch (task)
            {
            case 6:
                printf("Goodbye!\n");
                break;
            case 1:
                task1RobotPaths();
                break;
            case 2:
                task2HumanPyramid();
                break;
            case 3:
                task3ParenthesisValidator();
                break;
            case 4:
                task4QueensBattle();
                break;
            case 5:
                task5CrosswordGenerator();
                break;
            default:
                printf("Please choose a task number from the list.\n");
                break;
            }
        }
        else
        {
            scanf("%*s");
        }

    } while (task != 6);
}

void task1RobotPaths()
{
    printf("Please enter the coordinates of the robot (column, row):\n");
    int x, y;
    scanf("%d %d", &y, &x);
    int num_path = robot_path(x, y);
    printf("The total number of paths the robot can take to reach home is: %d\n", num_path);
}

int robot_path(int x, int y) {
    if (x < 0 || y < 0)
        return 0;
    if (x == 0 && y == 0)
        return 1;
    return robot_path(x - 1, y) + robot_path(x, y - 1);
}

void task2HumanPyramid()
{
    // Todo
}

void task3ParenthesisValidator()
{
    // Todo
}

void task4QueensBattle()
{
    // Todo
}

void task5CrosswordGenerator()
{
    // Todo
}
