#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

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
	plChar['•'] = "\\k{A}";
	plChar['π'] = "\\k{a}";
	plChar['∆'] = "\\'A";
	plChar['Ê'] = "\\'c";
	plChar[' '] = "\\k{E}";
	plChar['Í'] = "\\k{e}";
	plChar['£'] = "\\L{}";
	plChar['≥'] = "\\l{}";
	plChar['—'] = "\\'N";
	plChar['Ò'] = "\\'n";
	plChar['”'] = "\\'O";
	plChar['Û'] = "\\'o";
	plChar['å'] = "\\'S";
	plChar['ú'] = "\\'s";
	plChar['è'] = "\\'Z";
	plChar['ü'] = "\\'z";
	plChar['Ø'] = "\\.Z";
	plChar['ø'] = "\\.z";
}

std::string convertPolishChar(std::string word) {
	string newString = "";
	for(int i = 0; i < word.length(); i++) {
		if(plChar.find( word[i] ) != plChar.end()) {
			//cout << "Znalazlem " << word[i] << endl;
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
	
	ofstream outfile("out.tex", ofstream::out);
	//sprawdzamy, czy plik2.txt siÍ otworzy≥
	
	if(!outfile.is_open()) {
		cerr << "Unable to open plik2.tex" << endl;
		return 1;
	}
	
	//w tej zmiennej bÍdziemy przechowywali linie
	//odczytane z plik1.txt
	string line;
	//wczytujemy dane z plik1.txt
	int index = 0;
	outfile << "\\documentclass[a4paper,11pt]{article}" << endl;
	outfile << "\\usepackage{polski}";
	outfile << "\\begin{document}" << endl;
	outfile << "\\begin{tabular}{|r|l|} \\hline" << endl;
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
			//outfile << "\\hline" << endl;
			outfile << "\\end{tabular} \\\\" <<endl;
			index = 1;
		}else if(index == 1){
			outfile << "\\end{tabular} \\\\" <<endl;
			outfile << "&" <<endl;
			//outfile << "\\hline" << endl;
			index++;
		}
		outfile << "\\begin{tabular}{l}" << endl;
	    vector<string> data = split(line, ';');
		outfile << "" << convertPolishChar(data[0])<<"\\\\" <<  endl;
		outfile << "Urodziny: " << convertPolishChar(data[1]) << ", ";
		outfile << convertPolishChar("P≥eÊ: ")<< convertPolishChar(data[2]) << endl;
		outfile << "\\\\" << endl;
		outfile << "Wzrost: " << convertPolishChar(data[3]) << " m" << " " << endl;
		outfile << "\\\\" << endl;
		outfile << "E-mail: " << " \\\\ " 
		<< "" << convertPolishChar(data[4]) << "\\\\" << endl;
		outfile << "Telefony: " << endl;
		outfile << "\\\\" << endl;

		for(int i = 5; i < data.size(); i++) { 
			vector<string> phoneNumbers = split(data[i], ',');
			//cout <<"Ilosc numerow: "<< phoneNumbers.size();
			for(int j = 0; j < phoneNumbers.size(); j ++){
				vector<string> number = split(phoneNumbers[j], ':');
				outfile << "" << convertPolishChar(number[0]) << ": " << convertPolishChar(number[1]) << endl;
				outfile << "\\\\" << endl;

			}
			//cout << phoneNumbers[0] << ": " << phoneNumbers[1] << endl;
		}
	}
	outfile << "\\end{tabular}" <<endl;
	outfile << "\\end{document}" <<endl;
	
	cin.get();
	infile.close();
	outfile.close();
	return 0;
}
