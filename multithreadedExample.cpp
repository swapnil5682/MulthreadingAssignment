#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

mutex dataMutex;

void processData(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
	sleep(1);
        cerr << "\nError opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        {
            lock_guard<std::mutex> lock(dataMutex);
            cout << "\nThread ID " << this_thread::get_id() << ": " << line << endl;
        }
    }

    file.close();
}

int main() {
    int numFiles;
    cout << "Enter the number of files: ";
    cin >> numFiles;

    vector<string> filenames;
    cout << "Enter the Text file names separated by spaces(don't add extension): ";
    for (int i = 0; i < numFiles; ++i) {
        string filename;
        cin >> filename;
        filenames.push_back(filename + ".txt");
    }
    vector<thread> threads;

    for (const auto& filename : filenames) {
        threads.emplace_back(processData, filename);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}

