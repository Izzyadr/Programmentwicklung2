#include <iostream>
#include <string>

using namespace std;

class Buch {
protected:
    string _titel;
    double _basisAusleihGebuehr;

public:
    Buch(string titel, double basisAusleihGebuehr) : _titel(titel), _basisAusleihGebuehr(basisAusleihGebuehr) {}
    virtual double ausleihGebuehr(int tage) {
        return _basisAusleihGebuehr * tage;
    }
    virtual string getAusleihZeitraum() {
        return "2 Monate";
    }
    virtual ~Buch() {}
};

class Roman : public Buch {
public:
    Roman(string titel, double basisAusleihGebuehr) : Buch(titel, basisAusleihGebuehr) {}
    double ausleihGebuehr(int tage) override {
        double gebuehr = _basisAusleihGebuehr * tage;
        return (gebuehr > 5.0) ? 5.0 : gebuehr;
    }
    string getAusleihZeitraum() override {
        return "1 Monat";
    }
};

class Fachbuch : public Buch {
public:
    Fachbuch(string titel) : Buch(titel, 0) {}
    double ausleihGebuehr(int tage) override {
        return 2.0;
    }
    string getAusleihZeitraum() override {
        return "2 Wochen";
    }
};

int main() {
    Buch *buch = new Buch("Allgemeines Buch", 0.3);
    Buch *roman = new Roman("Literarischer Roman", 0.5);
    Buch *fachbuch = new Fachbuch("Technisches Fachbuch");

    cout << "Buch Gebühr: " << buch->ausleihGebuehr(10) << " Euro, Zeitraum: " << buch->getAusleihZeitraum() << endl;
    cout << "Roman Gebühr: " << roman->ausleihGebuehr(10) << " Euro, Zeitraum: " << roman->getAusleihZeitraum() << endl;
    cout << "Fachbuch Gebühr: " << fachbuch->ausleihGebuehr(10) << " Euro, Zeitraum: " << fachbuch->getAusleihZeitraum() << endl;

    delete buch;
    delete roman;
    delete fachbuch;

    return 0;
}
