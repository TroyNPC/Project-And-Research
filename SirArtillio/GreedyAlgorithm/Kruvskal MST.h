class kruvskal{
public:
	int run(){
            system("CLS");
            cout << "\n\n | ---- KRUVSKAL CODE ---- |\n\n";
            system("rmdir /S /Q GreedyAlgorithm\\kruvskal_output");
            system("mkdir GreedyAlgorithm\\kruvskal_output");     
            int result = system("python GreedyAlgorithm/kruvskal.py");
            return again();	
	}
};