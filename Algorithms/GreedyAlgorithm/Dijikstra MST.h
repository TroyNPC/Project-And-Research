class Dijikstra{
public:
	int run(){
		system("cls");
		cout << "\n\n| ---- DIJIKSTRA MST ---- |\n\n";
        system("rmdir /S /Q GreedyAlgorithm\\Dijikstra_output");
        system("mkdir GreedyAlgorithm\\Dijikstra_output");     
        int result = system("python GreedyAlgorithm/Dijikstra.py");
        return again();	
	}
};