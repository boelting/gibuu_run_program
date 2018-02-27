#include "TRint.h"

#include "ConvertDoHIA.hpp"
#include "GiBUUtrack.hpp"

using namespace std;

/* INFO to understand DoHIA.dat file format:
Column No.:          Quantity:
1                    GiBUU internal particle index (see attached pdf-files)
2                    particle charge
3                    GiBUU internal event number (not important)
4,5                  indices of parent's particles  (not important)
6                    particle mass (GeV)
7                    index which tells whether a particle is free or bound
                     (1 --- free,  0 --- bound)
8,9,10               v_x, v_y, v_z compoments of position vector (production vertex)
11,12,13             p_x, p_y, p_z compoments of momentum (GeV/c)
                     (z-axis along beam direction)
14                   event number
15                   number of subsequent GiBUU run (not important)
16                   impact parameter b (fm)

All the particles different from nucleons are stored. A particle is considered
as a free one if it is separated by at least 3 fm distance from every other particle
of the event. Otherwise, the particle is considered to be the bound one.
The calculations are done in the lab. frame up to the maximum time 200 fm/c
starting from the time when the antiproton had z= -(nuclear radius) - 5 fm
with the nuclear centre being at z=0.
*/

int main(int argc, char* argv[]){
	if(argc!=7){
		cout << "Invalid number of arguments: requires 6: path_data, path_pdg_table, job_max, run_div, number_runs, jobID" << endl;
		return 1;
	}
	string path = (string) argv[1];
	string pathPDG = (string) argv[2];
	int job_max = stoi(((string) argv[3])); // c++11
	int run_div = stoi(((string) argv[4])); // c++11
	int number_runs = stoi(((string) argv[5])); // c++11
	int jobID = stoi(((string) argv[6])); // c++11
	
	TRint *gROOT = new TRint("GiBUU_to_PDG ", &argc, argv, 0, 0, true);
	
	ConvertDoHIA Converter = ConvertDoHIA(path, pathPDG, job_max, run_div, number_runs, jobID, "/data/work/himspecf/schupp/data/GiBuu/carbon_michael");
	return 0;
}
