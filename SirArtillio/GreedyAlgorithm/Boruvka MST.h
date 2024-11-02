class Boruvka{
public:
	int run(){
		system("cls");
		cout << "\n\n| ---- BORUVKA MST ---- |\n\n";
        system("rmdir /S /Q GreedyAlgorithm\\Boruvka_output");
        system("mkdir GreedyAlgorithm\\Boruvka_output");     
        int result = system("python GreedyAlgorithm/Boruvka.py");
        return again();	
	}
};