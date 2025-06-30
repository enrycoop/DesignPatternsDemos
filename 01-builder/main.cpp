#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
/*
E questo è il nucleo del modello di progettazione della build, quindi invece di costruire l'oggetto in una

singola riga di quello che stai facendo è usare un componente specializzato che ha le funzioni speciali

per aiutarti a costruire il componente.

E poi ad un certo punto basta chiamare una funzione per ottenere qualunque cosa tu abbia costruito e lavorare con

quello.
 */
using namespace std;


struct HtmlElement {
    string name, text;
    vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement() = default;

    HtmlElement(const string& name,const string& text)
    : name(name), text(text) {}

    string str(int indent=0) const {
        ostringstream oss;
        string i(indent_size*indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if (text.size() > 0) {
            oss << string(indent_size*(indent+1), ' ') << text << endl;
        }

        // chiamata ricorsiva
        for (const auto& e : elements) {
            oss << e.str(indent + 1);
        }
        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }
};

struct HtmlBuilder {
    HtmlElement root;

    HtmlBuilder(string root_name) {
        root.name = root_name;
    }

    void add_child(string child_name, string child_text) {
        HtmlElement e{child_name,child_text};
        root.elements.emplace_back(e);
    }

    string str() const { return root.str(); }
};

int main() {
    cout << "/////////////////////////////////////////////" << endl;
    // senza builder
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
    cout << "/////////////////////////////////////////////" << endl;

    HtmlBuilder builder{"ul"};
    builder.add_child("li", "hello");
    builder.add_child("li", "world");

    cout << builder.str() << endl;
    return 0;
}