class Prim{
public:
	int run(){
		    system("CLS");
            cout << "\n\n | ---- PRIM CODE ---- |\n\n";
            system("rmdir /S /Q GreedyAlgorithm\\prim_output");
            system("mkdir GreedyAlgorithm\\prim_output");     
            int result = system("python GreedyAlgorithm/prim.py");
            return again();	
	}
};