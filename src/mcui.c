#include <windows.h>
#include <stdio.h>
#include <ctype.h>

// int TOP_LEFT = 0;
// int BOTTOM_LEFT = 1;
// int RIGHT = 2;

char topLeft[500];

int topLeftCounter = 0;
int topLeftCounterX = 2;
int topLeftCounterY = 0;

char bottomLeft[500];

int bottomLeftCounter = 0;
int bottomLeftCounterX = 2;
int bottomLeftCounterY = 0;

char right[500];

int rightCounter = 0;
int rightCounterX = 0;
int rightCounterY = 0;

char displaySet[500];
int displaySetCounter = 0;

void printChar(int mode) {

    CONSOLE_SCREEN_BUFFER_INFO info;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    columns = info.srWindow.Right - info.srWindow.Left + 1;
    rows  = info.srWindow.Bottom - info.srWindow.Top + 1;

    int a = rows / 2;
    int remRow;
    int initRow;
    if (a > rows) {
        remRow = a - rows;
        initRow = rows - remRow;
    }
    else {
        remRow = rows - a;
        initRow = rows - remRow;
    }

    int b = columns / 5;
    int remCol = columns - (b + b + b);
    int initCol = columns - remCol;

    char *processPrint[500] = {};
    int counter = 0;
    int linLen;

    if (mode == 0) {

        char top[500];
        strcpy(top, topLeft);

        char *token = strtok(top, " ");
        int printSize = 0;
        while (token != NULL) {
            processPrint[printSize] = token;
            printSize++;
            token = strtok(NULL, " ");
        }

        counter = 0;
        linLen = initCol + 4;

        topLeftCounterY = 0;

        COORD cordinates;
        cordinates.X = 2;
        cordinates.Y = 1;
        
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinates);

        while (processPrint[counter] != NULL) {
            if (strlen(processPrint[counter]) + 9 <= linLen) {
                printf("%s", processPrint[counter]);
                if (processPrint[counter+1]) printf(" ");
                linLen -= strlen(processPrint[counter]) + 1;

            } else {
                linLen = initCol + 4;
                topLeftCounterX = 2;
                topLeftCounterY++;
                cordinates.X = topLeftCounterX;
                cordinates.Y = topLeftCounterY+1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinates);

                printf("%s", processPrint[counter]);
                if (processPrint[counter+1]) printf(" ");
                linLen -= strlen(processPrint[counter]) + 1;
            }
            counter++;
        }

    } else if (mode == 1) {
        char bottom[500];
        strcpy(bottom, bottomLeft);

        char *token = strtok(bottom, " ");
        int printSize = 0;
        while (token != NULL) {
            processPrint[printSize] = token;
            printSize++;
            token = strtok(NULL, " ");
        }

        counter = 0;
        linLen = initCol+ 4;

        bottomLeftCounterY = 0;

        COORD cordinates;
        cordinates.X = 2;
        cordinates.Y = bottomLeftCounterY+initRow+1;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinates);

        while (processPrint[counter] != NULL) {
            if (strlen(processPrint[counter]) + 9 <= linLen) {
                printf("%s", processPrint[counter]);
                if (processPrint[counter+1]) printf(" ");
                linLen -= strlen(processPrint[counter]) + 1;

            } else {
                linLen = initCol + 4;
                bottomLeftCounterX = 2;
                bottomLeftCounterY++;
                cordinates.X = bottomLeftCounterX;
                cordinates.Y = bottomLeftCounterY+initRow+1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinates);

                printf("%s", processPrint[counter]);
                if (processPrint[counter+1]) printf(" ");
                linLen -= strlen(processPrint[counter]) + 1;
            }
            counter++;
        }

    } else if (mode == 2) {
        char rightTemp[500];
        strcpy(rightTemp, right);

        char *token = strtok(rightTemp, " ");
        int printSize = 0;
        while (token != NULL) {
            processPrint[printSize] = token;
            printSize++;
            token = strtok(NULL, " ");
        }

        counter = 0;
        linLen = initCol + 4;

        rightCounterY = 0+1;
        rightCounterX = initCol;

        COORD cordinates;
        cordinates.X = rightCounterX;
        cordinates.Y = rightCounterY;
        
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinates);

        while (processPrint[counter] != NULL) {
            if (strlen(processPrint[counter]) + 37 <= linLen) {
                printf("%s", processPrint[counter]);
                if (processPrint[counter+1]) printf(" ");
                linLen -= strlen(processPrint[counter]) + 1;

            } else {
                linLen = initCol + 4;
                rightCounterX = initCol;
                rightCounterY++;
                cordinates.X = rightCounterX;
                cordinates.Y = rightCounterY;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinates);

                printf("%s", processPrint[counter]);
                if (processPrint[counter+1]) printf(" ");
                linLen -= strlen(processPrint[counter]) + 1;
            }
            counter++;
        }

    } else {
        printf("INVALID STATE");
        exit(1);
    }

}

