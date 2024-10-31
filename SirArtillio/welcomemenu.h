class stop_errors{
public: 
    void error(){
    system("cls");
    cout << "\n| === ERROR === |\n\n";
    Sleep(1000);
    cout <<"\n.";
    Sleep(1000);
    cout << " .";
    Sleep(1000);
    cout << " .\n\n";
    Sleep(1000); 
    }    
};

void welcome_menu(){
        cout << "\n| ==== Welcome to menu ==== |\n\n";
        cout << "\nA.) Conversion\n";
        cout << "\nB.) Calculator\n";
        cout << "\nC.) Bitwise Operators\n";
        cout << "\nD.) Prime Numbers\n";
        cout << "\nE.) Prime Factorization\n";
        cout << "\nF.) LCD and GCD\n";
        cout << "\nG.) Euclidean Sequence\n";
        cout << "\nH.) Fibonacci Sequnece\n";
        cout << "\nI.) Egyptian Fraction\n";
        cout << "\nJ.) Modular Arithmetic\n";
        cout << "\nK.) CaesarCipher\n";
        cout << "\nL.) Diffie-Hellman\n";
        cout << "\nM.) RSA\n";
        cout << "\nN.) AES\n";
        cout << "\nO.) DES\n";
        cout << "\nP.) Activity Selection\n";
        cout << "\nQ.) Job Sequence\n";
        cout << "\nR.) Knapsack\n";
        cout << "\nS.) Mice and Holes\n";
        cout << "\nT.) Huffman Coding\n";
        cout << "\nZ.) Quit Program\n";
        cout << "\n\nChoose - ";
}