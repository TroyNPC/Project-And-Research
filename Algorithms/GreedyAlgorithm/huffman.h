#include <cstdlib>

class huffman {
    public:
        int run() {
            system("CLS");
            cout << "\n\n | ---- HUFFMAN CODE ---- |\n\n";
            system("rmdir /S /Q GreedyAlgorithm\\huffman_output");
            system("mkdir GreedyAlgorithm\\huffman_output");     
            int result = system("python GreedyAlgorithm/huffmans.py");
            return again();
        }
};
