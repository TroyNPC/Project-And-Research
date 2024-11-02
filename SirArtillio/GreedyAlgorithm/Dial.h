class Dial{
public:
	int run(){
		system("cls");
		cout << "\n| ---- DIAL MST ---- |\n\n";
        system("rmdir /S /Q GreedyAlgorithm\\Dial_output");
        system("mkdir GreedyAlgorithm\\Dial_output");     
        int result = system("python GreedyAlgorithm/Dial.py");
        return again();
	}
};