#include <iostream>
#include <string>
#include <map>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

using Dict = multimap<string, string>;

int main(int argc, char *argv[]){
    path p{"ftp/"};

    Dict Bank;

    if (exists(p)) {

        directory_iterator it{p};

        for (; it != directory_iterator{}; it++) {
            if (is_directory(*it)) {
                directory_iterator it1{*it};
                path kek = (*it);
                for (; it1 != directory_iterator{}; it1++)
                    if (is_regular_file(*it1)) {
                            path lol = (*it1);
                            if ((lol.extension() == ".txt") && (lol.filename().string().find(".old.") == string::npos) && (lol.filename().string() != "readme.txt")) {
                                cout << kek.filename().string() << " " << lol.filename().string() << endl;
                                Bank.emplace(lol.filename().string().substr(8,8), lol.filename().string().substr(17, 8));
                            }
                    }
            }
        }
        cout << "Enter the number of bank account: " << endl;
        string acc;
        cin >> acc;
        cout<< "account: " << acc <<" files: " << Bank.count(acc) << endl;
    }
}
