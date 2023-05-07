/*here's an example of how you can implement a simple program in C++ that checks whether a user's input link is a phishing link or not:*/


#include <iostream>
#include <string>

using namespace std;

int main() {
    // Create an array of phishing links
    string phishing_links[] = {"phishing_link_1.com", "phishing_link_2.com", "phishing_link_3.com"};

    // Ask the user for a link to check
    string user_link;
    cout << "Enter a link to check: ";
    cin >> user_link;

    // Check if the user's link is a phishing link
    bool is_phishing = false;
    for (auto phishing_link : phishing_links) {
        if (user_link.find(phishing_link) != string::npos) {
            is_phishing = true;
            break;
        }
    }

    // Output the result
    if (is_phishing) {
        cout << "The link is a phishing link." << endl;
    } else {
        cout << "The link is not a phishing link." << endl;
    }

    return 0;
}
