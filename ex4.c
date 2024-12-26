/******************
Name:
ID:
Assignment:
*******************/
#include <stdio.h>
#include <string.h>

#define NUM_OF_COLUMNS 5
#define MAX_ARRAY_PAREN 100
#define FIRST_PLACE_IN_ARRAY 0

void task1RobotPaths();
int robot_path(int row, int column);

void task2HumanPyramid();
float calculate_weight(float human_pyramid[NUM_OF_COLUMNS][NUM_OF_COLUMNS], int row, int column);

void task3ParenthesisValidator();
int validate_parent(char validate[], char paren_array[], int i, int current_place);

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
    // random big string length idk
    char validate[MAX_ARRAY_PAREN]; // the string the user entered
    char paren_array[MAX_ARRAY_PAREN] = {0}; // array to put all the start paren to check matches
    printf("Please enter a term for validation:\n");
    // enter the string the user entered inside the char array with '\0' at the end to show wehre is the end of it
    scanf("%s", validate);
    
    // check the array from start till you find '\0'
    // we have 2 FIRST_PLACE_IN_ARRAY. first one is for the string array the user gave, second one to see current place in paren array
    if (validate_parent(validate, paren_array, FIRST_PLACE_IN_ARRAY, FIRST_PLACE_IN_ARRAY))
      printf("The parentheses are balanced correctly.\n");
    else
      printf("The parentheses are not balanced correctly.\n");
}

int validate_parent(char validate[], char paren_array[], int i, int current_place) {
    // check until you found '\0' - end of string
    if (validate[i] == '\0') {
        // the array of parentheses_checking is empty
        return current_place == 0;
    }

    char current_char = validate[i];

    switch (current_char) {
        // add open paren to the paren array
        case '(':
        case '[':
        case '{':
        case '<':
            if (current_place == MAX_ARRAY_PAREN) {
                // last char is open paren and it will be false cause no closer
                return 0;
            }
            paren_array[current_place] = current_char;
            // call recursive but check next char, and let it be next place in paren array
            return validate_parent(validate, paren_array, i + 1, current_place + 1);

        // check for the match
        case ')':
        case ']':
        case '}':
        case '>':
            if (current_place == 0) {
                return 0; // this is the first char and it wont match anything
            }
        
            // find the matching to close paren
            char match_paren = 
                (current_char == ')') ? '(' : 
                (current_char == ']') ? '[' : 
                (current_char == '}') ? '{' : '<';
            // the recursive called for next place in paren array, so we need to check match in last place
            if (paren_array[current_place - 1] != match_paren) {
                return 0;
            }
        
            // if we got here it means there is a match, check for next char but with last place in array ("delete last char")
            return validate_parent(validate, paren_array, i + 1, current_place - 1);
        
        // smt that is not a paren, just skip them and move to the next char
        default:
            return validate_parent(validate, paren_array, i + 1, current_place);
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
