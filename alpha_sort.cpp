#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ppl{
    vector<string>names;
    vector<int>ages;
};

void insert_data(ppl& p, int n);
void alph_sort(ppl& p);
void data(ppl& p);

int main() {
    cout << "no. of people: ";
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "INVALID INPUT" << endl;
        return 1;
    }

    ppl list;

    insert_data(list, n);
    cout << "\ninserting data...\nData inserted\n" << endl;
    data(list);

    return 0;
}

void insert_data(ppl& p, int n) {
    string a_name;
    int an_age;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cout << "Name: ";
        getline(cin, a_name);
        p.names.push_back(a_name);
        cout << "Age: ";
        cin >> an_age;
        p.ages.push_back(an_age);
        
        if (i != n - 1) {
            cout << "------------------------" << endl;
        }
    }

}
void alph_sort(ppl& p) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < p.names.size() - 1; i++) {
            if (p.names[i].compare(p.names[i + 1]) > 0) {
                swap(p.names[i], p.names[i + 1]);
                swap(p.ages[i], p.ages[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}
void data(ppl& p) {
    cout << "Sorting data...\n";
    alph_sort(p);
    cout << "Viewing data...\n\n";
    for (int i = 0; i < p.names.size(); i++) {
        cout << "Name: " << p.names[i] << endl;
        cout << "Age: " << p.ages[i] << endl;
        if (i != p.names.size() - 1) {
            cout << "-------------------------" << endl;
        }
    }
}