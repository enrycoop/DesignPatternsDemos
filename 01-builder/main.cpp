#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>

using namespace std;

int main() {
    auto text = "Hello";
    string output;
    output += "<p>";
    output += text;
    output += "<p>";
    cout << output << endl;

    string words[] = { "hello", "world"};

    ostringstream oss;
    oss << "<ul>";
    for (auto word : words) {
        oss << "<li>" << word << "</li>";
    }
    oss << "</ul>";
    cout << oss.str() << endl;
    // qui il problema e' che non e' scalabile
    return 0;
}