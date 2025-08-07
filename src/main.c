#include "mcui.h"

#include <windows.h>
#include <stdio.h>

const int TOP_LEFT = 0;
const int BOTTOM_LEFT = 1;
const int RIGHT = 2;

int STATE = 0;

void main() {
    display();
    setInfo("Convertion from Morse code to English. Type using '.' and '-', using spaces between each letter and '/' between words.");
    
    while(1) {
        HANDLE stdIn;
        DWORD numRead;
        INPUT_RECORD inBuff[128];

        stdIn = GetStdHandle(STD_INPUT_HANDLE);

        while (1) {
            if (ReadConsoleInput(stdIn, inBuff, 128, &numRead)) {
                for (DWORD i = 0; i < numRead; i++) {
                    if (inBuff[i].EventType == WINDOW_BUFFER_SIZE_EVENT) {
                        display();
                        int printState = 0;
                        while (printState < 3) {
                            printChar(printState);
                            printState++;
                        }

                    } else if (inBuff[i].EventType == KEY_EVENT) {
                        const KEY_EVENT_RECORD key = inBuff[i].Event.KeyEvent;
                        if (key.wVirtualScanCode && key.bKeyDown == TRUE) {
                            if (key.wVirtualKeyCode && key.wVirtualKeyCode == 0x09) {
                                STATE++;
                                if (STATE > 1) STATE = 0;
                                display();

                                if (STATE == 0) {
                                    setInfo("Convertion from Morse code to English. Type using '.' and '-', using spaces between each letter and '/' between words.");
                                } else if (STATE == 1) {
                                    setInfo("Enter a sentence in English to be converted into Morse code.");
                                }
                                
                                printChar(0);
                                printChar(1);
                                
                            }
                            
                            char ch = key.uChar.AsciiChar;
                            if (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122 || ch == 32 || ch == '.' || ch == '-' || ch == '/' || ch >= '0' && ch == '9') {
                                if (STATE == 0) {
                                    addChar(0, ch);
                                    convertMorse();
                                    printChar(1);
                                } else if (STATE == 1) {
                                    addChar(1, ch);
                                    convertEnglish();
                                    printChar(0);
                                }
                            }
                            // if (ch == '`') printChar(2);
                        }
                    }
                }
            }
        }
    }
}