/******************
Name:
ID:
Assignment:
*******************/
#include <stdio.h>
#include <string.h>

#define NUM_OF_COLUMNS 5

void task1RobotPaths();
int robot_path(int row, int column);

void task2HumanPyramid();
float calculate_weight(float human_pyramid[NUM_OF_COLUMNS][NUM_OF_COLUMNS], int row, int column);

void task3ParenthesisValidator();
int validate_parent(char validate[100], int current_place, char end_char);

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
    int row, column;
    scanf("%d %d", &column, &row);
    int num_path = robot_path(row, column);
    printf("The total number of paths the robot can take to reach home is: %d\n", num_path);
}

int robot_path(int row, int column) {
    if (row < 0 || column < 0)
        return 0;
    if (row == 0 && column == 0)
        return 1;
    return robot_path(row - 1, column) + robot_path(row, column - 1);
}

void task2HumanPyramid()
{
    float human_pyramid[NUM_OF_COLUMNS][NUM_OF_COLUMNS] = {0}; // the pyramid will be shown as matrix
    printf("Please enter the weights of the cheerleaders:\n");
    
    // fill in the matrix
    for (int i = 0; i < NUM_OF_COLUMNS; i++) {
        for (int j = 0; j <= i; j++) {
            if (scanf("%f", &human_pyramid[i][j]) != 1 || human_pyramid[i][j] < 0) {
                printf("Negative weights are not supported.\n");
                return;
            }
        }
    }
    
    printf("The total weight supported by each cheerleader:\n");
    // do the recurtion and print the answer from bottom row to top
    for (int i = 0; i < NUM_OF_COLUMNS; i++) {
        for (int j = 0; j <= i; j++) {
            float cheerleader_weight = calculate_weight(human_pyramid, i, j);
            printf("%.2f ", cheerleader_weight);
        }
        printf("\n");
    }
}

float calculate_weight(float human_pyramid[NUM_OF_COLUMNS][NUM_OF_COLUMNS], int row, int column) {
    // if the row is 0 it means it is the top cheerleader and you can return the weight as it is
    if (row == 0 && column == 0) {
        return human_pyramid[row][column];
    }

    // base weight
    float cheerleader_weight = human_pyramid[row][column];

    // if it has a row above
    if (row > 0) {
        // if it has a column on the left
        if (column > 0) {
            // add half of the weight of the cee above (after adding the rest of the weight from cheerleaders from above the person above)
            cheerleader_weight += calculate_weight(human_pyramid, row - 1, column - 1) / 2;
        }
        // if it has a calumn on the right
        if (column < row) {
            // add half of the weight of the cee above (after adding the rest of the weight from cheerleaders from above the person above)
            cheerleader_weight += calculate_weight(human_pyramid, row - 1, column) / 2;
        }
    }

    return cheerleader_weight;
}

void task3ParenthesisValidator()
{
    char validate[100];
    for (int i = 0; i < 99; i++) {  // Leave space for '\0'
        if (scanf("%c", &validate[i]) != 1 || validate[i] == '\n') {
            validate[i] = '\0';  // Safely terminate the string
            break;
        }
    }
    printf("%s", validate);
    
    // check the array from start till you find '\0'
    if (validate_parent(validate, 0, '\0')) {
      printf("good");
    }
    else
      printf("bad");
}

int validate_parent(char validate[100], int current_place, char end_char) {
  if (validate[current_place] == '\0') {
        // check if the wanted end_char is '\0' (we change the end_char in the middle)
        return end_char == '\0';
    }

  char current_char = validate[current_place];
  
  switch (current_char) {
        case '(':
            if (!validate_parent(validate, current_place + 1, ')')) return 0;
            break;
        case '[':
            if (!validate_parent(validate, current_place + 1, ']')) return 0;
            break;
        case '{':
            if (!validate_parent(validate, current_place + 1, '}')) return 0;
            break;
        case '<':
            if (!validate_parent(validate, current_place + 1, '>')) return 0;
            break;
        case ')': case ']': case '}': case '>':
            // If we encounter a closing parenthesis, check if it matches
            return current_char == end_char && validate_parent(validate, current_place + 1, '\0');
        default:
            // Ignore non-parenthesis characters
            return validate_parent(validate, current_place + 1, end_char);
    }
}

void task4QueensBattle()
{
    // Todo
}

void task5CrosswordGenerator()
{
    // Todo
}
