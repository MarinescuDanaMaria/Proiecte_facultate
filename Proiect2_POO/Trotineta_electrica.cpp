#include <iostream>

using namespace std;

// definirea clasei si a atributelor 

class MasinaDeCurse
{

private:

	const string serieMasina;
	string numeEchipa;
	int nrTururiGrandPrix;
	float lungimeTur;
	int nrTururiEfectuate;
	float* timpPeTurEfectuat;
	static int timpMinimPeTur;

public:

	// constructor implicit 

	TrotinetaElectrica() : serieMasina("B01ASC")
	{   
		this->numeEchipa = " ";
		this->nivelBaterie = 100.0f;
		this->timpPeTurEfectuat = nullptr;
		this->nrSesiuniInchiriere = 0;

		TrotinetaElectrica::NIVEL_MAXIM_BATERIE--; // variabila statica , scade la fiecare utilizare
	}

	// constructor cu parametri

	TrotinetaElectrica(string model, float nivelBaterie, const float consumPerKm, float* kmPerSesiuneInchiriere, int nrSesiuniInchiriere) : model(model), consumPerKm(consumPerKm)
	{

		if (nivelBaterie >= 0 && nivelBaterie <= 100)
			this->nivelBaterie = nivelBaterie;
		else
			this->nivelBaterie = 100.0f;

		if (nrSesiuniInchiriere >= 0 && nrSesiuniInchiriere <= 30)
		{
			this->nrSesiuniInchiriere = nrSesiuniInchiriere;

			if (this->nrSesiuniInchiriere > 0)
			{
				this->kmPerSesiuneInchiriere = new float[this->nrSesiuniInchiriere];
				for (int i = 0; i < this->nrSesiuniInchiriere; i++)
					this->kmPerSesiuneInchiriere[i] = kmPerSesiuneInchiriere[i];
			}
			else
				this->kmPerSesiuneInchiriere = nullptr;
		}
		else
		{
			this->nrSesiuniInchiriere = 0;
			this->kmPerSesiuneInchiriere = nullptr;
		}

		NIVEL_MAXIM_BATERIE--;
	}

	//constructor de copiere

	TrotinetaElectrica(const TrotinetaElectrica& t) : model(t.model), consumPerKm(t.consumPerKm)
	{
		nivelBaterie = t.nivelBaterie;
		this->nrSesiuniInchiriere = t.nrSesiuniInchiriere;
		if (this->nrSesiuniInchiriere > 0)
		{
			this->kmPerSesiuneInchiriere = new float[this->nrSesiuniInchiriere];
			for (int i = 0; i < this->nrSesiuniInchiriere; i++)
				this->kmPerSesiuneInchiriere[i] = t.kmPerSesiuneInchiriere[i];
		}
		else
			this->kmPerSesiuneInchiriere = nullptr;

		NIVEL_MAXIM_BATERIE--;
	}

	// destructor

	~TrotinetaElectrica()
	{
		delete[] this->kmPerSesiuneInchiriere;
		NIVEL_MAXIM_BATERIE--;
	}

	// getteri

	string getModel()
	{
		return model;
	}

	int getNrSesiuniInchiriere()
	{
		return nrSesiuniInchiriere;
	}

	float getNivelBaterie()
	{
		return nivelBaterie;
	}

	// metode generice

	TrotinetaElectrica utilizeazaTrotineta(float kmparcursi)
	{
		nrSesiuniInchiriere++; // adaugam o noua inregistrare 

		float* aux = new float[nrSesiuniInchiriere]; // folosim o copie 
		for (int i = 0; i < this->nrSesiuniInchiriere - 1; i++)
		{
			aux[i] = this->kmPerSesiuneInchiriere[i];
		}

		aux[this->nrSesiuniInchiriere - 1] = kmparcursi; // adaugam kmparcursi asociati cu ultima inregistrare in vectorul de km

		delete[] this->kmPerSesiuneInchiriere;

		this->kmPerSesiuneInchiriere = aux;

		return *this;

	}

