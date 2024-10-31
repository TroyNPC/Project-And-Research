#include "Libraries.h"
//| === Callback To Go Back To Menu === |
int main();
//| === Callback To Go Back To Menu === |
#include "welcomemenu.h"
// -------------------------------------------> Headers <-------------------------------------------
#include "LibraryHeaders.h"
// -------------------------------------------> Headers <-------------------------------------------

// <-----------------------------------> MAIN FUNCTION <----------------------------------->
int main() {
    bool running = true;
    stop_errors stop;
    input write;
    char decision;

    while (running) {
        system("cls");
        welcome_menu();
        cin >> decision;

        switch (toupper(decision)) {
            case 'A': {
                choose_decisions(decision);
                choose_conversion();
                cout << "\n";
                running = false;
                break;
            }
            case 'B': {
                choose_decisions(decision);
                choose_calculator();
                cout << "\n";
                running = false;
                break;
            }
            case 'C': {
                Bitwiseinput typebit;
                typebit.input();
                cout << "\n";
                running = false;
                break;
            }
            case 'D': {
                Prime numbers;
                numbers.input();
                running = false;
                break;
            }
            case 'E': {
                PrimeFactor factor;
                factor.input();
                running = false;
                break;
            }
            case 'F': {
                LCDandGCD lcdandgcd;
                lcdandgcd.input();
                running = false;
                break;
            }
            case 'G': {
                write.encode();
                running = false;
                break;
            }
            case 'H': {
                Fibonacci limit;
                limit.fibonacci_input();
                running = false;
                break;
            }
            case 'I': {
                EgyptianFraction egyptian;
                egyptian.egyptian_input();
                running = false;
                break;
            }
            case 'J': {
                Modulars modular;
                modular.decision();
                running = false;
                break;
            }
            case 'K': {
                CaesarCipher encdec;
                encdec.input();
                running = false;
                break;
            }
            case 'L': {
                DiffieHellman usediffie;
                usediffie.input();
                running = false;
                break;
            }
            case 'M': {
                RSA rsa;
                rsa.input();
                running = false;
                break;
            }
            case 'N': {
                AES aes;
                aes.input();
                running = false;
                break;
            }
            case 'O': {
                DES des;
                des.input();
                running = false;
                break;
            }
            case 'P': {
                ActivitySelection activityselect;
                activityselect.input();
                running = false;
                break;
            }
            case 'Q': {
                JobSequencing sequence;
                sequence.input();
                running = false;
                break;
            }
            case 'R': {
                knapsack knap;
                knap.inputAndSolve();
                running = false;
                break;
            }
            case 'S': {
                MiceAndHoles miceandholes;
                miceandholes.input();
                running = false;
                break;
            }
            case 'T': {
                huffman huffcall;
                huffcall.run();
                running = false;
                break;
            }
            case 'U':{
                running = false;
                break;
            }
            case 'Z':{
                cout << "\n\n| ==== PROGRAM TERMINATED ==== |\n\n";
                running = false;
                break;
            }
            default: {
                stop.error();
                again();
                running = false;
                break;
            }
        }
    }
    return 0;
}

// <-----------------------------------> MAIN FUNCTION <----------------------------------->
