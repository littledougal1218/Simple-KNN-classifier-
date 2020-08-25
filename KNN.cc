#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;

class Point{
	int e[64];

	public:
	
	Point(){}

	~Point(){};

	void adde(int i, int a){
		e[i] = a;
	}

	int gete(int i){
		return e[i];
	}

	void print(){
		for (int i = 0; i < 64; i ++){
			cout << e[i];
			if (i != 63){
				cout << ",";
			}
		}
		cout << endl;
	}

};

Point *data1;
Point *data2;
Point *data3;
Point *data4;
Point *data5;
Point *data6;
Point *data7;
Point *data8;
Point *data9;
Point *data10;
Point *ps[11];

int label1[100];
int label2[100];
int label3[100];
int label4[100];
int label5[100];
int label6[100];
int label7[100];
int label8[100];
int label9[100];
int label10[100];
int *ls[11];


int testlabel[110];


int distances[1000] = {0};
int acc[30];
int count = 0;

Point getp(){
	Point p;
	char c;
	int i = 0;
	int a;
	while (i < 64){
		cin >> c;
		while (c != ','){
			a = a * 10 + c - '0';
			if (cin.peek() == '\n'){
				break;
			}
			if (cin.eof()){
				break;
			}
			cin >> c;
		}	
		p.adde(i, a);
		a = 0;
		i ++;
	}
	if (count == 0){
		count ++;
	}
	return p;
}

Point* geta(){
	Point *ps = new Point[100];
	for (int i = 0; i < 100; i ++){
		ps[i] = getp();
	}
	return ps;
}

void printp(Point* ps){
	for (int i = 0; i < 100; i ++){
		Point p = ps[i];
		p.print();
	}
}

void getl(){
	int a = 0;
	char c;
	for (int j = 0; j < 100; j ++){
		cin >> c;
		a = c - '0';
		label1[j] = a;
	}
	for (int j = 0; j < 100; j ++){
		cin >> c;
		a = c - '0';
		label2[j] = a;
	}
	for (int j = 0; j < 100; j ++){
		cin >> c;
		a = c - '0';
		label3[j] = a;
	}
	for (int j = 0; j < 100; j ++){
		cin >> c;
		a = c - '0';
		label4[j] = a;
	}
	for (int j = 0; j < 100; j ++){
		cin >> c;
		a = c - '0';
		label5[j] = a;
	}
	for (int j = 0; j < 100; j ++){
		cin >> c;
		a = c - '0';
		label6[j] = a;
	}
	for (int j = 0; j < 100; j ++){
		cin >> c;
		a = c - '0';
		label7[j] = a;
	}
	for (int j = 0; j < 100; j ++){
		cin >> c;
		a = c - '0';
		label8[j] = a;
	}
	for (int j = 0; j < 100; j ++){
		cin >> c;
		a = c - '0';
		label9[j] = a;
	}
	for (int j = 0; j < 100; j ++){
		cin >> c;
		a = c - '0';
		label10[j] = a;
	}
}

int eud(Point p1, Point p2){
	int sum = 0;
	int a = 0;
	int d = 0;
	for (int i = 0; i < 64; i ++){
		d = p1.gete(i) - p2.gete(i);
		a = d * d;
		sum += a;
	}
	sum = sqrt(sum);
	return sum;
}

void getalld(int a, int b, Point p){
	for (int i = 0; i < 10; i ++){
		if (i != a){
			for (int j = 0; j < 100; j ++){
				Point p2 = ps[i][j];
				int index = i * 100 + j;
				distances[index] = eud(p, p2);
			}
		}
	}

}

int templ[110];
int minlabel[30];

int findmode(){
	int c1;
	int c2;
	for (int i = 0; i < 30; i ++){
		if (minlabel[i] == 0){
			break;
		}
		if (minlabel[i] == 5){
			c1 ++;
		}
		else{
			c2 ++;
		}
	}
	if (c1 > c2){
		return 5;
	}
	return 6;
}

void findl(int a, int b, int k){
	for (int i = 0; i < k; i ++){
		int min = 999;
		int r = 0;
		for (int j = 0; j < 1000; j ++){
			if (j/100 != a){
				if (distances[j] < min){
					min = distances[j];
					r = j;
				}
			}
		}
		distances[r] = 999;
		minlabel[i] = ls[r/100][r%100];
		min = 999;
	}
	templ[b] = findmode();
	for (int i = 0; i < 30; i ++){
		minlabel[i] = 0;
	}
}

float allacc[30];
int tempacc[10];

float findacc(int a){
	if (a == 10){
		float acc = 0;
		for (int i = 0; i < 110; i ++){
			if (templ[i] == testlabel[i]){
				acc += 1;
			}
		}
		return acc/1.1;
	}
	int acc = 0;
	for (int i = 0; i < 100; i ++){
		if (templ[i] == ls[a][i]){
			acc += 1;
		}
	}
	return acc;
}

float findave(){
	float sum = 0;
	for (int i = 0; i < 10; i ++){
		sum += tempacc[i];
	}
	sum = sum/10;
	return sum;
}

int main(){
	data1 = geta();
	data2 = geta();
	data3 = geta();
	data4 = geta();
	data5 = geta();
	data6 = geta();
	data7 = geta();
	data8 = geta();
	data9 = geta();
	data10 = geta();
	
	ps[1] = data2;
	ps[2] = data3;
	ps[3] = data4;
	ps[4] = data5;
	ps[5] = data6;
	ps[6] = data7;
	ps[7] = data8;
	ps[8] = data9;
	ps[9] = data10;
	ps[0] = data1;

	ls[0] = label1; 
	ls[1] = label2; 
	ls[2] = label3; 
	ls[3] = label4; 
	ls[4] = label5; 
	ls[5] = label6; 
	ls[6] = label7; 
	ls[7] = label8; 
	ls[8] = label9; 
	ls[9] = label10; 

	getl();

	Point testdata[110];

	for (int i = 0; i < 110; i ++){
		testdata[i] = getp();
	}


	int a = 0;
	char c;
	for (int j = 0; j < 110; j ++){
		cin >> c;
		a = c - '0';
		testlabel[j] = a;
	}

	float maxacc = 0;
	int maxk = 0;

	for (int k = 1; k <31; k ++){
		for (int i = 0; i < 10; i ++){
			for (int j = 0; j < 100; j ++){
				Point p = ps[i][j];
				getalld(i, j, p);
				findl(i, j, k);
			}	
			tempacc[i] = findacc(i);
		}
		for (int m = 0; m < 1000; m ++){
			distances[m] = 0;
		}
		allacc[k] = findave();
		for (int i = 0; i < 10; i ++){
			tempacc[i] = 0;
		}
		cout << k << " " << allacc[k] << endl;
		if (allacc[k] > maxacc){
			maxacc = allacc[k];
			maxk = k;
		}
	}

	cout << maxk << endl;
	cout << maxacc << endl;

	for (int i = 0; i < 100; i ++){
		Point p = testdata[i];
		getalld(10, i, p);
		findl(10, i, 21);
	}	
	float tacc= findacc(10);	
	cout << tacc << endl;
}