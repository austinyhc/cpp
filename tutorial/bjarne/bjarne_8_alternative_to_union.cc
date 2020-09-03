#include <iostream>
#include <complex>
#include <string>


// Fail becuase the compiler does not know the size
// of structure, no_good.
// struct no_good {
//     no_good noGood;
// };

struct List;
struct Link {
    Link* previous;
    Link* successor;
    List* member_of;
    int value;
};

struct List {
    Link* head;
};


class Entry2 {
private:
    enum class Tag {none, number, text};
    Tag type;
    union {
        int i;
        std::string s;
    };

public:
    struct Bad_entry {};

    Entry2(const int& n) : type(Tag::none)
    {
        this->set_number(n);
    }

    Entry2(const std::string& s) : type(Tag::none)
    {
        this->set_text(s);
    }
    ~Entry2();

    // Copy constructor and copy assignment
    Entry2& operator=(const Entry2&);
    Entry2(const Entry2&);

    int number() const;
    std::string text() const;

    void set_number(int);
    void set_text(const std::string&);
};

int Entry2::number() const {
    if (type != Tag::number) throw Bad_entry{};
    return i;
}

std::string Entry2::text() const {
    if (type != Tag::text) throw Bad_entry{};
    return s;
}

void Entry2::set_number(int n) {
    if (type == Tag::text) {
        s.std::string::~string();
    }
    i = n;
    type = Tag::number;
}

void Entry2::set_text(const std::string& ss) {
    if (type == Tag::text) {
        s = ss;
    } else {
        new(&s) std::string(ss);
        type = Tag::text;
    }
}

Entry2& Entry2::operator=(const Entry2& e) {
    if (type==Tag::text && e.type==Tag::text) {
        s = e.s;
        return *this;
    }

    if (type==Tag::text) s.std::string::~string();

    switch (e.type) {
        case Tag::number:
            i = e.i;
            break;
        case Tag::text:
            new(&s) std::string(e.s);
    }
    type = e.type;
    return *this;
}

Entry2::~Entry2() {
    if (type == Tag::text) s.std::string::~string();
}

// In my opinion, there are two use cases for `union`.
//  1.) type punning without declaring two space for one data.
//      This is the low-level use case, we are looking at the same
//      bytecode but different data type
//  2.) Data container for two or more data. This is the high-level
//      use case, we can flexibly and economically contains data in
//      one class(container).

int main() {

    Entry2 e2 = std::string("Austin");
    std::cout << e2.text() << '\n';

    e2.set_number(2);
    std::cout << e2.number() << '\n';

    Entry2 e3 = 9;
    std::cout << e3.number() << '\n';

    e3 = std::string("Fran");
    std::cout << e3.text() << '\n';

    return 0;
}
