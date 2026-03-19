#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct Node {
    char word[50];
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE] = {NULL};

HWND hEdit, hResult;

// ================= HASH FUNCTION =================
int hashFunction(char* word) {
    int sum = 0;
    for(int i = 0; word[i] != '\0'; i++)
        sum += word[i];
    return sum % TABLE_SIZE;
}

// ================= INSERT =================
void insert(char* word) {
    int index = hashFunction(word);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// ================= SEARCH =================
int search(char* word) {
    int index = hashFunction(word);
    Node* temp = hashTable[index];
    while(temp) {
        if(strcmp(temp->word, word) == 0)
            return 1;
        temp = temp->next;
    }
    return 0;
}

// ================= LOAD DICTIONARY =================
void loadDictionary() {
    insert("hello");
    insert("world");
    insert("computer");
    insert("science");
    insert("engineering");
    insert("programming");
    insert("algorithm");
    insert("database");
    insert("network");
    insert("software");
    insert("hardware");
    insert("python");
    insert("java");
    insert("project");
    insert("student");
}

// ================= WINDOW PROCEDURE =================
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {

    switch(msg) {

        case WM_CREATE:

            // Input box
            hEdit = CreateWindow("EDIT", "",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    150, 120, 250, 30,
                    hwnd, NULL, NULL, NULL);

            // CHECK button
            CreateWindow("BUTTON", "CHECK",
                    WS_VISIBLE | WS_CHILD,
                    100, 180, 100, 40,
                    hwnd, (HMENU)1, NULL, NULL);

            // CLEAR button
            CreateWindow("BUTTON", "CLEAR",
                    WS_VISIBLE | WS_CHILD,
                    220, 180, 100, 40,
                    hwnd, (HMENU)2, NULL, NULL);

            // EXIT button
            CreateWindow("BUTTON", "EXIT",
                    WS_VISIBLE | WS_CHILD,
                    340, 180, 100, 40,
                    hwnd, (HMENU)3, NULL, NULL);

            // Result label
            hResult = CreateWindow("STATIC", "",
                    WS_VISIBLE | WS_CHILD,
                    150, 250, 300, 40,
                    hwnd, NULL, NULL, NULL);

            break;

        case WM_COMMAND:

            if(LOWORD(wp) == 1) { // CHECK
                char text[50];
                GetWindowText(hEdit, text, 50);

                if(search(text))
                    SetWindowText(hResult, "Correct Spelling!");
                else
                    SetWindowText(hResult, "Incorrect Spelling!");
            }

            if(LOWORD(wp) == 2) { // CLEAR
                SetWindowText(hEdit, "");
                SetWindowText(hResult, "");
            }

            if(LOWORD(wp) == 3) { // EXIT
                PostQuitMessage(0);
            }

            break;

        case WM_CTLCOLORSTATIC: {
            HDC hdc = (HDC)wp;
            SetTextColor(hdc, RGB(0,100,0));
            SetBkMode(hdc, TRANSPARENT);
            return (LRESULT)GetStockObject(NULL_BRUSH);
        }

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            RECT rect;
            GetClientRect(hwnd, &rect);

            HBRUSH hBrush = CreateSolidBrush(RGB(173, 216, 230)); // light blue
            FillRect(hdc, &rect, hBrush);
            DeleteObject(hBrush);

            SetBkMode(hdc, TRANSPARENT);
            SetTextColor(hdc, RGB(0,0,139));
            SetTextAlign(hdc, TA_CENTER);

            TextOut(hdc, 250, 40, "SPELL CHECKER", 13);
            TextOut(hdc, 100, 100, "Enter Word:", 11);

            EndPaint(hwnd, &ps);
            break;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wp, lp);
    }

    return 0;
}

// ================= MAIN =================
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR args, int ncmdshow) {

    loadDictionary();

    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInst;
    wc.lpszClassName = "SpellChecker";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);

    RegisterClass(&wc);

    CreateWindow("SpellChecker", "Spell Checker - Hash Table",
                 WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                 100, 100, 550, 400,
                 NULL, NULL, hInst, NULL);

    MSG msg = {0};
    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}