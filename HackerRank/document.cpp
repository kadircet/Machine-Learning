#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

const int K=1;

void toLower(string& x)
{
	for(int i=0;i<x.length();i++)
		x[i] = tolower(x[i]);
}

map<string, int> count[9];

int main()
{
	int n,d;
	string input, word;
	ifstream data("trainingdata.txt");
	data >> n;
	for(int i=0;i<n;i++)
	{
		data >> d;
		d--;
		getline(data, input);
		istringstream line(input);
		while(line.good())
		{
			line >> word;
			count[d][word]++;
			count[8][word]++;
		}
	}
	cout << count[8].size() << endl;
	data.close();
	
	double point[8];
	cin >> n;
	getline(cin, input);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<8;j++)
			point[j]=1;
		getline(cin, input);
		istringstream line(input);
		while(line.good())
		{
			line >> word;
			toLower(word);
			for(int j=0;j<8;j++)
			{
				double p=(1.*count[j][word]+K)/(count[8][word]+K*count[8].size());
				if(abs(p-0.5)>=0.45)
					point[j]*=p;
			}
		}
		double eta=0;
		for(int j=0;j<8;j++)
			eta+= point[j];
		for(int j=0;j<8;j++)
			point[j] /= eta;
		for(int j=0;j<8;j++)
			cout << point[j] << ' ';
		cout << endl;
	}
	return 0;
}

