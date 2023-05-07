# Phishing-link-detection


Phishing Link Checker
This is a simple C++ program that checks whether a given URL is a phishing link or not.

Version 1
The first version of the program (version1.cpp) checks whether the user's input link contains any of the known phishing links stored in an array. If a match is found, the program classifies the link as a phishing link. Otherwise, the program classifies the link as not a phishing link.

To run the program, simply compile and execute the version1.cpp file using your C++ compiler of choice.

Version 2
The second version of the program (version2.cpp) uses the Google Safe Browsing API to check whether a given URL is safe or not. The program sends a request to the API with the user's input URL and checks the API response for any matches. If there are no matches, the program classifies the link as safe. Otherwise, the program classifies the link as not safe.

To run the program, you need to have a valid API key and client ID from the Google Safe Browsing API. You also need to install the cURL library, which the program uses to make the API request. Once you have the API key, client ID, and cURL library installed, you can compile and execute the version2.cpp file using your C++ compiler of choice.

License
This program is licensed under the MIT License. See the LICENSE file for details.
