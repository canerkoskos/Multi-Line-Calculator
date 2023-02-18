// Caner KOSKOS
// 1306180059
// Date: 17.01.2021
// Development Environment: Visual Studio2019

#include<string>
#include<fstream>
#include <iostream>
#include <vector>


using namespace std;

/*double calculator(string s) {

    

}*/

string removeSpaces(string first) {
    string last;
    for (int i = 0; i < first.length(); i++) {
        if (first[i] != ' ') {
            last += first[i];
        }
    }

    return last;
}

int main()
{
    ifstream file;
    file.open("Challange4.inp");
    string s,ws;
    vector<string>varName;
    vector<string>islem;
    vector<double>varValue;
    int line = 0, a, o=0;

    while (getline(file, s)) {
        line++;
        ws = removeSpaces(s);
        
        int equ = ws.find("=");
        int out = ws.find("OUT");
        
        if (equ != -1) {
            varName.push_back(ws.substr(0, equ));
            string temp = ws.substr(equ+1);
            for (int i = 0; i < varName.size(); i++) {

                a = temp.find(varName[i]);
                if (a != -1) {
                    break;
                }
                
            }
            if (a != -1) {
                islem.push_back(temp);
            }
            else {
                varValue.push_back(stod(temp));
            }
            
        }
        if (out != -1) {
            for (int i = 0; i < varName.size(); i++) {
                if (varName[i] == ws.substr(out + 3)) {
                    o = i;
                    break;
                }

            }
        }      
    }
    file.close();
    vector<int>add;
    vector<int>sub;
    vector<int>mult;
    vector<int>div;
    vector<int>open;
    vector<int>close;

    vector<int>varLoc;
    vector<int>varSize;
    double first=0,second=0;
    for (int a = 0; a < islem.size(); a++) {
        for (int i = 0; i < islem[0].size(); i++) {

            if (islem[0][i] == '+') {
                add.push_back(i);

                for (int j = 0; j < varName.size() - 1; j++) {
                    if (varName[j] == islem[0].substr(0, i)) {
                        first = varValue[j];

                    }
                    if (varName[j] == islem[0].substr(i + 1)) {
                        second = varValue[j];
                    }

                }
                varValue.push_back(first + second);
                
                break;
            }
            else if (islem[0][i] == '-') {
                sub.push_back(i);
                for (int j = 0; j < varName.size() - 1; j++) {
                    if (varName[j] == islem[0].substr(0, i)) {
                        first = varValue[j];

                    }
                    if (varName[j] == islem[0].substr(i + 1)) {
                        second = varValue[j];
                    }

                }
                varValue.push_back(first - second);
                
                break;
            }
            else if (islem[0][i] == '*') {
                mult.push_back(i);
                for (int j = 0; j < varName.size() - 1; j++) {
                    if (varName[j] == islem[0].substr(0, i)) {
                        first = varValue[j];

                    }
                    if (varName[j] == islem[0].substr(i + 1)) {
                        second = varValue[j];
                    }

                }
                varValue.push_back(first * second);
                
                break;
            }
            else if (islem[0][i] == '/') {
                div.push_back(i);
                for (int j = 0; j < varName.size() - 1; j++) {
                    if (varName[j] == islem[0].substr(0, i)) {
                        first = varValue[j];

                    }
                    if (varName[j] == islem[0].substr(i + 1)) {
                        second = varValue[j];
                    }

                }
                varValue.push_back(first / second);
                
                break;
            }
            else if (islem[0][i] == '(') {
                open.push_back(i);
            }
            else if (islem[0][i] == ')') {
                close.push_back(i);
            }

        }
    }
    for(int i=0;i<varName.size();i++){
        varLoc.push_back(islem[0].find(varName[i]));
        for(int j=0;j<varName[i].size();j++){
        }
    }

    
    ofstream outfile;
    outfile.open("Challange4.out");
    outfile << varValue[o] << endl;
    outfile.close();

}