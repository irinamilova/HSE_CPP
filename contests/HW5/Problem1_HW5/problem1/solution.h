#ifndef SOLUTION_H
#define SOLUTION_H

#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

enum class CitationType
{
    WebPage,
    Article
};

class Citation
{
public:
    Citation(const std::string& title, int year)
        : _title(title), _year(year)
    {
    }

    virtual ~Citation() {}
    virtual void printCitation(std::ostream& ostr) const = 0;
    virtual std::string getInlineCitation() const = 0;

protected:
    std::string _title;
    int _year;
};

// example 1 - Web Page
// you will need to modify it
class WebPage : public Citation
{
public:
    WebPage(const std::string& title, int year, const std::string& url)
        : Citation(title, year),
          _url(url)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "URL: " << _url << std::endl;
    }

    std::string getInlineCitation() const override {
        return "[Web page, " + std::to_string(_year) + "]";
    }

protected:
    std::string _url;
};


class PublishedWork : public Citation
{
public:
    PublishedWork(const std::string& title, int year, const std::string& firstname, const std::string& lastname)
        : Citation(title, year),
          _firstname(firstname),
          _lastname(lastname)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "FirstName: " << _firstname << std::endl;
        ostr << "FirstName: " << _lastname << std::endl;
    }

protected:
    std::string _firstname;
    std::string _lastname;
};


class Article : public PublishedWork
{
public:
    Article(const std::string& title, int year, const std::string& firstname, const std::string& lastname, const std::string& journal)
        : PublishedWork(title, year, firstname, lastname),
          _journal(journal)
    {
    }

    void printCitation(std::ostream& ostr) const override {
        ostr << "Title: " << _title << "\n";
        ostr << "Year: " << _year << "\n";
        ostr << "Author: " << _firstname << " " << _lastname << "\n";
        ostr << "Journal: " << _journal << "\n";
    }

    std::string getInlineCitation() const override {
        return "[" + _lastname + ", " + std::to_string(_year) + "]";
    }

protected:
    std::string _journal;
};


// task 2
Citation* addCitation(std::map<std::string, Citation*>& citations, CitationType type, const std::map<std::string, std::string> data)
{
    Citation* citationToAdd;

    if (type == CitationType::WebPage) {
        std::string key = data.at("key");
        std::string title = data.at("title");
        int year = std::stoi(data.at("year"));
        std::string url = data.at("url");
        citationToAdd = new WebPage(title, year, url);
        citations[key] = citationToAdd;
    }
    else if (type == CitationType::Article) {
        std::string key = data.at("key");
        std::string title = data.at("title");
        int year = std::stoi(data.at("year"));
        std::string journal = data.at("journal");
        std::string lastname = data.at("lastname");
        std::string firstname = data.at("firstname");
        citationToAdd = new Article(title, year, firstname, lastname, journal);
        citations[key] = citationToAdd;
    }
    return citationToAdd;
}


// task 4
void insertInlineCitations(std::string& text, const std::map<std::string, Citation*>& citations)
{
    bool isKey = true;
    std::string key = "";
    std::string str = "";

    for (char symb : text)
    {
        if (isKey && symb == '{')
        {
            isKey = false;
            key += symb;
        }
        else if (isKey && symb != '{') {
            str += symb;
        }
        else if (!isKey && symb != '}') {
            key += symb;
        }
        else if (!isKey && symb == '}') {
            key += symb;
            isKey = true;
            if (citations.find(key) != citations.end()) {
                str += citations.at(key) -> getInlineCitation();
            }
            else {
                str += key;
            }
            key = "";
        }
    }
    text = str;
}

// task 5
void printBibliographyAppearance(std::string& text, const std::map<std::string, Citation*>& citations)
{

}


// task 6
// you may modify classes in any way you want to solve this task
// you may add additional functions
void insertInlineAlphabetical(std::string& text, const std::map<std::string, Citation*>& citations)
{

}

#endif