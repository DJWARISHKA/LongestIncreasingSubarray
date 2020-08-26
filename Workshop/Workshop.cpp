#include <iostream>
#include <list>
#include <iterator>
using namespace std;

enum Production {
	Table = 1,
	Chair = 2,
	Door = 3
};

class Workshop {
private:int Boards, Sawdust, Trimmings;
		list<Production> ProductionList;
public: Workshop() {
	Boards = Sawdust = Trimmings = 0;
}
		Workshop(int boards)
		{
			Boards = boards;
			Sawdust = Trimmings = 0;
		}
		~Workshop() {
			ProductionList.clear();
		}
		void AddProduct(Production product)
		{
			ProductionList.push_back(product);
		}
		void StartWorking();
		friend ostream& operator<<(ostream& out, const Workshop& v);
private: void MakeTable();
		 void MakeChair();
		 void MakeDoor();
};
ostream& operator<<(ostream& out, const Workshop& ws)
{
	out << ws.Boards << " ";
	out << ws.Sawdust << " ";
	out << ws.Trimmings;
	return out;
}
void Workshop::StartWorking()
{
	list <Production>::iterator it;
	for (it = ProductionList.begin(); it != ProductionList.end(); ++it) {
		if (Boards < 3 && Sawdust < 5 && Trimmings < 10) return;
		switch (*it)
		{
		case Production::Table:
			MakeTable();
			break;
		case Production::Chair:
			MakeChair();
			break;
		case Production::Door:
			MakeDoor();
			break;
		default:
			break;
		}
	}
}

void Workshop::MakeTable()
{
	if (Sawdust < 10) {
		if (Boards < 5) return;
		Boards -= 5;
		Sawdust++;
		Sawdust++;
		Trimmings++;
	}
	else Sawdust -= 10;
}
void Workshop::MakeChair()
{
	if (Sawdust < 5) {
		if (Boards < 3) return;
		Boards -= 3;
		Trimmings++;
		Trimmings++;
	}
	else Sawdust -= 5;
}
void Workshop::MakeDoor()
{
	if (Trimmings < 10) {
		if (Boards < 4) return;
		Boards -= 4;
		Sawdust++;
	}
	else Trimmings -= 10;
}
int main()
{
	int boards;
	cin >> boards;
	Workshop workshop(boards);
	int product;
	cin >> product;
	while (product > 0)
	{
		workshop.AddProduct((Production)product);
		cin >> product;
	}
	workshop.StartWorking();
	cout << workshop;
	return 0;
}