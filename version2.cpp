#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

// Callback function for handling the API response
size_t handle_response(char *ptr, size_t size, size_t nmemb, void *userdata) {
    string *response = (string*)userdata;
    response->append(ptr, size * nmemb);
    return size * nmemb;
}

int main() {
    // Set up the API request parameters
    string api_key = "your_api_key_here";
    string api_url = "https://safebrowsing.googleapis.com/v4/threatMatches:find?key=" + api_key;

    // Ask the user for a URL to check
    string user_url;
    cout << "Enter a URL to check: ";
    cin >> user_url;

    // Set up the API request payload
    string payload = "{"
                     "\"client\": {"
                     "\"clientId\": \"your_client_id_here\","
                     "\"clientVersion\": \"1.0.0\""
                     "},"
                     "\"threatInfo\": {"
                     "\"threatTypes\": [\"MALWARE\", \"SOCIAL_ENGINEERING\"],"
                     "\"platformTypes\": [\"WINDOWS\"],"
                     "\"threatEntryTypes\": [\"URL\"],"
                     "\"threatEntries\": [{\"url\": \"" + user_url + "\"}]"
                     "}"
                     "}";

    // Set up the API request using cURL
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        // Set up the cURL options
        curl_easy_setopt(curl, CURLOPT_URL, api_url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, payload.size());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_response);

        // Make the API request
        string response;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);

        // Clean up the cURL resources
        curl_easy_cleanup(curl);

        // Check if the API request was successful
        if (res == CURLE_OK) {
            // Check the API response for any matches
            if (response.find("\"matches\": []") != string::npos) {
                cout << "The URL is safe." << endl;
            } else {
                cout << "The URL is not safe." << endl;
            }
        } else {
            cout << "Error: Failed to make API request." << endl;
        }
    } else {
        cout << "Error: Failed to initialize cURL." << endl;
    }

    return 0;
}