	float incarcaTrotineta(int minute, float rataIncarcarePerMinut)
	{
		if (minute < 0 || rataIncarcarePerMinut < 0)
			cout << "Valorile trebuie sa fie pozitive";
		else
		{
			nivelBaterie += minute * rataIncarcarePerMinut;

			if (nivelBaterie > 100) // daca nivelul bateriei depaseste 100%
				nivelBaterie = nivelBaterie - (nivelBaterie - 100);

		}
		return nivelBaterie;
	}

	float kmDeParcurs()
	{
		return nivelBaterie / consumPerKm;
	}

	//  operatori 

	  // operatorul de atribuire 
	TrotinetaElectrica operator=(TrotinetaElectrica t)
	{
		nivelBaterie = t.nivelBaterie;
		nrSesiuniInchiriere = t.nrSesiuniInchiriere;

		if (this->kmPerSesiuneInchiriere != nullptr)
			delete[] this->kmPerSesiuneInchiriere;
		if (this->nrSesiuniInchiriere > 0)
		{
			this->kmPerSesiuneInchiriere = new float[this->nrSesiuniInchiriere];
			for (int i = 0; i < this->nrSesiuniInchiriere; i++)
				this->kmPerSesiuneInchiriere[i] = t.kmPerSesiuneInchiriere[i];
		}
		else
			this->kmPerSesiuneInchiriere = nullptr;

		return *this;
	}

	// operatorul functie 

	float operator()(int poz_start, int poz_final)
	{
		float s = 0;
		if (poz_start > poz_final)
		{
			int aux_poz;
			aux_poz = poz_start;
			poz_start = poz_final;
			poz_final = aux_poz;
		}
		if (poz_start >= 0 && poz_final < nrSesiuniInchiriere)
		{
			for (int i = poz_start; i <= poz_final; i++)
			{
				s += kmPerSesiuneInchiriere[i];
			}
		}
		else
			cout << "Valorile se afla in afara intervalului permis";
		return s;

	}


	friend ostream& operator<<(ostream& out, TrotinetaElectrica& t);

	friend istream& operator>>(istream& in, TrotinetaElectrica& t);

	friend TrotinetaElectrica operator+(float kmparcursi, TrotinetaElectrica& t);

};
int TrotinetaElectrica::NIVEL_MAXIM_BATERIE = 100; // pleaca de la 100, si la fiecare utilizare scade cu 1 

// operator +

TrotinetaElectrica operator+(float kmparcursi, TrotinetaElectrica& t)
{
	TrotinetaElectrica t_aux = t;
	t_aux.nrSesiuniInchiriere++;

	float* aux = new float[t_aux.nrSesiuniInchiriere];
	for (int i = 0; i < t_aux.nrSesiuniInchiriere - 1; i++)
	{
		aux[i] = t_aux.kmPerSesiuneInchiriere[i];
	}

	aux[t_aux.nrSesiuniInchiriere - 1] = kmparcursi;

	delete[] t_aux.kmPerSesiuneInchiriere;
	t_aux.kmPerSesiuneInchiriere = aux;

	return t_aux;

}


ostream& operator<<(ostream& out, TrotinetaElectrica& t)
{
	cout << endl << " Trotineta cu modelul : " << t.model << "  are nivelul bateriei : " << t.nivelBaterie << " si consumul per km : " << t.consumPerKm << ". "<< " Km parcursi la fiecare sesiune de inchiriere sunt : ";
	for (int i = 0; i < t.nrSesiuniInchiriere; i++)
		cout << t.kmPerSesiuneInchiriere[i] << ", ";
	cout << endl << " Nr. sesiunilor de inchiriere curente : " << t.nrSesiuniInchiriere;
	cout << endl << " Nivelul maxim al bateriei este : " << t.NIVEL_MAXIM_BATERIE;

	return out;
}



