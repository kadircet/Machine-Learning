#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <locale>
using namespace std;

#define __DEBUG 1

const int K=4;
const double PF=0.553;
map<string, int> dictF, dictC, dict;

void toLower(string& x)
{
	for(int i=0;i<x.length();i++)
		x[i] = tolower(x[i]);
}

int main()
{
	ifstream fruit("apple-fruit.txt");
	ifstream compa("apple-computers.txt");
	string input;
	unsigned long long int tW=0;
	while(fruit.good())
	{
		fruit >> input;
		toLower(input);
		dictF[input]++;
		dict[input]++;
		tW++;
	}
	while(compa.good())
	{
		compa >> input;
		toLower(input);
		dictC[input]++;
		dict[input]++;
		tW++;
	}
	fruit.close();
	compa.close();
	
	vector<double> resultf, resultc;
	vector<string> lines;
	double pf=1, pn=1, p;
	int N;
	cin >> N;
	getline(cin, input);
	for(int i=0; i<N; i++)
	{
		getline(cin, input);
		lines.push_back(input);
	}
	
	for(int i=0; i<N; i++)
	{
		input = lines[i];
		istringstream line(input);
		string word;
		while(line.good())
		{
			line >> word;
			toLower(word);
			p = 1.*(dictF[word]+K)/(tW+K*dict.size());
			if(abs(p-0.5)<=0.05)
				continue;
			p*=PF;
			pf *= p*10;
			pn *= (1-p);
		}
		resultf.push_back(pf/(pf+pn));
		pf=pn=1;
	}

	for(int i=0; i<N; i++)
	{
		input = lines[i];
		istringstream line(input);
		string word;
		while(line.good())
		{
			line >> word;
			toLower(word);
			p = 1.*(dictC[word]+K)/(tW+K*dict.size());
			if(abs(p-0.5)<=0.05)
				continue;
			p*=1-PF;
			pf *= p*10;
			pn *= (1-p);
		}
		resultc.push_back(pf/(pf+pn));
		pf=pn=1;
	}

	for(int i=0;i<N;i++)
	{
		if(resultf[i]>resultc[i])
		{
			cout << "fruit";
			#if __DEBUG == 1
				cout << '(' << resultf[i]/(resultf[i]+resultc[i]) << ')';
			#endif
			cout << endl;
		}
		else
		{
			cout << "computer-company";
			#if __DEBUG==1
				cout << '(' << resultc[i]/(resultf[i]+resultc[i]) << ')';
			#endif
			cout << endl;
		}
	}
	return 0;
}

