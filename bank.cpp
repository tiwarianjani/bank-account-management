#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

struct person {

    string name;
    string ID;
    string address;
    int contact;
    int cash;
};

class Bank {
private:
    vector<person> persons;

public:
    void choice();
    void addPerson();
    void show();
    void update();
    void search();
    void transactions();
    void remove();
};

void Bank::choice() {
    char ch;
    while (true) {
        cout << "\n\nPRESS..!!" << endl;
        cout << "1. Create new account" << endl;
        cout << "2. View customers list" << endl;
        cout << "3. Update information of existing account" << endl;
        cout << "4. Check the details of an existing account" << endl;
        cout << "5. For transactions" << endl;
        cout << "6. Remove existing account" << endl;
        cout << "7. Exit" << endl;
        cin >> ch;

        switch (ch) {
            case '1':
                addPerson();
                break;
            case '2':
                if (persons.empty()) {
                    cout << "No data is entered" << endl;
                } else {
                    show();
                }
                break;
            case '3':
                if (persons.empty()) {
                    cout << "No data is entered" << endl;
                } else {
                    update();
                }
                break;
            case '4':
                if (persons.empty()) {
                    cout << "No data is entered" << endl;
                } else {
                    search();
                }
                break;
            case '5':
                if (persons.empty()) {
                    cout << "No data is entered" << endl;
                } else {
                    transactions();
                }
                break;
            case '6':
                if (persons.empty()) {
                    cout << "No data is entered" << endl;
                } else {
                    remove();
                }
                break;
            case '7':
                exit(0);
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
}

void Bank::addPerson() {
    person newPerson;
    cout << "Enter data of person " << persons.size() + 1 << endl;
    cout << "Enter name: ";
    cin >> newPerson.name;
    cout << "ID: ";
    cin >> newPerson.ID;
    cout << "Address: ";
    cin >> newPerson.address;
    cout << "Contact: ";
    cin >> newPerson.contact;
    cout << "Total Cash: ";
    cin >> newPerson.cash;
    persons.push_back(newPerson);
}

void Bank::show() {
    int count = 1;
    int n=persons.size();
    for (int i=0;i<n;i++) {
    struct person personi=persons[i];
        cout << "Data of person " << count++ << endl;
        cout << "Name: " << personi.name << endl;
        cout << "ID: " << personi.ID << endl;
        cout << "Address: " << personi.address << endl;
        cout << "Contact: " << personi.contact << endl;
        cout << "Cash: " << personi.cash << endl;
    }
}

void Bank::update() {
    string id;
    cout << "Enter ID of the person whose data you want to update: ";
    cin >> id;
vector<person>::iterator it=persons.end();
int n=persons.size();
for (int i=0;i<n;i++)
{
	if(persons[i].ID==id)
	{
		it=persons.begin()+i;
		break;
	}


    if (it != persons.end()) {
        cout << "Previous data:" << endl;
        cout << "Name: " << it->name << endl;
        cout << "ID: " << it->ID << endl;
        cout << "Address: " << it->address << endl;
        cout << "Contact: " << it->contact << endl;
        cout << "Cash: " << it->cash << endl;
        cout << "Enter new data:" << endl;
        cout << "Enter name: ";
        cin >> it->name;
//        cout << "ID: ";
//        cin >> it->ID;
        cout << "Address: ";
        cin >> it->address;
        cout << "Contact: ";
        cin >> it->contact;
        cout << "Total Cash: ";
        cin >> it->cash;
    } else {
        cout << "No such record found" << endl;
    }
}
}

void Bank::search() {
    string id;
    cout << "Enter ID of the person whose data you want to search: ";
    cin >> id;
vector<person>::iterator it=persons.end();
int n=persons.size();
for (int i=0;i<n;i++)
{
	if(persons[i].ID==id)
	{
		it=persons.begin()+i;
		break;
	}
}
    if (it != persons.end()) {
        cout << "Name: " << it->name << endl;
        cout << "ID: " << it->ID << endl;
        cout << "Address: " << it->address << endl;
        cout << "Contact: " << it->contact << endl;
        cout << "Cash: " << it->cash << endl;
    } else {
        cout << "No such record found" << endl;
    }
}

void Bank::transactions() {
    string id;
    cout << "Enter ID of the person for transaction: ";
    cin >> id;
vector<person>::iterator it=persons.end();
int n=persons.size();
for (int i=0;i<n;i++)
{
	if(persons[i].ID==id)
	{
		it=persons.begin()+i;
		break;
	}
}
    if (it != persons.end()) {
        cout << "Name: " << it->name << endl;
        cout << "Address: " << it->address << endl;
        cout << "Contact: " << it->contact << endl;
        cout << "\nExisting Cash: " << it->cash << endl;
        cout << "Press 1 to deposit" << endl;
        cout << "Press 2 to withdraw" << endl;

        char ch;
        cin >> ch;

        switch (ch) {
            case '1':
                cout << "How much cash you want to deposit? ";
                int cash;
                cin >> cash;
                it->cash += cash;
                cout << "Now your available cash is " << it->cash << endl;
                break;

            case '2':
                int withdrawAmount;
                cout << "How much cash you want to withdraw? ";
                cin >> withdrawAmount;
                if (withdrawAmount > it->cash) {
                    cout << "Now your available cash is just " << it->cash << endl;
                    // Optionally handle this case
                } else {
                    it->cash -= withdrawAmount;
                    cout << "Your new cash is " << it->cash << endl;
                }
                break;

            default:
                cout << "Invalid input" << endl;
                break;
        }
    } else {
        cout << "No such record found" << endl;
    }
}

void Bank::remove() {
    cout << "Press 1 to remove a specific record" << endl;
    cout << "Press 2 to remove all records" << endl;
    
    char ch;
    cin >> ch;

    switch (ch) {
        case '1': {
            string id;
            cout << "Enter ID of the person whose data you want to remove: ";
            cin >> id;
vector<person>::iterator it=persons.end();
int n=persons.size();
for (int i=0;i<n;i++)
{
	if(persons[i].ID==id)
	{
		it=persons.begin()+i;
		break;
	}
}
            if (it != persons.end()) {
                persons.erase(it);
                cout << "Record removed successfully" << endl;
            } else {
                cout << "No such record found" << endl;
            }
            break;
        }

        case '2':
            persons.clear();
            cout << "All records removed successfully" << endl;
            break;

        default:
            cout << "Invalid Input" << endl;
            break;
    }
}

int main() {
    Bank b;
    b.choice();
    return 0;
}


