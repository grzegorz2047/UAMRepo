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

void writeStyle(ofstream& out, bool separate){
	if(!separate) out << "<style>" << endl;
	out << "body { " << endl << "background-color: #CCCCC;" <<endl << "color: green;"<< endl << "}" << endl;
	out << ".header { " << endl << "text-align: center; " << endl << "color: red;" << "font-style: italic;" << endl << "}" << endl; 
	out << ".field { " << endl  << "font-weight: bold;" << endl << "}" << endl; 
	out << ".phones { " << endl  << "text-align: right;" << endl << "font-family: \"Arial\", Times, serif;"  << endl << "}" << endl; 
	if(!separate) out << "</style>" << endl;
}
void writeHeader(ofstream& out, bool separate){
	out << "<head>" << endl;
	out << "<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\">" << endl;
	//out << "<meta http-equiv=\"Content-type\" content=\"text/html; charset=ISO-8859-2\" />" << endl;
	if(separate) out << "<link rel=\"stylesheet\" type=\"text/css\" href=\"out.css\">" << endl;
	out << "</head>" <<endl;
}

map<char, std::string> plChar;

void loadPolChar(){
	plChar['•'] = "&#260";
	plChar['π'] = "&#261";
	plChar['∆'] = "&#262";
	plChar['Ê'] = "&#263";
	plChar[' '] = "&#280";
	plChar['Í'] = "&#281";
	plChar['£'] = "&#321";
	plChar['≥'] = "&#322";
	plChar['—'] = "&#323";
	plChar['Ò'] = "&#324";
	plChar['”'] = "&#242";
	plChar['Û'] = "&#243";
	plChar['å'] = "&#346";
	plChar['ú'] = "&#347";
	plChar['è'] = "&#377";
	plChar['ü'] = "&#378";
	plChar['Ø'] = "&#379";
	plChar['ø'] = "&#380";
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
int main (int argc, char* argv[]){

	setlocale(LC_ALL,"");
		loadPolChar();	
	ifstream infile("osoby.txt", ifstream::in);
	//sprawdzamy, czy plik1.txt siÍ otworzy≥
	
	if(!infile.is_open()) {
		cerr << "Unable to open osoby.txt" << endl;
		return 1;
	}
	
	ofstream outfile("out.html", ofstream::out);
	//sprawdzamy, czy plik2.txt siÍ otworzy≥
	
	if(!outfile.is_open()) {
		cerr << "Unable to open plik2.html" << endl;
		return 1;
	}
	
	//w tej zmiennej bÍdziemy przechowywali linie
	//odczytane z plik1.txt
	string line;
	//wczytujemy dane z plik1.txt
	bool separateCss = false;


	int index = 0;
	//outfile << "\\pard\\intbl 1." << endl;
	//outfile << "1.wawd \\cell" << endl;
	//outfile << "\\pard\\intbl 2.\\cell" << endl;
	//outfile <<  "\\row" << endl;
	outfile << "<!DOCTYPE html>" << endl;
	outfile << "<html>" << endl;
	for(int i = 0; i < argc; i++){
		cout << "Argumenty " << argv[i] <<endl;
		if(argv[i] == "-c"){
			separateCss = true;
		}
	}
	if (separateCss) {
		writeStyle(outfile, false);
	} else{
		cout <<" argument -c!" << endl;
		separateCss = true;
		ofstream cssfile("out.css", ofstream::out);
		if(!cssfile.is_open()) {
			cerr << "Unable to open out.css" << endl;
			return 1;
		}
		writeStyle(cssfile, separateCss);
		cssfile.close();
		
	}
	writeHeader(outfile, separateCss);
	outfile << "<body>" << endl;
	outfile << "<table style=\"width:40%\">" << endl;
	outfile <<  "<tr>" << endl;
	outfile <<  "<br>" << endl;

	while(getline(infile, line)) {
		if( index == 2){
			outfile <<  "</tr>" << endl;
			outfile <<  "<tr>" << endl;
			index = 1;
		}else{
			index++;
		}
		outfile << "<td>" << endl;	
	    vector<string> data = split(line, ';');
		outfile << "<div class='field'>" << endl;
		outfile << "<div class='header'>" << endl;
		outfile  << convertPolishChar(data[0]) <<  endl;
		outfile << "</div>" << endl;
		outfile <<  "<br>" << endl;
		outfile << "Urodziny: " << convertPolishChar(data[1]) << ", ";
		outfile << convertPolishChar("P≥eÊ: ") << convertPolishChar(data[2]) << endl;
		outfile <<  "<br>" << endl;
		outfile << "Wzrost: " << convertPolishChar(data[3]) << " m" << " " << endl;
		outfile << "E-mail: " 
		 <<  "<br>" << endl
		<< "<a href=mailto:" << convertPolishChar(data[4]) <<">" << convertPolishChar(data[4]) << "</a>"<< endl;
		outfile <<  "<br>" << endl;
		outfile << " Telefony: " << endl;
		outfile <<  "<br>" << endl;
		outfile <<  "<div class='phones'>" << endl;
		
		for(int i = 5; i < data.size(); i++) { 
			vector<string> phoneNumbers = split(data[i], ',');
			//cout <<"Ilosc numerow: "<< phoneNumbers.size();
			for(int j = 0; j < phoneNumbers.size(); j ++){
				vector<string> number = split(phoneNumbers[j], ':');
				outfile << convertPolishChar(number[0]) << ": " << convertPolishChar(number[1]) << endl;
				outfile <<  "<br>" << endl;
			}
			//cout << phoneNumbers[0] << ": " << phoneNumbers[1] << endl;
		}
		outfile << "</div>" << endl;
		outfile << "</div>" << endl;
		outfile << "</td>" << endl;	
		
	}
	outfile << " </table> " << endl;
	outfile << "</body>" << endl;
	outfile << "</html>" << endl;

	cin.get();
	infile.close();
	outfile.close();
	return 0;
}
