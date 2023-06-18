#include<iostream>
#include<fstream>
#include<vector>

class Reservoir
{
private:
	std::string _Name;
	std::string _Type;
	double _Volume = 0;

public:
	Reservoir(std::string name) {
		this->_Name = name;
		this->_Type = "Like ";
		this->_Volume = 0;
	}
	Reservoir(std::string name, std::string type):Reservoir(name){
		this->_Type = type;
	}
	Reservoir(std::string name, std::string type, double volume) :Reservoir(name, type) {
		this->_Volume = volume;
	}

	double VolumReservoir(double length, double width, double depth) {
		_Volume = length * width * depth;
	}

	double SurfaceArea(double length, double width) {
		return (length * width);

	}

	void ShowData() {
		std::cout << "Name:   " << _Name << '\n';
		std::cout << "Type:   " << _Type << '\n';
		std::cout << "Volume: " << _Volume << '\n';

	}
	std::string GetDataName() {
		return _Name;
	

	}

	~Reservoir()
	{
		
	}

};

class Reservoirs {
private:
	std::vector< Reservoir*> ObjectReservoirs;

public:
	Reservoirs(Reservoir* reservoir) {
		ObjectReservoirs.push_back(reservoir);
	}
	void AddReservoir(Reservoir* reservoir) {
		ObjectReservoirs.push_back(reservoir);
	}
	void ShowRes() {
		for (auto it = ObjectReservoirs.begin(); it != ObjectReservoirs.end(); ++it)
			(*it)->ShowData();

	}
	void OutRes() {
		for (auto it = ObjectReservoirs.begin(); it != ObjectReservoirs.end(); ++it)
			(*it)->GetDataName();

	}

};

class OutputReservoir {
public:
	void Output(Reservoirs* reservoirs) {
		std::ofstream fout;
		fout.open("Reservoirs.txt");
		if (!fout.is_open())
			std::cout << "Error";
		else
			

		fout.close();
	}
	



};






int main() {

	Reservoir* res1 = new Reservoir("Nana", "ozero");
	Reservoirs ress(res1);
	Reservoir* res2 = new Reservoir("Nana");
	ress.AddReservoir(res2);

	ress.ShowRes();



	return 0;
}