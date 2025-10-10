#include <iostream>
#include<fstream>
#include<string>

using namespace std;
int main()
{
    std::ifstream file("a.txt");
    if(!file)
    {
        std::cerr<< "Error opening file" <<endl;
        return 1;
    }
    
    std::string line;
    
    while(getline(file,line))
    {
        cout<<line<<endl;
    }
    file.close();
    return 0;

}
