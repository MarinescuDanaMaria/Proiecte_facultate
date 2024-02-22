#include <iostream>
using namespace std;

template<class T>
class Stiva
{

    int nrElem;
    T* vect;

public:
    Stiva()
    {
        this->nrElem = 0;
        this->vect = nullptr;
    }

    Stiva(int nrElem, T* v)
    {
        if (nrElem <= 0)
            return;

        this->vect = new T[this->nrElem];
        this->nrElem = nrElem;
        for (int i = 0; i < this->nrElem; i++)
        {
            this->vect[i] = vect[i];
        }

    }

    Stiva(const Stiva& s)
    {
        this->vect = new T[s.nrElem];
        this->nrElem = s.nrElem;
        for (int i = 0; i < this->nrElem; i++) {
            this->vect[i] = s.vect[i];
        }
    }

    ~Stiva() {}

    int getNrElem()
    {
        return this->nrElem;
    }

    void push(const T& x)
    {
        T* sir = new T[this->nrElem + 1];
        for (int i = 0; i < this->nrElem; i++)
        {
            sir[i] = this->vect[i];
        }

        sir[this->nrElem] = x;
        this->nrElem++;
        delete[] this->vect;
        this->vect = sir;
    }

    T pop() 
    {
        if (this->getNrElem() > 0)
        {
            T* sir = new T[this->nrElem - 1];
            for (int i = 0; i < this->nrElem - 1; i++) 
            {
                sir[i] = this->vect[i];
            };

            T elem = this->vect[this->nrElem - 1];
            this->nrElem--;
            delete[] this->vect;
            this->vect = sir;

            return elem;
        }
        else
        {
            throw std::out_of_range(" Stiva este goala. ");
        }
    }

    void print()
    {
        for (int i = 0; i < this->nrElem; i++)
        {
            cout << this->vect[i] << " ";
        }
        cout << endl;
    }
};

template<class T>
class Coada
{

    int nrElem;
    T* vect;

public:
    Coada()
    {
        this->nrElem = 0;
        this->vect = nullptr;
    }

    Coada(int nrElem, T* vect)
    {
        if (nrElem <= 0)
            return;

        this->vect = new T[this->nrElem];
        this->nrElem = nrElem;
        for (int i = 0; i < this->nrElem; i++)
        {
            this->vect[i] = vect[i];
        }
    }

    Coada(const Coada& c)
    {
        this->vect = new T[c.nrElem];
        this->nrElem = c.nrElem;
        for (int i = 0; i < this->nrElem; i++)
        {
            this->vect[i] = c.vect[i];
        }
    }

    ~Coada() {}

    int getNrElem()
    {
        return this->nrElem;
    }

    void adaugare_in_coada(const T& x)
    {
        T* sir1 = new T[this->nrElem + 1];
        for (int i = 0; i < this->nrElem; i++) {
            sir1[i] = this->vect[i];
        }

        sir1[this->nrElem] = x;
        this->nrElem++;
        delete[] this->vect;
        this->vect = sir1;
    }

    T scoatere_din_coada()
    {
        if (this->getNrElem() > 0)
        {
            T* sir1 = new T[this->nrElem - 1];
            for (int i = 0; i < this->nrElem - 1; i++) 
            {
                sir1[i] = this->vect[i + 1];
            };

            T elem = this->vect[0];
            this->nrElem--;
            delete[] this->vect;
            this->vect = sir1;

            return elem;
        }
        else {
            throw std::out_of_range(" Coada este goala. ");
        }
    }

    void print()
    {
        for (int i = 0; i < this->nrElem; i++)
        {
            cout << this->vect[i] << " ";
        }
        cout << endl;
    }
};

void testare_Stiva() 
{
    Stiva<int> intStiva;
    intStiva.push(1);
    intStiva.push(2);
    intStiva.push(3);

    int s = intStiva.pop();

    intStiva.print();

    // testare constructor cu parametri

    int v[4] = { 7,3,5,6 };
    Stiva<int> stiva_vector = Stiva<int>(sizeof(v) / sizeof(int), v);

    // testare constructor din alta stiva
    Stiva<int> stiva = Stiva<int>(stiva_vector);
    stiva.push(10); // se adauga 10 in stiva

    stiva.print();

}

void testare_Coada() 
{
    Coada <int> intCoada;
    intCoada.adaugare_in_coada(1);
    intCoada.adaugare_in_coada(2);
    intCoada.adaugare_in_coada(3);

    intCoada.print();

    cout << "Elementul pe care il scoatem din coada este " << intCoada.scoatere_din_coada();

    intCoada.print();

    // testare constructor cu parametri
    int v1[] = { 20,30,40 };
    Coada<int> coada_vector = Coada<int>(sizeof(v1) / sizeof(int), v1);

    coada_vector.print();

    // testare constructor din alta stiva
    Coada<int> coada = Coada<int>(coada_vector);

    cout << endl << coada.scoatere_din_coada();
}


void main() {
    testare_Stiva();
    testare_Coada();
}
