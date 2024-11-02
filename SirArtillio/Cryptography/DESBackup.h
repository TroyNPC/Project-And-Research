class DES{
int hexToInt(const string& hex) {
    return stoul(hex, nullptr, 16);
}
string intToBinaryString(int num, int bits = 2) {
    string binaryStr = bitset<2>(num).to_string();
    return binaryStr.substr(binaryStr.size() - bits); // Ensures the result is only `bits`-length
}
string binaryToHex(const string& binary) {
    unsigned long decimalValue = std::stoul(binary, nullptr, 2);
    std::stringstream hexStream;
    hexStream << std::hex << decimalValue; 
    return hexStream.str(); 
    }


vector<vector<int>> S0_table = {
    {1, 0, 3, 2}, // row 0
    {3, 2, 0, 1}, // row 1
    {0, 2, 1, 3}, // row 2
    {2, 1, 0, 3}  // row 3
};

vector<vector<int>> S1_table = {
    {0, 1, 2, 3}, // row 0
    {2, 0, 1, 3}, // row 1
    {3, 0, 1, 2}, // row 2
    {2, 1, 0, 3}  // row 3
};

vector<int> input_vector(int size,string name){
vector<int> vec(size);

for (int i = 0; i < size; i++)
{
    cout << "enter the "<< i+1 << " character for "<<name<<" :";
    cin >> vec[i];
    system("CLS");
}
return vec;
}


void display_vector_table(const vector<int>& vec, const string& name) {
  
    int width = vec.size() * 10 + 1; 

    
  
    cout << name << ":\n";
    cout << string(width, '-') << '\n'; 

    cout << "| Input:  ";
    // Display inputs
    for (size_t i = 0; i < vec.size(); i++) {
        cout << setw(8) << i+1; 
    }
    cout << " |\n"; 

    cout << "| Output: ";
   
    for (size_t i = 0; i < vec.size(); i++) {
        cout << setw(8) << vec[i]; 
    }
    cout << " |\n"; 

    
    cout << string(width, '-') << "\n\n"; 
}

vector<int> left_shift(const vector<int>& bits, int shifts) {
    vector<int> shifted = bits;
    rotate(shifted.begin(), shifted.begin() + shifts, shifted.end());
    return shifted;
}

void Generate_key(vector<int> key,vector<int> P10,vector<int> P8, vector<int>& K1, vector<int>& K2){

vector<int> permuted_key(10);

 for (int i = 0; i < 10; ++i) {
        permuted_key[i] = key[P10[i] - 1];  // P10 is 1-indexed
    }

cout << "P10: ";
 for (auto bit : permuted_key) cout << bit << " ";
    cout<<endl;

 vector<int> left_half(permuted_key.begin(), permuted_key.begin() + 5);
 vector<int> right_half(permuted_key.begin() + 5, permuted_key.end());

left_half = left_shift(left_half, 1);
right_half = left_shift(right_half, 1);




vector<int> combined_key_for_K1;
combined_key_for_K1.insert(combined_key_for_K1.end(), left_half.begin(), left_half.end());
combined_key_for_K1.insert(combined_key_for_K1.end(), right_half.begin(), right_half.end());

cout << "LS1: ";
 for (auto bit : combined_key_for_K1) cout << bit << " ";
    cout<<endl;



for (int i = 0; i < 8; ++i) {
    K1[i] = combined_key_for_K1[P8[i] - 1];  
}

cout << "K1: ";
 for (auto bit : K1) cout << bit << " ";
    cout<<endl;


left_half = left_shift(left_half, 2); 
right_half = left_shift(right_half, 2); 


vector<int> combined_key_for_K2;
combined_key_for_K2.insert(combined_key_for_K2.end(), left_half.begin(), left_half.end());
combined_key_for_K2.insert(combined_key_for_K2.end(), right_half.begin(), right_half.end());

cout << "LS2: ";
 for (auto bit : combined_key_for_K2) cout << bit << " ";
    cout<<endl;

for (int i = 0; i < 8; ++i) {
    K2[i] = combined_key_for_K2[P8[i] - 1];  

}

cout << "K1: ";
 for (auto bit : K2) cout << bit << " ";
    cout<<endl;
}

vector<int>IP_EP_STEP(vector<int> PT, vector<int> IP, vector<int> EP, vector<int> P4,vector<int> K1){

vector<int>Initial(8);

 for (int i = 0; i < 8; ++i) {
        Initial[i] = PT[IP[i] - 1];  
    }

 vector<int> left_half(Initial.begin(), Initial.begin() + 4);
 vector<int> right_half(Initial.begin() + 4, Initial.end());

cout << "\n\nIP: ";
    for (auto bit : Initial) cout << bit << " ";
    cout << endl;

cout << "left_half: ";
for (auto bit : left_half) cout << bit << " ";
 cout << "\n";



    cout << "right half: ";
    for (auto bit : right_half) cout << bit << " ";
    cout << endl;

 
 vector<int> EP_bit(8);
 for (int i = 0; i < 8; ++i) {
        EP_bit[i] = right_half[EP[i] - 1];  
    }

   
cout << "EP: ";
for (auto bit : EP_bit) cout << bit << " ";


vector<int> XOR_result(8); 
    for (int i = 0; i < 8; ++i) {
        XOR_result[i] = EP_bit[i] ^ K1[i]; 
    }

cout << "XOR of EP and K1: ";
for (auto bit : XOR_result) cout << bit << " ";



cout <<endl;
vector<int> S0(XOR_result.begin(), XOR_result.begin() + 4); // S0 should be 4 bits
vector<int> S1(XOR_result.begin() + 4, XOR_result.end());   // S1 should be 4 bits


cout << "S0: ";
for (auto bit : S0) cout << bit << " ";

cout << "s1: ";
for (auto bit : S1) cout << bit << " ";




    // S0 row and col
    vector<int> S0row;
    if (!S0.empty()) {
        S0row.push_back(S0.front()); 
        S0row.push_back(S0.back());  
    }

    vector<int> S0col;
    if (S0.size() == 4) {
        S0col.push_back(S0[1]); 
        S0col.push_back(S0[2]); 
    }

    // S1 row and col
    vector<int> S1row;
    if (!S1.empty()) {
        S1row.push_back(S1.front()); 
        S1row.push_back(S1.back()); 
    }

    vector<int> S1col;
    if (S1.size() == 4) {
        S1col.push_back(S1[1]); 
        S1col.push_back(S1[2]); 
    }

    string s0joinedrow;
    string s0joinedcol;

    for (int bit : S0row) {
        s0joinedrow += to_string(bit);
    }
     for (int bit : S0col) {
        s0joinedcol += to_string(bit);
    }
    cout<<"row :" << s0joinedrow << ", col :"<< s0joinedcol<<endl;;



    string hexofS0row = binaryToHex(s0joinedrow);
    int s0rowint = hexToInt(hexofS0row);
   

    string hexofS0col = binaryToHex(s0joinedcol);
    int s0colint = hexToInt(hexofS0col);
   







    string s1joinedrow;
    string s1joinedcol;

    for (int bit : S1row) {
        s1joinedrow += to_string(bit);
    }
     for (int bit : S1col) {
        s1joinedcol += to_string(bit);
    }
    cout<<"row :" << s1joinedrow << ", col :"<< s1joinedcol<<endl;;



    string hexofS1row = binaryToHex(s1joinedrow);
    int s1rowint = hexToInt(hexofS1row);
  

    string hexofS1col = binaryToHex(s1joinedcol);
    int s1colint = hexToInt(hexofS1col);
   

    int s0_answer = S0_table[s0rowint][s0colint];
    int s1_answer = S1_table[s1rowint][s1colint];


    string s0_binary = intToBinaryString(s0_answer);
    string s1_binary = intToBinaryString(s1_answer);

    cout << "S0 Output (binary): " << s0_binary << endl;
    cout << "S1 Output (binary): " << s1_binary << endl;

    string combined_binary = s0_binary + s1_binary;

    vector<int> combined_vector;

for (char bit : combined_binary) {
    combined_vector.push_back(bit - '0');  // Convert char to int and add to vector
}
vector<int> P4_bit(4);
for (int i = 0; i < 4; ++i) {
        P4_bit[i] = combined_vector[P4[i] - 1];  
    }

 cout << "p4_bit: ";
 for (auto bit : P4_bit) cout << bit << " ";
    cout<<endl;


vector<int> XOR_result2(4); 
for (int i = 0; i < 4; ++i) {
    XOR_result2[i] = P4_bit[i] ^ combined_vector[i] ^ left_half[i];  // XOR corresponding bits
}






vector<int> final_answer;

final_answer.insert(final_answer.end(), XOR_result2.begin(), XOR_result2.end());
final_answer.insert(final_answer.end(), right_half.begin(), right_half.end());

cout << "XOR of IP,SOS1 and P4: ";
 for (auto bit : final_answer) cout << bit << " ";

    cout<<endl<<endl;


vector<int> shifted_answer;
shifted_answer.insert(shifted_answer.end(), right_half.begin(), right_half.end());
shifted_answer.insert(shifted_answer.end(), XOR_result2.begin(), XOR_result2.end());


cout << "final_answer: ";
 for (auto bit : shifted_answer) cout << bit << " ";

    cout<<endl;




return shifted_answer;
   
}


int main (){

vector<int> P10 = {5,3,8,9,10,1,2,4,7,6};
vector<int> P8 = {4,5,2,1,6,7,8,3};
vector<int> P4 = {2,3,1,1};
vector<int> IP = {2,3,5,6,7,1,4,8};
vector<int> EP = {4,3,2,1,4,2,1,3};

char answer;
cout << "do you want to provide you own table? Y/N : ";
cin >> answer;

if (answer == 'N'||answer == 'n')
{

}else if(answer == 'Y' || answer == 'y'){
vector<int> P10= input_vector(10,"P10");
vector<int> P8= input_vector(10,"P8"); ;
vector<int> P4= input_vector(4,"P4");;
vector<int> IP= input_vector(8,"IP");;
vector<int> EP= input_vector(8,"EP");;    
}else{
return 0;
}





vector<int> key (10);
char answer2;
cout << "PROVIDE USER INPUT Y/N? : ";
cin >> answer2;

if (answer2 == 'N'||answer2 == 'n'){
key = {1,1,0,0,0,1,1,1,1,0};

}

else if(answer2 == 'Y' || answer2 == 'y'){
cout << "Enter 10 bit Key : ";
for (int i = 0; i < 10; i++)
{
    cout << "enter the "<< i+1 << " bir for key: ";
    cin >> key[i];
    system("CLS");
} 
   
}
else
{
return 0;
}

vector<int> PT(8);

char answer3;
cout << "do you want to provide you own table? Y/N (Default: 1,1,1,0,1,1,0,1) : ";
cin >> answer3;

if (answer3 == 'N'||answer3 == 'n'){
 PT ={1,1,1,0,1,1,0,1};

}
else if(answer3 == 'Y' || answer3 == 'y'){
cout << "Enter 8 bit Plain Text : ";
for (int i = 0; i < 8; i++)
{
    cout << "enter the "<< i+1 << " bir for key: ";
    cin >> PT[i];
    system("CLS");
}}
else
{
return 0;
}

cout<<"\n\n| ---- Round 1 ---- |\n";



display_vector_table(P10, "P10");
display_vector_table(P8, "P8");
display_vector_table(P4, "P4");
display_vector_table(IP, "IP");
display_vector_table(EP, "EP");



vector<int> K1(8), K2(8);

Generate_key(key, P10, P8, K1, K2);


vector<int> answer_bit = IP_EP_STEP(PT, IP, EP, P4, K1);
cout<<"\n\n| ---- Round 1 ---- |\n";


cout<<"\n\n| ---- Round 2 ---- |\n\n";

vector<int> answer_bit2 = IP_EP_STEP(answer_bit, IP, EP, P4, K2);





return 0;
}
};