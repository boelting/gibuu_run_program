#include "Utility.hpp"

namespace util{

	string ZeroPadding(int i, int n_zero){
		string temp = to_string(i); // c++11
		return string(n_zero - temp.length(), '0') + temp;
	}

	string GetEnv(string name){
		if( !getenv(name.data()) ){
			cout << name <<" is not set, please enter manually: ";
			string in;
			cin >> in;
			return in;
		}
		else{
			return (string) getenv(name.data());
		}
	}

	string GetExecPath(bool withName){
		std::vector<char> buf(400);
		ssize_t len;
		do
		{
			buf.resize(buf.size() + 100);
			len = ::readlink("/proc/self/exe", &(buf[0]), buf.size());
		} while (buf.size() == len);

		if (len > 0)
		{
			buf[len] = '\0';
			string temp = string(&(buf[0]));
			if(! withName){
				size_t npos = temp.find_last_of('/');
				return temp.substr(0, npos);
			}
			else{
				return temp;
			}
		}
		exit(1);
	}

	string GetHomePath(){        
		return ("/home/" + (string) getenv("USER") );
	}

	string FormatInputPath(string in){
		size_t npos1 = 0;
		size_t npos2 = 0;
		
		if(in[in.length()-1] != '/') in+="/";
		
		while(npos1 != string::npos){
			npos1 = in.find('$', npos1);
			if(npos1 != string::npos){
				  npos2 = in.find('/', npos1);
				in = in.substr(0, npos1) +  (string) getenv(in.substr(npos1+1, npos2-npos1-1).c_str()) + in.substr(npos2);
			}
		}

		if(in[0] == '.'){
			return (GetExecPath() + in.substr(1));
		}
		else if(in[0] == '~'){
			return (GetHomePath() + in.substr(1));
		}
		return in;
		
	}


	void CreateDir(string Path, bool ThrowError){
		struct stat st;
		if(stat(Path.c_str(),&st) == 0){
			if(!ThrowError){
				return;
			}
			else{
				cout << "Error: Something with name " << Path << " exists" <<endl;
				exit(2);
			}
		}
		else mkdir(Path.c_str(), 0755);
	}
	
	void ShowProgressBar(float progress){
		int pro = (int) (progress+5)/10;
		cout << "|";
		if( pro == 0 ) cout << ">";
		else cout << " ";
		for( int i = 1; i <= 5; i++){
			if( pro == i ) cout << "=>";
			else cout << "= ";
		}
		cout << "\t" << setw(6) << to_string_with_precision(progress,2) << "\%\t";
		for( int i = 5; i <= 10; i++){
			if( pro == i ) cout << "=>";
			else cout << "= ";
		}
		cout << "|" << endl;
	}
}
