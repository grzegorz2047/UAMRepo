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

int main() {

	setlocale(LC_ALL,"");	

	ifstream infile("osoby.txt", ifstream::in);
	//sprawdzamy, czy plik1.txt siê otworzy³
	
	if(!infile.is_open()) {
		cerr << "Unable to open osoby.txt" << endl;
		return 1;
	}
	
	ofstream outfile("out.rtf", ofstream::out);
	//sprawdzamy, czy plik2.txt siê otworzy³
	
	if(!outfile.is_open()) {
		cerr << "Unable to open plik2.rtf" << endl;
		return 1;
	}
	
	//w tej zmiennej bêdziemy przechowywali linie
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
		//wypisujemy odczytan¹ liniê na standardowe wyjœcie
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
		outfile << "P³eæ: " << data[2] << endl;
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