istream& operator>>(istream& in, TrotinetaElectrica& t)
{
	cout << endl;
	cout << endl << " nivel baterie =";
	in >> t.nivelBaterie;
	cout << " nr sesiuni inchiriere =";
	in >> t.nrSesiuniInchiriere;

	delete[] t.kmPerSesiuneInchiriere;
	if (t.nrSesiuniInchiriere > 0)
	{
		t.kmPerSesiuneInchiriere = new float[t.nrSesiuniInchiriere];
		cout << " km per sesiune inchiriere = ";
		for (int i = 0; i < t.nrSesiuniInchiriere; i++)
			in >> t.kmPerSesiuneInchiriere[i];
	}
	else
	{
		t.kmPerSesiuneInchiriere = nullptr;
	}

	return in;
}


void main()
{
	cout << " TEMA POO MARINESCU DANA MARIA " <<endl<<endl;

    cout << " CERINTA 1 : Sa se creeze un proiect in Microsoft Visual Studio care sa nu genereze erori de compilare "<< endl<< endl;

    cout << " CERINTA 2 : Sa se defineasca clasa si atributele sale "<< endl<<endl;


	TrotinetaElectrica t1;
	TrotinetaElectrica t3;

	// testare metode 

	 // getteri si constructor implicit

	cout << " CERINTA 3 : Testare getteri si constructor implicit " << endl;
	cout << endl << " modelul pentru trotineta t1 = " << t1.getModel();
	cout << endl << " nr sesiuni inchiriere pt trotineta t1 = " << t1.getNrSesiuniInchiriere();
	cout << endl << " nivelul bateriei pt trotineta t1 = " << t1.getNivelBaterie();

	// apelare constructor cu parametri

	float kmPerSesiune[3] = { 10.5, 12.2f, 24.0 };
	TrotinetaElectrica t2("gfdsj123", 25, 8, kmPerSesiune, 20);

	cout << endl << endl;
	cout << " CERINTA 4 : Testare constructor cu parametri " << endl;

	cout << endl << " modelul pentru trotineta t2 = " << t2.getModel();
	cout << endl << " nr sesiuni inchiriere pt trotineta t2 = " << t2.getNrSesiuniInchiriere();
	cout << endl << " nivelul bateriei pt trotineta t2 = " << t2.getNivelBaterie();

	// apel functii

	cout << endl << endl;
	cout << " CERINTA 5 : Sa se adauge o noua sesiune de utilizare a trotinetei cu valoarea indicata pentru km parcursi ";

	cin >> t3;
	t3.utilizeazaTrotineta(12);
	cout << t3;

	cout << endl << endl;
	cout << " CERINTA 6 : Testare constructor de copiere " << endl;

	TrotinetaElectrica t7 = t3;
	cout << t7;

	cout << endl << endl;
	cout << " CERINTA 7 : Testare metode incarcaTrotineta() si kmDeParcurs() " << endl;

	cout << endl << " Nivelul bateriei dupa incarcare este : " << t3.incarcaTrotineta(20, 2); // returneaza nivelul bateriei dupa incarcare

    cout << endl << " Km care mai pot fi parcursi : " <<t3.kmDeParcurs();

	cout << endl << endl;
	cout << " CERINTA 8 : Testare operator de atribuire  " << endl;

    t2 = t7; 
	cout << t2;

	cout << endl << endl;
	cout << " CERINTA 9 : Testare operatori << si >> ";

	TrotinetaElectrica t4;
	cin >> t4;
	cout << t4;

	cout << endl << endl;
	cout << " CERINTA 10 : Testare operator +  " << endl;

	t7 = 10 + t7;
	cout << t7;

	cout << endl << endl;
	cout << " CERINTA 11 : Testare operator functie  " << endl;

    cout << endl << " Suma km pentru primele 3 sesiuni este : ";
	cout << t7(0,2);
}