void addChar(int mode, char ch) {
    CONSOLE_SCREEN_BUFFER_INFO info;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    columns = info.srWindow.Right - info.srWindow.Left + 1;
    rows  = info.srWindow.Bottom - info.srWindow.Top + 1;

    int a = rows / 2;
    int remRow;
    int initRow;
    if (a > rows) {
        remRow = a - rows;
        initRow = rows - remRow;
    }
    else {
        remRow = rows - a;
        initRow = rows - remRow;
    }

    int b = columns / 5;
    int remCol = columns - (b + b + b);
    int initCol = columns - remCol;

    if (mode == 0) {

        topLeft[topLeftCounter] = ch;

        if (topLeftCounterX > initCol - 4) {
            topLeftCounterX = 2;
            topLeftCounterY++;
        }

        COORD cordinates;
        cordinates.X = topLeftCounterX;
        cordinates.Y = topLeftCounterY+1;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinates);

        printf("%c",topLeft[topLeftCounter]);

        topLeftCounter++;
        topLeftCounterX++;

    } else if (mode == 1) {
        bottomLeft[bottomLeftCounter] = ch;

        if (bottomLeftCounterX > initCol - 4) {
            bottomLeftCounterX = 2;
            bottomLeftCounterY++;
        }

        COORD cordinates;
        cordinates.X = bottomLeftCounterX;
        cordinates.Y = bottomLeftCounterY+initRow+1;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinates);

        printf("%c",bottomLeft[bottomLeftCounter]);

        bottomLeftCounter++;
        bottomLeftCounterX++;
    } else if (mode == 2) {
        right[rightCounter] = ch;

        if (rightCounterX == 0) rightCounterX = initCol;
        if (rightCounterX > columns - 4) {
            rightCounterX = initCol;
            rightCounterY++;
        }

        COORD cordinates;
        cordinates.X = rightCounterX;
        cordinates.Y = rightCounterY+1;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinates);

        printf("%c",right[rightCounter]);

        rightCounter++;
        rightCounterX++;

    } else {
        printf("INVALID STATE");
        exit(1);
    }

}

