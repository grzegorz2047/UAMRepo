#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

map<char, std::string> plChar;

void loadPolChar(){
	plChar['•'] = "\\uc1\\u260*\\'A";
	plChar['π'] = "\\uc1\\u261*\\'a";
	plChar['∆'] = "\\uc1\\u262*\\'C";
	plChar['Ê'] = "\\uc1\\u263*\\'c";
	plChar[' '] = "\\uc1\\u264*\\'E";
	plChar['Í'] = "\\uc1\\u265*\\'e";
	plChar['£'] = "\\uc1\\u266*\\'L";
	plChar['≥'] = "\\uc1\\u267*\\'l";
	plChar['—'] = "\\uc1\\u268*\\'N";
	plChar['Ò'] = "\\uc1\\u269*\\'n";
	plChar['”'] = "\\uc1\\u270*\\'O";
	plChar['Û'] = "\\uc1\\u271*\\'o";
	plChar['å'] = "\\uc1\\u272*\\'S";
	plChar['ú'] = "\\uc1\\u273*\\'s";
	plChar['è'] = "\\uc1\\u274*\\'Z";
	plChar['ü'] = "\\uc1\\u275*\\'z";
	plChar['Ø'] = "\\uc1\\u276*\\'Z";
	plChar['ø'] = "\\uc1\\u277*\\'z";
}

std::string convertPolishChar(std::string word) {
	string newString = "";
	for(int i = 0; i < word.length(); i++) {
		if(plChar.find( word[i] ) != plChar.end()) {
			newString.append(plChar[word[i]]);
		}else{
			string s(1, word[i]);
			newString.append(s);
		}
	}
	//for( map<char, string>::iterator ii=.begin(); ii!=Employees.end(); ++ii) {
    //   cout << (*ii).first << ": " << (*ii).second << endl;
	//}
	return newString;
}
int main() {

	setlocale(LC_ALL,"");
	loadPolChar();	

	ifstream infile("osoby.txt", ifstream::in);
	//sprawdzamy, czy plik1.txt siÍ otworzy≥
	
	if(!infile.is_open()) {
		cerr << "Unable to open osoby.txt" << endl;
		return 1;
	}
	
	ofstream outfile("out.rtf", ofstream::out);
	//sprawdzamy, czy plik2.txt siÍ otworzy≥
	
	if(!outfile.is_open()) {
		cerr << "Unable to open plik2.rtf" << endl;
		return 1;
	}
	
	//w tej zmiennej bÍdziemy przechowywali linie
	//odczytane z plik1.txt
	string line;
	//wczytujemy dane z plik1.txt
	int index = 0;
	outfile << "{\\rtf1\\ansi\\ansicpg1250\\deff0" << endl;
	outfile << "{\\colortbl;\\red0\\green0\\blue0;\\red255\\green0\\blue0;\\red0\\green255\\blue0;}";
	outfile << "{\\fonttbl{\\f0\\froman Times;}{\\f1\\fswiss Arial;}{\\f2\\fmodern Courier New;}}" << endl;
	outfile << "\\trowd \\trgaph180" << endl;
	outfile << "\\cellx4000\\cellx8000" << endl;
	//outfile << "\\pard\\intbl 1." << endl;
	//outfile << "1.wawd \\cell" << endl;
	//outfile << "\\pard\\intbl 2.\\cell" << endl;
	//outfile <<  "\\row" << endl;

	while(getline(infile, line)) {
		//przerzuc linie do 2 pliku
		//outfile << line << endl;
		//wypisujemy odczytanπ liniÍ na standardowe wyjúcie
		//cout << line << endl;
		if( index == 2){
			outfile <<  "\\row" << endl;
			
			outfile << "\\trowd \\trgaph180" << endl;
			outfile << "\\cellx4000\\cellx8000" << endl;
			index = 1;
		}else{
			index++;
		}
		outfile << "\\pard\\intbl " << endl;
	    vector<string> data = split(line, ';');
		outfile << "\\f1 \\cf2 \\b \\qc \\i{" << data[0]<<"}" <<  endl;
		outfile << "\\par \\pard \\i0 " << endl;
		outfile << "\\cf1" << endl;
		outfile << "Urodziny: " << data[1] << ", ";
		outfile << "P≥eÊ: " << data[2] << endl;
		outfile << "\\par" << endl;
		outfile << "Wzrost: " << data[3] << " m" << " " << endl;
		outfile << "\\par" << endl;
		outfile << "E-mail: " << " \\par " 
		<< "\\cf3 {\\field{\\*\\fldinst{HYPERLINK \\mailto:" << data[4] << "\"}}{\\fldrslt{" << data[4] << " }}}" << endl;
		outfile << "\\par \\cf1 " << endl;
		outfile << " \\ql Telefony: " << endl;
		outfile << "\\par" << endl;

		for(int i = 5; i < data.size(); i++) { 
			vector<string> phoneNumbers = split(data[i], ',');
			//cout <<"Ilosc numerow: "<< phoneNumbers.size();
			for(int j = 0; j < phoneNumbers.size(); j ++){
				vector<string> number = split(phoneNumbers[j], ':');
				outfile << "\\qr \\f0 \\b " << number[0] << ": \\b0 " << number[1] << endl;
				outfile << "\\par" << endl;

			}
			//cout << phoneNumbers[0] << ": " << phoneNumbers[1] << endl;
		}
	    outfile << "\\cell " << endl;

	}

	outfile << "}";
	
	cin.get();
	infile.close();
	outfile.close();
	return 0;
}
