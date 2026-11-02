#include "fleet.h"
#include <string>
#include <vector>

int main() {

    int number_of_planes = 9;

	Fleet *fleet = new Fleet();
	std::vector<Aeroplane*> plane_fleet = fleet->instantiate_fleet(number_of_planes);
	fleet->print_fleet_data(plane_fleet);
	
	// Limpeza de memória dos ponteiros
	for(Aeroplane* plane : plane_fleet) {
	    delete plane;
	}
	delete fleet;
}