void display() {

    CONSOLE_SCREEN_BUFFER_INFO info;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    columns = info.srWindow.Right - info.srWindow.Left + 1;
    rows  = info.srWindow.Bottom - info.srWindow.Top + 1;

    const char *morseName = " Morse code ";
    const int morseLen = 12;
    int morseCounter = 0;

    const char *english = " English ";
    const int engLen = 9;
    int engCounter = 0;

    const char *settings = "Information";
    const int settLen = 11;
    int settCounter = 0;

    
    system("cls");

    // Screen partition calculation.
    int a = rows / 2;
    int remRow;
    int initRow;
    if (a > rows) {
        remRow = a - rows;
        initRow = rows - remRow;
    }
    else {
        remRow = rows - a;
        initRow = rows - remRow;
    }

    int b = columns / 5;
    int remCol = columns - (b + b + b);
    int initCol = columns - remCol;

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j <= columns; j++) {
            if (i == 0) {
                if (j > 1 && j <= morseLen+1) {
                    printf("%c", morseName[morseCounter]);
                    morseCounter++;
                    continue;

                } else if (j > initCol+1 && j < initCol + 1 + settLen + 1) {
                    printf("%c", settings[settCounter]);
                    settCounter++;
                    continue;

                }

                if (j == 0 || j == initCol) {
                    printf("%c", 218);
                } else if (j > 0 && j < initCol - 2 || j > initCol && j < columns - 1) { 
                    printf("%c", 196);
                } else if (j == initCol - 1 || j == columns - 1) {
                    printf("%c", 191);
                } else if (j == columns) printf(" ");
                
            } else if (i > 0 && i < initRow - 1) {
                if (j == 0 || j == initCol) {
                    printf("%c", 179);
                } else if (j > 0 && j < initCol - 2 || j > initCol && j < columns - 1) { // Avaiable space
                    printf(" ");
                } else if (j == initCol - 1 || j == columns - 1) {
                    printf("%c", 179);
                } else if (j == columns) printf(" ");
                
            } else if (i == initRow) {
                if (j == 0) {
                    printf("%c", 192);
                } else if (j > 0 && j < initCol - 2) {
                    printf("%c", 196);
                } else if (j == initCol - 1) {
                    printf("%c", 217);
                } else if (j == initCol) {
                    printf("%c", 179);
                } else if (j > initCol && j < columns - 1) {  // Avaiable space
                    printf(" ");
                } else if (j == columns - 1) {
                    printf("%c", 179);
                } else if (j == columns) printf(" ");
                
            } else if (i == initRow + 1) {

                if (j > 1 && j <= engLen+1) {
                    printf("%c", english[engCounter]);
                    engCounter++;
                    continue;
                }

                if (j == 0) {
                    printf("%c", 218);
                } else if (j > 0 && j < initCol - 2) {
                    printf("%c", 196);
                } else if (j == initCol - 1) {
                    printf("%c", 191);
                } else if (j == initCol) {
                    printf("%c", 179);
                } else if (j > initCol && j < columns - 1) {  // Avaiable space
                    printf(" ");
                } else if (j == columns - 1) {
                    printf("%c", 179);
                } else if (j == columns) printf(" ");
                
            } else if (i > initRow + 1 && i < rows - 1) {
                if (j == 0 || j == initCol) {
                    printf("%c", 179);
                } else if (j > 0 && j < initCol - 2 || j > initCol && j < columns - 1) {  // Avaiable space
                    printf(" ");
                } else if (j == initCol - 1 || j == columns - 1) {
                    printf("%c", 179);
                } else if (j == columns) printf(" ");

            } else if (i == rows - 1) {
                if (j == 0 || j == initCol) {
                    printf("%c", 192);
                } else if (j > 0 && j < initCol - 2 || j > initCol && j < columns - 1) {
                    printf("%c", 196);
                } else if (j == initCol - 1 || j == columns - 1) {
                    printf("%c", 217);
                } else if (j == columns) printf(" ");

            }

        }
    }

    printf("Press TAB to switch modes.");
}

// Converts Morse to English
void convertMorse() {
    char engCon[500];
    memset(bottomLeft, '\0', sizeof(bottomLeft));
    bottomLeftCounter = 0;
    bottomLeftCounterX = 2;
    bottomLeftCounterY = 0;

    strcpy(engCon, topLeft);

    // Remove trailing newline character
    engCon[strcspn(engCon, "\n")] = '\0';


    char *morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
                        ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/"};

    char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    char *word = strtok(engCon, " ");

    while (word != NULL) {
        int i;
        for (i = 0; i < 27; i++) {
            if (strcmp(morseCodes[i], word) == 0) {
                // printf("%c", letters[i]);
                addChar(1, letters[i]);
                break;
            }
        }
        word = strtok(NULL, " ");
    }
    
}

char *morse_code[54] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",   ".---",
    "-.-",  ".-..", "--",   "-.",   "---",  ".--.", "--.-", ".-.",  "...",  "-",
    "..-",  "...-", ".--",  "-..-", "-.--", "--..", "-----", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.",
    "-.--.", "-..-.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-",
    ".-..-."
};

char *getMorseCode(char ch) {
    if (isalpha(ch)) {
        return morse_code[toupper(ch) - 'A'];
    } else if (isdigit(ch)) {
        return morse_code[ch - '0' + 26];
    } else if (ch == ' ') {
        return "/"; // Use '/' for space in Morse code
    } else {
        return ""; // Ignore other characters
    }
}

void convertEnglish() {
    char morseCon[500];
    memset(topLeft, '\0', sizeof(topLeft));
    topLeftCounter = 0;
    topLeftCounterX = 2;
    topLeftCounterY = 0;

    strcpy(morseCon, bottomLeft);

    for (int i = 0; morseCon[i] != '\0'; i++) {
        char *morse = getMorseCode(morseCon[i]);
        if (morse[0] != '\0') {
            // printf("%s ", morse);
            int count = 0;
            while (morse[count]) {
                addChar(0, morse[count]);
                count++;
            }
            addChar(0, ' ');
        }
    }
}

void setInfo(char in[]) {
    memset(right, '\0', sizeof(right));
    rightCounter = 0;
    rightCounterX = 0;
    rightCounterY = 0;

    int count = 0;
    while (in[count])
    {
        addChar(2, in[count]);
        count++;
    }
    
}