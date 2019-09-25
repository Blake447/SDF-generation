#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace::std;

void PrintHeader();
void PrintFooter();
void PrintFunction(string);
void PrintDerivative(string);
void PrintCurvature(string);
void PrintSDF(int);
void PrintBoundFunction(float*, int);
void SortArray(double*, int);

int main()
{
	
	string f = "(x+4.0)*(x-3.0)*(x+7.0)";
	string df = "3.0 * (-1.66667 + 5.33333 * x + x*x)";
	string ddf = "6.0*(2.66667 + x)";

	int SP_SIZE = 5;	

	float sp[] = {-1000.0, -5.6294, -2.666667,  0.296066, 1000.0};

	
	PrintHeader();
	PrintFunction(f);
	PrintDerivative(df);
	PrintCurvature(ddf);
	PrintBoundFunction(sp, SP_SIZE);
	PrintSDF(SP_SIZE);
	PrintFooter();	

	return 0;
}

void PrintSDF(int sp_count)
{
	string tab = "     ";
	cout << "float sdfFunction(vec3 Point, vec3 Center)" << endl;
	cout << "{" << endl;
	cout << tab << "const int SP_COUNT = " << to_string(sp_count) << ";" << endl;
	cout << tab << "float d = 10000.0;" << endl;

	cout << tab << "for (int i = 0; i < SP_COUNT - 1; i++)" << endl;
	cout << tab << "{" << endl;
	cout << tab << tab << "d = min(d, sdfOfBound(Point, Center, GetBoundary(i)));" << endl;
	cout << tab << "}" << endl;
	cout << tab << "return d;" << endl;
	cout << "}" << endl;

}

void PrintFunction(string f)
{
	string tab = "    ";
	cout << "float f(float x)" << endl;
	cout << "{" << endl;

	cout << tab << "return " << f << ";" << endl;
	cout << "}" << endl;

}
void PrintDerivative(string df)
{
	string tab = "    ";
	cout << "float df(float x)" << endl;
	cout << "{" << endl;

	cout << tab << "return " << df << ";" << endl;
	cout << "}" << endl;

}
void PrintBoundFunction(float* sp, int SP_SIZE)
{
	cout << fixed;
	string tab = "    ";
	cout << "vec2 GetBoundary(int i)" << endl;
	cout << "{" << endl;
	for (int i = 0; i < SP_SIZE; i++)
	{
		cout << tab << "float sp" << to_string(i) << " = " << sp[i] << ";" << endl;
	}

	cout << endl;
	
	for (int j = 0; j < SP_SIZE - 1; j++)
	{
		cout << tab << "if (i == " << j << ")" << endl;
		cout << tab <<"{" << endl;
		cout << tab << tab << "return vec2(sp" << to_string(j) << ", sp" << to_string(j+1) << ");" << endl;
		cout << tab << "}" << endl;
	}

	cout << endl;
	cout << tab << "return vec2(0.0, 0.0);" << endl;

	cout << "}" << endl;
}


void PrintCurvature(string ddf)
{
	string tab = "    ";
	cout << "float ddf(float x)" << endl;
	cout << "{" << endl;

	cout << tab << "return " << ddf << ";" << endl;
	cout << "}" << endl;

}

void PrintHeader()
{

	ifstream file_in;
	file_in.open("header.txt");
	string line;


	while (getline(file_in, line))
	{
		cout << line << endl;
	}
	file_in.close();


}


void PrintFooter()
{

	ifstream file_in;
	file_in.open("footer.txt");
	string line;


	while (getline(file_in, line))
	{
		cout << line << endl;
	}
	file_in.close();


}

void SortArray(double* list, int size)
{
	for (int i = 0; i < size; i++)
	{
		double buffer = list[i];
		int index = i;
		for (int j = i; j < size; j++)
		{
			if (list[j] <= buffer)
			{
				buffer = list[j];
				index = j;
			}
		}

		buffer = list[i];
		list[i] = list[index];
		list[index] = buffer;

	}
}
